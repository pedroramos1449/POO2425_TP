//
// Created by mauro on 12/16/2024.
//

#include "CaravanaMilitar.h"

CaravanaMilitar::CaravanaMilitar(int id, int linha, int coluna)
        : Caravana(id, 'M', linha, coluna) {
    tripulantes = 40;
    capacidadeCarga = 5;
    capacidadeAgua = 400;
    aguaAtual = capacidadeAgua;
}

void CaravanaMilitar::comportamentoAutonomo() {
    // Persegue caravanas bárbaras a 6 posições de distância
}


