//
// Created by mauro on 11/26/2024.
//

#ifndef MAPA_H
#define MAPA_H

#include "../Zonas/Deserto.h"
#include "../Zonas/Montanha/Montanha.h"
#include "../Zonas/Cidade/Cidade.h"
#include "../Buffer/Buffer.h"
#include "../Caravanas/Caravana.h"

#include <vector>
#include <memory>

using namespace std;

class Mapa {
    int linhas;
    int colunas;
    vector<vector<shared_ptr<Zona>>> grelha; // Grelha do mapa

public:
    Mapa(int l, int c);

    void definirZona(int linha, int coluna, shared_ptr<Zona> zona);
    shared_ptr<Zona> obterZona(int linha, int coluna) const; // Obtém uma Deserto
    int getLinhas() const;
    void setLinhas(int linhas);
    int getColunas() const;
    void setColunas(int colunas);
    void mostrar(Buffer& buffer); // Atualiza o buffer com a representação do mapa
    void tempestadeAreia(int l, int c, int r);

    void removerElemento(int linha, int coluna);
};

#endif // MAPA_H

