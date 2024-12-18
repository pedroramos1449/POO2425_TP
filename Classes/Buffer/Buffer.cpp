//
// Created by mauro on 11/26/2024.
//

#include "Buffer.h"
#include <iostream>

Buffer::Buffer(int l, int c) : linhas(l), colunas(c), cursorLinha(0), cursorColuna(0) {
    matriz = make_unique<char[]>(linhas * colunas);
    //limpar();
}

void Buffer::limpar() {
    for (int i = 0; i < linhas * colunas; ++i)
        matriz[i] = ' ';
}

void Buffer::moverCursor(int l, int c) {
    if (l >= 0 && l < linhas && c >= 0 && c < colunas) {
        cursorLinha = l;
        cursorColuna = c;
    }
}

void Buffer::escrever(char c) {
    matriz[cursorLinha * colunas + cursorColuna] = c;
    if (cursorColuna + 1 < colunas)
        ++cursorColuna;
}

void Buffer::escrever(const string& str) {
    for (char c : str)
        escrever(c);
}

void Buffer::mostrar() {
    cout << "Mostrar" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j)
            cout << matriz[i * colunas + j];
        cout << endl;
    }
}
