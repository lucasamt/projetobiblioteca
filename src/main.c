#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define T 100

typedef struct
{
    char nome_Livro        [T];
    char nome_Autor        [T];
    char data_Publicacao   [T];
    char emprestado_por    [T];
    char id                [T];
} Livro;

typedef struct
{
    char nome_Aluno        [T];
    char ra                [T];
    char id                [T];
} Usuario;


typedef enum
{
    INCLUIR,
    PROCURAR,
    ATUALIZAR,
    LISTAR,
    EXCLUIR,
    SAIR
} Opcao;

unsigned int vazioUsuario (Usuario usuario)
{
    int   qtd   = 0, posicao;
    char* vetor = (char*)&usuario;

    for (posicao=0; posicao<sizeof(Usuario); posicao++)
    if (vetor[posicao] != 0)
    qtd++;

    if (qtd==0)
    return 1;
    else
    return 0;
}


unsigned int filesizeUsuario (FILE* mc)
{
    Usuario usuario;
    int posicao, retorno, posOriginal;

    posOriginal = ftell(mc);

    fseek (mc, 0, SEEK_END);
    posicao = ftell(mc)/sizeof(Usuario)-1;

    if (posicao==-1)
    {
        fseek (mc, posOriginal, SEEK_SET);
        return 0;
    }

    for (;;)
    {
        fseek (mc, posicao*sizeof(Usuario), SEEK_SET);
        fread (&usuario, sizeof(Usuario), 1, mc);

        if (vazioUsuario(usuario))
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

unsigned int qtosUsuarios (FILE* mc)
{
    // ftruncate(mc);
    return filesizeUsuario(mc)/sizeof(Usuario);
}

void incluirUsuario (FILE* mc)
{
    Usuario usuario;

    printf ("Nome do Aluno: ");
    fflush(stdin);
    gets   (usuario.nome_Aluno);
    fflush(stdin);
    printf ("RA: ");
    fflush(stdin);
    gets   (usuario.ra);
    printf ("ID: \n");
    fflush(stdin);
    gets   (usuario.id);

    fseek  (mc, 0, SEEK_END);
    fwrite (&usuario, sizeof(Usuario), 1, mc);
}

void listarUsuario (FILE* mc)
{
    unsigned int posicao, qtd=qtosUsuarios(mc);
    Usuario usuario;

    if (qtd == 0)
    printf ("\nAgenda vazia!\n\n");
    else
    for (posicao=0; posicao<qtd; posicao++)
    {
        fseek (mc, posicao*sizeof(Usuario), SEEK_SET);
        fread (&usuario, sizeof(Usuario), 1, mc);

        printf ("\nNome do Aluno: %s", usuario.nome_Aluno);
        printf ("\nRA: %s", usuario.ra);
        printf ("\nID: %s", usuario.id);
    }
}

void excluirUsuario (FILE* mc)
{
    char nome_Aluno [31];
    unsigned int posicao, qtd=qtosUsuarios(mc);
    Usuario usuario;

    if (qtd == 0)
    printf ("\nAgenda vazia!\n\n");
    else
    {
        printf ("\nNome do Aluno: ");
        fflush(stdin);
        gets   (nome_Aluno);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc,posicao*sizeof(Usuario),SEEK_SET);
            fread (&usuario, sizeof(Usuario), 1, mc);

            if (strcmp(nome_Aluno,usuario.nome_Aluno) == 0)
            {
                printf ("RA: %s", usuario.ra);
                printf ("\nID: %s", usuario.id);

                break;
            }
        }

        if (posicao==qtd)
        printf ("Usuario nao encontrado!\n\n");
        else
        {
            for (;posicao<qtd-1; posicao++)
            {
                fseek  (mc, (posicao+1)*sizeof(Usuario), SEEK_SET);
                fread  (&usuario, sizeof(Usuario), 1, mc);
                fseek  (mc, posicao*sizeof(Usuario), SEEK_SET);
                fwrite (&usuario, sizeof(Usuario), 1, mc);
            }

            memset (&usuario, 0, sizeof(Usuario));
            fwrite (&usuario, sizeof(Usuario), 1, mc);

            printf ("Informacoes excluidas com sucesso!\n\n");
        }
    }
}

void atualizarUsuario (FILE* mc)
{
    char nome_Aluno [31];
    unsigned int posicao, qtd=qtosUsuarios(mc);
    Usuario usuario;

    if (qtd == 0)
    printf ("\nAgenda vazia!\n\n");
    else
    {
        printf ("\nNome do Aluno: ");
        fflush(stdin);
        gets   (nome_Aluno);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(Usuario), SEEK_SET);
            fread (&usuario, sizeof(Usuario), 1, mc);

            if (strcmp(nome_Aluno,usuario.nome_Aluno) == 0)
            {
                printf ("RA: %s", usuario.ra);
                printf ("\nID: %s", usuario.id);

                break;
            }
        }

        if (posicao==qtd)
        printf ("Usuario nao encontrado!\n\n");
        else
        {
            printf ("\nNovo Nome do Aluno: ");
            fflush(stdin);
            gets   (usuario.nome_Aluno);
            printf ("Novo RA: ");
            fflush(stdin);
            gets   (usuario.ra);
            printf ("Novo ID: ");
            fflush(stdin);
            gets   (usuario.id);

            fseek (mc, -sizeof(Usuario), SEEK_CUR);
            fwrite (&usuario, sizeof(Usuario), 1, mc);
        }
    }
}

void procurarUsuario (FILE* mc)
{
    char nome_Aluno [31];
    unsigned int posicao, qtd=qtosUsuarios(mc);
    Usuario usuario;

    if (qtd == 0)
    printf ("\nAgenda vazia!\n\n");
    else
    {
        printf ("\nNome do Aluno: ");
        fflush(stdin);
        gets   (nome_Aluno);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(Usuario), SEEK_SET);
            fread (&usuario, sizeof(Usuario), 1, mc);

            if (strcmp(nome_Aluno,usuario.nome_Aluno) == 0)
            {
                printf ("RA: %s", usuario.ra);
                printf ("\nID: %s", usuario.id);

                return;
            }
        }

        printf ("Usuario nao encontrado!\n\n");
    }
}

unsigned int vazioLivro (Livro livro)
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

unsigned int filesizeLivro (FILE* mc)
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

        if (vazioLivro(livro))
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
{
    // ftruncate(mc);
    return filesizeLivro(mc)/sizeof(Livro);
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
    printf ("|   BIBLIOTECA   |\n");
    printf ("+----------------+\n\n");
}

unsigned int umNroNatural (char* solicitacao,
    char* mensagem,
    unsigned int min,
    unsigned int max)
    {
        char digitacao [T]; /* 100 uteis + o '\0' */
        unsigned int nroNat, qtdErros=0, posicao;

        do
        {
            printf ("%s", solicitacao);
            fflush(stdin);
            gets (digitacao);

            for (posicao=0, qtdErros=0; digitacao[posicao]!='\0'; posicao++)
            if (digitacao[posicao]<'0' ||
            digitacao[posicao]>'9')
            qtdErros++;

            if (strlen(digitacao)==0 || qtdErros>0)
            printf ("%s - Favor redigitar\n\n", mensagem);
            else
            {
                sscanf (digitacao, "%d", &nroNat);

                if (nroNat<min || nroNat>max)
                {
                    qtdErros++;
                    printf ("%s - Favor redigitar\n\n", mensagem);
                }
            }
        }
        while (strlen(digitacao)==0 || qtdErros>0);

        return nroNat;
    }

    void incluirLivro (FILE* mc)
    {
        Livro livro;

        printf ("\nNome do Livro: ");
        fflush(stdin);
        gets   (livro.nome_Livro);
        printf ("Nome do Autor: ");
        fflush(stdin);
        gets   (livro.nome_Autor);
        printf ("Data de Publicacao: ");
        fflush(stdin);
        gets   (livro.data_Publicacao);
        printf ("Emprestado por: ");
        fflush(stdin);
        gets   (livro.emprestado_por);
        printf ("ID: ");
        fflush(stdin);
        gets   (livro.id);
        fseek  (mc, 0, SEEK_END);
        fwrite (&livro, sizeof(Livro), 1, mc);
    }

    void procurarLivro (FILE* mc)
    {
        char nome_Livro [T];
        unsigned int posicao, qtd=qtosLivros(mc);
        Livro livro;

        if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
        else
        {
            printf ("\nNome do Livro: ");
            fflush(stdin);
            gets   (nome_Livro);

            for (posicao=0; posicao<qtd; posicao++)
            {
                fseek (mc, posicao*sizeof(Livro), SEEK_SET);
                fread (&livro, sizeof(Livro), 1, mc);

                if (strcmp(nome_Livro,livro.nome_Livro) == 0)
                {
                    printf ("Nome do Autor: %s", livro.nome_Autor);
                    printf ("\nData de Publicacao: %s", livro.data_Publicacao);
                    printf ("\nEmprestado por: %s", livro.emprestado_por);
                    printf ("\nID: %s", livro.id);
                    return;
                }
            }

            printf ("Livro nao encontrado!\n\n");
        }
    }

    void atualizarLivro (FILE* mc)
    {
        char nome_Livro [T];
        unsigned int posicao, qtd=qtosLivros(mc);
        Livro livro;

        if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
        else
        {
            printf ("\nNome do Livro: ");
            fflush(stdin);
            gets   (nome_Livro);

            for (posicao=0; posicao<qtd; posicao++)
            {
                fseek (mc, posicao*sizeof(Livro), SEEK_SET);
                fread (&livro, sizeof(Livro), 1, mc);

                if (strcmp(nome_Livro,livro.nome_Livro) == 0)
                {
                    printf ("Nome do Autor: %s", livro.nome_Autor);
                    printf ("\nData de Publicacao: %s", livro.data_Publicacao);
                    printf ("\nEmprestado por: %s", livro.emprestado_por);
                    printf ("\nID: %s", livro.id);
                    break;
                }
            }

            if (posicao==qtd)
            printf ("Livro nao encontrado!\n\n");
            else
            {
                printf ("\nNovo Nome do Livro: ");
                fflush(stdin);
                gets   (livro.nome_Livro);
                printf ("Novo Nome do Autor: ");
                fflush(stdin);
                gets   (livro.nome_Autor);
                printf ("Novo Data de Publicacao: ");
                fflush(stdin);
                gets   (livro.data_Publicacao);
                printf ("Novo Emprestado por: ");
                fflush(stdin);
                gets   (livro.emprestado_por);
                printf ("Novo ID: ");
                fflush(stdin);
                gets   (livro.id);
                fseek (mc, -sizeof(Livro), SEEK_CUR);
                fwrite (&livro, sizeof(Livro), 1, mc);
            }
        }
    }

    void listarLivro (FILE* mc)
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

            printf ("\nNome do Livro: %s", livro.nome_Livro);
            printf ("\nNome do Autor: %s", livro.nome_Autor);
            printf ("\nData de Publicacao: %s", livro.data_Publicacao);
            printf ("\nEmprestado por: %s", livro.emprestado_por);
            printf ("\nID: %s", livro.id);

        }
    }

    void excluirLivro (FILE* mc)
    {
        char nome_Livro [T];
        unsigned int posicao, qtd=qtosLivros(mc);
        Livro livro;

        if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
        else
        {
            printf ("\nNome do Livro: ");
            fflush(stdin);
            gets   (nome_Livro);

            for (posicao=0; posicao<qtd; posicao++)
            {
                fseek (mc,posicao*sizeof(Livro),SEEK_SET);
                fread (&livro, sizeof(Livro), 1, mc);

                if (strcmp(nome_Livro,livro.nome_Livro) == 0)
                {
                    printf ("Nome do Autor: %s", livro.nome_Autor);
                    printf ("\nData de Publicacao: %s", livro.data_Publicacao);
                    printf ("\nEmprestado por: %s", livro.emprestado_por);
                    printf ("\nID: %s", livro.id);

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

                memset (&livro, 0, sizeof(Livro));
                fwrite (&livro, sizeof(Livro), 1, mc);

                printf ("Informacoes excluidas com sucesso!\n\n");
            }
        }
    }

    int main ()
    {
        static char* menuLivros [6] = {
            "Incluir Livro",
            "Procurar Livro",
            "Atualizar Livro",
            "Listar Livros",
            "Excluir Livro",
            "Sair do Programa"
        };

        static char* menuUsuarios [6] = {
            "Incluir Usuario",
            "Procurar Usuario",
            "Atualizar Usuario",
            "Listar Usuario",
            "Excluir Usuario",
            "Sair do Programa"
        };

        int modulo;
        FILE* muitosLivros;
        FILE* muitosUsuarios;
        Opcao opcao;

        system("cls");
        apresenteSe();

        muitosLivros = fopen ("livros.dados", "rb+");
        if (muitosLivros==NULL)
        muitosLivros = fopen ("livros.dados", "wb+");

        muitosUsuarios = fopen ("usuario.dados", "rb+");
        if (muitosUsuarios==NULL)
        muitosUsuarios = fopen ("usuario.dados", "wb+");

        do
        {
            do
            {
                printf("\n Voce deseja:");
                printf("\n 1 - Fazer operacoes com Livros");
                printf("\n 2 - Fazer operacoes com Usuarios");
                printf("\n 3 - Sair\n");
                scanf("%d", &modulo);
            }while(modulo != 1 && modulo != 2 && modulo != 3);

            if(modulo == 3){
                exit(0);
            }

            if(modulo == 1){
                opcao = opcaoEscolhida (menuLivros, 6);

                switch (opcao)
                {
                    case INCLUIR:
                    incluirLivro (muitosLivros);
                    break;

                    case PROCURAR:
                    procurarLivro (muitosLivros);
                    break;

                    case ATUALIZAR:
                    atualizarLivro (muitosLivros);
                    break;

                    case LISTAR:
                    listarLivro (muitosLivros);
                    break;

                    case EXCLUIR:
                    excluirLivro (muitosLivros);
                }
            }else{
                opcao = opcaoEscolhida (menuUsuarios, 6);

                switch (opcao)
                {
                    case INCLUIR:
                    incluirUsuario (muitosUsuarios);
                    break;

                    case PROCURAR:
                    procurarUsuario (muitosUsuarios);
                    break;

                    case ATUALIZAR:
                    atualizarUsuario (muitosUsuarios);
                    break;

                    case LISTAR:
                    listarUsuario (muitosUsuarios);
                    break;

                    case EXCLUIR:
                    excluirUsuario (muitosUsuarios);
                }
            }
        }
        while (opcao != SAIR);

        fclose (muitosLivros);
    }
