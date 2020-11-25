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
