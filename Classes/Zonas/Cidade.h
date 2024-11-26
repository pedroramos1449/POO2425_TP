//
// Created by mauro on 11/26/2024.
//

#ifndef CIDADE_H
#define CIDADE_H

#include "Zona.h"

class Cidade : public Zona {
    char nome; // Nome da cidade (uma letra)
public:
    explicit Cidade(char n) : nome(n) {}
    char getTipo() const override { return nome; }
};

#endif // CIDADE_H
