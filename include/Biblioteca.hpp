#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Emprestimo.hpp"
#include "Periodico.hpp"

class Biblioteca {
    private:
        std::vector<Usuario*> usuarios;
        std::vector<Publicacao*> publicacoes;
        std::vector<Emprestimo*> emprestimos;

    public:
        Biblioteca();


        std::vector<Usuario*> getUsuarios() const;
        std::vector<Publicacao*> getPublicacoes() const;
        std::vector<Emprestimo*> getEmprestimos() const;


        void insereUsuario(Usuario *u);
        void inserePublicacao(Publicacao *p);
        void insereEmprestimo(Emprestimo *e);
        void insereItemInEmprestimo(Emprestimo *e, ItemEmprestimo *i);
        void excluiUsuario(Usuario *u);
        void excluiPublicacao(Publicacao *p);
        void excluiEmprestimo(Emprestimo *e);
        void excluiItemInEmprestimo(Emprestimo *e, ItemEmprestimo *i);
        void devolveItemInEmprestimo(Emprestimo *e, ItemEmprestimo *i);
        void devolveTodosItens(Emprestimo *e);
        std::vector<Publicacao*> encontraPubli(std::string t);
        std::vector<Livro*> encontraAutor(std::string aut);
};

#endif