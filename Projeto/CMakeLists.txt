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
        Classes/Zonas/Zona.cpp
        Classes/Zonas/Zona.h
        Classes/Zonas/Deserto.cpp
        Classes/Zonas/Deserto.h
        Classes/Zonas/Montanha.cpp
        Classes/Zonas/Montanha.h
        Classes/Zonas/Cidade.cpp
        Classes/Zonas/Cidade.h)
