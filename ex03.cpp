#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Definir uma estrutura para representar um produto
struct Produto {
    string codigo;
    string nome;
    double preco;
};

const int MAX_PRODUTOS = 300;
Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

// Função para inserir um novo produto
void inserirProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        cout << "Limite máximo de produtos atingido." << endl;
        return;
    }

    Produto novoProduto;
    cout << "Digite o código do produto (13 caracteres numéricos): ";
    cin >> novoProduto.codigo;
    cout << "Digite o nome do produto (até 20 caracteres): ";
    cin.ignore();
    getline(cin, novoProduto.nome);
    cout << "Digite o preço do produto (duas casas decimais): ";
    cin >> novoProduto.preco;

    // Verificar se o código ou o nome já existe
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == novoProduto.codigo || produtos[i].nome == novoProduto.nome) {
            cout << "Produto com o mesmo código ou nome já existe." << endl;
            return;
        }
    }

    produtos[totalProdutos] = novoProduto;
    totalProdutos++;
    cout << "Produto cadastrado com sucesso." << endl;
}

// Função para excluir um produto
void excluirProduto() {
    string codigoExcluir;
    cout << "Digite o código do produto a ser excluído: ";
    cin >> codigoExcluir;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigoExcluir) {
            for (int j = i; j < totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            totalProdutos--;
            cout << "Produto excluído com sucesso." << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

// Função para listar todos os produtos
void listarProdutos() {
    if (totalProdutos == 0) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }

    cout << "Lista de produtos cadastrados:" << endl;
    for (int i = 0; i < totalProdutos; i++) {
        cout << "Código: " << produtos[i].codigo << " | Nome: " << produtos[i].nome << " | Preço: R$" << fixed << setprecision(2) << produtos[i].preco << endl;
    }
}

// Função para consultar o preço de um produto por código
void consultarPreco() {
    string codigoConsultar;
    cout << "Digite o código do produto para consultar o preço: ";
    cin >> codigoConsultar;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigoConsultar) {
            cout << "Preço do produto " << produtos[i].nome << ": R$" << fixed << setprecision(2) << produtos[i].preco << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

int main() {
    int opcao;

    do {
        cout << "MENU:" << endl;
        cout << "1. Inserir um novo produto" << endl;
        cout << "2. Excluir um produto cadastrado" << endl;
        cout << "3. Listar
