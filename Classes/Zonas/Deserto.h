//
// Created by mauro on 11/26/2024.
//

#ifndef DESERTO_H
#define DESERTO_H

class Deserto  {
public:
    virtual char getTipo() const { return '.'; }
    virtual ~Deserto() = default; // Destrutor virtual
};

#endif // DESERTO_H
