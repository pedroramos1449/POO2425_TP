//
// Created by mauro on 11/26/2024.
//

#ifndef MAPA_H
#define MAPA_H

#include "../Zonas/Deserto.h"
#include "../Zonas/Montanha.h"
#include "../Zonas/Cidade.h"
#include "../Zonas/Zona.h"
#include "../Buffer/Buffer.h"

#include <vector>
#include <memory>

using namespace std;

class Mapa {
    int linhas;
    int colunas;
    vector<vector<shared_ptr<Zona>>> grelha; // Grelha do mapa

public:
    Mapa(int l, int c);

    void definirZona(int linha, int coluna, shared_ptr<Zona> zona); // Define uma zona
    shared_ptr<Zona> obterZona(int linha, int coluna) const; // Obtém uma zona
    void mostrar(Buffer& buffer); // Atualiza o buffer com a representação do mapa
};

#endif // MAPA_H
