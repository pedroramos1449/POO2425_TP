//
// Created by mauro on 11/26/2024.
//

#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <vector>
#include <memory>
#include "../Mapa/Mapa.h"
#include "../Buffer/Buffer.h"
#include "../Caravanas/Caravana.h"

using namespace std;

class Simulador {
    unique_ptr<Buffer> buffer;
    unique_ptr<Mapa> mapa;
    vector<shared_ptr<Caravana>> caravanas;

    int turno;
    int moedas;
    int instantesEntreNovosItens;
    int duracaoItem;
    int maxItens;
    int precoVendaMercadoria;
    int precoCompraMercadoria;
    int precoCaravana;
    int instantesEntreNovosBarbaros;
    int duracaoBarbaros;

public:
    Simulador();
    void executarTurno(); // Executa as ações de um turno/instante
    void processarComando(const string& comando); // Processa comandos do utilizador
    void lerConfig(const string &nomeArquivo);
    void deduzirElementosMapa();
};

#endif // SIMULADOR_H
