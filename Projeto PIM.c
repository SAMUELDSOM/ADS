/******************************************************************************

Comente sempre que alterar.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 50

char nome[SIZE][200], cpf[11][200], fone[SIZE][200], linha[SIZE][200], cnpj[14][200], senha[8][200];

void cadastro();
void componente();

int main()
{
 int cont = 0;
 int op2 = 0;
 FILE *file;

    while (op2 == 0)
    {
        printf("\n\tINVESTIMENTOS SSC\n\n");
        printf("Digite 1 para cadastrar um usuario:\n");
        printf("Digite 2 se já tem cadastro:\n");
        scanf("%d", &cont);
        system("cls");

        switch (cont)
        {

         /*Tela de cadastro*/
         case 1:
         file = fopen("Usuarios", "a");
            if(file == NULL){
             printf("não deu mermão");
             return 1;
            } 
   
         cadastro(file);//Chama a função de cadastro de usuário 
        
         fclose(file);
         break; 
     
         //Tela de login
         case 2:
         file = fopen("Usuarios", "r");
            if(file == NULL){
             printf("não deu mermão");
             return 1;
            }
         char linha[50];
         char usua[20];
         char login[50];
         char login2[20];
         char senha1[20];
         char senha2[20];
         char *retorno;
            
         int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

            printf("Digite o Login:\n");
            scanf("%s", login);
            printf("Digite a Senha:\n");
            scanf("%s", senha1); 
            system("cls");

            while ((fscanf(file, "%s ; %s\n", login2, senha2)) != EOF)//Comparando dados do arquivo "Usuarios.txt" com os dados de entrada
            {
                if (strcmp(login, login2) == 0 && strcmp(senha1, senha2)== 0){
                 printf("\n\n\t%s LOGADO!\n\n", login2);
                 login_efetuado = 1;
                 int sair = 1;
                    do
                    {
                        printf("\n\tMENU INICIAL\n\n");
                        printf("Cadastrar cliente (digite 1)\n");//Lucas
                        printf("Cadastrar funcionario (digite 2)\n");//Kaue
                        printf("");//Samuel
                        printf("Relatorios(digite 4)\n");//Samuel e Vieira
                        scanf("%d", &sair);

                        switch (sair)
                        {
                         case 1:
                            //Lucas
                            break;
                         case 2:
                            //Kaue
                            break;
                         case 3:
                            //Samuel
                            break;
                         case 4:
                            //Samuel e Vieira
                            break;
                        
                         default:
                            break;
                        }
                    } while (sair != 0);
                    
                 /*O restante do codigo será desenvolvido dentro deste IF, pois somente dentro dele
                 é possivel a validação dos dados de login*/
                }   
            }

            if (login_efetuado != 1){
             printf("\n\n\tDADOS INVALIDOS!\n");
             printf("CADASTRE-SE OU TENTE NOVAMENTE\n\n");
            }
        
         fclose(file);
         break;
        }
    }
 return 0;
}
//Função para cadastro de usuário
void cadastro(FILE *fi)
{
    int opcao;
 
    do
    {
     gets(nome);
     printf("Escolha um nome de usuario:\n");
     gets(nome);
     fprintf(fi, "%s ; ", nome);
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("Crie uma senha(com 8 digitos):\n");
     gets(senha);
     fprintf(fi, "%s\n", senha);
     system("cls");
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("Cadastro executado com sucesso...\n");
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("Digite 1 para ver seus dados de cadastro.\nDigite 2 para sair.\n");
     scanf("%d", &opcao);
     system("cls");
        if (opcao == 1){
            while (opcao == 1)
            {
                printf("Nome de usuario: %s\n", nome);
                printf("Senha: %s\n", senha);
                printf("*----------------------------------------------------------------------------------------*\n");
                printf(".\nDigite 1 para ver seu cadastro.\nDigite 2 para sair.\n");
                scanf("%d", &opcao);
                system("cls");
            }
        }
    } while (opcao == 0);
}

void componente(FILE *fi)
{
    int opcao;
 
    do
    {
     gets(nome);
     printf("Escolha um nome de usuario:\n");
     gets(nome);
     fprintf(fi, "%s ; ", nome);
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("Crie uma senha(com 8 digitos):\n");
     gets(senha);
     fprintf(fi, "%s\n", senha);
     system("cls");
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("Cadastro executado com sucesso...\n");
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("Digite 1 para ver seus dados de cadastro.\nDigite 2 para sair.\n");
     scanf("%d", &opcao);
     system("cls");
        if (opcao == 1){
            while (opcao == 1)
            {
                printf("Nome de usuario: %s\n", nome);
                printf("Senha: %s\n", senha);
                printf("*----------------------------------------------------------------------------------------*\n");
                printf(".\nDigite 1 para ver seu cadastro.\nDigite 2 para sair.\n");
                scanf("%d", &opcao);
                system("cls");
            }
        }
    } while (opcao == 0);
}