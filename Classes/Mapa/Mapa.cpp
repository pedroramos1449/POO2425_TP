//
// Created by mauro on 11/26/2024.
//

#include "Mapa.h"

Mapa::Mapa(int l, int c) : linhas(l), colunas(c), grelha(l, vector<shared_ptr<Deserto>>(c, nullptr)) {}

void Mapa::definirDeserto(int linha, int coluna, shared_ptr<Deserto> Deserto) {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
        grelha[linha][coluna] = move(Deserto);
}

shared_ptr<Deserto> Mapa::obterDeserto(int linha, int coluna) const {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
        return grelha[linha][coluna];
    return nullptr;
}

void Mapa::mostrar(Buffer& buffer) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            buffer.moverCursor(i, j);
            if (grelha[i][j]) {
                buffer.escrever(grelha[i][j]->getTipo());
            } else {
                buffer.escrever('.');
            }
        }
    }
}


