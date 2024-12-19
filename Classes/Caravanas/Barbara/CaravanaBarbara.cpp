//
// Created by mauro on 12/16/2024.
//

#include "CaravanaBarbara.h"

CaravanaBarbara::CaravanaBarbara(int id, int linha, int coluna)
        : Caravana(id, 'B', linha, coluna) {
    tripulantes = 40;
    capacidadeCarga = 0;
    capacidadeAgua = 0;
    aguaAtual = 0;
}

void CaravanaBarbara::comportamentoAutonomo() {
    // Persegue caravanas do utilizador a 8 posições de distância
}

bool CaravanaBarbara::afetarPorTempestade() {
    tripulantes = max(0, tripulantes - (tripulantes / 10)); // Lose 10% of the crew
    if (rand() % 100 < 25) {
        return true; // 25% chance to destroy the caravan
    }
    return false;
}
