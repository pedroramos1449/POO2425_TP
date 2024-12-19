//
// Created by mauro on 12/16/2024.
//

#ifndef COMERCIO_H
#define COMERCIO_H

#include "../Caravana.h"

class CaravanaComercio : public Caravana {
public:
    CaravanaComercio(int id, int linha, int coluna);
    char getTipo() const override { return '$'; }
    void comportamentoAutonomo() override;
    bool afetarPorTempestade() override;
};

#endif // COMERCIO_H

