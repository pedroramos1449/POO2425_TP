//
// Created by mauro on 11/26/2024.
//

#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <vector>
#include <memory>
#include "../Mapa/Mapa.h"
#include "../Caravana/Caravana.h"
#include "../Buffer/Buffer.h"
using namespace std;

class Simulador {
    unique_ptr<Buffer> buffer;
    unique_ptr<Mapa> mapa;
    vector<shared_ptr<Caravana>> caravanas;

public:
    Simulador(int linhas, int colunas);
    void executarTurno(); // Executa as ações de um turno
    void processarComando(const string& comando); // Processa comandos do utilizador
};

#endif // SIMULADOR_H