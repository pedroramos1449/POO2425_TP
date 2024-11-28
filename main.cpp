
#include "Classes/Buffer/Buffer.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// Função para inicializar o estado no buffer
void inicializarEstado(Buffer& buffer, const vector<string>& mapa, int turno, int moedas) {
    buffer.limpar();

    // Exibe informações do turno e moedas
    buffer.moverCursor(0, 0);
    buffer.escrever("Turno: ");
    buffer.escrever(to_string(turno));
    buffer.moverCursor(1, 0);
    buffer.escrever("Moedas: ");
    buffer.escrever(to_string(moedas));

    // Exibe o mapa no buffer
    buffer.moverCursor(3, 0); // Pula linhas para separar informações do mapa
    for (int i = 0; i < mapa.size(); ++i) {
        buffer.moverCursor(3 + i, 0);
        buffer.escrever(mapa[i]);
    }

    buffer.mostrar();
}

// Função para avançar n instantes
//NOTA: Incorreta, nao funciona como no enunciado, apenas para teste
void executarInstantes(Buffer& buffer, vector<string>& mapa, int& turno, int moedas, int n) {
    for (int i = 0; i < n; ++i) {
        turno++;

        // Atualiza o estado do mapa (exemplo: movimento de caravana)
        if (mapa[5][5] == '1') {
            mapa[5][5] = '.';
            mapa[6][5] = '1'; // Caravana move-se para baixo
        } else if (mapa[6][5] == '1') {
            mapa[6][5] = '.';
            mapa[7][5] = '1'; // Continua movendo
        }

        // Atualiza o buffer para cada instante
        inicializarEstado(buffer, mapa, turno, moedas);
    }
}

int main() {
    // Dimensões do mapa
    const int linhas = 10;
    const int colunas = 20;

    // Mapa estático para teste
    vector<string> mapa = {
            "....................",
            ".+..................",
            "....................",
            "...a................",
            "....................",
            ".....1..............",
            "....................",
            "....................",
            "....................",
            "...................."
    };

    // Variáveis estáticas para teste
    int turno = 0;
    int moedas = 100;


    //TODO:O Buffer so será no futuro inicializado na Fase1, falta implementar Fase1

    // Criação do buffer com o tamanho do mapa
    Buffer buffer(linhas + 3, colunas); // Linhas extras para exibir informações

    // Inicialização do estado inicial
    inicializarEstado(buffer, mapa, turno, moedas);

    // Loop principal
    string comando;
    while (true) {
        cout << "Comando: ";
        getline(cin, comando);

        if (comando == "sair")
            break;

        // Processa o comando "prox <n>"
        if (comando.find("prox") == 0) {
            stringstream ss(comando);
            string cmd;
            int n;

            ss >> cmd >> n; // Lê o comando e o número de instantes
            if (n > 0) {
                executarInstantes(buffer, mapa, turno, moedas, n);
            } else {
                cout << "Número de instantes inválido!" << endl;
            }
        } else {
            cout << "Comando desconhecido!" << endl;
        }
    }

    return 0;
}
