/*
Repositório do Código: https://github.com/lucasamt/projetobiblioteca

Integrantes

Guilherme Araujo Alexandre 20133153
Lucas Ament 20011615
Renato Donizeti da Silva Junior 20014023

*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

#include "./mods/main.c"
#define T 1024

typedef
    struct
{
  char nome_Livro[30];
  char nome_Autor[60];
  char data_Publicacao[11];
}Cadastro;

typedef
    enum
{
  CADASTRAR,
  CONSULTAR,
  EXCLUIR,
  SAIR
}Escolha;

unsigned int filesize (FILE* sisbibli)
{
    Cadastro cad;
    int posicao, retorno, posOriginal;

    posOriginal = ftell(sisbibli);

    fseek (mc, 0, SEEK_END);
    posicao = ftell(sisbibli)/sizeof(cad)-1;

    if (posicao==-1)
    {
        fseek (sisbibli, posOriginal, SEEK_SET);
        return 0;
    }
   for (;;)
    {
        fseek (sisbibli, posicao*sizeof(Cadastro), SEEK_SET);
        fread (&cad, sizeof(Cadrasto), 1, sisbibli);

        if (vazio(cad))
        {
            posicao--;
            if (posicao==-1)
            {
                fseek (sisbibli, posOriginal, SEEK_SET);
                return 0;
            }
        }
        else
        {
            retorno = ftell(sisbibli);
            fseek (sisbibli, posOriginal, SEEK_SET);
            return retorno;
        }
    }

    retorno = ftell(sisbibli);
    fseek (sisbibli, posOriginal, SEEK_SET);
    return retorno;
}

int main()
{
    //Fazer DO WHILE com switch case dentro do DO WHILE e colocar para voltar ao menu toda vez que a condição for diferente de SAIR

    return 0;
}
