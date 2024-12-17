//
// Created by mauro on 11/26/2024.
//

#include "Mapa.h"

Mapa::Mapa(int l, int c, int numCidades, int numMontanhas)
    : linhas(l), colunas(c), grelha(l, vector<shared_ptr<CelulaMapa>>(c))
{
    // Inicializar a semente para geração de números aleatórios
    srand(static_cast<unsigned>(time(nullptr)));

    // Gera as zonas no mapa
    gerarZonas(numCidades, numMontanhas);
}


void Mapa::gerarZonas(int numCidades, int numMontanhas) {
    // Inicializar aleatoriedade
    srand(static_cast<unsigned>(time(nullptr)));

    // Inicializar todas as células como deserto
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            grelha[i][j] = make_shared<CelulaMapa>(make_shared<Deserto>());
        }
    }

    // Gerar cidades em posições aleatórias
    for (int n = 0; n < numCidades; ++n) {
        int x, y;
        do {
            x = rand() % linhas;
            y = rand() % colunas;
        } while (!posicaoValidaParaCidade(x, y)); // Verifica se a posição é válida
        grelha[x][y]->setZona(make_shared<Cidade>());
    }

    // Gerar montanhas em posições aleatórias
    for (int n = 0; n < numMontanhas; ++n) {
        int x, y;
        do {
            x = rand() % linhas;
            y = rand() % colunas;
        } while (!posicaoValida(x, y, "Montanha")); // Evita colocar montanhas em cima de cidades
        grelha[x][y]->setZona(make_shared<Montanha>());
    }
}


bool Mapa::posicaoValidaParaCidade(int x, int y) const {
    if (grelha[x][y]->getZona()->getTipo() != "Deserto")
        return false; // Não sobrepõe zonas existentes

    // Verificar se há pelo menos um espaço livre (não montanha) em redor
    const vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto& [dx, dy] : direcoes) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < linhas && ny >= 0 && ny < colunas) {
            if (grelha[nx][ny]->getZona()->getTipo() != "Montanha")
                return true; // Pelo menos um vizinho não é montanha
        }
    }
    return false; // Rodeado de montanhas ou fora dos limites
}


bool Mapa::posicaoValida(int x, int y, const std::string& tipoZona) const {
    if (tipoZona == "Montanha") {
        return grelha[x][y]->getZona()->getTipo() == "Deserto";
    }
    return false;
}



void Mapa::definirZona(int linha, int coluna, shared_ptr<Zona> zona) {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        grelha[linha][coluna]->setZona(zona);
    }
}

void Mapa::adicionarCaravana(int linha, int coluna, shared_ptr<Caravana> caravana) {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        grelha[linha][coluna]->adicionarCaravana(caravana);
    }
}

vector<shared_ptr<Caravana>> Mapa::obterCaravanas(int linha, int coluna) const {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        return grelha[linha][coluna]->getCaravanas();
    }
    return {};
}

void Mapa::adicionarItem(int linha, int coluna, shared_ptr<Item> item) {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        grelha[linha][coluna]->adicionarItem(item);
    }
}

shared_ptr<Zona> Mapa::obterZona(int linha, int coluna) const {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        return grelha[linha][coluna]->getZona();
    }
    return nullptr; // Se a posição for inválida
}

void Mapa::mostrar(Buffer& buffer) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            shared_ptr<Zona> zona = obterZona(i, j);  // Obtém a zona na posição (i, j)
            if (zona) {
                buffer.moverCursor(i, j);
                buffer.escrever(zona->getTipo());  // Escreve a representação da zona
            }
        }
    }
}

int Mapa::getLinhas() const {
    return linhas;
}

void Mapa::setLinhas(int linhas) {
    Mapa::linhas = linhas;
}

int Mapa::getColunas() const {
    return colunas;
}

void Mapa::setColunas(int colunas) {
    Mapa::colunas = colunas;
}


