//
// Created by mauro on 11/26/2024.
//

#ifndef ZONA_H
#define ZONA_H

class Zona {
public:
    virtual char getTipo() const = 0; // Retorna o tipo da zona ('D', 'C', '+')
    virtual ~Zona() = default;
};

#endif // ZONA_H
