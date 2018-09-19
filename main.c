#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
    char *arquivo = "nome.txt";
    char *result;
    char linha[100];
    char programa[100];
    int tamanho;
    int indice = 0;
    char lexema[10], token[10], valor[10];

void nextchar(){
    switch(programa[indice]){
        case '+':
        strcpy(lexema,"+");
        strcpy(token,"operator");
        strcpy(valor,"sum");
        printf("Lexema:%s\nToken:%s\nValor:%s\n",lexema,token,valor);
        break;

        case '0':
        strcpy(lexema,"0");
        strcpy(token,"zero");
        strcpy(valor,"0");
        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
        break;

        case '1':
        strcpy(lexema,"1");
        strcpy(token,"one");
        strcpy(valor,"1");
        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
        break;

        case ';':
        strcpy(lexema,";");
        strcpy(token,"point");
        strcpy(valor,";");
        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
        break;

        case ':':
        strcpy(lexema,":");
        strcpy(token,"point");
        strcpy(valor,":");
        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor); 
        break;

        case 'r':
            if (programa[indice + 1] == 'e')
            {
                if (programa[indice + 2] == 'a')
                {
                    if (programa[indice + 3] == 'l')
                    {
                        strcpy(lexema,"real");
                        strcpy(token,"type");
                        strcpy(valor,"");
                        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor); 
                    }
                    else if (programa[indice + 3] == 'd')
                    {
                        strcpy(lexema,"read");
                        strcpy(token,"read");
                        strcpy(valor,"");
                        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
                    }
                }
            }
            else{
                printf("\nYeah\n");
            }
        break;
        

        


        default:
        printf("%c",programa[indice]);

    }


}   
    


int main()
{
    if((fp=fopen(arquivo,"r"))==NULL){

        printf("Deu ruim");
    }
    else{
        int i = 1;
      
       while(!feof(fp))
       {
           result=fgets(linha,100,fp);
           if(result)
                strcat(programa,linha);
           i++;
       }

    fclose(fp);
    //printf("%s\n",programa);
    tamanho=strlen(programa);
 
    while(indice<=tamanho){
    nextchar();
    indice ++;

    }
    }
}
