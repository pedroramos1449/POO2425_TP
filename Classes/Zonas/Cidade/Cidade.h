//
// Created by mauro on 11/26/2024.
//

#ifndef CIDADE_H
#define CIDADE_H

#include "../Zona.h"

class Cidade : public Zona {
    int capacidade;
public:
    Cidade() : capacidade(20) {} // Maior capacidade devido à infraestrutura

    std::string getTipo() const override {
        return "Cidade";
    }

    int getCapacidade() const override {
        return capacidade;
    }

    void setCapacidade(int novaCapacidade) override {
        capacidade = novaCapacidade;
    }

    void atualizar() override {
        // Atualizações específicas para cidades (exemplo: mudanças populacionais)
    }
};

#endif // CIDADE_H
