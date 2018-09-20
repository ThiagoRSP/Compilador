  

            
        
            

            case 'g':
            if (programa[indice + 1] == 'o')
            {
                if (programa[indice + 2] == 't')
                {
                    if (programa[indice + 3] == 'o')
                    {
                            if (programa[indice + 4] == '\n' || programa[indice + 4] == ' ')
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

            }
            break;