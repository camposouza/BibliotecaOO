#include "Periodico.hpp"

// ---------- Construtores ----------
Periodico::Periodico(int cod, std::string t, std::string ed, int ano, int numEd, std::string mes) 
                    : Publicacao(cod, t, ed, ano) {

    this->numEdicao = numEd;
    this->mes = mes;
}


// ---------- Getters e Setters ----------
int Periodico::getNumEdicao() const { return this->numEdicao; }
std::string Periodico::getMes() const {return this->mes; }