//
// Created by mauro on 11/26/2024.
//

#include "Mapa.h"

Mapa::Mapa(int l, int c) : linhas(l), colunas(c), grelha(l, vector<shared_ptr<Zona>>(c, nullptr)) {}

void Mapa::definirZona(int linha, int coluna, shared_ptr<Zona> zona) {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
        grelha[linha][coluna] = move(zona);
}

shared_ptr<Zona> Mapa::obterZona(int linha, int coluna) const {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
        return grelha[linha][coluna];
    return nullptr;
}

void Mapa::mostrar(Buffer& buffer) {
    buffer.limpar();
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (grelha[i][j])
                buffer.moverCursor(i, j), buffer.escrever(grelha[i][j]->getTipo());
            else
                buffer.moverCursor(i, j), buffer.escrever('.');
        }
    }
    buffer.mostrar();
}

int Mapa::getLinhas() const {
    return linhas;
}

void Mapa::setLinhas(int linhas) {
    Mapa::linhas = linhas;
}

int Mapa::getColunas() const {
    return colunas;
}

void Mapa::setColunas(int colunas) {
    Mapa::colunas = colunas;
}


