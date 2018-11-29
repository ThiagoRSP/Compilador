#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *fp;
char *arquivo = "nome.txt";
char *result;
char linha[100];
char palavra [100];
char programa[1000];
int tamanho;
int indice;
char lexema[10], token[10], valor[10];
int contador=1;

void NextChar(){
	
	
	switch  (programa[indice]){
		
	
		
		case '\n':
		contador = contador + 1;
		break;
		
		case '+':
			strcpy(lexema,"+");
			strcpy(token, "operator");
			strcpy(valor, "SUM");
			printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
		break;
		
		// ZERO 0
		case '0':
			if((programa[indice+1]==' ') || (programa[indice+1]) =='\n'){
			strcpy(lexema,"0");
			strcpy(token, "ZERO");
			strcpy(valor, "0");
			printf("\nLexema: %s\nToken: %s\nValor: %s\n\n", lexema, token, valor);}
			else
				printf("\n Erro lexico");
			
		break;
		
		// UM 1
		case '1':
			if((programa[indice+1]==' ') || (programa[indice+1]) =='\n'){
			strcpy(lexema,"1");
			strcpy(token, "UM");
			strcpy(valor, "1");
			printf("\nLexema: %s\nToken: %s\nValor: %s\n\n", lexema, token, valor);}
			else
				printf("\n Erro lexico");
			
		break;
		
		// ; ponto e virgula
		case ';':
			strcpy(lexema,";");
			strcpy(token, "point");
			strcpy(valor, "-");
			printf("\nLexema: %s\nToken: %s\nValor: %s\n\n", lexema, token, valor);
		break;
		
		// : dois pontos
		case ':':
			strcpy(lexema,":");
			strcpy(token, "point");
			strcpy(valor, "-");
			printf("\nLexema: %s\nToken: %s\nValor: %s\n\n", lexema, token, valor);
				
		break;
		
		case '<':
			if(programa[indice+1]=='-'){
			indice++;
			strcpy(lexema,"<-");
			strcpy(token, "attr");
			strcpy(valor, "-");
			printf("\nLexema: %s\nToken: %s\nValor: %s\n\n", lexema, token, valor);
			}
		break;
		
	//	BEGIN
		case 'b':
				indice = indice+1;
				if (programa[indice]=='e'){
				//case 'e':
					indice = indice+1;
					if (programa[indice]=='g'){
			//		case 'g':
						indice = indice+1;
						if(programa[indice]=='i'){
			//			case 'i':
							indice = indice+1;
							if(programa[indice]=='n'){
			//						case 'n':
				// case ' ':								
										indice = indice+1;
										
										
										if(programa[indice]==' ') {
	
											strcpy(lexema,"begin");
											strcpy(token, "delimiter");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d",contador);
											break;} 
			else if((programa[indice])=='\n'){
											strcpy(lexema,"begin");
											strcpy(token, "delimiter");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d",contador);
											contador = contador +1; 
											break;} 
			
			else {
				indice = indice - 1;
				printf("\n Erro lexico");								
			}
			}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 		
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
			}  else {
				indice = indice - 1;
			printf("\n Erro lexico");
			} 
		break;
		
		//	END
		case 'e':
				indice = indice+1;
				if (programa[indice]=='n'){
				//case 'n':
					indice = indice+1;
					if (programa[indice]=='d'){
			// case ' ':								
										indice = indice+1;
										if(programa[indice]==' '){
	
											strcpy(lexema,"end");
											strcpy(token, "delimiter");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											break;} 
			else if((programa[indice])=='\n'){
			
			strcpy(lexema,"end");
			strcpy(token, "delimiter");
			strcpy(valor, "-");
			printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
			printf("LINHA: %d\n", contador);
			contador = contador +1; 
											break;
			} 
			
			else{
				indice = indice - 1;
				printf("\n Erro lexico");							
			}
					
					
					} else {
					indice = indice - 1;
				printf("\n Erro lexico");} 		
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			}
		break;

		//	REAL
		case 'r':
				indice = indice+1;
				if (programa[indice]=='e'){
				//case 'e':
					indice = indice+1;
					if (programa[indice]=='a'){
			//		case 'g':
						indice = indice+1;
						if(programa[indice]=='l'){
			// case ' ':								
										indice = indice+1;
										if(programa[indice]==' ') {
	
											strcpy(lexema,"real");
											strcpy(token, "type");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											
											break;} 
			else if((programa[indice])=='\n'){
											strcpy(lexema,"real");
											strcpy(token, "type");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											contador = contador +1;
											break;
			}
			else{
				indice = indice - 1;
				printf("\n Erro lexico");								
			}// CASE 'READ':
			}else 	if(programa[indice]=='d'){
			// case ' ':								
										indice = indice+1;
										if(programa[indice]==' '){
	
											strcpy(lexema,"read");
											strcpy(token, "read");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											break;
			}else if ((programa[indice])=='\n'){
											strcpy(lexema,"read");
											strcpy(token, "type");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											contador = contador +1;
											break;
			}else if ((programa[indice])==':'){
											strcpy(lexema,"read");
											strcpy(token, "type");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											indice--;
											break;
			}
			else{
				indice = indice - 1;
			printf("\n Erro lexico");							
			}
			
			
			}else{
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
			}  else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
		break;
			
		//	INTEGER
		case 'i':
			//case 'n'
				indice = indice+1;
				if (programa[indice]=='n'){
			// case 't':
					indice = indice+1;
					if (programa[indice]=='t'){
			//case 'e':
						indice = indice+1;
						if(programa[indice]=='e'){
			//case 'g':
							indice = indice+1;
							if(programa[indice]=='g'){
			//case 'e':
								indice = indice+1;
								if(programa[indice]=='e'){
			//case 'r':
										indice = indice+1;
										if(programa[indice]=='r'){
			// case ' ':								
										indice = indice+1;
										if(programa[indice]==' '){
	
											strcpy(lexema,"integer");
											strcpy(token, "type");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											break;
			} else if((programa[indice]) =='\n') {
											strcpy(lexema,"integer");
											strcpy(token, "type");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											contador = contador + 1;
											break;
			}
			else{
				indice = indice - 1;
				printf("\n Erro lexico");								
			}				
			
			} else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 		
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
			}  else {
				indice = indice - 1;
				printf("\n Erro lexico");
			}
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
		break;		
	
		//	PROGRAM
		case 'p':
			//case 'r'
				indice = indice+1;
				if (programa[indice]=='r'){
			// case 'o':
					indice = indice+1;
					if (programa[indice]=='o'){
			//case 'g':
						indice = indice+1;
						if(programa[indice]=='g'){
			//case 'r':
							indice = indice+1;
							if(programa[indice]=='r'){
			//case 'a':
								indice = indice+1;
								if(programa[indice]=='a'){
			//case 'm':
										indice = indice+1;
										if(programa[indice]=='m'){
			// case ' ':								
										indice = indice+1;
										if(programa[indice]==' '){
	
											strcpy(lexema,"program");
											strcpy(token, "start");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											break;
			}else if ((programa[indice]) ==';') {
											indice--;
											strcpy(lexema,"program");
											strcpy(token, "start");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											break;
			}else if ((programa[indice]) =='\n') {
											strcpy(lexema,"program");
											strcpy(token, "start");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											contador = contador + 1;
											break;
			}
			
			else{
				indice = indice - 1;
				printf("\n Erro lexico");							
			}
											
											
			} else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 		
				}else {
				indice = indice - 1;
			printf("\n Erro lexico");
			} 
				}else {
				indice = indice - 1;
			printf("\n Erro lexico");
			} 
			}  else {
				indice = indice - 1;
			printf("\n Erro lexico");
			}
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
		break;
	
		//	GOTO
		case 'g':
				indice = indice+1;
				if (programa[indice]=='o'){
			//case 't':
					indice = indice+1;
					if (programa[indice]=='t'){
			//case 'o':
						indice = indice+1;
						if(programa[indice]=='o'){
			// case ' ':								
										indice = indice+1;
										if(programa[indice]==' '){
	
											strcpy(lexema,"goto");
											strcpy(token, "goto");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											break;
			}else if ((programa[indice]) =='\n'){
											strcpy(lexema,"goto");
											strcpy(token, "goto");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											contador = contador + 1;
											break;
											
			}
			else{
				indice = indice - 1;
				printf("\n Erro lexico");							
			}
			}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
			}  else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
		break;
	
	
		//	LOOP
		case 'l':
				indice = indice+1;
				if (programa[indice]=='o'){
				//case 'e':
					indice = indice+1;
					if (programa[indice]=='o'){
			//		case 'g':
						indice = indice+1;
						if(programa[indice]=='p'){
			// case ' ':								
										indice = indice+1;
										if(programa[indice]==' '){
	
											strcpy(lexema,"loop");
											strcpy(token, "loop");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											break;
			}else if((programa[indice]) =='\n') {
											strcpy(lexema,"loop");
											strcpy(token, "loop");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											contador = contador + 1;
											break;
			
			}else{
				indice = indice - 1;
				printf("\n Erro lexico");							
			}
			}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
			}  else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
		break;
	
		//	WRITE
		case 'w':
				indice = indice+1;
				if (programa[indice]=='r'){
				//case 'e':
					indice = indice+1;
					if (programa[indice]=='i'){
			//		case 'g':
						indice = indice+1;
						if(programa[indice]=='t'){
			//			case 'i':
							indice = indice+1;
							if(programa[indice]=='e'){
			//						case 'n':
				// case ' ':								
										indice = indice+1;
										if(programa[indice]==' ') {
	
											strcpy(lexema,"write");
											strcpy(token, "write");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											break;
			}else if (programa[indice] =='\n'){
											strcpy(lexema,"write");
											strcpy(token, "write");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n", contador);
											contador = contador + 1;
											break;
			}
			else{
				indice = indice - 1;
				printf("\n Erro lexico");							
			}
			}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 		
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
				}else {
				indice = indice - 1;
			printf("\n Erro lexico");
			} 
			}  else {
				indice = indice - 1;
				printf("\n Erro lexico");
			} 
		break;
	
			//	var
		case 'v':
				indice = indice+1;
				if (programa[indice]=='a'){
				//case 'n':
					indice = indice+1;
					if (programa[indice]=='r'){
			// case ' ':								
										indice = indice+1;
										if(programa[indice]==' '){
	
											strcpy(lexema,"var");
											strcpy(token, "var");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
											break;
			} else if (programa[indice] =='\n'){
											strcpy(lexema,"var");
											strcpy(token, "var");
											strcpy(valor, "-");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
											contador = contador + 1;
											break;
				
			} 
			else{
				indice = indice - 1;
				printf("\n Erro lexico");								
			}
					
					
					} else {
					indice = indice - 1;
					printf("\n Erro lexico");} 		
				}else {
				indice = indice - 1;
				printf("\n Erro lexico");
			}
		break;
		//||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'
		case 'A':
			
			while (programa[indice+1]!=' '){
			
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{ //if(programa[indice+1]!='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 printf("\n Erro lexico");
			 break;
		}
			}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
				case 'B':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'C':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'D':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
						case 'E':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'F':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'G':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
						case 'H':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
						case 'I':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
						case 'J':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'K':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'L':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'M':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'N':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'O':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'P':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'Q':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
						case 'R':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'S':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
						case 'T':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
						case 'U':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'V':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'W':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'X':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
							case 'Y':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
						case 'Z':
			
			while (programa[indice+1]!=' ')
			if(programa[indice+1]=='A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
			 indice++;
			 }else{
			 printf("\n Erro lexico");
			break;}
			
						                   strcpy(lexema,"qlqrnome");
											strcpy(token, "id");
											strcpy(valor, "tabela");
											printf("\nLexema: %s\nToken: %s\nValor: %s\n", lexema, token, valor);
											printf("LINHA: %d\n",contador);
			break;
	
	case ' ':
	break;
	
	case EOF:
	break;
	
	case '	':
		break;
	
	default:
	//printf(" %s", palavra[indice]);
	while(programa[indice+1]!=' '){
		indice=indice+1;
	}
	printf("\n Erro lexico");
	break;
	}
	
}

int main (){


if(( fp = fopen(arquivo,"r")) == NULL){
	
	printf("ERRO");
}
 else{
 	 int i = 1;
 
	while (!feof(fp))
	{
		result = fgets(linha,100,fp);
		if(result){
			
		strcat(programa,linha);
		}
		i++;
	}	
	fclose(fp);
	//printf("%s",programa);
	
	} 
	
	tamanho = strlen(programa);
	indice = 0;
	
	while (indice <= tamanho){
		NextChar();
		indice++;
	}
		//printf("%s",programa);
	return 0;
}
