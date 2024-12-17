//
// Created by mauro on 12/16/2024.
//

#include "CaravanaSecreta.h"

CaravanaSecreta::CaravanaSecreta(int id, int linha, int coluna)
        : Caravana(id, 'S', linha, coluna) {
    tripulantes = 30; // Defina o valor
    capacidadeCarga = 20; // Defina o valor
    capacidadeAgua = 300; // Defina o valor
    aguaAtual = capacidadeAgua;
}

void CaravanaSecreta::comportamentoAutonomo() {
    // Comportamento secreto definido pelo grupo
}
