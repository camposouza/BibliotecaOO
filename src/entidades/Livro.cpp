#include "Livro.hpp"

// ---------- Construtores ----------
Livro::Livro(int cod, std::string t, std::string ed, int ano, std::string auts, int qtd) 
            : Publicacao(cod, t, ed, ano) {

    this->autores = auts;
    this->qtdExemplares = qtd;

}

Livro::Livro(int cod, std::string t, std::string ed, int ano, std::string auts) 
            : Publicacao(cod, t, ed, ano) {
    
    this->autores = auts;
    this->qtdExemplares = 0;

}

Livro::Livro() : Publicacao() {}


// ---------- Getters e Setters ----------
std::string Livro::getAutor() const { return this->autores; }
int Livro::getQtdExemplares() const { return this->qtdExemplares; }


// ---------- Metodos ----------
void Livro::incrementaExemplares() { this->qtdExemplares++; }

void Livro::decrementaExemplares() { 
    if (this->qtdExemplares > 0) {
        this->qtdExemplares--;
    } else {
        throw "Nao ha exemplares desse livro disponiveis para emprestimo";
    }
}