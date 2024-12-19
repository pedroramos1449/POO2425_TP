//
// Created by mauro on 11/26/2024.
//

#include <iostream>
#include "Caravana.h"

Caravana::Caravana(int id, char tipo, int linha, int coluna)
        : id(id), tipo(tipo), linha(linha), coluna(coluna), tripulantes(0),
          capacidadeCarga(0), cargaAtual(0), capacidadeAgua(0), aguaAtual(0) {}

void Caravana::mover(const std::string& direcao) {
    // Exemplo simples de movimento
    if (direcao == "C") linha--;
    else if (direcao == "B") linha++;
    else if (direcao == "E") coluna--;
    else if (direcao == "D") coluna++;
}

void Caravana::comportamentoAutonomo() {
    // Comportamento padrão
}

void Caravana::perderTripulante() {
    if (tripulantes > 0) tripulantes--;
}
