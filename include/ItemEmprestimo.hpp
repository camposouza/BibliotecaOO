#ifndef ITEMEMPRESTIMO_H
#define ITEMEMPRESTIMO_H

#include <ctime>
#include "Livro.hpp"
#include "Usuario.hpp"

class ItemEmprestimo {
    private:
        Date dataDevolucao;
        Livro *livro;
        
    public:
        ItemEmprestimo(Livro *l);

        Livro* getLivro() const;
        Date getDataDevolucao() const;
        void setDataDevolucao(Date &d);



};

#endif