/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char nome[50], cpf[11], fone[50], linha[50], e_mail[20];
    int cont = 5;
    int opcao = 1;
    int op2 = 0;
    char *resultado;

    FILE *file;
    while (op2 == 0)
 {
    
    printf("\n\tINVESTIMENTOS SSC\n\n");
    printf("Digite 1 para se cadastrar:\n");
    printf("Digite 2 se já tem cadastro:\n");
    scanf("%d", &cont);
    system("cls");

    switch (cont)
    {
    case 1:
    //Abrindo arquivo
    file = fopen("Alunos_Unip", "a");
    if(file == NULL){
        printf("não deu mermão");
        return 1;
        }  
        while(opcao != 0){
        gets(nome);
    
        printf("Nome:\n");
        gets(nome);
        fprintf(file, "%s; ", nome);
        system("cls");
        printf("Numero:\n");
        gets(fone);
        fprintf(file, "%s; ", fone);
        system("cls");
        printf("CPF:\n");
        gets(cpf);
        fprintf(file, "%s; ", cpf);
        system("cls");
        printf("E-MAIL:\n");
        scanf("%s", e_mail);
        fprintf(file, "%s\n", e_mail);
        system("cls");
        printf("Cadastro executado com sucesso...\n");
        printf("Vamos continuar?(se nao,digite 0):\n");
        scanf("%d", &opcao);
        system("cls");
        }
        fclose(file);
        break; 
     
    case 2:
    file = fopen("Alunos_Unip", "r");
    if(file == NULL){
        printf("não deu mermão");
        return 1;
        }
        while(!feof(file)){
       resultado = fgets(linha, 41, file);
        if(resultado){
            printf("%s", linha);
        }
        }
        printf("\nDigite 0 para continuar:");
        scanf("%d", &op2);
        system("cls");
        break;
    }
    
 }
    return 0;
}
