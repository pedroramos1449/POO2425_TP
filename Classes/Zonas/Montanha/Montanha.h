//
// Created by mauro on 11/26/2024.
//

#ifndef MONTANHA_H
#define MONTANHA_H
#include "../Deserto/Deserto.h"


class Montanha : public Deserto {
public:
    char getTipo() const override { return 'M'; }
};

#endif // MONTANHA_H
