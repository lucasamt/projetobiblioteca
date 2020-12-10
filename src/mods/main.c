void Cadastrar_Livro(Livro l[T], int *qtd_livros)
// void Cadastrar_Livro(FILE* mc)
{

    // Contato contato;
    //
    // printf ("\nNome.......: ");
    // gets   (contato.nome);
    // printf ("Aniversario: ");
    // gets   (contato.aniversario);
    // printf ("Endereco...: ");
    // gets   (contato.endereco);
    // printf ("Telefone...: ");
    // gets   (contato.telefone);
    // printf ("Celular....: ");
    // gets   (contato.celular);
    // printf ("e-mail.....: ");
    // gets   (contato.email);
    // printf ("skype......: ");
    // gets   (contato.skype);
    //
    // fseek  (mc, 0, SEEK_END);
    // fwrite (&contato, sizeof(Contato), 1, mc);
    //
    int contador_Livro = *qtd_livros;
    char escolha;
     do
     {
         printf("Digite o nome do livro: ");
         fflush(stdin);
         gets(l[contador_Livro].nome_Livro);
         printf("Digite o seu autor: ");
         fflush(stdin);
         gets(l[contador_Livro].nome_Autor);
         printf("Digite sua data de publicação: ");
         fflush(stdin);
         gets(l[contador_Livro].data_Publicacao);
         do
         {
             printf("Voce deseja adicionar mais livros?\n\"S\" ou \"N\":");
             scanf(" %c", &escolha);
             if (toupper(escolha) != 'S' && toupper(escolha) != 'N')
             {
                 printf("\nESCOLHA INVÁLIDA!!!\nDigite Novamente...");
             }
         } while (toupper(escolha) != 'S' && toupper(escolha) != 'N');
         contador_Livro++;
     }while(toupper(escolha)!='N');
     *qtd_livros+=contador_Livro;
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
    // char nome [31];
    // unsigned int posicao, qtd=qtosContatos(mc);
    // Contato contato;
    //
    // if (qtd == 0)
    //     printf ("\nAgenda vazia!\n\n");
    // else
    // {
    //     printf ("\nNome.......: ");
    //     gets   (nome);
    //
    //     for (posicao=0; posicao<qtd; posicao++)
    //     {
    //         fseek (mc, posicao*sizeof(Contato), SEEK_SET);
    //         fread (&contato, sizeof(Contato), 1, mc);
    //
    //         if (strcmp(nome,contato.nome) == 0)
    //         {
    //             printf ("Aniversario: %s", contato.aniversario);
    //             printf ("\nEndereco...: %s", contato.endereco);
    //             printf ("\nTelefone...: %s", contato.telefone);
    //             printf ("\nCelular....: %s", contato.celular);
    //             printf ("\ne-mail.....: %s", contato.email);
    //             printf ("\nskype......: %s\n", contato.skype);
    //
    //             break;
    //         }
    //     }
    //
    //     if (posicao==qtd)
    //         printf ("Contato nao encontrado!\n\n");
    //     else
    //     {
    //         printf ("\nNovo Nome.......: ");
    //         gets   (contato.nome);
    //         printf ("Novo Aniversario: ");
    //         gets   (contato.aniversario);
    //         printf ("Novo Endereco...: ");
    //         gets   (contato.endereco);
    //         printf ("Novo Telefone...: ");
    //         gets   (contato.telefone);
    //         printf ("Novo Celular....: ");
    //         gets   (contato.celular);
    //         printf ("Novo e-mail.....: ");
    //         gets   (contato.email);
    //         printf ("Novo skype......: ");
    //         gets   (contato.skype);
    //
    //         fseek (mc, -sizeof(Contato), SEEK_CUR);
    //         fwrite (&contato, sizeof(Contato), 1, mc);
    //     }
    // }
}

void Busca_Livro()
{
    // char nome [31];
    // unsigned int posicao, qtd=qtosContatos(mc);
    // Contato contato;
    //
    // if (qtd == 0)
    //     printf ("\nAgenda vazia!\n\n");
    // else
    // {
    //     printf ("\nNome.......: ");
    //     gets   (nome);
    //
    //     for (posicao=0; posicao<qtd; posicao++)
    //     {
    //         fseek (mc, posicao*sizeof(Contato), SEEK_SET);
    //         fread (&contato, sizeof(Contato), 1, mc);
    //
    //         if (strcmp(nome,contato.nome) == 0)
    //         {
    //             printf ("Aniversario: %s", contato.aniversario);
    //             printf ("\nEndereco...: %s", contato.endereco);
    //             printf ("\nTelefone...: %s", contato.telefone);
    //             printf ("\nCelular....: %s", contato.celular);
    //             printf ("\ne-mail.....: %s", contato.email);
    //             printf ("\nskype......: %s\n", contato.skype);
    //
    //             return;
    //         }
    //     }
    //
    //     printf ("Contato nao encontrado!\n\n");
    // }
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
    Livro l[T]; //criação de um vetor para armazenar as informações sobre o livro a partir da typedef
    Usuario u[T]; //criação de um vetor para armazenar as informações sobre o usuario a partir da typedef
    int num, qtd_livros = 0;
    do
    {
        num=0;
        system("cls");

        // Dividir menu?

        printf("Bem vindo ao Sistema de Biblioteca!\n");
        printf("1 - Cadastrar Livro\n");
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
            case 1: Cadastrar_Livro(l[T], &qtd_livros);
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
