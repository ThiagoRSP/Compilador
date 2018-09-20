#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
    char *arquivo = "nome.txt";
    char *result;
    char linha[1000];
    char programa[1000];
    int tamanho;
    int indice = 0;
    char lexema[100], token[100], valor[100];

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

        case '<':
            if (programa[indice + 1] == '-')
            {
                strcpy(lexema,"<-");
                strcpy(token,"attr");
                strcpy(valor,"");
                printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor); 
            }
            break;


        case 'r':
            if (programa[indice + 1] == 'e')
            {
                if (programa[indice + 2] == 'a')
                {
                    if (programa[indice + 3] == 'l')
                    {
                        if (programa[indice + 4] == '\n' || programa[indice + 4] == ' ' || programa[indice + 4] == feof(fp))
                        {
                            strcpy(lexema,"real");
                            strcpy(token,"type");
                            strcpy(valor,"");
                            printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor); 
                        }
                        
                    }
                    else if (programa[indice + 3] == 'd')
                    {
                        if (programa[indice + 4] == '\n' || programa[indice + 4] == ' '|| programa[indice + 4] == feof(fp))
                        {
                            strcpy(lexema,"read");
                            strcpy(token,"read");
                            strcpy(valor,"");
                            printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
                        }
                    }
                }
            }
            else{
                printf("%c",programa[indice-1]);
            }
        break;
        

        case 'i':
            if (programa[indice + 1] == 'n')
            {
                if (programa[indice + 2] == 't')
                {
                    if (programa[indice + 3] == 'e')
                    {
                        if(programa[indice + 4] == 'g')
                        {
                            if(programa[indice + 5] == 'e')
                            {
                                if(programa[indice + 6] == 'r')
                                {
                                    if (programa[indice + 7] == '\n' || programa[indice + 7] == ' ' || programa[indice + 7] != feof(fp))
                                    {
                                        strcpy(lexema,"integer");
                                        strcpy(token,"type");
                                        strcpy(valor,"");
                                        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
                                    }
                                 }
                            }
                        }
                    }
                }
            }
            else
            {
                printf("%c",programa[indice-1]);
            }
        break;  

        case 'b':
                if (programa[indice + 1] == 'e')
                {
                    if (programa[indice + 2] == 'g')
                    {
                       
                            if (programa[indice + 4] == 'i')
                            {
                                if(programa[indice + 5] == 'n')
                                {  
                                    if (programa[indice + 6] == '\n' || programa[indice + 6] == ' '|| programa[indice + 6] == feof(fp))
                                    {
                                        strcpy(lexema,"begin");
                                        strcpy(token,"delimeter");
                                        strcpy(valor,"");
                                        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
                                    }
                                }
                            }
                        
                    }
                }
                else{
                    printf("%c",programa[indice-1]);
                }
            break;

            case 'w':
                if (programa[indice + 1] == 'r')
                    {
                        if (programa[indice + 2] == 'i')
                        {
                            if (programa[indice + 3] == 't')
                            {
                                if(programa[indice + 4] == 'e')
                                {  
                                    if (programa[indice + 5] == '\n' || programa[indice + 5] == ' ' || programa[indice + 5] == feof(fp))
                                    {
                                        strcpy(lexema,"write");
                                        strcpy(token,"write");
                                        strcpy(valor,"");
                                        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
                                    }
                                }
                            }
                        }
                    }
                    else{
                        printf("%c",programa[indice-1]);
                    }
            break;

            case 'p':
                if (programa[indice + 1] == 'r')
                    {
                        if (programa[indice + 2] == 'o')
                        {
                            if (programa[indice + 3] == 'g')
                            {
                                if(programa[indice + 4] == 'r')
                                {
                                    if(programa[indice + 5] == 'a')
                                    {
                                        if(programa[indice + 6] == 'm')
                                        {
                                            if (programa[indice + 7] == '\n' || programa[indice + 7] == ' ' || programa[indice + 7] == feof(fp))
                                            {
                                                strcpy(lexema,"program");
                                                strcpy(token,"start");
                                                strcpy(valor,"");
                                                printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
                                            }
                                         }
                                    }
                                }
                            }
                        }
                    }
                    else{
                        printf("%c",programa[indice-1]);
                    }
            break;

            case 'e':
            if (programa[indice + 1] == 'n')
            {
                if (programa[indice + 2] == 'd')
                {
                    if (programa[indice + 3] == '\n' || programa[indice + 3] == ' ' || programa[indice + 3] != feof(fp))
                    {
                        strcpy(lexema,"end");
                        strcpy(token,"delimeter");
                        strcpy(valor,"");
                        printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
                    }   
                }
            }
            else{
                    printf("%c",programa[indice-1]);
                }
            break;

            case 'g':
            if (programa[indice + 1] == 'o')
            {
                if (programa[indice + 2] == 't')
                {
                    if (programa[indice + 3] == 'o')
                    {
                            if (programa[indice + 4] == '\n' || programa[indice + 4] == ' ' || programa[indice + 4] == feof(fp))
                            {
                                strcpy(lexema,"goto");
                                strcpy(token,"goto");
                                strcpy(valor,"");
                                printf("\nLexema: %s\n Token: %s\n Valor: %s\n",lexema,token,valor);
                            }
                        
                    }
                }
            }
            else{
                    printf("%c",programa[indice-1]);
                }
            break;
        


        default:
        printf("%c",programa[indice - 1] );

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
           result=fgets(linha,1000,fp);
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
