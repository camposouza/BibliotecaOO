#include "Biblioteca.hpp"

// ---------- Construtores ----------
Biblioteca::Biblioteca() {}


// ---------- Getters e Setters ----------
std::vector<Usuario*> Biblioteca::getUsuarios() const { return this->usuarios; }
std::vector<Publicacao*> Biblioteca::getPublicacoes() const { return this->publicacoes; }
std::vector<Emprestimo*> Biblioteca::getEmprestimos() const { return this->emprestimos; }


// ---------- Metodos ----------
void Biblioteca::insereUsuario(Usuario *u) {
    std::vector<Usuario*> lista = this->getUsuarios();

    for (auto it = lista.begin(); it != lista.end(); it++) {
        if ((*it)->getCPF() == u->getCPF()) { throw "Ja existe um usuario com esse CPF"; }
    }
    this->usuarios.push_back(u);
}

void Biblioteca::inserePublicacao(Publicacao *p) {
    std::vector<Publicacao*> lista = this->getPublicacoes();

    for (auto it = lista.begin(); it != lista.end(); it++) {
        if ((*it)->getCod() == p->getCod()) { throw "Ja existe uma publicacao com esse codigo"; }
    }

    Livro *livro = dynamic_cast<Livro*>(p);
    if(livro) {
        this->publicacoes.push_back(livro);
    } else {
        Periodico *periodico = dynamic_cast<Periodico*>(p);
        this->publicacoes.push_back(periodico);
    }
}

void Biblioteca::insereEmprestimo(Emprestimo *e) {
    this->emprestimos.push_back(e);
}

void Biblioteca::insereItemInEmprestimo(Emprestimo *e, ItemEmprestimo *i) {
     for (auto it = this->emprestimos.begin(); it != this->emprestimos.end(); it++) {
        if ((*it)->getNum() == e->getNum()) {
            (*it)->adicionaItem(i);
        }
    }
}

void Biblioteca::excluiUsuario(Usuario *u) {
    for (auto it = this->emprestimos.begin(); it != this->emprestimos.end(); it++) {
        if ((*it)->getUsuario()->getNome() == u->getNome()) {
            throw "Esse usuario tem um debito, nao eh possivel exclui-lo";
        }
    }

    for (auto it = this->usuarios.begin(); it != this->usuarios.end(); it++) {
        if ((*it)->getNome() == u->getNome()) {
            this->usuarios.erase(it);
            delete u;
            break;
        }
    }
}

void Biblioteca::excluiPublicacao(Publicacao *p) {
    std::vector<Publicacao*> lista_p = this->getPublicacoes();
    std::vector<Emprestimo*> lista_e = this->getEmprestimos();

    Livro *livro = dynamic_cast<Livro*>(p);
    if(livro) {
        for (auto it = lista_e.begin(); it != lista_e.end(); it++) {
            if ((*it)->findLivro(*livro));
            throw "Esse livro esta emprestado, nao eh possivel exclui-lo";
        }
        for (auto it = lista_p.begin(); it != lista_p.end(); it++) {
            if ((*it)->getTitulo() == p->getTitulo()) {
                lista_p.erase(it);
                delete livro;
                break;
            }
        }
        this->publicacoes = lista_p;
        
    } else {
        Periodico *periodico = dynamic_cast<Periodico*>(p);
        for (auto it = lista_p.begin(); it != lista_p.end(); it++) {
            if ((*it)->getTitulo() == p->getTitulo()) {
                lista_p.erase(it);
                delete periodico;
                break;
            }
        }
        this->publicacoes = lista_p;
    }
}

void Biblioteca::excluiEmprestimo(Emprestimo *e) {
    std::vector<Emprestimo*> lista = this->getEmprestimos();
    
    for (auto it = lista.begin(); it != lista.end(); it++) {
        if ((*it)->getNum() == e->getNum()) {
            if (!e->checaLivrosDevolvidos()) { 
                throw "Nao eh possivel excluir esse Emprestimo, ha Livros que nao foram devolvidos"; 
            }
            lista.erase(it);
            delete e;
            break;
        }
    }
    this->emprestimos = lista;
}

void Biblioteca::excluiItemInEmprestimo(Emprestimo *e, ItemEmprestimo *i) {
    for (auto it = this->emprestimos.begin(); it != this->emprestimos.end(); it++) {
        if ((*it)->getNum() == e->getNum()) {
            (*it)->excluiItem(i);
        }
    }
}

void Biblioteca::devolveItemInEmprestimo(Emprestimo *e, ItemEmprestimo *i) {
    for (auto it = this->emprestimos.begin(); it != this->emprestimos.end(); it++) {
        if ((*it)->getNum() == e->getNum()) {
            (*it)->devolveLivro(i);
        }
    }
}

void Biblioteca::devolveTodosItens(Emprestimo *e) {
    for (auto it = this->emprestimos.begin(); it != this->emprestimos.end(); it++) {
        if ((*it)->getNum() == e->getNum()) {
            (*it)->devolveTodosLivros();
        }
    }
}

std::vector<Publicacao*> Biblioteca::encontraPubli(std::string t) {
    std::vector<Publicacao*> lista = this->getPublicacoes();

    std::vector<Publicacao*> lista_t;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        if ((*it)->getTitulo().find(t) != std::string::npos) {
            lista_t.push_back(*it);
        }
    }
    return lista_t;
}

std::vector<Livro*> Biblioteca::encontraAutor(std::string aut) {
    std::vector<Publicacao*> lista = this->getPublicacoes();

    std::vector<Livro*> livros_a;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        Livro *livro = dynamic_cast<Livro*>(*it);
        if (livro) {
            if (livro->getAutor().find(aut) != std::string::npos) {
            livros_a.push_back(livro);
            }
        }
    }
    return livros_a;
}