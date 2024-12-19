//
// Created by mauro on 12/16/2024.
//

#ifndef MILITAR_H
#define MILITAR_H

#include "../Caravana.h"

class CaravanaMilitar : public Caravana {
public:
    CaravanaMilitar(int id, int linha, int coluna);
    char getTipo() const override { return 'M'; }
    void comportamentoAutonomo() override;
    bool afetarPorTempestade() override;
};

#endif // MILITAR_H

