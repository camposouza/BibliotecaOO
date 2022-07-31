#ifndef PERIODICO_H
#define PERIODICO_H

#include "Publicacao.hpp"

class Periodico : public Publicacao {
    private:
        int numEdicao;
        std::string mes;

    public:
        Periodico(int cod, std::string t, std::string ed, int ano, int numEd, std::string mes);
        ~Periodico() { };

        int getNumEdicao() const;
        std::string getMes() const;

        void f() {};
};

#endif