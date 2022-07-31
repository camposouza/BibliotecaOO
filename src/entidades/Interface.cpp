#include "Interface.hpp"

Biblioteca bib = Biblioteca();

// ---------- Funcoes Auxiliares ----------
void imprimeDadosUsuario(Usuario *u) {
    std::cout << "  Nome: " <<u->getNome() << " - " << "CPF: " << u->getCPF() << std::endl;
    std::cout << "  Endereco: " << u->getEndereco() << std::endl;
    std::cout << "  Telefone: " << u->getFone() << std::endl;
}

void imprimeDadosLivro(Livro *l) {
    std::cout << "  Livro COD: " << l->getCod() << std::endl;
    std::cout << "  " << l->getTitulo() << ", por " << l->getAutor() << std::endl;
    std::cout << "  Editora " << l->getEditora() << std::endl;
    std::cout << "  " << l->getQtdExemplares() << " exemplares disponiveis" << std::endl;
}

void imprimeDadosPeriodico(Periodico *p) {
    std::cout << "  Periodico COD: " << p->getCod() << std::endl;
    std::cout << "  " << p->getTitulo() << std::endl;
    std::cout << "  Edicao " << p->getNumEdicao() << ", " << p->getMes() << " de " << p->getAno() << std::endl;
    std::cout << "  Editora " << p->getEditora() << std::endl;
}

void imprimeDadosItem(ItemEmprestimo *i) {
    std::cout << i->getLivro()->getTitulo() << ". Devolvido em: "
              << i->getDataDevolucao().tm_mday << "/" 
              << i->getDataDevolucao().tm_mon << "/"
              << i->getDataDevolucao().tm_year << std::endl;
}

void imprimeDadosEmprestimo(Emprestimo *e) {
    std::cout << "  Emprestimo numero: " << e->getNum() << std::endl;
    std::cout << "  Feito por " << e->getUsuario()->getNome() << std::endl;
    std::cout << "  Data do emprestimo: " 
              << e->getDataEmprestimo().tm_mday << "/"
              << e->getDataEmprestimo().tm_mon + 1 << "/"
              << e->getDataEmprestimo().tm_year + 1900 << ". "
              << "  Data prev. p/ devolucao: "
              << e->getDataPrevDevolucao().tm_mday << "/"
              << e->getDataPrevDevolucao().tm_mon << "/"
              << e->getDataPrevDevolucao().tm_year << std::endl;
    std::cout << "  Numero de itens: " << e->getNumItens() << std:: endl;

    int i = 1;
    std::vector<ItemEmprestimo*> lista = e->getItens();
    for (auto it = lista.begin(); it != lista.end(); it++) {
        std::cout << "  " << i << "- "; imprimeDadosItem(*it);
        i++;
    }

}

Usuario* encontraUsuario(std::string &u_nome) {
    std::vector<Usuario*> lista = bib.getUsuarios();

    Usuario *u = nullptr;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        if (u_nome == (*it)->getNome()) {
            u = *it;
            break;
        }
    }
    if (u == nullptr) { throw "Usuario nao encontrado"; }
    return u;
}

Livro* encontraLivro(std::string &l_titulo) {
    std::vector<Publicacao*> lista = bib.getPublicacoes();

    Livro* l = nullptr;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        Livro *livro = dynamic_cast<Livro*>(*it);
        if (livro) {
            if (l_titulo == livro->getTitulo()) {
                l = livro;
                break;
            }
        }
    }

    if (l == nullptr) { throw "Livro nao encontrado"; }
    return l;
}

Periodico* encontraPeriodico(std::string &p_titulo) {
    std::vector<Publicacao*> lista = bib.getPublicacoes();

    Periodico *p = nullptr;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        Periodico *periodico = dynamic_cast<Periodico*>(*it);
        if (periodico) {
            if (p_titulo == periodico->getTitulo()) {
                p = periodico;
                break;
            }
        }   
    }

    if (p == nullptr) { throw "Periodico nao encontrado"; }
    return p;
}

Emprestimo* encontraEmprestimo(int e_num) {
    std::vector<Emprestimo*> lista = bib.getEmprestimos();

    Emprestimo *e = nullptr;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        if (e_num == (*it)->getNum()) {
            e = *it;
            break;
        }
    }
    if (e == nullptr) { throw "Emprestimo nao encontrado"; }
    return e;
}

bool isNumber(const std::string& s) {
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}


// Inicializando a interface
void Interface::iniciaInterface() {

    int opcao = 99;

    while (opcao != 0) {

        switch (opcao) {
         case 1:
            this->cadastrarNovoUsuario();
            break;
         case 2:
            this->cadastrarNovoLivro();
            break;
        case 3:
            this->cadastrarNovoPeriodico();
            break;
        case 4:
            this->cadastrarNovoEmprestimo();
            break;
        case 5:
            this->inserirNovoItemInEmprestimo();
            break;
        case 6:
            this->excluirUsuario();
            break;
        case 7:
            this->excluirLivro();
            break;
        case 8:
            this->excluirPeriodico();
            break;
        case 9:
            this->excluirEmprestimo();
            break;
        case 10:
            this->excluirItemInEmprestimo();
            break;
        case 11:
            this->devolverTodoEmprestimo();
            break;
        case 12:
            this->devolverLivro();
            break;
        case 13:
            this->pesquisarPublicacao();
            break;
        case 14:
            this->pesquisarAutor();
            break;
        case 15:
            this->mostrarUsuarios();
            break;
        case 16:    
            this->mostrarPublicacoes();
            break;
        case 17:    
            this->mostrarEmprestimos();
            break;
        case 99:
            this->main();
            break;
        case 0:   
            // Exit program 
            break;
        default:
            std::cout << "Opcao invalida. Por favor, digite novamente." << std::endl;
            break;
        }

        std::cout << std::endl;
        std::cout << "Digite uma opcao: ";

        std::string opcao_string;
        int opcao_invalida = 404;
        std::getline(std::cin, opcao_string);
        if (isNumber(opcao_string)) {
            opcao = std::stoi(opcao_string);
            if (opcao == 0) std::cout << "Finalizando programa..." << std::endl;
        } else {
            opcao = opcao_invalida;
        }
    }  
}


// ---------- Metodos ----------
void Interface::cadastrarNovoUsuario() {
    std::cout << "Vamos inserir os dados deste Usuario! " << std::endl;
    
    std::string nome;
    std::string cpf;
    std::string endereco;
    std::string fone;

    std::cout << "Nome: "; std::getline(std::cin, nome);
    std::cout << "CPF: "; std::getline(std::cin, cpf);
    std::cout << "Endereco: "; std::getline(std::cin, endereco);
    std::cout << "Fone: "; std::getline(std::cin, fone);

    Usuario *u = new Usuario(nome, cpf, endereco, fone);
    try { 
        bib.insereUsuario(u); 
        std::cout << "Usuario cadastrado com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }    
}

void Interface::cadastrarNovoLivro() {
    std::cout << "Vamos inserir os dados deste Livro! " << std::endl;

    int cod;
    std::string t;
    std::string ed;
    int ano;
    std::string auts;
    int qtd;

    std::cout << "Codigo da publicacao: "; std::cin>>cod;
    std::cout << "Título: "; std::cin.ignore(); std::getline(std::cin, t);
    std::cout << "Editora: "; std::getline(std::cin, ed);
    std::cout << "Ano: "; std::cin>>ano;
    std::cout << "Autores: "; std::cin.ignore(); std::getline(std::cin, auts);
    std::cout << "Quantidade de exemplares: "; std::cin>>qtd; std::cin.ignore();

    Livro *l = new Livro(cod, t, ed, ano, auts, qtd);
    try { 
        bib.inserePublicacao(l); 
        std::cout << "Livro cadastrado com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }
     
}

void Interface::cadastrarNovoPeriodico() {
    std::cout << "Vamos inserir os dados deste Periodico! " << std::endl;

    int cod;
    std::string t;
    std::string ed;
    int ano;
    int numEd;
    std::string mes;

    std::cout << "Codigo da publicacao: "; std::cin>>cod;
    std::cout << "Título: "; std::cin.ignore(); std::getline(std::cin, t);
    std::cout << "Editora: "; std::getline(std::cin, ed);
    std::cout << "Ano: "; std::cin>>ano;
    std::cout << "Numero da Edicao: "; std::cin>>numEd;
    std::cout << "Mes de Lancamento: "; std::cin>>mes; std::cin.ignore();

    Periodico *p = new Periodico(cod, t, ed, ano, numEd, mes);
    try { 
        bib.inserePublicacao(p);
        std::cout << "Periodico cadastrado com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }   
}

void Interface::cadastrarNovoEmprestimo() {
    std::cout << "Vamos cadastrar um novo Emprestimo! " << std::endl;
    
    std::string u_nome;
    std::cout << "Insira o nome do Usuario: "; std::getline(std::cin, u_nome);
    try { 
        Usuario *u = encontraUsuario(u_nome);

        Date dataPrev;
        std::cout << "Qual a data prevista p/ devolucao? " << std::endl;
        std::cout << "Dia: "; std::cin>>dataPrev.tm_mday;
        std::cout << "Mes: "; std::cin>>dataPrev.tm_mon;
        std::cout << "Ano: "; std::cin>>dataPrev.tm_year;
        Emprestimo *e = new Emprestimo(dataPrev, u);

        std::cout << "Vamos agora cadastrar os Itens dos Emprestimos!" << std::endl;
        int qtd;
        std::cout << "Quantos Itens serao emprestados? "; std::cin >>qtd;

        std::string l_titulo;
        std::cin.ignore();
        for (int j = 0; j < qtd; j++) {
            std::cout << "Insira o titulo do Livro a ser emprestado: "; std::getline(std::cin, l_titulo);
            Livro *l = encontraLivro(l_titulo);
            
            e->emprestaLivro(l);
        }

        bib.insereEmprestimo(e);

        std::cout << "Emprestimo cadastrado com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }
}

void Interface::inserirNovoItemInEmprestimo() {
    std::cout << "Vamos inserir um novo Item em um Emprestimo existente!" << std::endl;

    int e_num;
    std::cout << "Digite o codigo do Emprestimo desejado: "; std::cin>>e_num; std::cin.ignore();

    try { 
        Emprestimo *e = encontraEmprestimo(e_num);
        std::string l_titulo;
        std::cout << "Digite o titulo do Livro que deseja emprestar: "; std::getline(std::cin, l_titulo);
        Livro *l = encontraLivro(l_titulo);
        ItemEmprestimo *i = new ItemEmprestimo(l);

        bib.insereItemInEmprestimo(e, i);

        std::cout << "Item inserido com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }    
}

void Interface::excluirUsuario() {
    std::cout << "Vamos excluir um Usuario!" << std::endl;

    std::string u_nome;
    std::cout << "Insira o nome do Usuario: "; std::getline(std::cin, u_nome);

    try {
        Usuario *u = encontraUsuario(u_nome);
        bib.excluiUsuario(u);

        std::cout << "Usuario excluido com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }     
}

void Interface::excluirLivro() {
    std::cout << "Vamos excluir um Livro!" << std::endl;

    std::string l_titulo;
    std::cout << "Insira o titulo do Livro: "; std::getline(std::cin, l_titulo);

    try {
        Livro *l = encontraLivro(l_titulo);
        bib.excluiPublicacao(l);

        std::cout << "Livro excluido com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }
}

void Interface::excluirPeriodico() {
    std::cout << "Vamos excluir um Periodico!" << std::endl;
    
    std::string p_titulo;
    std::cout << "Insira o titulo do Periodico: "; std::getline(std::cin, p_titulo);

    try {
        Periodico *p = encontraPeriodico(p_titulo);
        bib.excluiPublicacao(p);

        std::cout << "Periodico excluido com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }     
}

void Interface::excluirEmprestimo() {
    std::cout << "Vamos excluir um Emprestimo!" << std::endl;
    
    int e_num;
    std::cout << "Insira o numero do Emprestimo: "; std::cin>>e_num; std::cin.ignore();

    try { 
        Emprestimo *e = encontraEmprestimo(e_num);
        bib.excluiEmprestimo(e);
    
        std::cout << "Emprestimo excluido com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }   
}

void Interface::excluirItemInEmprestimo() {
    std::cout << "Vamos excluir um Item de um Emprestimo!" << std::endl;

    int e_num;
    std::cout << "Insira o numero do Emprestimo: "; std::cin>>e_num; std::cin.ignore();

    try { 
        Emprestimo *e = encontraEmprestimo(e_num);

        std::string l_titulo;
        std::cout << "Insira o titulo do Livro: "; std::getline(std::cin, l_titulo);
        Livro *l = encontraLivro(l_titulo);
        ItemEmprestimo *i = new ItemEmprestimo(l);

        bib.excluiItemInEmprestimo(e, i);

        std::cout << "Item excluido do Emprestimo com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }   
}

void Interface::devolverTodoEmprestimo() {
    std::cout << "Vamos devolver um Emprestimo inteiro!" << std::endl;
    
    int e_num;
    std::cout << "Insira o numero do Emprestimo: "; std::cin>>e_num; std::cin.ignore();

    try {
        Emprestimo *e = encontraEmprestimo(e_num);
        bib.devolveTodosItens(e);

        std::cout << "Emprestimo devolvido com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; } 
}

void Interface::devolverLivro() {
    std::cout << "Vamos devolver um Livro!" << std::endl;

    int e_num;
    std::cout << "Insira o numero do Emprestimo: ";  std::cin>>e_num; std::cin.ignore();
    try {
        Emprestimo *e = encontraEmprestimo(e_num);

        std::string l_titulo;
        std::cout << "Insira o titulo do Livro: "; std::getline(std::cin, l_titulo);
        Livro *l = encontraLivro(l_titulo);
        ItemEmprestimo *i = new ItemEmprestimo(l);

        bib.devolveItemInEmprestimo(e, i);

        std::cout << "Livro devolvido com sucesso!" << std::endl;
    } catch (const char *e) { std::cerr << e << '\n'; }
    

}

void Interface::pesquisarPublicacao() {
    std::string p_titulo;
    std::cout << "Digite o nome da Publicacao: "; std::getline(std::cin, p_titulo);

    std::vector<Publicacao*> lista = bib.encontraPubli(p_titulo);

    if (lista.empty()) { std::cout << "Nao existem Publicacoes com esse titulo" << std::endl;}
    for (auto it = lista.begin(); it != lista.end(); it++) {
        Livro *livro = dynamic_cast<Livro*>(*it);

        if(livro) {
            imprimeDadosLivro(livro);
        } else {
            Periodico *periodico = dynamic_cast<Periodico*>(*it);
            imprimeDadosPeriodico(periodico);
        }
    }    
}

void Interface::pesquisarAutor() {
    std::string a_nome;
    std::cout << "Digite o nome do autor: "; std::getline(std::cin, a_nome);

    std::vector<Livro*> lista = bib.encontraAutor(a_nome);

    if (lista.empty()) { std::cout << "Nao existem Livros com esse autor" << std::endl;}
    for (auto it = lista.begin(); it != lista.end(); it++) {
        imprimeDadosLivro(*it);
    }
}

void Interface::mostrarUsuarios() {
    std::vector<Usuario*> lista = bib.getUsuarios();

    int i = 1;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        std::cout << "* Usuario " << i << std::endl;
        imprimeDadosUsuario(*it);
        i++;
    }
}

void Interface::mostrarPublicacoes() {
    std::vector<Publicacao*> lista = bib.getPublicacoes();

    int i = 1;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        std::cout << "* Publicacao " << i << std::endl;
        Livro *livro = dynamic_cast<Livro*>(*it);

        if(livro) {
            imprimeDadosLivro(livro);
        } else {
            Periodico *periodico = dynamic_cast<Periodico*>(*it);
            imprimeDadosPeriodico(periodico);
        }
        i++;
    } 
}

void Interface::mostrarEmprestimos() {
    std::vector<Emprestimo*> lista = bib.getEmprestimos();

    int i = 1;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        std::cout << "* Emprestimo " << i << std::endl;
        imprimeDadosEmprestimo(*it);
        i++;
    }
}

void Interface:: main() {
    std::cout << std::endl << std::endl;
    std::cout << "/----- Digite a opcao desejada e tecle Enter -----\\" << '\n';
    std::cout << "1 - Cadastrar um novo Usuario" << std::endl; // OK
    std::cout << "2 - Cadastrar um novo Livro" << std::endl; // OK
    std::cout << "3 - Cadastrar um novo Periodico" << std::endl; // OK
    std::cout << "4 - Cadastrar um novo Emprestimo" << std::endl; // OK
    std::cout << "5 - Inserir um novo Item de emprestimo" << std::endl; // OK 
    std::cout << "6 - Excluir um Usuario" << std::endl; // OK
    std::cout << "7 - Excluir um Livro" << std::endl; // OK
    std::cout << "8 - Excluir um Periodico" << std::endl; // OK
    std::cout << "9 - Excluir um Emprestimo" << std::endl; // OK
    std::cout << "10 - Excluir um Item de emprestimo" << std::endl; // OK
    std::cout << "11 - Devolver todos os Livros do Emprestimo" << std::endl; // OK
    std::cout << "12 - Devolver um Livro de um Emprestimo" << std::endl;
    std::cout << "13 - Pesquisar Publicacaoes por titulo" << std::endl; // OK
    std::cout << "14 - Pesquisar Livros por autor" << std::endl; // OK
    std::cout << "15 - Listar todos os Usuarios" << std::endl; // OK
    std::cout << "16 - Listar todas as Publicacaoes" << std::endl; // OK
    std::cout << "17 - Listar todos os Emprestimos e seus Itens" << std::endl; // OK
    std::cout << "99 - Mostrar o menu novamente" << std::endl; // OK
    std::cout << "0 - Sair do programa" << std::endl; // OK
}