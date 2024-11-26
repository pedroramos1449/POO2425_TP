//
// Created by mauro on 11/26/2024.
//

#ifndef CARAVANA_H
#define CARAVANA_H

#include <string>
using namespace std;

class Caravana {
    int id;
    int tripulacao;
    int capacidadeCarga;
    int capacidadeAgua;

public:
    explicit Caravana(int id);

    virtual void mover(const string& direcao); // Mover-se numa direção
    virtual void comportamentoAutonomo(); // Comportamento automático

    int getID() const;
    virtual ~Caravana() = default;
};

class CaravanaComercial : public Caravana {
public:
    explicit CaravanaComercial(int id);
    void comportamentoAutonomo() override; // Específico para caravanas comerciais
};

class CaravanaMilitar : public Caravana {
public:
    explicit CaravanaMilitar(int id);
    void comportamentoAutonomo() override; // Específico para caravanas militares
};

#endif // CARAVANA_H
