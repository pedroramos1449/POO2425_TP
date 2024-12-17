//
// Created by mauro on 12/17/2024.
//

#ifndef CELULAMAPA_H
#define CELULAMAPA_H

#include "../Zonas/Zona.h"
#include "../Caravanas/Caravana.h"
#include "../Itens/Item.h"

#include <vector>
#include <memory>


using namespace std;

class CelulaMapa {
    shared_ptr<Zona> zona;                   // A zona principal (Deserto, Montanha, etc.)
    vector<shared_ptr<Caravana>> caravanas;     // Lista de caravanas na célula
    vector<shared_ptr<Item>> itens;            // Lista de itens na célula

public:
    // Construtor
    explicit CelulaMapa(shared_ptr<Zona> zonaInicial) : zona(zonaInicial) {}

    // Métodos para a zona
    shared_ptr<Zona> getZona() const { return zona; }
    void setZona(shared_ptr<Zona> novaZona) { zona = novaZona; }

    // Métodos para caravanas
    void adicionarCaravana(shared_ptr<Caravana> caravana) { caravanas.push_back(caravana); }
    void removerCaravana(shared_ptr<Caravana> caravana);
    const vector<shared_ptr<Caravana>>& getCaravanas() const { return caravanas; }

    // Métodos para itens
    void adicionarItem(shared_ptr<Item> item) { itens.push_back(item); }
    void removerItem(shared_ptr<Item> item);
    const vector<shared_ptr<Item>>& getItens() const { return itens; }
};


#endif //CELULAMAPA_H
