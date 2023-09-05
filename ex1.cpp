#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Passagem {
public:
    Passagem(int numeroAssento, const std::string& dataHora, const std::string& cpf, const std::string& nome, int idade)
        : numeroAssento(numeroAssento), dataHora(dataHora), cpf(cpf), nome(nome), idade(idade) {}

    int getNumeroAssento() const { return numeroAssento; }
    const std::string& getDataHora() const { return dataHora; }
    const std::string& getCPF() const { return cpf; }
    const std::string& getNome() const { return nome; }
    int getIdade() const { return idade; }

private:
    int numeroAssento;
    std::string dataHora;
    std::string cpf;
    std::string nome;
    int idade;
};

class Viagem {
public:
    Viagem(const std::string& horario)
        : horario(horario), assentos(40) {}

    const std::string& getHorario() const { return horario; }

    bool venderPassagem(int numeroAssento, const std::string& dataHora, const std::string& cpf, const std::string& nome, int idade) {
        if (numeroAssento < 1 || numeroAssento > 40 || assentos[numeroAssento - 1] != nullptr) {
            return false; // Assento inválido ou já vendido
        }
        assentos[numeroAssento - 1] = std::make_shared<Passagem>(numeroAssento, dataHora, cpf, nome, idade);
        return true;
    }

    double calcularArrecadacao() const {
        double total = 0.0;
        for (const auto& passagem : assentos) {
            if (passagem != nullptr) {
                total += 80.0;
            }
        }
        return total;
    }

    double calcularMediaIdade() const {
        int totalIdade = 0;
        int totalPassageiros = 0;
        for (const auto& passagem : assentos) {
            if (passagem != nullptr) {
                totalIdade += passagem->getIdade();
                totalPassageiros++;
            }
        }
        if (totalPassageiros > 0) {
            return static_cast<double>(totalIdade) / totalPassageiros;
        } else {
            return 0.0; // Evitar divisão por zero
        }
    }

private:
    std::string horario;
    std::vector<std::shared_ptr<Passagem>> assentos;
};

class EmpresaOnibus {
public:
    void adicionarViagem(const std::string& horario) {
        viagens.push_back(Viagem(horario));
    }

    Viagem* buscarViagem(const std::string& horario) {
        for (auto& viagem : viagens) {
            if (viagem.getHorario() == horario) {
                return &viagem;
            }
        }
        return nullptr; // Viagem não encontrada
    }

    double calcularArrecadacaoTotal() const {
        double total = 0.0;
        for (const auto& viagem : viagens) {
            total += viagem.calcularArrecadacao();
        }
        return total;
    }

    double calcularMediaIdadeTotal() const {
        int totalIdade = 0;
        int totalPassageiros = 0;
        for (const auto& viagem : viagens) {
            totalIdade += viagem.calcularMediaIdade();
            totalPassageiros++;
        }
        if (totalPassageiros > 0) {
            return static_cast<double>(totalIdade) / totalPassageiros;
        } else {
            return 0.0; // Evitar divisão por zero
        }
    }

private:
    std::vector<Viagem> viagens;
};

int main() {
    EmpresaOnibus empresa;

    empresa.adicionarViagem("08:00");
    empresa.adicionarViagem("10:00");
    empresa.adicionarViagem("12:00");
    empresa.adicionarViagem("14:00");
    empresa.adicionarViagem("16:00");

    // Exemplo de venda de passagem
    Viagem* viagem = empresa.buscarViagem("08:00");
    if (viagem != nullptr) {
        if (viagem->venderPassagem(1, "2023-09-05 08:30", "12345678901", "João", 30)) {
            std::cout << "Passagem vendida com sucesso!" << std::endl;
        } else {
            std::cout << "Assento inválido ou já vendido." << std::endl;
        }
    } else {
        std::cout << "Viagem não encontrada." << std::endl;
    }

    // Outras operações, como calcular arrecadação total e média de idade total, podem ser realizadas aqui.

    return 0;
}
