#include <stdio.h>
#include <stdlib.h>

int main(){

    char name [10];
    char codinome [10] = "viadão"; 

    printf("Digite seu nome:");
    scanf("%s",name);

    printf("Bem Vindo, %s \n", name);
    printf("Seu nome agora passa a ganhar um atributo glorioso\n");

    name = name + codinome;

    printf("Receba com toda glória, %s", name);

}