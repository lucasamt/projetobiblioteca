void Cadastrar_Livro(FILE* mc)
{

    Livro cadastro;

    printf ("\nNome...............: ");
    fflush(stdin);
    gets(Livro.nome);
    printf ("\nAutor..............: ");
    flush(stdin);
    gets(Livro.nome_Autor);
    printf ("Data de publicação...: ");
    fflush(stdin);
    gets(Livro.data_Publicacao);
    fseek  (mc, 0, SEEK_END);
    fwrite (&cadastro, sizeof(cadastro), 1, mc);
}

void Remover_Livro(FILE* mc)
{
    int idLivro;
    unsigned int posicao, qtd=qtdLivros();
    Livro livro

    if (qtd == 0)
        printf ("\nNao ha livros cadastrados!\n\n");
    else
    {
        printf ("\nID.......: ");
        scanf("%d", &idLivro);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc,posicao*sizeof(Livro),SEEK_SET);
            fread (&contato, sizeof(Livro), 1, mc);

            if (livro.id == 0)
            {
                printf ("\ne-mail.....: %s", livro.id);
                printf ("Aniversario: %s", livro.nome_Livro);
                printf ("\nEndereco...: %s", livro.nome_Autor);
                printf ("\nTelefone...: %s", livro.data_Publicacao);
                printf ("\nCelular....: %s", livro.emprestado_por);

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

void Emprestar_Livro()
{
    char nome [31];
    unsigned int posicao, qtd=qtdLivros(mc);
    Livro livro;

    if (qtd == 0)
        printf ("\nLivro esta emprestado!\n\n");
    else
    {
        printf ("\nLivro.......: ");
        gets   (livro);

        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(Livro), SEEK_SET);
            fread (&Livro, sizeof(Livro), 1, mc);

            if (strcmp(nome,Livro.nome) == 0)
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
             printf ("Livro nao encontrado!\n\n");
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

void Busca_Livro(FILE* mc)
{
  char nome_Livro[T];
  unsigned int posicao, qtd=qtosContatos(mc);
  Livro cadastrar;

  if (qtd == 0)
      printf ("\nAgenda vazia!\n\n");
  else
  {
      printf ("\nNome do Livro: ");
      fflush(stdin);
      gets(nome_Livro);

      for (posicao=0; posicao<qtd; posicao++)
      {
          fseek (mc, posicao*sizeof(cadastrar), SEEK_SET);
          fread (&cadastrar, sizeof(cadastrar), 1, mc);

          if (strcmp(nome_Livro,contato.nome_Livro) == 0)
          {
              system("cls");
              printf("Nome do Livro.: %s", Livro.nome_Livro);
              printf("Autor do Livro: %s", Livro.nome_Autor);
              if(Emprestar_Livro==0)
              {
               printf("O Livro esta disponivel\n");
              }
              else
              {
               printf("O livro esta emprestado\n");
              }
              return;
          }
      }

      printf ("Contato nao encontrado!\n\n");
  }
}

void Listar_Todos_Livros(FILE* mc)
{
    unsigned int posicao, qtd=qtosContatos(mc);
    Livro cadastro;

    if (qtd == 0)
        printf ("\nAgenda vazia!\n\n");
    else
        for (posicao=0; posicao<qtd; posicao++)
        {
            fseek (mc, posicao*sizeof(cadastro), SEEK_SET);
            fread (&cadastro, sizeof(cadastro), 1, mc);

            printf("Nome do Livro: %s", );
        }
}

void Incluir_Usuario(FILE* )
{
  Usuario incluir;

  printf ("\nNome do Aluno: ");
  fflush(stdin);
  gets(Usuario.nome_Aluno);
  printf ("\nRA...........: ");
  flush(stdin);
  gets(Usuario.ra);
  fseek  (mc, 0, SEEK_END);
  fwrite (&incluir, sizeof(incluir), 1, mc);
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

unsigned int qtdLivros (FILE* mc)
{
    ftruncate(mc);
    return filesize(mc)/sizeof(Livro);
}
unsigned int qtdUsuarios (FILE* mc)
{
    ftruncate(mc);
    return filesize(mc)/sizeof(Usuario);
}

void menu()
{
    FILE* LivrosDados;
    FILE* UsuariosDados;

    LivrosDados = fopen ("LivrosDados.dados", "rb+");
    if (LivrosDados==NULL)
        LivrosDados = fopen ("LivrosDados.dados", "wb+");

    UsuariosDados = fopen ("UsuariosDados.dados", "rb+");
    if (UsuariosDados==NULL)
        UsuariosDados = fopen ("UsuariosDados.dados", "wb+");


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
            case 1: Cadastrar_Livro(LivrosDados);
                break;
            case 2: Remover_Livro(LivrosDados);
                break;
            case 3: Emprestar_Livro(LivrosDados);
                break;
            case 4: Busca_Livro(LivrosDados);
                break;
            case 5: Incluir_Usuario(UsuariosDados);
                break;
            case 6: Remover_Usuario(UsuariosDados);
                break;
            case 7: Alterar_Usuario(UsuariosDados);
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
