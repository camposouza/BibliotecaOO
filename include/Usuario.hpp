#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <ctime>


typedef std::tm Date;

class Usuario {
    private:
        std::string nome;
        std::string cpf;
        std::string endereco;
        std::string fone;
        Date dataPenalizacao;

    public:
        Usuario(std::string nome, std::string cpf, std::string endereco, std::string fone);
        Usuario();
        ~Usuario() { };

        std::string getNome() const;
        std::string getCPF() const;
        std::string getEndereco() const;
        std::string getFone() const;

};

#endif