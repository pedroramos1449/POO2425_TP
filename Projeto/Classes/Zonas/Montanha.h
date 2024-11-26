//
// Created by mauro on 11/26/2024.
//

#ifndef MONTANHA_H
#define MONTANHA_H

#include "Zona.h"

class Montanha : public Zona {
public:
    char getTipo() const override { return '+'; }
};

#endif // MONTANHA_H
