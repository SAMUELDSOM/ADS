/******************************************************************************

Comente sempre que alterar.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#define SIZE 50

char nome[SIZE][200],senha[8][200];
char funcio[60], clint[60], date[60];
char*nome_comp=NULL;
char*tipo_serv=NULL;
float valor;

void cadastro();
void servico();
void cliente();


int main()
{
 setlocale(LC_ALL, "Portuguese");
 int cont = 0;
 int op2 = 0;
 FILE *file;
                    //MENU DE USU√ùRIO
    while (op2 == 0)
    {
    printf("*----------------------------------------------------------------------------------------*\n");
    printf("*------------------------------------AIRcoDe---------------------------------------------*\n");
    printf("*------------------(CADASTRAR UM USU¡RIO = 1)--(FAZER LOGIN = 2)-------------------------*\n");
    printf("\nDIGITE A SUA OP«√O...:");
    scanf("%d", &cont);
    system("cls");

        switch (cont)
        {

         //TELA DE CADASTRO DE USU√ùRIO
         case 1:
         file = fopen("Usuarios", "a");
            if(file == NULL){
             printf("ERROR !! CONTATE O ADIM");
             return 1;
            } 
   
         cadastro(file);//CHAMA A FUN«√O DE CADASTRO DE USU√ùRIO 
        
         fclose(file);
         break; 
     
         case 2:
         file = fopen("Usuarios", "r");
            if(file == NULL){
             printf("ERROR !! CONTATE O ADIM");
             return 1;
            }
         char login[50];
         char login2[20];
         char senha1[20];
         char senha2[20];
         char *retorno;
         int sair = 6;
            
         int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

            printf("DIGITE SEU USU¡RIO..: ");
            scanf("%s", login);                     //TELA DE LOGIN
            printf("DIGITE SUA SENHA..: ");
            scanf("%s", senha1); 
            system("cls");

            while ((fscanf(file, "%s ; %s\n", login2, senha2)) != EOF)//VALIDA«√O DE DADOS
            {
                if (strcmp(login, login2) == 0 && strcmp(senha1, senha2)== 0 && sair == 6){
                 login_efetuado = 1;
                 
                    do
                    {
                        printf("+----------------------------------------+\n");
                        printf("|\t\tMENU INICIAL                |\n");
                        printf("+----------------------------------------+\n");
                        printf("|1 - Cadastrar cliente                   |\n");//Lucas
                        printf("|2 - Cadastrar funcion·rio               |\n");//Kaue
                        printf("|3 - Nova ordem de serviÁo               |\n");//Samuel
                        printf("|4 - RelatÛrios                          |\n");//Samuel e Vieira
                        printf("|0 - Para retornar a tela de login       |\n");
                        printf("+----------------------------------------+\n");
                        printf("\nDIGITE A SUA OP«√O...:");
                        scanf("%d", &sair);
                        system("cls");

                        switch (sair)
                        {
                         case 1:

                            cliente(file);
                            

                            break;
                         case 2:
                            
                            break;
                         case 3:

                            file = fopen("serviÁo.txt", "a");
                            if(file == NULL)
                            {
                                printf("ERROR !! CONTATE O ADIM");
                                return 1;
                            }                               

                                servico(file);

                            
                            fclose(file);

                            char linha[9999];
                            char*resultado;
                            int contador = 0;


                            file = fopen("serviÁo.txt","r");

                            while(!feof(file))
                            {
                                resultado = fgets(linha, 9999, file);
                                if(resultado)
                                {
                                    contador = contador + 1;
                                }
                            }
                            fclose(file);

                                printf("N˙mero da OS: A/%d\n", contador);
                                printf("Nome do funcion·rio: %s\n", funcio);
                                printf("Nome do cliente: %s\n", clint);
                                printf("Componente a ser revisado: %s\n", nome_comp);
                                printf("Tipo de Revis„o: %s\n", tipo_serv);
                                printf("Data de abertura da ORDEM DE SERVI«O: %s\n", date);
                                printf("Valor final a ser pago: %.3f", valor);
                                
                            break;
                         case 4:
                            
                            break;
                        
                         default:
                                printf ("\n--------------------------------------------------------------------------------\n");
                                printf("!OP«√O INV¡LIDA!");
                            break;
                        }
                    } while (sair != 0);
                
                }   
            }

            if (login_efetuado != 1){
             printf("\n\n\tDADOS INVALIDOS!\n");
             printf("CADASTRE-SE OU TENTE NOVAMENTE\n\n");
             system("pause");
             system("cls");
            }
            
         fclose(file);
         break;
         default:
         printf("\t\t!OP«√O INV¡LIDA!\n");
         printf ("\n--------------------------------------------------------------------------------\n");
         system("pause");
         system("cls");
        }
    }
 return 0;
}
//FUN«√O PARA CADASTRO DE USU¡RIOS
void cadastro(FILE *fi)
{
    int opcao;
 
    do
    {
     gets(nome);
     printf("ESCOLHA UM NOME DE USU¡RIO..:\n");
     gets(nome);
     fprintf(fi, "%s ; ", nome);
     system("cls");
     printf("CRIE UMA SENHA..:\n");
     gets(senha);
     fprintf(fi, "%s\n", senha);
     system("cls");
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("*-------------------------CADASTRO CONCLUIDO COM SUCESSO---------------------------------*\n");
     printf("*--------------------(VER DADOS CADASTRADOS = 1)--(SAIR = 2)-----------------------------*\n");
     printf("\nDIGITE A SUA OP«√O...:");
     scanf("%d", &opcao);
     system("cls");
        if (opcao == 1){
            while (opcao == 1)
            {
                printf("*----------------------------------------------------------------------------------------*\n");
                printf("Nome de usu·rio: %s\n", nome);
                printf("Senha: %s\n", senha);
                system("pause");
                system("cls");
                printf("*----------------------------------------------------------------------------------------*\n");
                printf("*--------------------(VER DADOS CADASTRADOS = 1)--(SAIR = 2)-----------------------------*\n");
                printf("*----------------------------------------------------------------------------------------*\n");
                printf("\nDIGITE A SUA OP«√O...:");
                scanf("%d", &opcao);
                system("cls");
            }
        }
    } while (opcao == 0);
}
//FUN«√O PARA ABERTURA DE ORDEM DE SERVI√áO
void servico(FILE *fl)
{
    int comp, tserv;

        gets(clint);
        printf("NOME DO CLIENTE..: \n");
        gets(clint);
        fprintf(fl, "%s ; ", clint);
        system("cls");

        printf("FUNCION¡RIO RESPONSAVEL PELA OS..: \n");
        gets(funcio);
        fprintf(fl, "%s ; ", funcio);
        system("cls");

        while (comp<1 || comp>7)
        {

            printf ("\n--------------------------------------------------------------------------------\n");
            printf("COMPONENTE A SER REVISADO:\n1-Distribuidora\n2-Bomba de combustivel\n3-Dosadora\n4-Carburador\n5-Magneto\n6-Alternador\n7-Motor de partida\n");
            printf ("\n--------------------------------------------------------------------------------\n");
            printf("\nDIGITE A SUA OP«√O...:");
            scanf("%d", &comp);
            system("cls");

            switch (comp)
            {
            case 1:
                nome_comp = "Distribuidora";
                fprintf(fl, "%s ; ", nome_comp);
                printf("O componente escolido foi uma %s.", nome_comp);
                break;
            case 2:
        
                nome_comp = "Bomba de combustivel";
                fprintf(fl, "%s ; ", nome_comp);
                printf("O componente escolido foi uma %s.", nome_comp);
                break;
            case 3:
        
                nome_comp = "Dosadora";
                fprintf(fl, "%s ; ", nome_comp);
                printf("O componente escolido foi uma %s.", nome_comp);
                break;
            case 4:
        
                nome_comp = "Carburador";
                fprintf(fl, "%s ; ", nome_comp);
                printf("O componente escolido foi um %s.", nome_comp);
                break;
            case 5:
        
                nome_comp = "Magneto";
                fprintf(fl, "%s ; ", nome_comp);
                printf("O componente escolido foi um %s.", nome_comp);
                break;
            case 6:
        
                nome_comp = "Alternador";
                fprintf(fl, "%s ; ", nome_comp);
                printf("O componente escolido foi um %s.", nome_comp);
                break; 
            case 7:
        
                nome_comp = "Motor de partida";
                fprintf(fl, "%s ; ", nome_comp);
                printf("O componente escolido foi um %s.", nome_comp);
                break;       
            default:
                printf ("\n--------------------------------------------------------------------------------\n");
                printf("!OP«√O INV¡LIDA!");
            }
            system("cls");
        }

        while (tserv<1 || tserv>4)
        {
            printf ("\n--------------------------------------------------------------------------------\n");
            printf("TIPO DE REVIS√O:\n1-Revis„o geral\n2-Revis„o de 500 horas\n3-Revis„o 100 horas\n4-Revis„o parcial\n");
            printf ("\n--------------------------------------------------------------------------------\n");
            printf("\nDIGITE A SUA OP«√O...:");
            scanf("%d", &tserv);
            system("cls");

            switch (tserv)
            {
            case 1:
                tipo_serv = "Revis„o geral";
                    if (strcmp(nome_comp, "Distribuidora") == 0){
                        valor = 1.800;
                    }
                        if (strcmp(nome_comp, "Bomba de combustivel") == 0){
                            valor = 3.000;
                        }
                            if (strcmp(nome_comp, "Dosadora") == 0){
                                valor = 7.000;
                            }
                                if (strcmp(nome_comp, "Carburador") == 0){
                                    valor = 10.000;
                                }
                            if (strcmp(nome_comp, "Magneto") == 0){
                                valor = 2.200;
                            }
                        if (strcmp(nome_comp, "Alternador") == 0){
                            valor = 2.500;
                        }
                    if (strcmp(nome_comp, "Motor de partida") == 0){
                        valor = 2.300;
                    }
                fprintf(fl, "%s ; ", tipo_serv);
                fprintf(fl, "%.3f\n", valor);         
                printf("O tipo de Revis„o escolida foi uma %s, no valor de %.3f", tipo_serv, valor);
                break;
            case 2:
        
                tipo_serv = "Revis„o_de_500 horas";
                    if (strcmp(nome_comp, "Distribuidora") == 0){
                        valor = 1.200;
                    }
                        if (strcmp(nome_comp, "Bomba de combustivel") == 0){
                            valor = 2.600;
                        }
                            if (strcmp(nome_comp, "Dosadora") == 0){
                                valor = 2.900;
                            }   
                                if (strcmp(nome_comp, "Carburador") == 0){
                                    valor = 5.000;
                                }
                            if (strcmp(nome_comp, "Magneto") == 0){
                                valor = 1.800;
                            }
                        if (strcmp(nome_comp, "Alternador") == 0){
                            valor = 1.750;
                        }
                    if (strcmp(nome_comp, "Motor de partida") == 0){
                        valor = 1.900;
                    } 
                fprintf(fl, "%s ; ", tipo_serv);
                fprintf(fl, "%.3f\n", valor);    
                printf("O tipo de Revis„o escolida foi uma %s, no valor de %.3f", tipo_serv , valor);
                break;
            case 3:
        
                tipo_serv = "Revis„o_100_horas";
                    if (strcmp(nome_comp, "Distribuidora") == 0){
                        valor = 800;
                    }
                        if (strcmp(nome_comp, "Bomba de combustivel") == 0){
                            valor = 2.200;
                        }
                            if (strcmp(nome_comp, "Dosadora") == 0){
                                valor = 2.100;
                            }
                                if (strcmp(nome_comp, "Carburador") == 0){
                                    valor = 3.000;
                                }
                            if (strcmp(nome_comp, "Magneto") == 0){
                                valor = 1.000;
                            }
                        if (strcmp(nome_comp, "Alternador") == 0){
                            valor = 1.475;
                        }
                    if (strcmp(nome_comp, "Motor de partida") == 0){
                        valor = 1.385;
                    } 
                fprintf(fl, "%s ; ", tipo_serv);
                fprintf(fl, "%.3f\n", valor);
                printf("O tipo de Revis„o escolida foi uma %s, no valor de %.3f", tipo_serv , valor);
                break;
            case 4:
        
                tipo_serv = "Revis„o_parcial";
                    if (strcmp(nome_comp, "Distribuidora") == 0){
                        valor = 500;
                    }   
                        if (strcmp(nome_comp, "Bomba de combustivel") == 0){
                            valor = 1.000;
                        }
                            if (strcmp(nome_comp, "Dosadora") == 0){
                                valor = 950;
                            }
                                if (strcmp(nome_comp, "Carburador") == 0){
                                    valor = 1.800;
                                }
                            if (strcmp(nome_comp, "Magneto") == 0){
                                valor = 500;
                            }
                        if (strcmp(nome_comp, "Alternador") == 0){
                            valor = 900;
                        }
                    if (strcmp(nome_comp, "Motor de partida") == 0){
                        valor = 1.100;
                    } 
                fprintf(fl, "%s ; ", tipo_serv);
                fprintf(fl, "%.3f\n", valor);
                printf("O tipo de Revis„o escolida foi uma %s, no valor de %.3f", tipo_serv , valor);
                break;
            default:
                printf ("\n--------------------------------------------------------------------------------\n");
                printf("!OP«√O INV¡LIDA!");
            }
            system("cls");
        }
            gets(date);       
            printf("DATA DE ABERTURA DA ORDEM DE SERVI«O(dd/mm/yyyy):\n");
            gets(date);
            system("cls");
                 
}
//FUN√á√ÉO PARA CADASTRO DE CLIENTES
void cliente(){

    int op; //VARIAVEL SWITCH

      //MENU DE CADASTRO COM VARIAVEL

    printf("*----------------------------------------------------------------------------------------*\n");
    printf("*-----------------------------TELA DE CADASTRO-------------------------------------------*\n");
    printf("*---------------------(CADASTRO CPF = 1)--(CADASTRO CNPJ = 2)----------------------------*\n");
    printf("\nDIGITE A SUA OP«√O...:");

    scanf("%d", &op);


    if(op == 1 ){
        cad_CPF();
    }
    if(op == 2){
       cad_CNPJ();
    }
}



 void cad_CPF(){

    //DECLARACAO DE VARIAVEIS

    char CPF[12][100],nome_cliente[50][100],Contato1[11][50],Contato[12][50],CEP[50][50],mail[50][50],cnpj[14][50];    //* A MAIORIA DAS STRING RECEBEM UMA CASA A MAIS POR CONTA DO \0 OU \n *//
    int VCPF =1; //VARIAVEL WHILE CPF

    FILE *Cadastro_cliente;    //"CADASTRO_CLIENTE" NOME ATRIBUIDO PRA CHAMAR O ARQUIVO

    Cadastro_cliente = fopen("clientes.txt","a");

        if(Cadastro_cliente == NULL){			//CASO NAO ABRA O ARQUIVO APRESENTRAR O "ERROR !! CONTATE O ADIM"
            printf ("ERROR !! CONTATE O ADIM");
            return 1;
        }
            // CADASTRO DE CLIENTE COM CPF
            while(VCPF ==1){
                system("cls");
                printf("*-----------------------------CADASTRO CPF-------------------------------------------*\n");

                gets(CPF);
                printf("\nDIGITE O CPF...:");
                gets(CPF);
                fprintf(Cadastro_cliente,"%s ; ",CPF);
                fflush(stdin); 											  // LIMPAR BUFFER PARA EVITAR TRANSTORNOS

                printf("\nDIGITE O NOME DO CLIENTE...:");
                scanf("%[^\n]s", &nome_cliente);                                                // "[^\n] PERMITE A LEITURA DO ESPA√áO ENTRE OS NOMES. & APONTAMENTO NA MEMORIA.
                fprintf(Cadastro_cliente,"%s ; ",nome_cliente);                                 //NAO APRESENTOU FALHAS EU USEI.
                fflush(stdin);

                printf("\nDIGITE O N⁄MERO DO TELEFONE...:");						 //GRAVACAO DE CONTATO
                gets(Contato1);
                fprintf(Cadastro_cliente,"%s ; ",Contato1); //SEPARACAO POR PONTO E VIRUGLA PARA UM USO FUTURO.
                fflush(stdin);

                printf("\nDIGITE O N⁄MERO DO CELULAR...:");
                gets(Contato);										//GRAVACAO DE CONTATO
                fprintf(Cadastro_cliente,"%s ; ",Contato);
                fflush(stdin);

                printf("\nDIGITE APENAS OS N⁄MEROS DO CEP...:");
                gets(CEP);										     //GRAVACAO CEP
                fprintf(Cadastro_cliente,"%s ; ",CEP);
                fflush(stdin);

                printf("\nDIGITE O E-MAIL...:");
                gets(mail);											//GRAVACAO DO E-MAIL DO CLIENTE
                fprintf(Cadastro_cliente,"%s\n",mail);
                fflush(stdin);

                printf("\nDESEJA CONTINUAR CADASTRANDO ?(SIM -1 / NAO -2) :");			//CASO O USUARIO DESEJE CADASTRAR OUTRO CLIENTE
                scanf("%d",&VCPF);

                system("cls");
                printf("*----------------------------------------------------------------------------------------*\n");
                printf("*-------------------------CADASTRO CONCLUIDO COM SUCESSO---------------------------------*\n");
                printf("*----------------------------------------------------------------------------------------*\n");
                system("pause");
                system("cls");

        fclose(Cadastro_cliente);
        }
    
}

void cad_CNPJ(){

     //DECLARACAO DE VARIAVEIS
     int VCNPJ =1;//VARIAVEL WHILE CNPJ

     int dgcnpj; //VARIAVEL PRESENTE DENTRO WHILE CNPJ

     char CPF[12][100],nome_cliente[50][100],Contato1[11][50],Contato[12][50],CEP[50][50],mail[50][50],cnpj[14][50];

     //char IES [13][50];

     FILE *Cadastro_cliente;


     Cadastro_cliente = fopen("clientes.txt","a");
     if(Cadastro_cliente == NULL){
            printf ("ERROR !! CONTATE O ADIM");
            return 1;
        }
            //CADASTRO DE CLIENTE COM CNPJ
           while(VCNPJ==1){
            system("cls");
            printf("*-----------------------------CADASTRO CNPJ-------------------------------------------*\n");

            fflush(stdin);								// LIMPAR BUFFER PARA EVITAR TRANSTORNOS
            printf("\nDIGITE O CNPJ DO CLIENTE...:");
            gets(cnpj);
            fprintf(Cadastro_cliente, "%s ; " , cnpj);
            fflush(stdin);
            
            printf("\nDIGITE A IDENTIFICAC√O DO CLIENTE....:");
            scanf("%[^\n]s",nome_cliente); 						// "[^\n] PERMITE A LEITURA DO ESPA√áO ENTRE OS NOMES. & APONTAMENTO NA MEMORIA.
            fprintf(Cadastro_cliente,"%s ; ", nome_cliente);
            fflush(stdin);

            printf("\nDIGITE O CEP..:");
            gets(CEP);
            fprintf(Cadastro_cliente,"%s ; ",CEP); 					//CADASTRO DO CEP
            fflush(stdin);

            printf("\nDIGITE O N⁄MERO DO TELEFONE...:");
            gets(Contato1);
            fprintf(Cadastro_cliente,"%s ; ",Contato1); 				//CADASTRO DO TELEFONE
            fflush(stdin);

            printf("\nDIGITE O N⁄MERO DO CELULAR...:");
            gets(Contato);
            fprintf(Cadastro_cliente,"%s ; ",Contato);  					 //CADASTRO DE CELULAR
            fflush(stdin);

            printf("\nDIGITE O E-MAIL...:");
            gets(mail);
            fprintf(Cadastro_cliente,"%s\n",mail);
            fflush(stdin);

            printf("\nDESEJA CONTINUAR CADASTRANDO ?(SIM -1 / NAO -2) :");				//CASO O USUARIO DESEJE CADASTRAR OUTRO CLIENTE
            scanf("%d",&VCNPJ);
            system("cls");
            printf("*----------------------------------------------------------------------------------------*\n");
            printf("*-------------------------CADASTRO CONCLUIDO COM SUCESSO---------------------------------*\n");
            printf("*----------------------------------------------------------------------------------------*\n");
            system("pause");
            system("cls");

      fclose(Cadastro_cliente);

      }
      
}