cmake_minimum_required(VERSION 3.30)
project(Projeto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projeto main.cpp
        Classes/Buffer/Buffer.cpp
        Classes/Buffer/Buffer.h
        Classes/Mapa/Mapa.cpp
        Classes/Mapa/Mapa.h
        Classes/Caravana/Caravana.cpp
        Classes/Caravana/Caravana.h
        Classes/Simulador/Simulador.cpp
        Classes/Simulador/Simulador.h
        Classes/Zonas/Deserto/Deserto.cpp
        Classes/Zonas/Deserto/Deserto.h
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
        Classes/Caravana/Militar/Militar.cpp
        Classes/Caravana/Militar/Militar.h
        Classes/Caravana/Secreta/Secreta.cpp
        Classes/Caravana/Secreta/Secreta.h
        Classes/Caravana/Barbara/Barbara.cpp
        Classes/Caravana/Barbara/Barbara.h
        Classes/Caravana/Comercio/Comercio.cpp
        Classes/Caravana/Comercio/Comercio.h)
