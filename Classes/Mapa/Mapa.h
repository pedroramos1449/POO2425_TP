//
// Created by mauro on 11/26/2024.
//

#ifndef MAPA_H
#define MAPA_H

#include "../Zonas/Deserto//Deserto.h"
#include "../Zonas/Montanha/Montanha.h"
#include "../Zonas/Cidade/Cidade.h"
#include "../Buffer/Buffer.h"

#include <vector>
#include <memory>

using namespace std;

class Mapa {
    int linhas;
    int colunas;
    vector<vector<shared_ptr<Deserto>>> grelha; // Grelha do mapa

public:
    Mapa(int l, int c);

    void definirDeserto(int linha, int coluna, shared_ptr<Deserto> Deserto); // Define uma Deserto
    shared_ptr<Deserto> obterDeserto(int linha, int coluna) const; // Obtém uma Deserto
    void mostrar(Buffer& buffer); // Atualiza o buffer com a representação do mapa
};

#endif // MAPA_H

