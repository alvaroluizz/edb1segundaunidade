#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Estrutura para representar um Paciente
struct Paciente {
    string nome;
    int idade;

    Paciente(string n, int i) : nome(n), idade(i) {}
};

int main() {
    // Filas para pacientes normais e prioritários
    queue<Paciente> filaNormal;
    queue<Paciente> filaPrioritaria;

    while (true) {
        cout << "Digite o comando (ADICIONAR, ATENDER, VERIFICAR, SAIR): ";
        string comando;
        cin >> comando;
        cin.ignore();  // Limpa o buffer de entrada

        if (comando == "ADICIONAR") {
            string nome;
            int idade;
            cout << "Digite o nome do paciente: ";
            getline(cin, nome);  // Usa getline para permitir nomes com espaços
            cout << "Digite a idade do paciente: ";
            cin >> idade;
            cin.ignore();  // Limpa o buffer de entrada

            Paciente paciente(nome, idade);

            if (idade >= 60) {
                filaPrioritaria.push(paciente);
                cout << "Paciente " << nome << " (Prioritário) adicionado à fila." << endl;
            } else {
                filaNormal.push(paciente);
                cout << "Paciente " << nome << " (Normal) adicionado à fila." << endl;
            }
        } else if (comando == "ATENDER") {
            if (!filaPrioritaria.empty()) {
                Paciente paciente = filaPrioritaria.front();
                filaPrioritaria.pop();
                cout << "Paciente " << paciente.nome << " (Prioritário) foi atendido." << endl;
            } else if (!filaNormal.empty()) {
                Paciente paciente = filaNormal.front();
                filaNormal.pop();
                cout << "Paciente " << paciente.nome << " (Normal) foi atendido." << endl;
            } else {
                cout << "Nenhum paciente na fila para ser atendido." << endl;
            }
        } else if (comando == "VERIFICAR") {
            cout << "Fila Prioritária: ";
            if (filaPrioritaria.empty()) {
                cout << "vazia" << endl;
            } else {
                queue<Paciente> temp = filaPrioritaria;
                while (!temp.empty()) {
                    cout << temp.front().nome << " ";
                    temp.pop();
                }
                cout << endl;
            }

            cout << "Fila Normal: ";
            if (filaNormal.empty()) {
                cout << "vazia" << endl;
            } else {
                queue<Paciente> temp = filaNormal;
                while (!temp.empty()) {
                    cout << temp.front().nome << " ";
                    temp.pop();
                }
                cout << endl;
            }
        } else if (comando == "SAIR") {
            break;
        } else {
            cout << "Comando inválido!" << endl;
        }
    }

    return 0;
}
