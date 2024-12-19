//
// Created by mauro on 12/16/2024.
//

#ifndef BARBARA_H
#define BARBARA_H


#include "../Caravana.h"

class CaravanaBarbara : public Caravana {
public:
    CaravanaBarbara(int id, int linha, int coluna);
    char getTipo() const override { return '!'; }
    void comportamentoAutonomo() override;
    bool afetarPorTempestade() override;
};



#endif //BARBARA_H
