//
// Created by mauro on 11/26/2024.
//

#ifndef MONTANHA_H
#define MONTANHA_H

#include "../Zona.h"

class Montanha : public Zona {
    int capacidade;
public:
    Montanha() : capacidade(5) {} // Menor capacidade devido a terrenos difíceis

    std::string getTipo() const override {
        return "Montanha";
    }

    int getCapacidade() const override {
        return capacidade;
    }

    void setCapacidade(int novaCapacidade) override {
        capacidade = novaCapacidade;
    }

    void atualizar() override {
        // Atualizações específicas para a montanha (exemplo: avalanches)
    }
};

#endif // MONTANHA_H

