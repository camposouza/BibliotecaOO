CC=g++
CFLAGS=-std=c++11 -Wall -g
TARGET=biblioteca

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Biblioteca.o ${BUILD_DIR}/Emprestimo.o ${BUILD_DIR}/Interface.o ${BUILD_DIR}/ItemEmprestimo.o ${BUILD_DIR}/Livro.o ${BUILD_DIR}/Periodico.o ${BUILD_DIR}/Publicacao.o ${BUILD_DIR}/Usuario.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Biblioteca.o: ${INCLUDE_DIR}/Biblioteca.hpp ${SRC_DIR}/entidades/Biblioteca.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Biblioteca.cpp -o ${BUILD_DIR}/Biblioteca.o

${BUILD_DIR}/Emprestimo.o: ${INCLUDE_DIR}/Emprestimo.hpp ${SRC_DIR}/entidades/Emprestimo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Emprestimo.cpp -o ${BUILD_DIR}/Emprestimo.o

${BUILD_DIR}/Interface.o: ${INCLUDE_DIR}/Interface.hpp ${SRC_DIR}/entidades/Interface.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Interface.cpp -o ${BUILD_DIR}/Interface.o

${BUILD_DIR}/ItemEmprestimo.o: ${INCLUDE_DIR}/ItemEmprestimo.hpp ${SRC_DIR}/entidades/ItemEmprestimo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/ItemEmprestimo.cpp -o ${BUILD_DIR}/ItemEmprestimo.o

${BUILD_DIR}/Livro.o: ${INCLUDE_DIR}/Livro.hpp ${SRC_DIR}/entidades/Livro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Livro.cpp -o ${BUILD_DIR}/Livro.o

${BUILD_DIR}/Periodico.o: ${INCLUDE_DIR}/Periodico.hpp ${SRC_DIR}/entidades/Periodico.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Periodico.cpp -o ${BUILD_DIR}/Periodico.o

${BUILD_DIR}/Publicacao.o: ${INCLUDE_DIR}/Publicacao.hpp ${SRC_DIR}/entidades/Publicacao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Publicacao.cpp -o ${BUILD_DIR}/Publicacao.o

${BUILD_DIR}/Usuario.o: ${INCLUDE_DIR}/Usuario.hpp ${SRC_DIR}/entidades/Usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Usuario.cpp -o ${BUILD_DIR}/Usuario.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Biblioteca.hpp ${INCLUDE_DIR}/Emprestimo.hpp ${INCLUDE_DIR}/Interface.hpp ${INCLUDE_DIR}/ItemEmprestimo.hpp ${INCLUDE_DIR}/Livro.hpp ${INCLUDE_DIR}/Periodico.hpp ${INCLUDE_DIR}/Publicacao.hpp ${INCLUDE_DIR}/Usuario.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o



# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it.

clean:
	rm -f ${BUILD_DIR}/*
