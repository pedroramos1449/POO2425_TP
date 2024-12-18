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
