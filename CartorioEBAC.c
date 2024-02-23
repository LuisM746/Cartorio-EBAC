#include <stdio.h> //Biblioteca comunica��o usu�rio
#include <stdlib.h> //Biblioteca aloca��o espa�o em mem�ria
#include <locale.H> //Biblioteca regi�o do texto 
#include <string.h> //Biboteca das string

int registro() //Fun��o respons�vel por cadastrar usu�rios no sistema
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    //Come�o da cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Fim da cri�a� de vari�veis/string 

    printf("digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); //"%s" refere-se a string

    strcpy(arquivo, cpf); //Copia os valores das string

    FILE *file; //Localiza o arquivo
    file = fopen(arquivo, "w"); //Cria um arquivo e escreve nele
    fprintf(file, cpf); //Salva o valor da vari�vel
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
    fprintf(file, " "); //Adiciona um espa�o no arquivo
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

int consulta() //Fun��o respons�vel por cunsultar usu�rios no sistema 
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r"); //Abre e l� o arquivo

    if(file == NULL) //Respons�vel para mandar uma mensagem caso o nome do arquivo(no caso o cpf) n�o for encontrado
    {
        printf("Este CPF n�o est� cadastrado!.\n");
    }

    while (fgets(conteudo, 200, file) != NULL) //Ler enquanto tiver algo no arquivo, no m�ximo 200 caracteres //while = enquanto //fgats() l� o arquivo
    {
        printf("\nEssas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo); 
        printf("\n\n");
    }
    
    system("pause");

}

int deletar() //Fun��o respons�vel por deletar usu�rios do sistema
{
    char cpf[40];

    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    fclose(file);
    
    if (file == NULL)
    {
        printf("CPF n�o encontrado!\n");
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

    int opcao=0; //Defin��o de vari�vel
    int laco=1;

    for (laco = 1;laco = 1;) //Repetir c�digo
    {    

        system("cls"); 
    
        setlocale(LC_ALL, "Portuguese_Brazil"); //Defini��o de linguagem

        printf("\tCart�rio da EBAC\n\n"); //Come�o do menu
        printf("Escolha a op��o desejada no menu:\n\n");
        printf("\t1 - Registrar nome\n");
        printf("\t2 - Consultar nome\n");
        printf("\t3 - Deletar nome\n\n"); 
        printf("op��o: "); //Fim do menu

        scanf("%d", &opcao); //Armazena a op��o do usu�rio 

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
            printf("Opi��o indispon�vel!\n");
            system("pause");

        } //Fim da sele��o

    } //Fim da repeti��o

}