//
// Created by mauro on 11/26/2024.
//

#ifndef MAPA_H
#define MAPA_H

#include "../Zonas/Cidade/Cidade.h"
#include "../Zonas/Montanha/Montanha.h"
#include "../Zonas/Deserto.h"
#include "../Buffer/Buffer.h"
#include "../Caravanas/Caravana.h"
#include "CelulaMapa.h"

#include <vector>
#include <memory>

#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Mapa {

public:
    Mapa(int l, int c, int numCidades, int numMontanhas); // Construtor atualizado
    void mostrar() const;

    void gerarZonas(int numCidades, int numMontanhas); // Método para gerar zonas
    bool posicaoValidaParaCidade(int x, int y) const;

    bool posicaoValida(int x, int y, const std::string &tipoZona) const;

    // Métodos para manipular zonas
    void definirZona(int linha, int coluna, shared_ptr<Zona> zona);
    shared_ptr<Zona> obterZona(int linha, int coluna) const;

    // Métodos para caravanas
    void adicionarCaravana(int linha, int coluna, shared_ptr<Caravana> caravana);
    void removerCaravana(int linha, int coluna, shared_ptr<Caravana> caravana);
    vector<shared_ptr<Caravana>> obterCaravanas(int linha, int coluna) const;

    // Métodos para itens
    void adicionarItem(int linha, int coluna, shared_ptr<Item> item);
    void removerItem(int linha, int coluna, shared_ptr<Item> item);
    vector<shared_ptr<Item>> obterItens(int linha, int coluna) const;

    void mostrar(Buffer& buffer); // Atualiza o buffer com a representação do mapa

    int getLinhas() const;
    void setLinhas(int linhas);
    int getColunas() const;
    void setColunas(int colunas);
private:
    int linhas;
    int colunas;
    vector<vector<shared_ptr<CelulaMapa>>> grelha; // Grelha do mapa
};

#endif // MAPA_H

