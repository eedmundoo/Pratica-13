#include <iostream>
#include <string>
using namespace std;

// Definição da estrutura Empregado
struct Empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};

// Função para reajustar o salário em 10%
void Reajusta_dez_porcento(Empregado empregados[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        empregados[i].salario *= 1.10; // Aumenta o salário em 10%
    }
}

int main() {
    const int MAX_EMPREGADOS = 50;
    Empregado empregados[MAX_EMPREGADOS];
    int quantidadeEmpregados;

    // Solicita ao usuário a quantidade de empregados
    cout << "Digite a quantidade de empregados (até 50): ";
    cin >> quantidadeEmpregados;

    // Preenche os dados dos empregados
    for (int i = 0; i < quantidadeEmpregados; i++) {
        cout << "Empregado #" << i + 1 << endl;
        cout << "Nome: ";
        cin >> empregados[i].nome;
        cout << "Sobrenome: ";
        cin >> empregados[i].sobrenome;
        cout << "Ano de Nascimento: ";
        cin >> empregados[i].anoNascimento;
        cout << "RG: ";
        cin >> empregados[i].RG;
        cout << "Ano de Admissão: ";
        cin >> empregados[i].anoAdmissao;
        cout << "Salário: ";
        cin >> empregados[i].salario;
    }

    // Chama a função para reajustar o salário
    Reajusta_dez_porcento(empregados, quantidadeEmpregados);

    // Exibe os dados dos empregados após o reajuste
    cout << "\nDados dos empregados após o reajuste de 10%:\n";
    for (int i = 0; i < quantidadeEmpregados; i++) {
        cout << "Empregado #" << i + 1 << endl;
        cout << "Nome: " << empregados[i].nome << " " << empregados[i].sobrenome << endl;
        cout << "Ano de Nascimento: " << empregados[i].anoNascimento << endl;
        cout << "RG: " << empregados[i].RG << endl;
        cout << "Ano de Admissão: " << empregados[i].anoAdmissao << endl;
        cout << "Salário após reajuste: R$" << empregados[i].salario << endl;
    }

    return 0;
}
