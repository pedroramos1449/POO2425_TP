cmake_minimum_required(VERSION 3.30)
project(Projeto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projeto main.cpp
        Classes/Buffer/Buffer.cpp
        Classes/Buffer/Buffer.h
        Classes/Mapa/Mapa.cpp
        Classes/Mapa/Mapa.h
        Classes/Caravanas/Caravana.cpp
        Classes/Caravanas/Caravana.h
        Classes/Simulador/Simulador.cpp
        Classes/Simulador/Simulador.h
        Classes/Zonas/Deserto.cpp
        Classes/Zonas/Deserto.h
        Classes/Zonas/Montanha/Montanha.cpp
        Classes/Zonas/Montanha/Montanha.h
        Classes/Zonas/Cidade/Cidade.cpp
        Classes/Zonas/Cidade/Cidade.h
        Classes/Itens/ArcaTesouro/Arca.cpp
        Classes/Itens/ArcaTesouro/Arca.h
        Classes/Itens/CaixaPandora/Caixa.cpp
        Classes/Itens/CaixaPandora/Caixa.h
        Classes/Itens/Jaula/Jaula.cpp
        Classes/Itens/Jaula/Jaula.h
        Classes/Itens/Mina/Mina.cpp
        Classes/Itens/Mina/Mina.h
        Classes/Itens/Surpresa/Surpresa.cpp
        Classes/Itens/Surpresa/Surpresa.h
        Classes/Itens/Item.cpp
        Classes/Itens/Item.h
        Classes/Caravanas/Militar/CaravanaMilitar.cpp
        Classes/Caravanas/Militar/CaravanaMilitar.h
        Classes/Caravanas/Secreta/CaravanaSecreta.cpp
        Classes/Caravanas/Secreta/CaravanaSecreta.h
        Classes/Caravanas/Barbara/CaravanaBarbara.cpp
        Classes/Caravanas/Barbara/CaravanaBarbara.h
        Classes/Caravanas/Comercio/CaravanaComercio.cpp
        Classes/Caravanas/Comercio/CaravanaComercio.h
        Classes/Mapa/CelulaMapa.cpp
        Classes/Mapa/CelulaMapa.h
        Classes/Zonas/Zona.cpp
        Classes/Zonas/Zona.h)
