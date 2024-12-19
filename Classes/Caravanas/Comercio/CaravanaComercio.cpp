//
// Created by mauro on 12/16/2024.
//

#include "CaravanaComercio.h"

CaravanaComercio::CaravanaComercio(int id, int linha, int coluna)
        : Caravana(id, 'C', linha, coluna) {
    tripulantes = 20;
    capacidadeCarga = 40;
    capacidadeAgua = 200;
    aguaAtual = capacidadeAgua;
}

void CaravanaComercio::comportamentoAutonomo() {
    // Comportamento de caravanas comerciais
}

bool CaravanaComercio::afetarPorTempestade() {
    if (rand() % 100 < (cargaAtual > capacidadeCarga / 2 ? 50 : 25)) {
        // 50% or 25% chance to destroy the caravan
        return true;
    } else {
        cargaAtual *= 0.75; // Lose 25% of the cargo
    }
    return false;
}


