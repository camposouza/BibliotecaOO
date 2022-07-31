#include "Emprestimo.hpp"

int Emprestimo::proximoNumero = 1;

// ---------- Construtores ----------
Emprestimo::Emprestimo(Date dataPrev, Usuario *u) {
    this->num = proximoNumero;
    std::time_t t = std::time(0);
    std::tm *hoje = std::localtime(&t);
    this->dataEmprestimo = *hoje;
    this->dataPrevDevolucao = dataPrev;
    this->usuario = u;
    this->proximoNumero++;
}


// ---------- Getters e Setters ----------
int Emprestimo::getNum() const { return this->num; }
Date Emprestimo::getDataEmprestimo() const { return this->dataEmprestimo; }
Date Emprestimo::getDataPrevDevolucao() const { return this->dataPrevDevolucao; }
Usuario* Emprestimo::getUsuario() const { return this->usuario; }
std::vector<ItemEmprestimo*> Emprestimo::getItens() const { return this->itens; }
int Emprestimo::getNumItens() const { return this->itens.size(); }


// ---------- Metodos ----------
void Emprestimo::emprestaLivro(Livro *l) {
    l->decrementaExemplares();
    ItemEmprestimo* i = new ItemEmprestimo(l);
    this->itens.push_back(i);
}

void Emprestimo::adicionaItem(ItemEmprestimo *i) {
    this->emprestaLivro(i->getLivro());
}


ItemEmprestimo* Emprestimo::excluiItem(ItemEmprestimo *i) {  
    for (auto it = this->itens.begin(); it != this->itens.end(); it++) {
        if ((*it)->getLivro()->getCod() == i->getLivro()->getCod()) {
            this->itens.erase(it);
            i->getLivro()->incrementaExemplares();
            return (*it);
        }
    }
    throw "Esse Livro nao esta nesse Emprestimo";
    return nullptr;
}

void Emprestimo::devolveLivro(ItemEmprestimo *i) {
    ItemEmprestimo *item = nullptr;
    for (auto it = this->itens.begin(); it != this->itens.end(); it++) {
        if ((*it)->getLivro()->getCod() == i->getLivro()->getCod()) {
            i->getLivro()->incrementaExemplares();
            item = *it;
            std::time_t t = std::time(0);
            std::tm *hoje = std::localtime(&t);
            hoje->tm_mon += 1;
            hoje->tm_year += 1900;
            item->setDataDevolucao(*hoje);
        }
    }
    if (item == nullptr) {  throw "Esse Livro nao esta nesse Emprestimo"; }
}

void Emprestimo::devolveTodosLivros() {
    for (auto it = itens.begin(); it != itens.end(); it++) {
        this->devolveLivro(*it);
    }
}


bool Emprestimo::findLivro(Livro &l) {
    std::vector<ItemEmprestimo*> lista = this->getItens();

    for (auto it = lista.begin(); it != lista.end(); it++) {
        if ((*it)->getLivro()->getCod() == l.getCod()) {
            return true;
        }
    }
    return false;
}

bool Emprestimo::checaLivrosDevolvidos() {
    std::vector<ItemEmprestimo*> lista = this->getItens();

    bool todos_devolvidos = true;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        if (((*it)->getDataDevolucao().tm_mday == 0)) {
            todos_devolvidos = false;
        }
    }
    return todos_devolvidos;
}