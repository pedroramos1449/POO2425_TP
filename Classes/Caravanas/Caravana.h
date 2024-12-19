//
// Created by mauro on 11/26/2024.
//

#ifndef CARAVANA_H
#define CARAVANA_H

#include <string>
#include "../Zonas/Deserto.h"

using namespace std;

class Caravana : public Zona {
protected:
    int id;
    char tipo; // Tipo ('C' = Comercial, 'M' = Militar, 'S' = Secreta, 'B' = Bárbara)
    int linha, coluna; // Posição no mapa
    int tripulantes;
    int capacidadeCarga;
    int cargaAtual;
    int capacidadeAgua;
    int aguaAtual;

public:
    Caravana(int id, char tipo, int linha, int coluna);
    virtual void mover(const std::string& direcao);
    virtual void comportamentoAutonomo();
    virtual bool afetarPorTempestade() = 0;
    virtual char getTipo() const = 0;
    virtual ~Caravana() = default;
    int getID() const { return id; }
    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }
    void perderTripulante();
    bool estaSemTripulantes() const { return tripulantes <= 0; }
    void reabastecerAgua() { aguaAtual = capacidadeAgua; }
};

#endif // CARAVANA_H
