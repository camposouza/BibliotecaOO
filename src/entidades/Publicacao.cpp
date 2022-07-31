#include "Publicacao.hpp"

// ---------- Construtores ----------
Publicacao::Publicacao(int cod, std::string t, std::string ed, int ano) {
    this->codPublicacao = cod;
    this->titulo = t;
    this->editora = ed;
    this->ano = ano;
}

Publicacao::Publicacao() {}


// ---------- Getters e Setters ----------

int Publicacao::getCod() const { return this->codPublicacao; }
std::string Publicacao::getTitulo() const { return this->titulo; }
std::string Publicacao::getEditora() const { return this->editora; }
int Publicacao::getAno() const { return this->ano; }