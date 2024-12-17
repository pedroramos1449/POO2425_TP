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



