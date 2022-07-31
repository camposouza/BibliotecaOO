#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include "Publicacao.hpp"

class Livro : public Publicacao {
    private:
        std::string autores;
        int qtdExemplares;
    
    public:
        Livro(int cod, std::string t, std::string ed, int ano, std::string auts, int qtd);
        Livro(int cod, std::string t, std::string ed, int ano, std::string auts);
        Livro();
        ~Livro() { };
        
        std::string getAutor() const;
        int getQtdExemplares() const;

        void incrementaExemplares();
        void decrementaExemplares();

        void f() {};
};

#endif