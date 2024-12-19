//
// Created by mauro on 12/16/2024.
//

#ifndef SECRETA_H
#define SECRETA_H


#include "../Caravana.h"

class CaravanaSecreta : public Caravana {
public:
    CaravanaSecreta(int id, int linha, int coluna);
    char getTipo() const override { return '?'; }
    void comportamentoAutonomo() override;
    bool afetarPorTempestade() override;
};



#endif //SECRETA_H
