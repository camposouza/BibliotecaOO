#ifndef INTERFACE_H
#define INTERFACE_H

#include "Biblioteca.hpp"

class Interface {
    public:
        Interface() { };

        void iniciaInterface();

        void cadastrarNovoUsuario();
        void cadastrarNovoLivro();
        void cadastrarNovoPeriodico();
        void cadastrarNovoEmprestimo();
        void inserirNovoItemInEmprestimo();
        void excluirUsuario();
        void excluirLivro();
        void excluirPeriodico();
        void excluirEmprestimo();
        void excluirItemInEmprestimo();
        void devolverTodoEmprestimo();
        void devolverLivro();
        void pesquisarPublicacao();
        void pesquisarAutor();
        void mostrarUsuarios();
        void mostrarPublicacoes();
        void mostrarEmprestimos();
        void main();
};

#endif