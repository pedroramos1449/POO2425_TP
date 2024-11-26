//
// Created by mauro on 11/26/2024.
//

#ifndef DESERTO_H
#define DESERTO_H

#include "Zona.h"

class Deserto : public Zona {
public:
    char getTipo() const override { return 'D'; }
};

#endif // DESERTO_H
