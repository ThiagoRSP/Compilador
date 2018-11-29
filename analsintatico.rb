#Armazenar palavras do arquivo
array1 = []
#Variável pra incrementar
i = 0
k = 0

def esperar(variavel,palavra)
	if variavel == palavra
		return true
	else
		return false	
	end
end

def program(array1)
	j = 0
	if esperar(array1[j], "program\n")
	   j += 1
	   puts "Funcionar #{j}"
	   esperar(array1[j], "id\n")
	   j += 1
	   puts "Funcionar #{j}"
	   esperar(array1[j], "pointPV\n")
	   j += 1	
	   puts "Funcionar #{j}"		
	   if (esperar(array1[j], "var\n"))
	   	j += 1
	   	puts "Funcionar #{j}"
	   	condition = 'seguir'
	   	while condition != 'parada'
	   		if (esperar(array1[j], "id\n"))
		    	j += 1
		    	puts "Funcionar #{j}"
		    	if (esperar(array1[j], "point2P\n"))
		   		   j += 1
		   		   puts "Funcionar #{j}"
		   		   if (esperar(array1[j], "type\n"))
		   		   	j += 1
		   		   	puts "Funcionar #{j}"
		   		   	  if esperar(array1[j], "pointPV\n")
		   			  	j += 1
		   			  	puts "Funcionar #{j}"
		   			  	if esperar(array1[j], "id\n")
		   			  		puts "foi"
		   			  	else
		   			  		puts "Fim de declaração de variável"
		   			  		condition = 'parada'
		   			  		return j	
		   			  	end
		   		   	  else
		   		   	  	puts "Erro sintático #{j}"
		   		   	  	break	
		   		   	  end
		   		   else
		   		   	puts "Erro sintático #{j}" 	
		   		   	break	
		   		   end
		    	else
		    		puts "Erro sintático #{j}"
		    		break	
		    	end
	   		else
	   			puts "Erro sintático #{j}"
	   			break	
	   		end
	   	end	   	   	 
		else
		   puts "Erro Sintático #{j}"  	   
	   end
	else
		puts "Erro Sintático #{j}"	
	end
end

def writeAndRead(array1,incremento)

	j = incremento

	condition = 'seguir'

	while condition != 'parada'
   	  	if esperar(array1[j], "read\n") || esperar(array1[j], "write\n")
			j += 1
			puts "ta indo writeAndRead"
			if esperar(array1[j], "pointAP\n")
				j += 1
				puts "ta indo writeAndRead"
				if esperar(array1[j], "id\n")
					j += 1	
					puts "ta indo writeAndRead"
					if esperar(array1[j], "pointFP\n")
						j += 1
						puts "ta indo writeAndRead"
						if esperar(array1[j], "pointPV\n")
							j += 1	
							puts "ta indo #{j}"
							if esperar(array1[j], "read\n") || esperar(array1[j], "write\n")
								puts "fim do ciclo #{j}"
							else
								condition = 'parada'
								return j	
							end
						else
							puts "Erro sintático #{j}"
							break	
						end
					else
						puts "Erro sintático #{j}"
						break	
					end
				else
				 puts "Erro sintático #{j}"	
				 break	
				end
			else
				puts "Erro sintático #{j}"
				break	
			end		
		else
			puts "Erro sintático #{j}"
			break	
		end
   	end
end

def atribuicao(array1,incremento)
	
	j = incremento

	condition = 'seguir'

	while condition != 'parada'
		if esperar(array1[j], "id\n")
			j += 1
			puts "Foi attr"
			if esperar(array1[j], "attr\n") 
				j += 1
				puts "Foi attr"
				if esperar(array1[j], "id\n")
					j += 1
					puts "Foi attr"

					# Se encerrar com o ponto, então é uma declaração 
					# de variável simples

					if esperar(array1[j], "pointPV\n")
						j += 1
						puts "Declarada variável simples"
						if esperar(array1[j], "id\n")
							puts "Recomeçando"
						else
							condition = 'parada'
							return j
						end

					# Se tiver um operador depois do id, então é uma declaração 
					# de variável com operação 
						
					elsif esperar(array1[j], "operator\n")
						j += 1
						puts "Seguindo para declaração com operação"
						if esperar(array1[j], "zero\n") || esperar(array1[j], "one\n")
							j += 1
							puts "foi"
							if esperar(array1[j], "pointPV\n")
								 j += 1
								 puts "Declarada variável com operação completa"
								 if esperar(array1[j], "id\n")
								 	puts "recomeçando"
								 else
								 	condition = 'parada'
								 	return j
								 end
							else
								puts "Erro sintático a"
								break	 
							end
						else
							puts "Erro sintático b"
							break	
						end
					else	
						puts "Erro sintático c"
						break	
					end
				else
					puts "Erro sintático d"
					break	
				end
			else
				puts "Erro sintático e"
				break	
			end
		else
			puts "Erro sintático1 f"
			break	
		end
	end

end

@contador = 0

def loopi(array1,incremento)

	j = incremento

	condition = 'seguir'

	@contador += 1

	contadorInterno = @contador

	while condition != 'parada'
   	  	if esperar(array1[j], "loop\n")
			j += 1
			puts "ta indo o loopi contador #{contadorInterno}"
				
			if esperar(array1[j], "id\n")
				j = atribuicao(array1,j)	
			elsif esperar(array1[j], "read\n") || esperar(array1[j], "write\n")
				j = writeAndRead(array1,j)	
			elsif esperar(array1[j], "loop\n")
				puts "O valor do contador é #{contadorInterno}"
				j = loopi(array1,j)	
			else
				puts "Erro Sintático"	
				break
			end	
		
			puts "contador interno #{contadorInterno}"

			if esperar(array1[j], "delimiter\n")		
				contadorInterno -= 1
				puts "Contador interno Delimiter #{contadorInterno}"
				@contador = contadorInterno
				j += 1
				return j
			else
				puts "Ta caindo aqui"
				condition= 'parada'
				return j
			end
		else
			puts "Erro sintático l"
			break
		end
   	end
end

def main(array1,incremento)
	j = incremento
	if esperar(array1[j], "delimiterBG\n") 
   	  j += 1	

   	  condition = 'seguir'

   	  while condition != 'parada'
	   	if esperar(array1[j], "read\n") || esperar(array1[j], "write\n")
			j = writeAndRead(array1,j)   
		elsif esperar(array1[j], "id\n")
		  	j = atribuicao(array1,j)	
		elsif esperar(array1[j], "loop\n")
		  	j = loopi(array1,j)
		   	if @contador == 0
		   		puts "Delimiter fechando ok"
		   		if esperar(array1[j], "delimiter\n")
		   			puts "Erro Sintático. Delimiter em excesso"
		   			break
		   		end
		   	else
		   		puts "Erro no delimiter"				  		
		   	end
		elsif esperar(array1[j],"delimiter\n")
			puts "Delimiter Final. Fim de programa"
			condition = 'parada'
		else
			puts "Erro sintático. Faltando delimiter"	
			break
	   	end
   	  end

	else
		puts "Não tem begin para iniciar o programa principal"	
    end
end

File.open('arq.txt', 'r') do |f1|
    while line = f1.gets
    	array1[i] = line
    	i += 1
    end
   
end

j = program(array1)

    main(array1,j)