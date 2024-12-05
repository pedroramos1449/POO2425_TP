

#include "Classes/Simulador/Simulador.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    Simulador simulador;

    string comando;
    while (true) {
        cout << "Comando: ";
        getline(cin, comando);

        if (comando == "sair")
            break;

        simulador.processarComando(comando);
    }

    return 0;
}
