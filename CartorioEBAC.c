#include <stdio.h> //Biblioteca comunicação usuário
#include <stdlib.h> //Biblioteca alocação espaço em memória
#include <locale.H> //Biblioteca região do texto 
#include <string.h> //Biboteca das string

int registro() //Função responsável por cadastrar usuários no sistema
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    //Começo da criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Fim da criçaõ de variáveis/string 

    printf("digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); //"%s" refere-se a string

    strcpy(arquivo, cpf); //Copia os valores das string

    FILE *file; //Localiza o arquivo
    file = fopen(arquivo, "w"); //Cria um arquivo e escreve nele
    fprintf(file, cpf); //Salva o valor da variável
    fclose(file); //Fecha o arquivo

    file = fopen(arquivo, "a"); //Atualiza o arquivo
    fprintf(file, ","); //Adiciona o que tiver entre aspas
    fclose(file); //Fecha o arquivo

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, " "); //Adiciona um espaço no arquivo
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
   scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause"); //Pausa o sistema

}

int consulta() //Função responsável por cunsultar usuários no sistema 
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r"); //Abre e lê o arquivo

    if(file == NULL) //Responsável para mandar uma mensagem caso o nome do arquivo(no caso o cpf) não for encontrado
    {
        printf("Este CPF não está cadastrado!.\n");
    }

    while (fgets(conteudo, 200, file) != NULL) //Ler enquanto tiver algo no arquivo, no máximo 200 caracteres //while = enquanto //fgats() lê o arquivo
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo); 
        printf("\n\n");
    }
    
    system("pause");

}

int deletar() //Função responsável por deletar usuários do sistema
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    fclose(file);
    
    if (file == NULL)
    {
        printf("CPF não encontrado!\n");
        system("pause");
    }

      if (file != NULL)
    {
        remove(cpf);
        printf("CPF deletado com sucesso!\n");
        system("pause");
    }

}


int main()
{

    int opcao=0; //Definção de variável
    int laco=1;

    for (laco = 1;laco = 1;) //Repetir código
    {    

        system("cls"); 
    
        setlocale(LC_ALL, "Portuguese_Brazil"); //Definição de linguagem

        printf("\tCartório da EBAC\n\n"); //Começo do menu
        printf("Escolha a opção desejada no menu:\n\n");
        printf("\t1 - Registrar nome\n");
        printf("\t2 - Consultar nome\n");
        printf("\t3 - Deletar nome\n\n"); 
        printf("opção: "); //Fim do menu

        scanf("%d", &opcao); //Armazena a opção do usuário 

        system("cls"); //Limpar programa

        switch(opcao)
        {
            case 1:
            registro();
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            default:
            printf("Opição indisponível!\n");
            system("pause");

        } //Fim da seleção

    } //Fim da repetição

}