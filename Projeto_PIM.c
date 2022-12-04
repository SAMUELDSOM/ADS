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

int funcionarios();
void cadastro();
void servico();
void cliente();         //FUNÇÕES UTILIZADAS NO CÓDIGO
void relatorioc();
void relatoriof();
void relatorios();


int main()
{
 setlocale(LC_ALL, "Portuguese");
 int cont = 0;
 int op2 = 0;
 FILE *file;
                    //MENU DE USUÁRIO
    while (op2 == 0)
    {
    printf("*----------------------------------------------------------------------------------------*\n");
    printf("*------------------------------------AIRcoDe---------------------------------------------*\n");
    printf("*------------------(CADASTRAR UM USUÁRIO = 1)--(FAZER LOGIN = 2)-------------------------*\n");
    printf("\nDIGITE A SUA OPÇÃO...:");
    scanf("%d", &cont);
    system("cls");

        switch (cont)
        {

         //TELA DE CADASTRO DE USUÁRIO
         case 1:
         file = fopen("Usuarios", "a");
            if(file == NULL){
             printf("ERROR !! CONTATE O ADIM");
             return 1;
            } 
   
         cadastro(file);//CHAMA A FUNÇÃO DE CADASTRO DE USUÁRIO 
        
         fclose(file);
         break; 
         //TELA DE LOGIN
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
         int login_efetuado = 0; 

            printf("DIGITE SEU USUÁRIO..: ");
            scanf("%s", login);
            system("cls");                     
            printf("DIGITE SUA SENHA..: ");
            scanf("%s", senha1); 
            system("cls");

            while ((fscanf(file, "%s ; %s\n", login2, senha2)) != EOF)//VALIDAÇÃO DE DADOS
            {
                if (strcmp(login, login2) == 0 && strcmp(senha1, senha2)== 0 && sair == 6){
                 login_efetuado = 1;
                 
                    do
                    {
                        printf("+----------------------------------------+\n");
                        printf("|\t\tMENU INICIAL             |\n");
                        printf("+----------------------------------------+\n");
                        printf("|1 - Cadastrar cliente                   |\n");//Lucas
                        printf("|2 - Menu de colaboradores               |\n");//Kaue
                        printf("|3 - Nova ordem de serviço               |\n");//Samuel
                        printf("|4 - Relatórios                          |\n");//Samuel e Vieira
                        printf("|0 - Para retornar a tela de login(sair) |\n");
                        printf("+----------------------------------------+\n");
                        printf("\nDIGITE A SUA OPÇÃO...:");
                        scanf("%d", &sair);
                        system("cls");

                        switch (sair)
                        {
                            case 1:

                                cliente(); //CHAMA A FUNÇÃO PARA CADASTRO DE CLIENTES
                            

                                break;
                            case 2:

                                funcionarios();
                            
                                break;
                            case 3:

                                file = fopen("serviço.txt", "a");
                                if(file == NULL){
                                    printf("ERROR !! CONTATE O ADIM");
                                    return 1;
                                }                               

                                    servico(file); //CHAMA A FUNÇÃO PARA ABERTURA DE ORDEM DE SERVIÇO

                            
                                
                                fclose(file);
                                char linha[9999];
                                char*resultado; 
                                int contador = 0;
                                int op;
                                

                                file = fopen("serviço.txt","a+");

                                while(!feof(file))
                                {                                           //CONTABILIZA A QUANTIDADE DE ORDENS DE SERVIÇO ABERTAS
                                    resultado = fgets(linha, 9999, file);
                                    if(resultado){
                                        contador = contador + 1;
                                    }
                                }
                                fprintf(file, "%d\n", contador);
                                fclose(file);
                                    
                                
                                    printf("Número da OS: A/%d\n", contador);
                                    printf("Nome do funcionário: %s\n", funcio);
                                    printf("Nome do cliente: %s\n", clint);
                                    printf("Componente a ser revisado: %s\n", nome_comp);       //RESUMO DA OS
                                    printf("Tipo de Revisão: %s\n", tipo_serv);
                                    printf("Data de abertura da ORDEM DE SERVIÇO: %s\n", date);
                                    printf("Valor final a ser pago: R$ %.3f", valor);
                                    printf ("\n--------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    system("cls");
                                
                                break;
                            case 4:
                                
                               
                                do
                                {

                                    printf ("\n--------------------------------------------------------------------------------\n");
                                    printf("RELATÓRIOS DISPONIVEIS:\n\n1-Relatório de clientes\n2-Relatório de funcionários\n3-Relatório de serviço\n0-Retornar ao menu inicial\n");
                                    printf ("\n--------------------------------------------------------------------------------\n");
                                    printf("\nDIGITE A SUA OPÇÃO...: ");
                                    scanf("%d", &op );
                                    system("cls");

                                

                                    switch (op)
                                    {

                                        case 1:

                                            relatorioc();       //CHAMA A FUNÇÃO PARA GERAR UMA BASE DE DADOS DE CLIENTES CADASTRDOS
                                            printf("\n\n");
                                            system("pause");
                                            system("cls");

                                            break;

                                        case 2:

                                            relatoriof();       //FUNÇÃO PARA GERAR UMA BASE DE DADOS DE FUNCIONÁRIOS
                                            printf("\n\n");
                                            system("pause");
                                            system("cls");

                                            break;
                                        case 3:

                                            relatorios();       //FUNÇÃO PARA GERAR UMA BASE DE DADOS DE ORDENS DE SERVIÇO ABERTAS
                                            printf("\n\n");
                                            system("pause");
                                            system("cls");

                                            break;
                               
                                        case 0:
                                            break;              //RETORNA AO MENU PRINCIPAL

                                        default:
                                            printf("\t\t!OPÇÃO INVÁLIDA!\n");
                                            printf ("\n--------------------------------------------------------------------------------\n");
                                            system("pause");
                                            system("cls");
                                    }    
                                } while (op != 0);
                                system("cls");    
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
         printf("\t\t!OPÇÃO INVÁLIDA!\n");
         printf ("\n--------------------------------------------------------------------------------\n");
         system("pause");
         system("cls");
        }
    }
 return 0;
}
//FUNÇÃO PARA CADASTRO DE USUÁRIOS
void cadastro(FILE *fi)
{
    int opcao;
 
    do
    {
     gets(nome);
     printf("ESCOLHA UM NOME DE USUÁRIO..:\n");
     gets(nome);
     fprintf(fi, "%s ; ", nome);            //DADOS DO USUÁRIO
     system("cls");
     printf("CRIE UMA SENHA..:\n");
     gets(senha);
     fprintf(fi, "%s\n", senha);
     system("cls");
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("*-------------------------CADASTRO CONCLUIDO COM SUCESSO---------------------------------*\n");
     printf("*--------------------(VER DADOS CADASTRADOS = 1)--(SAIR = 2)-----------------------------*\n");
     printf("\nDIGITE A SUA OPÇÃO...:");
     scanf("%d", &opcao);
     system("cls");
        if (opcao == 1){
            while (opcao == 1)
            {
                printf("*----------------------------------------------------------------------------------------*\n");
                printf("Nome de usuário: %s\n", nome);      
                printf("Senha: %s\n", senha);       //RESUMO DO CADASTRO
                system("pause");
                system("cls");
                printf("*----------------------------------------------------------------------------------------*\n");
                printf("*--------------------(VER DADOS CADASTRADOS = 1)--(SAIR = 2)-----------------------------*\n");
                printf("*----------------------------------------------------------------------------------------*\n");
                printf("\nDIGITE A SUA OPÇÃO...:");
                scanf("%d", &opcao);
                system("cls");
            }
        }
    } while (opcao == 0);
}
//FUNÇÃO PARA ABERTURA DE ORDEM DE SERVIÇO
void servico(FILE *fl)
{
    int comp, tserv;

        gets(clint);
        printf("NOME DO CLIENTE..: ");
        gets(clint);
        fprintf(fl, "%s ; ", clint);
        system("cls");

        printf("\nFUNCIONÁRIO RESPONSAVEL PELA OS..: ");
        gets(funcio);
        fprintf(fl, "%s ; ", funcio);
        system("cls");

        while (comp<1 || comp>7)
        {

            printf ("\n--------------------------------------------------------------------------------\n");
            printf("COMPONENTE A SER REVISADO:\n1-Distribuidora\n2-Bomba de combustivel\n3-Dosadora\n4-Carburador\n5-Magneto\n6-Alternador\n7-Motor de partida\n");
            printf ("\n--------------------------------------------------------------------------------\n");
            printf("\nDIGITE A SUA OPÇÃO...: ");
            scanf("%d", &comp);
            system("cls");

            switch (comp)           //ESCOLHA DO COMPONENTE PARA REVISÃO
            {
                case 1:
                    nome_comp = "Distribuidora";
                    fprintf(fl, "%s ; ", nome_comp);
                    printf("O componente escolido foi uma %s.", nome_comp);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;
                case 2:
        
                    nome_comp = "Bomba de combustivel";
                    fprintf(fl, "%s ; ", nome_comp);
                    printf("O componente escolido foi uma %s.", nome_comp);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;
                case 3:
        
                    nome_comp = "Dosadora";
                    fprintf(fl, "%s ; ", nome_comp);
                    printf("O componente escolido foi uma %s.", nome_comp);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;
                case 4:
        
                    nome_comp = "Carburador";
                    fprintf(fl, "%s ; ", nome_comp);
                    printf("O componente escolido foi um %s.", nome_comp);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;
                case 5:
        
                    nome_comp = "Magneto";
                    fprintf(fl, "%s ; ", nome_comp);
                    printf("O componente escolido foi um %s.", nome_comp);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;
                case 6:
        
                    nome_comp = "Alternador";
                    fprintf(fl, "%s ; ", nome_comp);
                    printf("O componente escolido foi um %s.", nome_comp);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break; 
                case 7:
        
                    nome_comp = "Motor de partida";
                    fprintf(fl, "%s ; ", nome_comp);
                    printf("O componente escolido foi um %s.", nome_comp);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;       
                default:
                    printf("\t\t!OPÇÃO INVÁLIDA!\n");
                    printf ("\n--------------------------------------------------------------------------------\n");
                    system("pause");
                    system("cls");
            }   
                system("pause");
                system("cls");    
        }

        while (tserv<1 || tserv>4)
        {
            printf ("\n--------------------------------------------------------------------------------\n");
            printf("TIPO DE REVISÃO:\n1-Revisão geral\n2-Revisão de 500 horas\n3-Revisão 100 horas\n4-Revisão parcial\n");
            printf ("\n--------------------------------------------------------------------------------\n");
            printf("\nDIGITE A SUA OPÇÃO...: ");
            scanf("%d", &tserv);
            system("cls"); 

            switch (tserv)      //ESCOLHA DO TIPO DE REVISÃO
            {
                case 1:
                    tipo_serv = "Revisão geral";
                        if (strcmp(nome_comp, "Distribuidora") == 0){       //PREÇOS JÁ PRÉ-ESTABELECIDOS
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
                    fprintf(fl, "%.3f ; ", valor);         //RESUMO DA ESCOLHA
                    printf("O tipo de Revisão escolida foi uma %s, no valor de R$ %.3f", tipo_serv, valor);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;

                case 2:
                    tipo_serv = "Revisão de 500 horas";
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
                    fprintf(fl, "%.3f ; ", valor);    
                    printf("O tipo de Revisão escolida foi uma %s, no valor de R$ %.3f", tipo_serv , valor);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;

                case 3:
                    tipo_serv = "Revisão 100 horas";
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
                    fprintf(fl, "%.3f ; ", valor);
                    printf("O tipo de Revisão escolida foi uma %s, no valor de R$ %.3f", tipo_serv , valor);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;

                case 4:
                    tipo_serv = "Revisão parcial";
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
                    fprintf(fl, "%.3f ; ", valor);
                    printf("O tipo de Revisão escolida foi uma %s, no valor de R$ %.3f\n", tipo_serv , valor);
                    printf ("\n--------------------------------------------------------------------------------\n\n");
                    break;
                default:
                    printf("\t\t!OPÇÃO INVÁLIDA!\n");
                    printf ("\n--------------------------------------------------------------------------------\n");
                    system("pause");
                    system("cls");
            }
                system("pause");
                system("cls");
        }
            gets(date);       
            printf("DATA DE ABERTURA DA ORDEM DE SERVIÇO(dd/mm/yyyy)..: ");     //REGISTRANDO DATA DE ABERTURA
            gets(date);
            fprintf(fl, "%s ; ", date);
            system("pause");
            system("cls");
                 
}
//FUNÇÃO PARA CADASTRO DE CLIENTES
void cliente(){

    int op; //VARIAVEL SWITCH

      //MENU DE CADASTRO COM VARIAVEL

    printf("*----------------------------------------------------------------------------------------*\n");
    printf("*-----------------------------TELA DE CADASTRO-------------------------------------------*\n");
    printf("*---------------------(CADASTRO CPF = 1)--(CADASTRO CNPJ = 2)----------------------------*\n");
    printf("\nDIGITE A SUA OPÇÃO...:");

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
                scanf("%[^\n]s", &nome_cliente);                                                // "[^\n] PERMITE A LEITURA DO ESPAÃ‡O ENTRE OS NOMES. & APONTAMENTO NA MEMORIA.
                fprintf(Cadastro_cliente,"%s ; ",nome_cliente);                                 //NAO APRESENTOU FALHAS EU USEI.
                fflush(stdin);

                printf("\nDIGITE O NÚMERO DO TELEFONE...:");						 //GRAVACAO DE CONTATO
                gets(Contato1);
                fprintf(Cadastro_cliente,"%s ; ",Contato1); //SEPARACAO POR PONTO E VIRUGLA PARA UM USO FUTURO.
                fflush(stdin);

                printf("\nDIGITE O NÚMERO DO CELULAR...:");
                gets(Contato);										//GRAVACAO DE CONTATO
                fprintf(Cadastro_cliente,"%s ; ",Contato);
                fflush(stdin);

                printf("\nDIGITE APENAS OS NÚMEROS DO CEP...:");
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
            
            printf("\nDIGITE A IDENTIFICACÃO DO CLIENTE....:");
            scanf("%[^\n]s",nome_cliente); 						// "[^\n] PERMITE A LEITURA DO ESPAÃ‡O ENTRE OS NOMES. & APONTAMENTO NA MEMORIA.
            fprintf(Cadastro_cliente,"%s ; ", nome_cliente);
            fflush(stdin);

            printf("\nDIGITE O CEP..:");
            gets(CEP);
            fprintf(Cadastro_cliente,"%s ; ",CEP); 					//CADASTRO DO CEP
            fflush(stdin);

            printf("\nDIGITE O NÚMERO DO TELEFONE...:");
            gets(Contato1);
            fprintf(Cadastro_cliente,"%s ; ",Contato1); 				//CADASTRO DO TELEFONE
            fflush(stdin);

            printf("\nDIGITE O NÚMERO DO CELULAR...:");
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

//FUNÇÃO PARA GERAR UMA BASE DE DADOS DE CLIENTES CADASTRDOS
void relatorioc()
{

 char linha2[9999];
 char*resultado2;
 FILE *file;

 file = fopen("clientes.txt", "r");
 if(file == NULL){
 printf("ERROR !! CONTATE O ADIM");
 return 1;
 }   
    printf("*----------------------------------------------------------------------------------------*\n");
    printf("*-----------------------DADOS DOS CLIENTES PRONTOS PARA SEREM TRATADOS-------------------*\n");
    printf("*----------------------------------------------------------------------------------------*\n\n");   
        while(!feof(file))
        {
            resultado2 = fgets(linha2, 9999, file);
            if(resultado2){
            printf("%s", linha2);
            }
        }
 fclose(file);
}
//FUNÇÃO PARA GERAR UMA BASE DE DADOS DE FUNCIONÁRIOS
void relatoriof()
{
    
 char linha2[9999];
 char*resultado2;
 FILE *file;

 file = fopen("funcionarios.txt", "r");
 if(file == NULL){
 printf("ERROR !! CONTATE O ADIM");
 return 1;
 } 

    printf("*----------------------------------------------------------------------------------------*\n");
    printf("*------------------DADOS DOS FUNCIONÁRIOS PRONTOS PARA SEREM TRATADOS--------------------*\n");
    printf("*----------------------------------------------------------------------------------------*\n\n");
        while(!feof(file))
        {
            resultado2 = fgets(linha2, 9999, file);
            if(resultado2){
            printf("%s", linha2);
            }
        }
 fclose(file);
}
//FUNÇÃO PARA GERAR UMA BASE DE DADOS DE ORDENS DE SERVIÇO ABERTAS
void relatorios()
{

 char linha2[9999];
 char*resultado2;
 FILE *file;

 file = fopen("serviço.txt", "r");
 if(file == NULL){
 printf("ERROR !! CONTATE O ADIM");
 return 1;
 }  
    printf("*----------------------------------------------------------------------------------------*\n");
    printf("*--------------------DADOS DE SERVOÇOS PRONTOS PARA SEREM TRATADOS-----------------------*\n");
    printf("*----------------------------------------------------------------------------------------*\n\n");    
        while(!feof(file))
        {
            resultado2 = fgets(linha2, 9999, file);
            if(resultado2){   
            printf("%s", linha2);
            }
        }
 fclose(file);
}

int funcionarios()
{
    //Declaração das variáveis usada durante todo o programa//
 
 int opc,mest,fven, motivo, mestA,mes,mes2,diast; //Variáveis do tipo inteira
 float sal,vtotal,sal6,sal3,sal2,total2,decimo,parcela,rescisao,hr,hre,extra,sal4,extra1,sal5,ferias; //vaiáveis que armazenam uma quantidade maior de casas decimais//
 char nome[100],cpf[20],cart[35],salario[35],num[12],loja[47],car[35];// Váriaveis do tipo inteira//
 char linha; //Usado para o arquivo//
 char*resultado; //Usado para o arquivo//
 FILE*funcionarios; //Usado para o arquivo//
 
    do
    {

        printf("\n\n*---------------------------------------------------------------------------------------------*\n");
        printf("------------------------BEM VINDO A TELA DE MENU GERAL DE COLABORADORES------------------------\n");//tela de cadastro e consulta de colaborador 
        printf("-----------------------------------------------------------------------------------------------\n\n\n");
        //Opção que o usuário escolhe para execução do programa
        printf("1-CADASTRO DE COLABORADOR\n2-CÁLCULO DE DÉCIMO TERCEIRO\n3-CÁLCULO DE RESCISÃO\n4-CÁLCULO DE HORAS EXTRAS\n5-CÁLCULO DE FÉRIAS\n0-PARA VOLTAR AO MENU INICIAL\n\nDIGITE O QUE DESEJA: ");
        scanf("%d", &opc);
        system("cls");

     switch (opc)
     {
        case 1:
        
            system("cls"); //Limpando o que foi executado na tela aterior
        
            //abrindo arquivo para salvar dados dos funcionários
            funcionarios=fopen ("funcionarios.txt", "a"); 
                if (funcionarios==NULL)
                {
                    printf("erro na execução"); //Escrevendo para o usuário que aconteceu um erro no arquivo
                    return 1;
                }
        
            //Tela cadastro do funcionário onde pede informações essencias para armazenamento no arquivo txt
            gets(nome);
            printf ("DIGITE O NOME COMPLETO: "); //função de texto onde é imprimido informações na tela do usuário
            gets(nome); //leitura de caracteres digitado pelo usuário
            fprintf(funcionarios,"%s ; ",nome); // armazenamento da leitura escrita pelo usuário no arquivo
            fflush(stdin); //limpando os espaço salvo anterior
            system("cls");
            printf ("CPF: ");
            gets(cpf);
            fprintf(funcionarios,"%s ; ",cpf);
            fflush(stdin);
            system("cls");
            printf ("NUMERO DA CARTEIRA DE TRABALHO: ");;
            gets(cart);
            fprintf(funcionarios,"%s ; ",cart);
            fflush(stdin);
            system("cls");
            printf ("LOCAL DE TRABALHO(LOJA): ");
            gets(loja);
            fprintf(funcionarios,"%s ; ",loja);
            fflush(stdin);
            system("cls");
            printf ("CARGO/FUNÇÃO: ");
            gets(car);
            fprintf(funcionarios,"%s ; ",car);
            fflush(stdin);
            system("cls");
            printf ("SALÁRIO BRUTO: ");
            gets(salario);
            fprintf(funcionarios,"%s ; ",salario);
            fflush(stdin);
            system("cls");
            printf ("TELEFONE PARA CONTATO:");
            gets(num);
            fprintf(funcionarios,"%s\n",num);
            fflush(stdin);
            system("cls");
            //informação para que refaça novamente o cadastro, caso o usuário digite 1, ou finalize o processo caso digite 2
            printf("\nPARABÉNS, CADASTRO REALIZADO COM SUCESSO!\n\n");
            system("pause");
            system("cls");
            //Fechamento de arquivo txt//
            fclose(funcionarios);
        break;
    

        case 2: //PARA CÁCULO DE DÉCIMO TERCEIRO//
            system("cls");
            printf("\nQUANTIDADE DE MESES TRABALHADO NO ANO ATUAL: ");
            scanf("%d", &mes);
            system("cls");
            printf("DIGITE O SALÁRIO BRUTO: ");
            scanf("%f", &sal2);
            decimo=(sal2/12)*mes;//Dividindo o salário por 12 e multiplicando pela quantidade de meses trabalhado dentro do ano//
            parcela=decimo/2; //Dividindo o décimo por dois para mostrar o valor de cada parcela//
            system("cls");
            printf("\nO VALOR TOTAL DO DÉCIMO É DE: R$%.2f\n\nSENDO 1ª PARCELA DE: R$%.2f E SEGUNDA PARCELA DE: R$%.2f\n\n",decimo,parcela,parcela);
            system("pause");
            system("cls");
        break;

        case 3: //Cálculo para rescisão//
            system("cls");
            printf("MOTIVO\n1. DISPENSA SEM JUSTA CAUSA\n2. DISPENSA COM JUSTA CAUSA\n3. PEDIDO DE DEMISSÃO\n\nDIGITE O MOTIVO:");
            scanf("%d",&motivo);
                if (motivo==1)
                {
                    system("cls");
                    printf("DIGITE O SALÁRIO BRUTO: ");
                    scanf("%f", &sal3);
                    system("cls");
                    printf("\nQUANTIDADE DE MESES TRABALHADO NO TOTAL NA EMPRESA: ");
                    scanf("%d", &mes2);
                    system("cls");
                    printf("\nQUANTIDADE DE MESES TRABALHADO NO ANO ATUAL: ");
                    scanf("%d", &mestA);
                    system("cls");
                    printf("\nQUANTIDADE DE DIAS TRABALHADO NO MÊS DA DEMISSÃO: ");
                    scanf("%d", &diast);
                    system("cls");
                    printf("\nEXISTE FÉRIAS VENCIDAS\n1. SIM\n2. NÃO\n:");
                    scanf("%d",&fven);
                        if(fven==1)//Cálculos de rescisão caso seja demitido pela empresa e existe férias vencidas
                        { 
                            rescisao=sal3; //Aviso prévio é o valor do salário
                            rescisao=rescisao+((sal3/30)*mest); //Salário proporcional aos dias trabalhado
                            rescisao=rescisao+(sal3/3)+sal3; //Férias vencida 
                            rescisao=rescisao+((sal3/12)*mestA); //Décimo proporcional aos dias trabalhado
                            rescisao=rescisao+((sal3*8/100)*mes2)*1.4; //Valor do FGTS proporcional mais a multa
                        }
                        if(fven==2)//Cálculos de rescisão caso seja demitido pela empresa e não existe férias vencidas
                        {
                            rescisao=sal3; //Aviso prévio é o valor do salário
                            rescisao=rescisao+((sal3/30)*diast); //Salário proporcional aos dias trabalhado
                            rescisao=rescisao+((sal3/12)*mestA); //Décimo proporcional aos dias trabalhad
                            rescisao=rescisao+((sal3*8/100)*mes2)*1.4; //Valor do FGTS proporcional mais a multa
                        }
                }        
                if (motivo==2)
                {
                    system("cls");
                    printf("DIGITE O SALÁRIO BRUTO: ");
                    scanf("%f", &sal3);
                    system("cls");
                    printf("QUANTIDADE DE DIAS TRABALHADO: ");
                    scanf("%d", &diast);
                    system("cls");
                    printf("\nEXISTE FÉRIAS VENCIDAS\n1. SIM\n2. NÃO\n:");
                    scanf("%d",&fven);
                        if(fven==1)//Cálculos de rescisão caso seja demitido pela empresa e existe férias vencidas
                        {     
                            rescisao=(sal3/30)*diast; //Salário proporcional aos dias trabalhado
                            rescisao=rescisao+(sal3/3)+sal3; //Férias vencida 
                        }
                        if(fven==2)//Cálculos de rescisão caso seja demitido pela empresa e existe férias vencidas
                        { 
                            rescisao=(sal3/30)*diast; //Salário proporcional aos dias trabalhado
                        }
                }
                if (motivo==3)
                {
                    system("cls");
                    printf("DIGITE O SALÁRIO BRUTO: ");
                    scanf("%f", &sal3);
                    system("cls");
                    printf("\nQUANTIDADE DE MESES TRABALHADO NO TOTAL NA EMPRESA: ");
                    scanf("%d", &mes2);
                    system("cls");
                    printf("\nQUANTIDADE DE MESES TRABALHADO NO ANO ATUAL: ");
                    scanf("%d", &mestA);
                    system("cls");
                    printf("\nQUANTIDADE DE DIAS TRABALHADO NO MÊS DA DEMISSÃO: ");
                    scanf("%d", &diast);
                    system("cls");
                    printf("\nEXISTE FÉRIAS VENCIDAS\n1. SIM\n2. NÃO\n:");
                    scanf("%d",&fven);
                        if(fven==1)//Cálculos de rescisão caso seja demitido pela empresa e existe férias vencidas
                        {
                            rescisao=sal3; //Aviso prévio é o valor do salário
                            rescisao=rescisao+((sal3/30)*mest); //Salário proporcional aos dias trabalhado
                            rescisao=rescisao+(sal3/3)+sal3; //Férias vencida 
                            rescisao=rescisao+((sal3/12)*mestA); //Décimo proporcional aos dias trabalhado
                        }
                        if(fven==2)//Cálculos de rescisão caso seja demitido pela empresa e não existe férias vencidas
                        {
                            rescisao=sal3; //Aviso prévio é o valor do salário
                            rescisao=rescisao+((sal3/30)*diast); //Salário proporcional aos dias trabalhado
                            rescisao=rescisao+((sal3/12)*mestA); //Décimo proporcional aos dias trabalhad
                        }
                }
            system("cls");
            printf("\nO VALOR TOTAL DA RESCISÃO É DE: R$%.2f\n\n",rescisao);
            system("pause");
            system("cls");
        break;

        case 4: //Cálculo para horas extras//
            system("cls");
            printf("\nQUANTIDADE DE HORAS FIXAS MENSAIS PROPOSTAS: ");
            scanf("%f", &hr);
            system("cls");
            printf("QUANTIDADE DE HORAS EXTRAS: ");
            scanf("%f", &hre);
            system("cls");
            printf("DIGITE O VALOR DO SALÁRIO BRUTO: ");
            scanf("%f", &sal4);
            extra=(sal4/hr)*1.5*hre; //Dividindo  salário pela quantidade de horas mensais, multiplicando por 50% e multiplicando por horas extras//
            extra1=extra+sal4; //somando o salário mais o total de hora extras que devem ser pagos//
            system("cls");
            printf("\nO VALOR TOTAL COM HORAS EXTRAS QUE DEVE SER PAGO É DE: R$%.2f\n\nSENDO O SALÁRIO DE R$%.2f MAIS O VALOR DE HORAS EXTRAS DE R$%.2f\n\n",extra1,sal4,extra);
            system("pause");
            system("cls");
        break;

        case 5:// cálculo para férias//
            system("cls");
            printf("\nDIGITE O SALÁRIO BRUTO: ");
            scanf("%f", &sal5);
            system("cls");
            ferias=sal5/3; //Dividindo o salário por 3//
            vtotal=(sal5/3)+sal5; //dividindo o salário por 3 e somando junto com salário//
            system("cls");
            printf("\nO VALOR TOTAL DE R$%.2f\n\nSENDO O SALÁRIO DE R$%.2f MAIS O VALOR DE FÉRIAS QUE SÃO R$%.2f\n\n",vtotal,sal5,ferias);
            system("pause");
            system("cls");
        break;

        case 0:
            break;

        default:
            printf("\t\t!OPÇÃO INVÁLIDA!\n");
            printf ("\n--------------------------------------------------------------------------------\n");
            system("pause");
            system("cls");
     }    
    } while (opc != 0);
    //Fim da execução do menu de colaborador//
    return 0;
}