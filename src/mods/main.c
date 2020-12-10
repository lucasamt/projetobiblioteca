#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define T 255
typedef
    struct
    {
        char nome_Livro        [T];
        char nome_Autor        [T];
        char data_Publicacao   [T];
        char emprestado_por    [T];
        char id                [T];
    }
    Livro;

typedef
    enum
    {
        INCLUIR,
        PROCURAR,
        ATUALIZAR,
        LISTAR,
        EXCLUIR,
        SAIR
    }
    Opcao;

unsigned int vazio (Livro livro)
{
    int   qtd   = 0, posicao;
    char* vetor = (char*)&livro;

    for (posicao=0; posicao<sizeof(Livro); posicao++)
        if (vetor[posicao] != 0)
            qtd++;

    if (qtd==0)
        return 1;
    else
        return 0;
}

unsigned int filesize (FILE* mc)
{
    Livro livro;
    int posicao, retorno, posOriginal;

    posOriginal = ftell(mc);

    fseek (mc, 0, SEEK_END);
    posicao = ftell(mc)/sizeof(Livro)-1;

    if (posicao==-1)
    {
        fseek (mc, posOriginal, SEEK_SET);
        return 0;
    }

    for (;;)
    {
        fseek (mc, posicao*sizeof(Livro), SEEK_SET);
        fread (&livro, sizeof(Livro), 1, mc);

        if (vazio(livro))
        {
            posicao--;
            if (posicao==-1)
            {
                fseek (mc, posOriginal, SEEK_SET);
                return 0;
            }
        }
        else
        {
            retorno = ftell(mc);
            fseek (mc, posOriginal, SEEK_SET);
            return retorno;
        }
    }

    retorno = ftell(mc);
    fseek (mc, posOriginal, SEEK_SET);
    return retorno;
}

unsigned int qtosLivros (FILE* mc)
{ftruncate(mc);
    return filesize(mc)/sizeof(Livro);
}

Opcao opcaoEscolhida (char** mnu, unsigned int qtdOpc)
{
    unsigned int opcAtual;
    char         opcDigitada;

    printf ("\n");

    for (opcAtual=0; opcAtual<qtdOpc; opcAtual++)
        printf ("%c) %s\n", 'a'+opcAtual, mnu[opcAtual]);

    printf ("\nSua Opcao? ");

    for(;;)
    {
        opcDigitada = getch();

        if (opcDigitada>='a' && opcDigitada<='a'+qtdOpc-1)
        {
            printf ("%c\n", opcDigitada);
            return opcDigitada-'a';
        }
        else
            if (opcDigitada>='A' && opcDigitada<='A'+qtdOpc-1)
            {
                printf ("%c\n", opcDigitada);
                return opcDigitada-'A';
            }
    }
}

void apresenteSe ()
{
    printf ("+----------------+\n");
    printf ("| AGENDA PESSOAL |\n");
    printf ("+----------------+\n\n");
}

unsigned int umNroNatural (char* solicitacao,
                           char* mensagem,
                           unsigned int min,
                           unsigned int max)
{
     char digitacao [101]; /* 100 uteis + o '\0' */
     unsigned int nroNat, qtdErros=0, posicao;

     do
     {
         printf ("%s", solicitacao);
         gets (digitacao);

         for (posicao=0, qtdErros=0; digitacao[posicao]!='\0'; posicao++)
             if (digitacao[posicao]<'0' ||
                 digitacao[posicao]>'9')
                 qtdErros++;

             if (strlen(digitacao)==0 || qtdErros>0)
                 printf ("%s - Favor redigitar...\n\n", mensagem);
             else
             {
                 sscanf (digitacao, "%d", &nroNat);

                 if (nroNat<min || nroNat>max)
                 {
                     qtdErros++;
                     printf ("%s - Favor redigitar...\n\n", mensagem);
                 }
             }
    }
    while (strlen(digitacao)==0 || qtdErros>0);

    return nroNat;
}

void incluir (FILE* mc)
{
    Livro livro;

    printf ("\nNome do Livro.......: ");
    gets   (livro.nome_Livro);
    printf ("Nome do Autor: ");
    gets   (livro.nome_Autor);
    printf ("Data de Publicacao...: ");
    gets   (livro.data_Publicacao);
    printf ("Emprestado por...: ");
    gets   (livro.emprestado_por);
    printf ("ID....: ");
    gets   (livro.id);
    fseek  (mc, 0, SEEK_END);
    fwrite (&livro, sizeof(Livro), 1, mc);
}

void procurar (FILE* mc)
{
    char nome_Livro [31];
    unsigned int posicao, qtd=qtosLivros(mc);
    Livro livro;

    if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
    else
    {
        printf ("\nNome do Livro.......: ");
        gets   (nome_Livro);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(Livro), SEEK_SET);
            fread (&livro, sizeof(Livro), 1, mc);

            if (strcmp(nome_Livro,livro.nome_Livro) == 0)
            {
                printf ("Nome do Autor: %s", livro.nome_Autor);
                printf ("\nData de Publicacao...: %s", livro.data_Publicacao);
                printf ("\nEmprestado por...: %s", livro.emprestado_por);
                printf ("\nID....: %s", livro.id);
                return;
            }
        }

        printf ("Livro nao encontrado!\n\n");
    }
}

void atualizar (FILE* mc)
{
    char nome_Livro [31];
    unsigned int posicao, qtd=qtosLivros(mc);
    Livro livro;

    if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
    else
    {
        printf ("\nNome do Livro.......: ");
        gets   (nome_Livro);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(Livro), SEEK_SET);
            fread (&livro, sizeof(Livro), 1, mc);

            if (strcmp(nome_Livro,livro.nome_Livro) == 0)
            {
                printf ("Nome do Autor: %s", livro.nome_Autor);
                printf ("\nData de Publicacao...: %s", livro.data_Publicacao);
                printf ("\nEmprestado por...: %s", livro.emprestado_por);
                printf ("\nID....: %s", livro.id);
                break;
            }
        }

        if (posicao==qtd)
            printf ("Livro nao encontrado!\n\n");
        else
        {
            printf ("\nNovo Nome do Livro.......: ");
            gets   (livro.nome_Livro);
            printf ("Novo Nome do Autor: ");
            gets   (livro.nome_Autor);
            printf ("Novo Data de Publicacao...: ");
            gets   (livro.data_Publicacao);
            printf ("Novo Emprestado por...: ");
            gets   (livro.emprestado_por);
            printf ("Novo ID....: ");
            gets   (livro.id);
            fseek (mc, -sizeof(Livro), SEEK_CUR);
            fwrite (&livro, sizeof(Livro), 1, mc);
        }
    }
}

void listar (FILE* mc)
{
    unsigned int posicao, qtd=qtosLivros(mc);
    Livro livro;

    if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
    else
        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(Livro), SEEK_SET);
            fread (&livro, sizeof(Livro), 1, mc);

            printf ("\nNome do Livro.......: %s", livro.nome_Livro);
            printf ("\nNome do Autor: %s", livro.nome_Autor);
            printf ("\nData de Publicacao...: %s", livro.data_Publicacao);
            printf ("\nEmprestado por...: %s", livro.emprestado_por);
            printf ("\nID....: %s", livro.id);

        }
}

void excluir (FILE* mc)
{
    char nome_Livro [31];
    unsigned int posicao, qtd=qtosLivros(mc);
    Livro livro;

    if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
    else
    {
        printf ("\nNome do Livro.......: ");
        gets   (nome_Livro);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc,posicao*sizeof(Livro),SEEK_SET);
            fread (&livro, sizeof(Livro), 1, mc);

            if (strcmp(nome_Livro,livro.nome_Livro) == 0)
            {
                printf ("Nome do Autor: %s", livro.nome_Autor);
                printf ("\nData de Publicacao...: %s", livro.data_Publicacao);
                printf ("\nEmprestado por...: %s", livro.emprestado_por);
                printf ("\nID....: %s", livro.id);


                break;
            }
        }

        if (posicao==qtd)
            printf ("Livro nao encontrado!\n\n");
        else
        {
            for (;posicao<qtd-1; posicao++)
            {
                fseek  (mc, (posicao+1)*sizeof(Livro), SEEK_SET);
                fread  (&livro, sizeof(Livro), 1, mc);
                fseek  (mc, posicao*sizeof(Livro), SEEK_SET);
                fwrite (&livro, sizeof(Livro), 1, mc);
            }

            printf ("%d\n", vazio(livro));
            memset (&livro, 0, sizeof(Livro));
            printf ("%d\n", vazio(livro));
            fwrite (&livro, sizeof(Livro), 1, mc);

            printf ("Informacoes excluidas com sucesso!\n\n");
        }
    }
}

int main ()
{
     static char* menu [6] = {"Incluir Livro",
                              "Procurar Livro",
                              "Atualizar Livro",
                              "Listar Livros",
                              "Excluir Livro",
                              "Sair do Programa"};

     FILE* muitosLivros;
     Opcao opcao;

     apresenteSe();

     muitosLivros = fopen ("livros.dados", "rb+");
     if (muitosLivros==NULL)
         muitosLivros = fopen ("livros.dados", "wb+");

     do
     {
         opcao = opcaoEscolhida (menu, 6);

         switch (opcao)
         {
             case INCLUIR:
                  incluir (muitosLivros);
                  break;

             case PROCURAR:
                  procurar (muitosLivros);
                  break;

             case ATUALIZAR:
                  atualizar (muitosLivros);
                  break;

             case LISTAR:
                  listar (muitosLivros);
                  break;

             case EXCLUIR:
                  excluir (muitosLivros);
         }
     }
     while (opcao != SAIR);

     fclose (muitosLivros);
}
