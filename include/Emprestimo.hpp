#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <vector>
#include "Usuario.hpp"
#include "ItemEmprestimo.hpp"

class Emprestimo {
    private:
        int num;
        Date dataEmprestimo;
        Date dataPrevDevolucao;
        Usuario *usuario;
        std::vector<ItemEmprestimo*> itens;
        static int proximoNumero;

    public:
        Emprestimo(Date dataPrev, Usuario *u);
        ~Emprestimo() { };

        int getNum() const;
        Date getDataEmprestimo() const;
        Date getDataPrevDevolucao() const;
        Usuario* getUsuario() const;
        std::vector<ItemEmprestimo*> getItens() const;
        int getNumItens() const;

        void emprestaLivro(Livro *l);
        void adicionaItem(ItemEmprestimo *i);
        ItemEmprestimo* excluiItem(ItemEmprestimo *i);
        void devolveLivro(ItemEmprestimo *i);
        void devolveTodosLivros();

        /**
         * @brief Checa se o Emprestimo possui certo Livro l como um de seus Itens
         *
         * @param l Livro a ser chegado
         * 
         * @return true se o Emprestimo possui o Livro, false se nao
         */
        bool findLivro(Livro &l);
        /**
         * @brief Checa se todos os Itens do Emprestimo estao devolvidos, ou seja, se a 
         * dataDevolucao de cada item eh diferente de 0
         * 
         * @return true se todos os livros foram devolvidos, false se nao
         */
        bool checaLivrosDevolvidos();
};

#endif