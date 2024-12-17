//
// Created by mauro on 12/17/2024.
//

#ifndef ZONA_H
#define ZONA_H

#include <string>

class Zona {
public:
    virtual ~Zona() = default;

    // Métodos virtuais puros para comportamento comum
    virtual std::string getTipo() const = 0;  // Retorna o tipo de zona (ex: "Deserto", "Montanha")
    virtual int getCapacidade() const = 0;    // Exemplo: capacidade de abrigar caravanas ou itens
    virtual void setCapacidade(int capacidade) = 0;

    // Outros métodos abstratos que podem ser úteis
    virtual void atualizar() = 0; // Atualizações específicas para a zona
};

#endif // ZONA_H
