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

bool CaravanaSecreta::afetarPorTempestade()  {
    // Custom secret logic (can be similar to Militar or unique)
    tripulantes = max(0, tripulantes - (tripulantes / 5)); // Custom logic for loss of crew
    if (rand() % 100 < 20) { // Custom destruction chance
        return true;
    }
    return false;
}