#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <string>


class Publicacao {
    private:
        int codPublicacao;
        std::string titulo;
        std::string editora;
        int ano;

    public:
        Publicacao(int cod, std::string t, std::string ed, int ano);
        Publicacao();
        virtual ~Publicacao() {};

        int getCod() const;
        std::string getTitulo() const;
        std::string getEditora() const;
        int getAno() const;

        virtual void f() = 0;
};


#endif