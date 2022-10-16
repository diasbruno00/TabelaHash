
#ifndef TABELAHASH_H
#define TABELAHASH_H

typedef struct
{
    char nome[40];
    float salario ;
    char cpf[11];
    int codigo ;
    char datanascimento[11];

} Tfuncionario;

typedef Tfuncionario *Hash ;

void imprime (Hash *tab, int n);

void inserir (Hash *tab, int n, char *nome, char *dataNascimento, float salario, int codigo,char *cpf);

int busca(Hash *tab, int m, int codigo);

void libera(Hash *tab, int m);

int calculaHash(int codigo,int m);

Tfuncionario *aloca (char *nome, float salario, int codigo, char *dataNascimento, char *cpf);

void inicialiaza(Hash *tab, int m);

#endif
