#include "Simulador.h"
#include <sstream>
#include <iostream>

#include "Simulador.h"
#include <sstream>
#include <iostream>
#include <fstream>

Simulador::Simulador()
        : buffer(make_unique<Buffer>(20, 40)), // Buffer inicial padrão
          mapa(nullptr), moedas(0), turno(0),
          instantesEntreNovosItens(0), duracaoItem(0), maxItens(0),
          precoVendaMercadoria(0), precoCompraMercadoria(0), precoCaravana(0),
          instantesEntreNovosBarbaros(0), duracaoBarbaros(0) {}

void Simulador::lerConfig(const string& nomeArquivo) {
    ifstream cfg(nomeArquivo);
    if (!cfg.is_open()) {
        cerr << "Erro: Não foi possível abrir o arquivo de configuração." << endl;
        return;
    }

    string linha;
    int linhas = 0, colunas = 0;
    vector<string> mapaConfig;

    while (getline(cfg, linha)) {
        stringstream ss(linha);
        string chave;
        ss >> chave;

        if (chave == "linhas") {
            ss >> linhas;
        } else if (chave == "colunas") {
            ss >> colunas;
        } else if (linha.find('.') != string::npos || linha.find('+') != string::npos) {
            mapaConfig.push_back(linha);
        } else if (chave == "moedas") {
            ss >> moedas;
        } else if (chave == "instantes_entre_novos_itens") {
            ss >> instantesEntreNovosItens;
        } else if (chave == "duração_item") {
            ss >> duracaoItem;
        } else if (chave == "max_itens") {
            ss >> maxItens;
        } else if (chave == "preço_venda_mercadoria") {
            ss >> precoVendaMercadoria;
        } else if (chave == "preço_compra_mercadoria") {
            ss >> precoCompraMercadoria;
        } else if (chave == "preço_caravana") {
            ss >> precoCaravana;
        } else if (chave == "instantes_entre_novos_barbaros") {
            ss >> instantesEntreNovosBarbaros;
        } else if (chave == "duração_barbaros") {
            ss >> duracaoBarbaros;
        }
    }

    cfg.close();

    // Inicializa o mapa com as dimensões lidas
    mapa = make_unique<Mapa>(linhas, colunas);

    // Configura as zonas no mapa
    for (int i = 0; i < mapaConfig.size(); ++i) {
        for (int j = 0; j < mapaConfig[i].size(); ++j) {
            char tipo = mapaConfig[i][j];
            if (tipo == '.') {
                mapa->definirZona(i, j, make_shared<Deserto>());
            } else if (tipo == '+') {
                mapa->definirZona(i, j, make_shared<Montanha>());
            } else if (tipo == '!') {
                //Caravana Barbara //NOTA: Prof disse que caravana barbara pode ser tipo diferente
                //mapa->definirZona(i, j, make_shared<Caravana>(tipo));
            } else {
                //Caravana comercial //Caravan militar
            }
        }
    }

    // Deduz elementos do mapa (cidades, caravanas, bárbaros)
    //deduzirElementosMapa();
}

void Simulador::deduzirElementosMapa() {
    // Percorre o mapa e deduz os elementos iniciais (cidades, caravanas, bárbaros)
    for (int i = 0; i < mapa->getLinhas(); ++i) {
        for (int j = 0; j < mapa->getColunas(); ++j) {
            shared_ptr<Zona> zona = mapa->obterZona(i, j);
            if (!zona) continue;

            char tipo = zona->getTipo();
            if (isdigit(tipo)) {
                // Caravana identificada por um número
                caravanas.push_back(make_shared<Caravana>(tipo - '0'));
            } else if (tipo == '!') {
                // Bárbaro identificado por um símbolo específico
                mapa->definirZona(i, j, make_shared<Deserto>());
            }
        }
    }
}
void Simulador::executarTurno() {
    if (!mapa) {
        if (buffer) {
            buffer->limpar();
            buffer->moverCursor(0, 0);
            buffer->escrever("Erro: mapa nao configurado.");
            buffer->mostrar();
        } else {
            cerr << "Erro: Buffer nao inicializado durante turno." << endl;
        }
        return;
    }

    // Update state in the buffer
    if (buffer) {
        buffer->limpar();
        mapa->mostrar(*buffer); // Display the map on the buffer
        buffer->mostrar();
    } else {
        cerr << "Erro: Buffer nao inicializado." << endl;
    }
}

void Simulador::processarComando(const string& comando) {
    stringstream ss(comando);
    string cmd;
    ss >> cmd;

    buffer->limpar();
    buffer->moverCursor(0, 0);

    if (cmd == "config") {
        string nomeArquivo;
        ss >> nomeArquivo;
        lerConfig(nomeArquivo);

        buffer->limpar();
        buffer->moverCursor(0, 0);
        mapa->mostrar(*buffer);
        //buffer->escrever("Configuracao carregada.");
        cout << "\nConfiguracao carregada...\n" << endl;
        //buffer->mostrar();
        
    } else if (cmd == "sair") {
        // Comando da fase 1
        buffer->escrever("Comando: sair");

    } else if (cmd == "prox") {
        // Comando da fase 2
        int n;
        ss >> n;
        buffer->escrever("Comando: prox ");
        buffer->escrever(to_string(n));

    } else if (cmd == "exec") {
        // Comando da fase 2
        string nomeFicheiro;
        ss >> nomeFicheiro;
        buffer->escrever("Comando: exec ");
        buffer->escrever(nomeFicheiro);

    } else if (cmd == "comprac") {
        // Comando da fase 2
        string cidade, tipoCaravana;
        ss >> cidade >> tipoCaravana;
        buffer->escrever("Comando: comprac ");
        buffer->escrever(cidade + " " + tipoCaravana);

    } else if (cmd == "precos") {
        // Comando da fase 2
        buffer->escrever("Comando: precos");

    } else if (cmd == "cidade") {
        // Comando da fase 2
        string cidade;
        ss >> cidade;
        buffer->escrever("Comando: cidade ");
        buffer->escrever(cidade);

    } else if (cmd == "caravana") {
        // Comando da fase 2
        string caravana;
        ss >> caravana;
        buffer->escrever("Comando: caravana ");
        buffer->escrever(caravana);

    } else if (cmd == "compra") {
        // Comando da fase 2
        string caravana;
        int mercadoria;
        ss >> caravana >> mercadoria;
        buffer->escrever("Comando: compra ");
        buffer->escrever(caravana + " " + to_string(mercadoria));

    } else if (cmd == "vende") {
        // Comando da fase 2
        string caravana;
        ss >> caravana;
        buffer->escrever("Comando: vende ");
        buffer->escrever(caravana);

    } else if (cmd == "move") {
        // Comando da fase 2
        string caravana, direcao;
        ss >> caravana >> direcao;
        buffer->escrever("Comando: move ");
        buffer->escrever(caravana + " " + direcao);

    } else if (cmd == "auto") {
        // Comando da fase 2
        string caravana;
        ss >> caravana;
        buffer->escrever("Comando: auto ");
        buffer->escrever(caravana);

    } else if (cmd == "stop") {
        // Comando da fase 2
        string caravana;
        ss >> caravana;
        buffer->escrever("Comando: stop ");
        buffer->escrever(caravana);

    } else if (cmd == "barbaro") {
        // Comando da fase 2
        int linha, coluna;
        ss >> linha >> coluna;
        buffer->escrever("Comando: barbaro ");
        buffer->escrever(to_string(linha) + " " + to_string(coluna));

    } else if (cmd == "areia") {
        // Comando da fase 2
        int linha, coluna, raio;
        ss >> linha >> coluna >> raio;
        buffer->escrever("Comando: areia ");
        buffer->escrever(to_string(linha) + " " + to_string(coluna) + " " + to_string(raio));

    } else if (cmd == "moedas") {
        // Comando da fase 2
        int quantidade;
        ss >> quantidade;
        buffer->escrever("Comando: moedas ");
        buffer->escrever(to_string(quantidade));

    } else if (cmd == "tripul") {
        // Comando da fase 2
        string caravana;
        int tripulantes;
        ss >> caravana >> tripulantes;
        buffer->escrever("Comando: tripul ");
        buffer->escrever(caravana + " " + to_string(tripulantes));

    } else if (cmd == "saves") {
        // Comando da fase 2
        string nome;
        ss >> nome;
        buffer->escrever("Comando: saves ");
        buffer->escrever(nome);

    } else if (cmd == "loads") {
        // Comando da fase 2
        string nome;
        ss >> nome;
        buffer->escrever("Comando: loads ");
        buffer->escrever(nome);

    } else if (cmd == "lists") {
        // Comando da fase 2
        buffer->escrever("Comando: lists");

    } else if (cmd == "dels") {
        // Comando da fase 2
        string nome;
        ss >> nome;
        buffer->escrever("Comando: dels ");
        buffer->escrever(nome);

    } else if (cmd == "terminar") {
        // Comando da fase 2
        buffer->escrever("Comando: terminar");

    } else {
        // Comando desconhecido
        buffer->escrever("Comando desconhecido: ");
        buffer->escrever(cmd);
    }

    buffer->mostrar();
}
