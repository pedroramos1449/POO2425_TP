//
// Created by mauro on 11/26/2024.
//

#ifndef DESERTO_H
#define DESERTO_H


class Deserto {
public:
    virtual char getTipo() const = 0; // Retorna o tipo da zona ('C', 'M')
    virtual ~Deserto() = default;
};

#endif // DESERTO_H
