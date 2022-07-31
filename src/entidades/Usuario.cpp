#include "Usuario.hpp"

// ---------- Construtores ----------
Usuario::Usuario(std::string nome, std::string cpf, std::string endereco, std::string fone) {
    this->nome = nome;
    this->cpf = cpf;
    this->endereco = endereco;
    this->fone = fone;
    std::time_t t = std::time(0);
    this->dataPenalizacao = *std::localtime(&t);
    this->dataPenalizacao.tm_year += 1900;
    this->dataPenalizacao.tm_mon += 1;
}

Usuario::Usuario() {}


// ---------- Getters e Setters ----------
std::string Usuario::getNome() const { return this->nome; }
std::string Usuario::getCPF() const { return this->cpf; }
std::string Usuario::getEndereco() const { return this->endereco; }
std::string Usuario::getFone() const { return this->fone; }