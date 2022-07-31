#include "ItemEmprestimo.hpp"

// --------- Construtores ----------
ItemEmprestimo::ItemEmprestimo(Livro *l) {
    this->livro = l;
    this->dataDevolucao.tm_mday = 0;
    this->dataDevolucao.tm_mon = 0;
    this->dataDevolucao.tm_year = 0;
}


// --------- Getters e Setters ----------
Livro* ItemEmprestimo::getLivro() const { return this->livro; }

Date ItemEmprestimo::getDataDevolucao() const { return this->dataDevolucao; }
void ItemEmprestimo::setDataDevolucao(Date &d) { this->dataDevolucao = d; }