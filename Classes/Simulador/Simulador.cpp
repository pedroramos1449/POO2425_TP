#include "Simulador.h"
#include <sstream>
#include <iostream>

Simulador::Simulador()
        : buffer(make_unique<Buffer>(10, 20)),
          mapa(nullptr), moedas(0) {}

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
        buffer->escrever("Comando: config");

        // Initialize the map
        mapa = make_unique<Mapa>(10, 20);

        // Define static zones for testing
        mapa->definirZona(0, 1, make_shared<Deserto>());
        mapa->definirZona(1, 1, make_shared<Montanha>());
        mapa->definirZona(3, 3, make_shared<Cidade>('A'));
        mapa->definirZona(5, 5, make_shared<Cidade>('B'));
        mapa->definirZona(7, 7, make_shared<Montanha>());
        mapa->definirZona(2, 4, make_shared<Deserto>());

        moedas = 1000;

        // Display the map in the buffer
        buffer->limpar();
        buffer->moverCursor(0, 0);
        buffer->escrever("Mapa configurado manualmente.");
        mapa->mostrar(*buffer);
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

    buffer->mostrar();
}
