#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef
    struct
    {
        char nome        [31];
        char aniversario [11];
        char endereco    [51];
        char telefone    [14];
        char celular     [14];
        char email       [51];
        char skype       [51];
    }
    Contato;

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

unsigned int vazio (Contato contato)
{
    int   qtd   = 0, posicao;
    char* vetor = (char*)&contato;

    for (posicao=0; posicao<sizeof(Contato); posicao++)
        if (vetor[posicao] != 0)
            qtd++;

    if (qtd==0)
        return 1;
    else
        return 0;
}

unsigned int filesize (FILE* mc)
{
    Contato contato;
    int posicao, retorno, posOriginal;

    posOriginal = ftell(mc);

    fseek (mc, 0, SEEK_END);
    posicao = ftell(mc)/sizeof(Contato)-1;

    if (posicao==-1)
    {
        fseek (mc, posOriginal, SEEK_SET);
        return 0;
    }

    for (;;)
    {
        fseek (mc, posicao*sizeof(Contato), SEEK_SET);
        fread (&contato, sizeof(Contato), 1, mc);

        if (vazio(contato))
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

unsigned int qtosContatos (FILE* mc)
{ftruncate(mc);
    return filesize(mc)/sizeof(Contato);
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
    Contato contato;

    printf ("\nNome.......: ");
    gets   (contato.nome);
    printf ("Aniversario: ");
    gets   (contato.aniversario);
    printf ("Endereco...: ");
    gets   (contato.endereco);
    printf ("Telefone...: ");
    gets   (contato.telefone);
    printf ("Celular....: ");
    gets   (contato.celular);
    printf ("e-mail.....: ");
    gets   (contato.email);
    printf ("skype......: ");
    gets   (contato.skype);

    fseek  (mc, 0, SEEK_END);
    fwrite (&contato, sizeof(Contato), 1, mc);
}

void procurar (FILE* mc)
{
    char nome [31];
    unsigned int posicao, qtd=qtosContatos(mc);
    Contato contato;

    if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
    else
    {
        printf ("\nNome.......: ");
        gets   (nome);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(Contato), SEEK_SET);
            fread (&contato, sizeof(Contato), 1, mc);

            if (strcmp(nome,contato.nome) == 0)
            {
                printf ("Aniversario: %s", contato.aniversario);
                printf ("\nEndereco...: %s", contato.endereco);
                printf ("\nTelefone...: %s", contato.telefone);
                printf ("\nCelular....: %s", contato.celular);
                printf ("\ne-mail.....: %s", contato.email);
                printf ("\nskype......: %s\n", contato.skype);

                return;
            }
        }

        printf ("Contato nao encontrado!\n\n");
    }
}

void atualizar (FILE* mc)
{
    char nome [31];
    unsigned int posicao, qtd=qtosContatos(mc);
    Contato contato;

    if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
    else
    {
        printf ("\nNome.......: ");
        gets   (nome);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(Contato), SEEK_SET);
            fread (&contato, sizeof(Contato), 1, mc);

            if (strcmp(nome,contato.nome) == 0)
            {
                printf ("Aniversario: %s", contato.aniversario);
                printf ("\nEndereco...: %s", contato.endereco);
                printf ("\nTelefone...: %s", contato.telefone);
                printf ("\nCelular....: %s", contato.celular);
                printf ("\ne-mail.....: %s", contato.email);
                printf ("\nskype......: %s\n", contato.skype);

                break;
            }
        }

        if (posicao==qtd)
            printf ("Contato nao encontrado!\n\n");
        else
        {
            printf ("\nNovo Nome.......: ");
            gets   (contato.nome);
            printf ("Novo Aniversario: ");
            gets   (contato.aniversario);
            printf ("Novo Endereco...: ");
            gets   (contato.endereco);
            printf ("Novo Telefone...: ");
            gets   (contato.telefone);
            printf ("Novo Celular....: ");
            gets   (contato.celular);
            printf ("Novo e-mail.....: ");
            gets   (contato.email);
            printf ("Novo skype......: ");
            gets   (contato.skype);

            fseek (mc, -sizeof(Contato), SEEK_CUR);
            fwrite (&contato, sizeof(Contato), 1, mc);
        }
    }
}

void listar (FILE* mc)
{
    unsigned int posicao, qtd=qtosContatos(mc);
    Contato contato;

    if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
    else
        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(Contato), SEEK_SET);
            fread (&contato, sizeof(Contato), 1, mc);

            printf ("\nNome.......: %s", contato.nome);
            printf ("\nAniversario: %s", contato.aniversario);
            printf ("\nEndereco...: %s", contato.endereco);
            printf ("\nTelefone...: %s", contato.telefone);
            printf ("\nCelular....: %s", contato.celular);
            printf ("\ne-mail.....: %s", contato.email);
            printf ("\nskype......: %s\n", contato.skype);
        }
}

void excluir (FILE* mc)
{
    char nome [31];
    unsigned int posicao, qtd=qtosContatos(mc);
    Contato contato;

    if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
    else
    {
        printf ("\nNome.......: ");
        gets   (nome);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc,posicao*sizeof(Contato),SEEK_SET);
            fread (&contato, sizeof(Contato), 1, mc);

            if (strcmp(nome,contato.nome) == 0)
            {
                printf ("Aniversario: %s", contato.aniversario);
                printf ("\nEndereco...: %s", contato.endereco);
                printf ("\nTelefone...: %s", contato.telefone);
                printf ("\nCelular....: %s", contato.celular);
                printf ("\ne-mail.....: %s", contato.email);
                printf ("\nskype......: %s\n", contato.skype);

                break;
            }
        }

        if (posicao==qtd)
            printf ("Contato nao encontrado!\n\n");
        else
        {
            for (;posicao<qtd-1; posicao++)
            {
                fseek  (mc, (posicao+1)*sizeof(Contato), SEEK_SET);
                fread  (&contato, sizeof(Contato), 1, mc);
                fseek  (mc, posicao*sizeof(Contato), SEEK_SET);
                fwrite (&contato, sizeof(Contato), 1, mc);
            }

            printf ("%d\n", vazio(contato));
            memset (&contato, 0, sizeof(Contato));
            printf ("%d\n", vazio(contato));
            fwrite (&contato, sizeof(Contato), 1, mc);

            printf ("Informacoes excluidas com sucesso!\n\n");
        }
    }
}

int main ()
{
     static char* menu [6] = {"Incluir Contato",
                              "Procurar Contato",
                              "Atualizar Contato",
                              "Listar Contatos",
                              "Excluir Contato",
                              "Sair do Programa"};

     FILE* muitosContatos;
     Opcao opcao;

     apresenteSe();

     muitosContatos = fopen ("contatos.dados", "rb+");
     if (muitosContatos==NULL)
         muitosContatos = fopen ("contatos.dados", "wb+");

     do
     {
         opcao = opcaoEscolhida (menu, 6);

         switch (opcao)
         {
             case INCLUIR:
                  incluir (muitosContatos);
                  break;

             case PROCURAR:
                  procurar (muitosContatos);
                  break;

             case ATUALIZAR:
                  atualizar (muitosContatos);
                  break;

             case LISTAR:
                  listar (muitosContatos);
                  break;

             case EXCLUIR:
                  excluir (muitosContatos);
         }
     }
     while (opcao != SAIR);

     fclose (muitosContatos);
}
