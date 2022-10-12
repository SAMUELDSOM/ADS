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
    char nome[20];
    char fone[20];
    int opcao = 1;
    char linha[40];
    char *resultado;

    FILE *file;
    
    //Abrindo arquivo
    file = fopen("Alunos_Unip", "a");
    if(file == NULL){
        printf("não deu mermão");
        return 1;
    }  
    while(opcao != 0){
    printf("Nome:");
    scanf("%s", nome);
    fprintf(file, "%s;", nome);
    printf("Numero:");
    scanf("%s", fone);
    fprintf(file, "%s\n", fone);
    
    printf("Cadastro executado com sucesso...\n");
    printf("Vamos continuar?(se nao,digite 0):\n");
    scanf("%d", &opcao);
}
    fclose(file);
    
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
    
    return 0;
}
