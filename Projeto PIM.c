/******************************************************************************

Comente sempre que alterar.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 50

char nome[SIZE][200],senha[8][200];

void cadastro();
void servico();

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
                        printf("Nova ordem de serviço (digite 3)\n");//Samuel
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
                            file = fopen("serviço.txt", "a");
                            if(file == NULL){
                            printf("não deu mermão");
                            return 1;
                            } 

                            servico(file);

                            fclose(file);

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

void servico(FILE *fl)
{
    char funcio[60], clint[60];
    char*nome_comp=NULL;
    char*tipo_serv=NULL;
    int comp, tserv;
    float valor;

        gets(funcio);
        printf("\nFuncionário responsável pela OS: \n");
        gets(funcio);
        fprintf(fl, "%s ; ", funcio);
        //Necessaria base de funcionarios

        printf("\nCliente: \n");
        gets(clint);
        fprintf(fl, "%s ; ", clint);
        //Necessaria base de clientes

        printf ("\n--------------------------------------------------------------------------------\n");
        printf("Componente a ser revisado:\n1-Distribuidora\n2-Bomba_de_combustivel\n3-Dosadora\n4-Carburador\n5-Magneto\n6-Alternador\n7-Motor_de_partida\n");
        scanf("%d", &comp);
        printf ("\n--------------------------------------------------------------------------------\n");

        switch (comp)
        {
        case 1:
            nome_comp = "Distribuidora";
            fprintf(fl, "%s ; ", nome_comp);
            printf("O componente escolido foi uma %s.", nome_comp);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;
        case 2:
        
            nome_comp = "Bomba_de_combustivel";
            fprintf(fl, "%s ; ", nome_comp);
            printf("O componente escolido foi uma %s.", nome_comp);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;
        case 3:
        
            nome_comp = "Dosadora";
            fprintf(fl, "%s ; ", nome_comp);
            printf("O componente escolido foi uma %s.", nome_comp);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;
        case 4:
        
            nome_comp = "Carburador";
            fprintf(fl, "%s ; ", nome_comp);
            printf("O componente escolido foi um %s.", nome_comp);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;
        case 5:
        
            nome_comp = "Magneto";
            fprintf(fl, "%s ; ", nome_comp);
            printf("O componente escolido foi um %s.", nome_comp);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;
        case 6:
        
            nome_comp = "Alternador";
            fprintf(fl, "%s ; ", nome_comp);
            printf("O componente escolido foi um %s.", nome_comp);
            printf ("\n--------------------------------------------------------------------------------\n");
            break; 
        case 7:
        
            nome_comp = "Motor_de_partida";
            fprintf(fl, "%s ; ", nome_comp);
            printf("O componente escolido foi um %s.", nome_comp);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;       
        default:
        printf("!Componente inválido!");
        printf ("\n--------------------------------------------------------------------------------\n");
        }

        printf("Tipo de revisao:\n1-Revisão geral\n2-Revisao de 500 horas\n3-Revisao 100 horas\n4-Revisao parcial\n");
        scanf("%d", &tserv);
        printf ("\n--------------------------------------------------------------------------------\n");

        switch (tserv)
        {
        case 1:
            tipo_serv = "Revisão_geral";
                if (strcmp(nome_comp, "Distribuidora") == 0){
                    valor = 1.800;
                }
                    if (strcmp(nome_comp, "Bomba_de_combustivel") == 0){
                        valor = 1.800;
                    }
                        if (strcmp(nome_comp, "Dosadora") == 0){
                            valor = 1.800;
                        }
                            if (strcmp(nome_comp, "Carburador") == 0){
                                valor = 1.800;
                            }
                        if (strcmp(nome_comp, "Magneto") == 0){
                            valor = 1.800;
                        }
                    if (strcmp(nome_comp, "Alternador") == 0){
                        valor = 1.800;
                    }
                if (strcmp(nome_comp, "Motor_de_partida") == 0){
                    valor = 1.800;
                }
            /*fprintf(fl, "%s ; ", tipo_serv);
            fprintf(fl, "%s\n", valor);*/         
            printf("O tipo de revisão escolida foi uma %s, no valor de %.3f.", tipo_serv, valor);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;
        case 2:
        
            tipo_serv = "Revisao_de_500 horas";
                if (strcmp(nome_comp, "Distribuidora") == 0){
                    valor = 1.800;
                }
                    if (strcmp(nome_comp, "Bomba_de_combustivel") == 0){
                        valor = 1.800;
                    }
                        if (strcmp(nome_comp, "Dosadora") == 0){
                            valor = 1.800;
                        }
                            if (strcmp(nome_comp, "Carburador") == 0){
                                valor = 1.800;
                            }
                        if (strcmp(nome_comp, "Magneto") == 0){
                            valor = 1.800;
                        }
                    if (strcmp(nome_comp, "Alternador") == 0){
                        valor = 1.800;
                    }
                if (strcmp(nome_comp, "Motor_de_partida") == 0){
                    valor = 1.800;
                } 
            fprintf(fl, "%s ; ", tipo_serv);
            fprintf(fl, "%s\n", valor);    
            printf("O tipo de revisão escolida foi uma %s, no valor de %.3f.", tipo_serv , valor);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;
        case 3:
        
            tipo_serv = "Revisao_100_horas";
                if (strcmp(nome_comp, "Distribuidora") == 0){
                    valor = 1.800;
                }
                    if (strcmp(nome_comp, "Bomba_de_combustivel") == 0){
                        valor = 1.800;
                    }
                        if (strcmp(nome_comp, "Dosadora") == 0){
                            valor = 1.800;
                        }
                            if (strcmp(nome_comp, "Carburador") == 0){
                                valor = 1.800;
                            }
                        if (strcmp(nome_comp, "Magneto") == 0){
                            valor = 1.800;
                        }
                    if (strcmp(nome_comp, "Alternador") == 0){
                        valor = 1.800;
                    }
                if (strcmp(nome_comp, "Motor_de_partida") == 0){
                    valor = 1.800;
                } 
            fprintf(fl, "%s ; ", tipo_serv);
            fprintf(fl, "%s\n", valor);
            printf("O tipo de revisão escolida foi uma %s, no valor de %.3f.", tipo_serv , valor);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;
        case 4:
        
            tipo_serv = "Revisao_parcial";
                if (strcmp(nome_comp, "Distribuidora") == 0){
                    valor = 1.800;
                }
                    if (strcmp(nome_comp, "Bomba_de_combustivel") == 0){
                        valor = 1.800;
                    }
                        if (strcmp(nome_comp, "Dosadora") == 0){
                            valor = 1.800;
                        }
                            if (strcmp(nome_comp, "Carburador") == 0){
                                valor = 1.800;
                            }
                        if (strcmp(nome_comp, "Magneto") == 0){
                            valor = 1.800;
                        }
                    if (strcmp(nome_comp, "Alternador") == 0){
                        valor = 1.800;
                    }
                if (strcmp(nome_comp, "Motor_de_partida") == 0){
                    valor = 1.800;
                } 
            fprintf(fl, "%s ; ", tipo_serv);
            fprintf(fl, "%s\n", valor);
            printf("O tipo de revisão escolida foi uma %s, no valor de %.3f.", tipo_serv , valor);
            printf ("\n--------------------------------------------------------------------------------\n");
            break;
        
        }    
}