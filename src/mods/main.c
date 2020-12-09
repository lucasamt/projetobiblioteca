/*
int atoi(const char* str)
{
    int num = 0;
    int i = 0;
    bool isNegetive = false;
    if(str[i] == '-'){
        isNegetive = true;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    if(isNegetive) num = -1 * num;
    return num;
}

int operacaoImpossivel()
{
    system("cls");
    printf("- Não é possível concluir esta operação!");
    system("pause");

    return 0;
}

double** novaMatriz (unsigned int quantidade_de_linhas, unsigned int quantidade_de_colunas)
{
    double** ret = (double**)malloc(quantidade_de_linhas*sizeof(double*));

    unsigned int linha;

    for (linha=0; linha<quantidade_de_linhas; linha++)
    ret[linha] = (double*)malloc(quantidade_de_colunas*sizeof(double));

    return ret;
}

void removerEspaco(char *str)
{

    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
    str[count] = '\0';
}

int verificarNumero(char caracter)
{
    if (caracter >= '0' && caracter <= '9' && caracter != '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void limparCaractere(char str)
{
    str = '\0';
}
void limparString(char *str)
{
    memset(str,0,sizeof(str));
}
*/


// codigo de ajuda
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>

typedef struct materiaa
{
    char materia[15];
    float nota1, nota2;
}mat;

typedef struct Listagem
{
    char nome[60], RA[9];
    mat disciplina[7];
}list;

void Incluir_Alunos(list a[100], int *contador, int quantidade[100])
{
    char escolha;
    int  h, cont, quant;
    cont = *contador;
    do
    {
        printf("Digite o seu nome: ");
        fflush(stdin);
        gets(a[cont].nome);
        printf("Digite o seu RA: ");
        fflush(stdin);
        gets(a[cont].RA);
        printf("\nQuantas matérias cursando? ");
        scanf("%d", &quant);
        for(h=0;h<quant;h++)
        {
            printf("Digite o nome da disciplina: ");
            fflush(stdin);
            gets(a[cont].disciplina[h].materia);
            printf("Nota 1: ");
            scanf("%f", &a[cont].disciplina[h].nota1);
            printf("Nota 2: ");
            scanf("%f", &a[cont].disciplina[h].nota2);
        }
        do
        {
            printf("Voce deseja adicionar mais algum aluno?\nDigite \"S\" para sim ou \"N\" para não: ");
            scanf(" %c", &escolha);
            if (toupper(escolha) != 'S' && toupper(escolha) != 'N')
            {
                printf("\nESCOLHA INVÁLIDA!!!\nDigite Novamente...");
            }
        } while (toupper(escolha) != 'S' && toupper(escolha) != 'N');
        quantidade[cont]=quant;
        cont++;
    }while(toupper(escolha)!='N');
    *contador+=cont;
}

void Remover_Alunos(list b[100], int quanti[100], int *bcont, int *exc)
{
    char excluir_RA[9], esco;
    int x, y, z, qtd=0, aux=0, cont=0, num=0;
    do
    {
        printf("\nDigite o RA: ");
        fflush(stdin);
        gets(excluir_RA);
        for (x=0;x<=*bcont;x++)
        {
            if(strcmp(excluir_RA, b[x].RA)==0)
            {
                aux=x;
            }
        }
        if(strcmp(excluir_RA, b[aux].RA)==0)
        {
            cont=1;
            *exc++;
            b[aux].nome[0]='\0';
            b[aux].RA[0]='\0';
            for(x=0;x<quanti[y];x++)
            {
                b[aux].disciplina[x].materia[0]='\0';
                b[y].disciplina[z].nota1=0;
                b[y].disciplina[z].nota2=0;
            }
            do
            {
                printf("Voce deseja remover mais algum aluno?\nDigite \"S\" para sim ou \"N\" para não: ");
                scanf(" %c", &esco);
                if (toupper(esco) != 'S' && toupper(esco) != 'N')
                {
                    printf("\nESCOLHA INVÁLIDA!!!\nDigite Novamente...");
                }
                else if(toupper(esco) == 'S'){cont=0;}
                else if(toupper(esco) == 'N'){cont=1;}

            } while (toupper(esco) != 'S' && toupper(esco) != 'N');
        }
        else
        {
            printf("\nRA INVÁLIDO!!!\nDigite 0 para digitar novamente ou 1 para voltar ao menu: ");
            scanf("%d", &num);
            if(num==0){cont=0;}
            else if(num==1){cont=1;}
        }
    }while(cont==0);
}

void Alterar_Informacoes(list a[100], int *contador, int quant[100])
{
    char ra[10];
    int x, y, h, aux, contador2, cont, num;
    float media;
    cont = *contador;
    do
    {
        system("cls");
        printf("Digite o RA do aluno: ");
        fflush(stdin);
        gets(ra);
        for (x=0;x<=cont;x++)
        {
            if(strcmp(ra, a[x].RA) == 0)
            {
                aux=x;
            }
        }
        if(strcmp(ra, a[aux].RA) == 0)
        {
            contador2=1;
            printf("O aluno do RA: %s. De nome: %s.", a[aux].RA, a[aux].nome);
            printf("\nQue cursa as disciplinas:\n");
            for(y=0;y<quant[aux];y++)
            {
                media=0;
                media = (a[aux].disciplina[y].nota1 + a[aux].disciplina[y].nota2) / 2;
                printf("Matéria: %s.\nNota 1: %f.\nNota 2: %f.\nMédia: %.2f.\n", a[aux].disciplina[y].materia, a[aux].disciplina[y].nota1, a[aux].disciplina[y].nota2, media);
            }
            printf("\n\n\tAlterar informacoes!!!\n");
            printf("Digite o novo nome: ");
            fflush(stdin);
            gets(a[aux].nome);
            printf("Digite o novo RA: ");
            fflush(stdin);
            gets(a[aux].RA);
            printf("\nQuantas matérias cursando? ");
            scanf("%d", &quant[aux]);
            for(h=0;h<quant[aux];h++)
            {
            printf("Digite o nome da nova disciplina: ");
            fflush(stdin);
            gets(a[aux].disciplina[h].materia);
            printf("Nota 1 alterada: ");
            scanf("%f", &a[aux].disciplina[h].nota1);
            printf("Nota 2: ");
            scanf("%f", &a[aux].disciplina[h].nota2);
            }
            system("pause");
        }
        else
        {
            printf("\nRA INVÁLIDO!!!\nDigite 0 para digitar novamente ou 1 para voltar ao menu: ");
            scanf("%d", &num);
            if(num==0){contador2=0;}
            else if(num==1){contador2=1;}
        }
    }while(contador2==0);
}

void Busca_Aluno(list d[100], int quant[100], int *buscacont)
{
    char ra[9];
    int x, y, cont, aux, num, contador;
    float media;
    cont = *buscacont;
    do
    {
        system("cls");
        printf("Digite o RA do aluno: ");
        fflush(stdin);
        gets(ra);
        for (x=0;x<=cont;x++)
        {
            if(strcmp(ra, d[x].RA) == 0)
            {
                aux=x;
            }
        }
        if(strcmp(ra, d[aux].RA) == 0)
        {
            contador=1;
            printf("O aluno do RA: %s De nome: %s", d[aux].RA, d[aux].nome);
            printf("\nQue cursa as disciplinas:\n");
            for(y=0;y<quant[aux];y++)
            {
                media=0;
                media = (d[aux].disciplina[y].nota1 + d[aux].disciplina[y].nota2) / 2;
                printf("Matéria: %s\nNota 1: %.2f\nNota 2: %.2f\nMédia: %.2f\n", d[aux].disciplina[y].materia, d[aux].disciplina[y].nota1, d[aux].disciplina[y].nota2, media);
            }
            system("pause");
        }
        else
        {
            printf("\nRA INVÁLIDO!!!\nDigite 0 para digitar novamente ou 1 para voltar ao menu: ");
            scanf("%d", &num);
            if(num==0){contador=0;}
            else if(num==1){contador=1;}
        }
    }while(contador==0);
}


void Listagem_Tudo(list c[100], int *contador, int quant[100])
{
    int x, y, cont;
    float media;
    cont = *contador;

    for (y=0;y<cont;y++)
    {
        if (c[y].nome[0]!='\0' && c[y].RA[0]!='\0')
        {
            printf("\n_____________________________________________\n\n\n");
            printf("Nome: %s\nRA: %s\n\n", c[y].nome, c[y].RA);
            for(x=0;x<quant[y];x++)
            {
                media=0;
                media = (c[y].disciplina[x].nota1 + c[y].disciplina[x].nota2) / 2;
                printf("Matéria: %s\nNota 1: %.2f\nNota 2: %.2f\nMédia: %.2f\n\n", c[y].disciplina[x].materia, c[y].disciplina[x].nota1, c[y].disciplina[x].nota2, media);
            }
        }
    }
    printf("\n\n");
    system("pause");
}

void Listagem_Materia(list e[100], int *contador, int quant[100])
{
    int x, y, cont;
    char mate[15];
    cont = *contador;

    printf("Digite o nome da matéria: ");
    scanf("%s",&mate);

   for (y=0;y<=cont;y++)
    {
        for(x=0;x<quant[y];x++)
        {
            if(strcmp(mate, e[y].disciplina[x].materia) == 0)
            {
                printf("Nome: %s.\n\n", e[y].nome);
            }
        }
    }
    system("pause");
}

void menu()
{
    setlocale(LC_ALL, "portuguese");
    int num, iacount=0, x=1, qntd[100], excluidos=0, primeiratent=0;
    list exe[100];
    char escolha;
    do
    {
        num=0;
        system("cls");
        printf("Bem vindo!\n1 - Incluir Alunos.\n2 - Remover Alunos por RA.\n3 - Alterar Informações.\n4 - Busca de Aluno por RA.\n5 - Listagem de todos Alunos, com todas as disciplinas e média aritméticas.\n6 - Listagem de todos os Alunos de uma determinada disciplina.\n7 - Sair.\n");
        printf("Escolha um dos números acima: ");
        scanf("%d", &num);
        if(num<1 || num>7)
        {
             printf("\n\nNúmero Inválido. Digite Novamente.\n");
             system("pause");
        }
        switch(num)
        {
            case 1:
                Incluir_Alunos(exe, &iacount, qntd);
                primeiratent=1;
            break;
            case 2:
                if (primeiratent==1)
                {
                    Remover_Alunos(exe, qntd, &iacount, &excluidos);
                }
                else
                {
                    system("cls");
                    printf("\n\n\tERRO! Voce precisa adicionar alguem para usar essa função\n\n");
                    system("pause");
                }
                break;
            case 3:
                if (primeiratent==1)
                {
                    Alterar_Informacoes(exe, &iacount, qntd);
                }
                else
                {
                    system("cls");
                    printf("\n\n\tERRO! Voce precisa adicionar alguem para usar essa função\n\n");
                    system("pause");
                }
                break;
            case 4:
                if (primeiratent==1)
                {
                    Busca_Aluno(exe, qntd, &iacount);
                }
                else
                {
                    system("cls");
                    printf("\n\n\tERRO! Voce precisa adicionar alguem para usar essa função\n\n");
                    system("pause");
                }
                break;
            case 5:
                if (primeiratent==1)
                {
                    Listagem_Tudo(exe, &iacount, qntd);
                }
                else
                {
                    system("cls");
                    printf("\n\n\tERRO! Voce precisa adicionar alguem para usar essa função\n\n");
                    system("pause");
                }
                break;
            case 6:
                if (primeiratent==1)
                {
                    Listagem_Materia(exe, &iacount, qntd);
                }
                else
                {
                    system("cls");
                    printf("\n\n\tERRO! Voce precisa adicionar alguem para usar essa função\n\n");
                    system("pause");
                }
                break;
            case 7:
                do
                {
                    printf("\n\n\tTem certeza que deseja sair do programa? Digite 'S' para sim ou 'N' para não\n\n");
                    scanf(" %c", &escolha);
                    if(toupper(escolha)=='S')
                    {
                        num=7;
                    }
                    else if (toupper(escolha)=='N')
                    {
                        num=0;
                    }
                    else if (toupper(escolha)!='S'&&toupper(escolha)!='N')
                    {
                        system ("cls");
                        printf("\n\n\tEscolha invalida, digite novamente\n\n");
                        system("pause");
                    }
                } while (toupper(escolha)!='S'&&toupper(escolha)!='N');
                break;
        }
    }while(num != 7);

}
