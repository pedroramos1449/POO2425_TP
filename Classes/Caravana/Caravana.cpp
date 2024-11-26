//
// Created by mauro on 11/26/2024.
//

#include "Caravana.h"

Caravana::Caravana(int id) : id(id), tripulacao(0), capacidadeCarga(0), capacidadeAgua(0) {}

void Caravana::mover(const string& direcao) {
    // Implementação do movimento
}

void Caravana::comportamentoAutonomo() {
    // Implementação genérica
}

int Caravana::getID() const {
    return id;
}

CaravanaComercial::CaravanaComercial(int id) : Caravana(id) {}

void CaravanaComercial::comportamentoAutonomo() {
    // Comportamento de caravanas comerciais
}

CaravanaMilitar::CaravanaMilitar(int id) : Caravana(id) {}

void CaravanaMilitar::comportamentoAutonomo() {
    // Comportamento de caravanas militares
}
