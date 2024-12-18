#include "Simulador.h"
#include <sstream>
#include <iostream>

#include "Simulador.h"
#include "../Caravanas/Militar/CaravanaMilitar.h"
#include "../Caravanas/Secreta/CaravanaSecreta.h"
#include "../Caravanas/Barbara/CaravanaBarbara.h"
#include "../Caravanas/Comercio/CaravanaComercio.h"
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

    int idCaravanaComercio = 0;
    int idCaravanaBarbara = 0;
    int idCaravanaMilitar = 0;
    int idCaravanaSecreta = 0;

// Configura as zonas no mapa
    for (int i = 0; i < mapaConfig.size(); ++i) {
        for (int j = 0; j < mapaConfig[i].size(); ++j) {
            char tipo = mapaConfig[i][j];

            if (tipo == '.') {
                // ZONA VAZIA - Deserto
                mapa->definirZona(i, j, make_shared<Deserto>());
            }
            else if (tipo == '+') {
                // MONTANHA
                mapa->definirZona(i, j, make_shared<Montanha>());
            }
            else if (islower(tipo)) {
                // CIDADE (a, b, c, d...)
                mapa->definirZona(i, j, make_shared<Cidade>(tipo));
            }
            else if (isdigit(tipo)) {
                // **CARAVANA COMERCIAL (0-9)**
                int id = tipo - '0'; // Converte o caractere '0'-'9' para o valor numérico correspondente
                auto caravana = make_shared<CaravanaComercio>(id, i, j);
                caravanas.push_back(caravana);
                // **Mostra o número no mapa**
                mapa->definirZona(i, j, caravana);
            }
            else if (tipo == '!') {
                // **CARAVANA BÁRBARA**
                auto caravana = make_shared<CaravanaBarbara>(idCaravanaBarbara++, i, j);
                caravanas.push_back(caravana);
                // **Mostra o '!' no mapa**
                mapa->definirZona(i, j, caravana);
            }
            else if (tipo == 'M') {
                // **CARAVANA MILITAR**
                auto caravana = make_shared<CaravanaMilitar>(idCaravanaMilitar++, i, j);
                caravanas.push_back(caravana);
                // **Mostra o 'M' no mapa**
                mapa->definirZona(i, j, caravana);
            }
            else if (tipo == '?') {
                // **CARAVANA SECRETA**
                auto caravana = make_shared<CaravanaSecreta>(idCaravanaSecreta++, i, j);
                caravanas.push_back(caravana);
                // **Mostra o '?' no mapa**
                mapa->definirZona(i, j, caravana);
            }
            else {
                cerr << "Caractere desconhecido no mapa: " << tipo
                     << " na posição (" << i << ", " << j << ")" << endl;
            }
        }
    }

    // Deduz elementos do mapa (cidades, caravanas, bárbaros)
    //deduzirElementosMapa();
}

void Simulador::deduzirElementosMapa() {
    for (int i = 0; i < mapa->getLinhas(); ++i) {
        for (int j = 0; j < mapa->getColunas(); ++j) {
            shared_ptr<Zona> zona = mapa->obterZona(i, j);
            if (!zona) continue;

            char tipo = zona->getTipo();

            // Verificação de caravana
            if (isdigit(tipo)) { // CARAVANA COMERCIAL (0-9)
                int id = tipo - '0'; // Converte o caractere para o número
                auto caravana = make_shared<CaravanaComercio>(id, i, j);
                caravanas.push_back(caravana);
                mapa->definirZona(i, j, make_shared<Deserto>()); // Substitui a posição no mapa para Deserto
            }
            else if (tipo == '!') { // CARAVANA BÁRBARA
                static int idBarbaro = 0; // Incremental para dar ID único às caravanas bárbaras
                auto caravana = make_shared<CaravanaBarbara>(idBarbaro++, i, j);
                caravanas.push_back(caravana);
                mapa->definirZona(i, j, make_shared<Deserto>()); // Substitui a posição no mapa para Deserto
            }
            else if (tipo == 'M') { // CARAVANA MILITAR
                static int idMilitar = 0; // Incremental para dar ID único às caravanas militares
                auto caravana = make_shared<CaravanaMilitar>(idMilitar++, i, j);
                caravanas.push_back(caravana);
                mapa->definirZona(i, j, make_shared<Deserto>()); // Substitui a posição no mapa para Deserto
            }
            else if (tipo == '?') { // CARAVANA SECRETA
                static int idSecreta = 0; // Incremental para dar ID único às caravanas secretas
                auto caravana = make_shared<CaravanaSecreta>(idSecreta++, i, j);
                caravanas.push_back(caravana);
                mapa->definirZona(i, j, make_shared<Deserto>()); // Substitui a posição no mapa para Deserto
            }
            else if (islower(tipo)) { // CIDADE (a, b, c, d...)
                // Pode ser que você queira contabilizar ou armazenar as cidades
                cout << "Cidade identificada na posição (" << i << ", " << j << ") com o nome: " << tipo << endl;
            }
            else if (tipo == '+') { // MONTANHA
                // Não precisa fazer nada, pois a montanha já é uma zona que permanece no mapa
            }
            else if (tipo == '.') { // DESERTO
                // Nada a fazer, já é um deserto
            }
            else {
                cerr << "Caractere desconhecido no mapa: " << tipo
                     << " na posição (" << i << ", " << j << ")" << endl;
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
        buffer->mostrar();
        
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

    //buffer->mostrar();
}
