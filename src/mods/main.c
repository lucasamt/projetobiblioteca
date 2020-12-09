void Incluir_Livro()
{
    // char escolha;
    // int  h, cont, quant;
    // cont = *contador;
    // do
    // {
    //     printf("Digite o seu nome: ");
    //     fflush(stdin);
    //     gets(a[cont].nome);
    //     printf("Digite o seu RA: ");
    //     fflush(stdin);
    //     gets(a[cont].RA);
    //     printf("\nQuantas matérias cursando? ");
    //     scanf("%d", &quant);
    //     for(h=0;h<quant;h++)
    //     {
    //         printf("Digite o nome da disciplina: ");
    //         fflush(stdin);
    //         gets(a[cont].disciplina[h].materia);
    //         printf("Nota 1: ");
    //         scanf("%f", &a[cont].disciplina[h].nota1);
    //         printf("Nota 2: ");
    //         scanf("%f", &a[cont].disciplina[h].nota2);
    //     }
    //     do
    //     {
    //         printf("Voce deseja adicionar mais algum aluno?\nDigite \"S\" para sim ou \"N\" para não: ");
    //         scanf(" %c", &escolha);
    //         if (toupper(escolha) != 'S' && toupper(escolha) != 'N')
    //         {
    //             printf("\nESCOLHA INVÁLIDA!!!\nDigite Novamente...");
    //         }
    //     } while (toupper(escolha) != 'S' && toupper(escolha) != 'N');
    //     quantidade[cont]=quant;
    //     cont++;
    // }while(toupper(escolha)!='N');
    // *contador+=cont;
}

void Remover_Livro()
{
    // char excluir_RA[9], esco;
    // int x, y, z, qtd=0, aux=0, cont=0, num=0;
    // do
    // {
    //     printf("\nDigite o RA: ");
    //     fflush(stdin);
    //     gets(excluir_RA);
    //     for (x=0;x<=*bcont;x++)
    //     {
    //         if(strcmp(excluir_RA, b[x].RA)==0)
    //         {
    //             aux=x;
    //         }
    //     }
    //     if(strcmp(excluir_RA, b[aux].RA)==0)
    //     {
    //         cont=1;
    //         *exc++;
    //         b[aux].nome[0]='\0';
    //         b[aux].RA[0]='\0';
    //         for(x=0;x<quanti[y];x++)
    //         {
    //             b[aux].disciplina[x].materia[0]='\0';
    //             b[y].disciplina[z].nota1=0;
    //             b[y].disciplina[z].nota2=0;
    //         }
    //         do
    //         {
    //             printf("Voce deseja remover mais algum aluno?\nDigite \"S\" para sim ou \"N\" para não: ");
    //             scanf(" %c", &esco);
    //             if (toupper(esco) != 'S' && toupper(esco) != 'N')
    //             {
    //                 printf("\nESCOLHA INVÁLIDA!!!\nDigite Novamente...");
    //             }
    //             else if(toupper(esco) == 'S'){cont=0;}
    //             else if(toupper(esco) == 'N'){cont=1;}
    //
    //         } while (toupper(esco) != 'S' && toupper(esco) != 'N');
    //     }
    //     else
    //     {
    //         printf("\nRA INVÁLIDO!!!\nDigite 0 para digitar novamente ou 1 para voltar ao menu: ");
    //         scanf("%d", &num);
    //         if(num==0){cont=0;}
    //         else if(num==1){cont=1;}
    //     }
    // }while(cont==0);
}

void Emprestar_Livro()
{
    // char ra[10];
    // int x, y, h, aux, contador2, cont, num;
    // float media;
    // cont = *contador;
    // do
    // {
    //     system("cls");
    //     printf("Digite o RA do aluno: ");
    //     fflush(stdin);
    //     gets(ra);
    //     for (x=0;x<=cont;x++)
    //     {
    //         if(strcmp(ra, a[x].RA) == 0)
    //         {
    //             aux=x;
    //         }
    //     }
    //     if(strcmp(ra, a[aux].RA) == 0)
    //     {
    //         contador2=1;
    //         printf("O aluno do RA: %s. De nome: %s.", a[aux].RA, a[aux].nome);
    //         printf("\nQue cursa as disciplinas:\n");
    //         for(y=0;y<quant[aux];y++)
    //         {
    //             media=0;
    //             media = (a[aux].disciplina[y].nota1 + a[aux].disciplina[y].nota2) / 2;
    //             printf("Matéria: %s.\nNota 1: %f.\nNota 2: %f.\nMédia: %.2f.\n", a[aux].disciplina[y].materia, a[aux].disciplina[y].nota1, a[aux].disciplina[y].nota2, media);
    //         }
    //         printf("\n\n\tAlterar informacoes!!!\n");
    //         printf("Digite o novo nome: ");
    //         fflush(stdin);
    //         gets(a[aux].nome);
    //         printf("Digite o novo RA: ");
    //         fflush(stdin);
    //         gets(a[aux].RA);
    //         printf("\nQuantas matérias cursando? ");
    //         scanf("%d", &quant[aux]);
    //         for(h=0;h<quant[aux];h++)
    //         {
    //         printf("Digite o nome da nova disciplina: ");
    //         fflush(stdin);
    //         gets(a[aux].disciplina[h].materia);
    //         printf("Nota 1 alterada: ");
    //         scanf("%f", &a[aux].disciplina[h].nota1);
    //         printf("Nota 2: ");
    //         scanf("%f", &a[aux].disciplina[h].nota2);
    //         }
    //         system("pause");
    //     }
    //     else
    //     {
    //         printf("\nRA INVÁLIDO!!!\nDigite 0 para digitar novamente ou 1 para voltar ao menu: ");
    //         scanf("%d", &num);
    //         if(num==0){contador2=0;}
    //         else if(num==1){contador2=1;}
    //     }
    // }while(contador2==0);
}

void Busca_Livro()
{
    // char ra[9];
    // int x, y, cont, aux, num, contador;
    // float media;
    // cont = *buscacont;
    // do
    // {
    //     system("cls");
    //     printf("Digite o RA do aluno: ");
    //     fflush(stdin);
    //     gets(ra);
    //     for (x=0;x<=cont;x++)
    //     {
    //         if(strcmp(ra, d[x].RA) == 0)
    //         {
    //             aux=x;
    //         }
    //     }
    //     if(strcmp(ra, d[aux].RA) == 0)
    //     {
    //         contador=1;
    //         printf("O aluno do RA: %s De nome: %s", d[aux].RA, d[aux].nome);
    //         printf("\nQue cursa as disciplinas:\n");
    //         for(y=0;y<quant[aux];y++)
    //         {
    //             media=0;
    //             media = (d[aux].disciplina[y].nota1 + d[aux].disciplina[y].nota2) / 2;
    //             printf("Matéria: %s\nNota 1: %.2f\nNota 2: %.2f\nMédia: %.2f\n", d[aux].disciplina[y].materia, d[aux].disciplina[y].nota1, d[aux].disciplina[y].nota2, media);
    //         }
    //         system("pause");
    //     }
    //     else
    //     {
    //         printf("\nRA INVÁLIDO!!!\nDigite 0 para digitar novamente ou 1 para voltar ao menu: ");
    //         scanf("%d", &num);
    //         if(num==0){contador=0;}
    //         else if(num==1){contador=1;}
    //     }
    // }while(contador==0);
}

/*void Listar_Todos_Livros(list c[100], int *contador, int quant[100])
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
}*/

void Incluir_Usuario()
{
    // char escolha;
    // int  h, cont, quant;
    // cont = *contador;
    // do
    // {
    //     printf("Digite o seu nome: ");
    //     fflush(stdin);
    //     gets(a[cont].nome);
    //     printf("Digite o seu RA: ");
    //     fflush(stdin);
    //     gets(a[cont].RA);
    //     printf("\nQuantas matérias cursando? ");
    //     scanf("%d", &quant);
    //     for(h=0;h<quant;h++)
    //     {
    //         printf("Digite o nome da disciplina: ");
    //         fflush(stdin);
    //         gets(a[cont].disciplina[h].materia);
    //         printf("Nota 1: ");
    //         scanf("%f", &a[cont].disciplina[h].nota1);
    //         printf("Nota 2: ");
    //         scanf("%f", &a[cont].disciplina[h].nota2);
    //     }
    //     do
    //     {
    //         printf("Voce deseja adicionar mais algum aluno?\nDigite \"S\" para sim ou \"N\" para não: ");
    //         scanf(" %c", &escolha);
    //         if (toupper(escolha) != 'S' && toupper(escolha) != 'N')
    //         {
    //             printf("\nESCOLHA INVÁLIDA!!!\nDigite Novamente...");
    //         }
    //     } while (toupper(escolha) != 'S' && toupper(escolha) != 'N');
    //     quantidade[cont]=quant;
    //     cont++;
    // }while(toupper(escolha)!='N');
    // *contador+=cont;
}

void Remover_Usuario()
{
    // char excluir_RA[9], esco;
    // int x, y, z, qtd=0, aux=0, cont=0, num=0;
    // do
    // {
    //     printf("\nDigite o RA: ");
    //     fflush(stdin);
    //     gets(excluir_RA);
    //     for (x=0;x<=*bcont;x++)
    //     {
    //         if(strcmp(excluir_RA, b[x].RA)==0)
    //         {
    //             aux=x;
    //         }
    //     }
    //     if(strcmp(excluir_RA, b[aux].RA)==0)
    //     {
    //         cont=1;
    //         *exc++;
    //         b[aux].nome[0]='\0';
    //         b[aux].RA[0]='\0';
    //         for(x=0;x<quanti[y];x++)
    //         {
    //             b[aux].disciplina[x].materia[0]='\0';
    //             b[y].disciplina[z].nota1=0;
    //             b[y].disciplina[z].nota2=0;
    //         }
    //         do
    //         {
    //             printf("Voce deseja remover mais algum aluno?\nDigite \"S\" para sim ou \"N\" para não: ");
    //             scanf(" %c", &esco);
    //             if (toupper(esco) != 'S' && toupper(esco) != 'N')
    //             {
    //                 printf("\nESCOLHA INVÁLIDA!!!\nDigite Novamente...");
    //             }
    //             else if(toupper(esco) == 'S'){cont=0;}
    //             else if(toupper(esco) == 'N'){cont=1;}
    //
    //         } while (toupper(esco) != 'S' && toupper(esco) != 'N');
    //     }
    //     else
    //     {
    //         printf("\nRA INVÁLIDO!!!\nDigite 0 para digitar novamente ou 1 para voltar ao menu: ");
    //         scanf("%d", &num);
    //         if(num==0){cont=0;}
    //         else if(num==1){cont=1;}
    //     }
    // }while(cont==0);
}

void Alterar_Usuario()
{
    // char excluir_RA[9], esco;
    // int x, y, z, qtd=0, aux=0, cont=0, num=0;
    // do
    // {
    //     printf("\nDigite o RA: ");
    //     fflush(stdin);
    //     gets(excluir_RA);
    //     for (x=0;x<=*bcont;x++)
    //     {
    //         if(strcmp(excluir_RA, b[x].RA)==0)
    //         {
    //             aux=x;
    //         }
    //     }
    //     if(strcmp(excluir_RA, b[aux].RA)==0)
    //     {
    //         cont=1;
    //         *exc++;
    //         b[aux].nome[0]='\0';
    //         b[aux].RA[0]='\0';
    //         for(x=0;x<quanti[y];x++)
    //         {
    //             b[aux].disciplina[x].materia[0]='\0';
    //             b[y].disciplina[z].nota1=0;
    //             b[y].disciplina[z].nota2=0;
    //         }
    //         do
    //         {
    //             printf("Voce deseja remover mais algum aluno?\nDigite \"S\" para sim ou \"N\" para não: ");
    //             scanf(" %c", &esco);
    //             if (toupper(esco) != 'S' && toupper(esco) != 'N')
    //             {
    //                 printf("\nESCOLHA INVÁLIDA!!!\nDigite Novamente...");
    //             }
    //             else if(toupper(esco) == 'S'){cont=0;}
    //             else if(toupper(esco) == 'N'){cont=1;}
    //
    //         } while (toupper(esco) != 'S' && toupper(esco) != 'N');
    //     }
    //     else
    //     {
    //         printf("\nRA INVÁLIDO!!!\nDigite 0 para digitar novamente ou 1 para voltar ao menu: ");
    //         scanf("%d", &num);
    //         if(num==0){cont=0;}
    //         else if(num==1){cont=1;}
    //     }
    // }while(cont==0);
}

// Listar Usuário?

void menu()
{
    setlocale(LC_ALL, "portuguese");
    int num;


    do
    {
        num=0;
        system("cls");

        // Dividir menu?

        printf("Bem vindo ao Sistema de Biblioteca!\n");
        printf("1 - Incluir Livro\n");
        printf("2 - Remover Livro\n");
        printf("3 - Emprestar Livro\n");
        printf("4 - Buscar Livros\n");
        printf("5 - Incluir Usuário\n");
        printf("6 - Remover Usuário\n");
        printf("7 - Alterar Usuário\n");
        printf("8 - Sair.\n");
        printf("Escolha um dos números acima: ");
        scanf("%d", &num);

        switch(num)
        {
            case 1: Incluir_Livro();
                break;
            case 2: Remover_Livro();
                break;
            case 3: Emprestar_Livro();
                break;
            case 4: Busca_Livro();
                break;
            case 5: Incluir_Usuario();
                break;
            case 6: Remover_Usuario();
                break;
            case 7: Alterar_Usuario();
                break;
            case 8: exit(0);
                break;
            default:
                printf("\n\nNúmero Inválido. Digite Novamente.\n");
                system("pause");
        }
    }while(num != 8);

}
