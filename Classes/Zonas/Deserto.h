//
// Created by mauro on 11/26/2024.
//

#ifndef DESERTO_H
#define DESERTO_H

#include "Zona.h"

class Deserto : public Zona {
    int capacidade;  // Exemplo: número de caravanas ou itens suportados
public:
    Deserto() : capacidade(10) {} // Capacidade inicial para exemplificação

    std::string getTipo() const override {
        return "Deserto";
    }

    int getCapacidade() const override {
        return capacidade;
    }

    void setCapacidade(int novaCapacidade) override {
        capacidade = novaCapacidade;
    }

    void atualizar() override {
        // Exemplo de atualização específica do deserto, como mudar condições climáticas
    }
};

#endif // DESERTO_H
