#Armazenar palavras do arquivo
array1 = []
array2 = []
arrayId = []
#Variável pra incrementar
i = 0
k = 0
a = 0
h = 0


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
File.open("arq2.txt", "r") do |f2|
	while line2 = f2.gets
		array2[a] = line2
		a+=1
	end	
end
 	arrayRW = []
    arrayAttr = []
def semantico1(array1,array2,arrayId,arrayAttr,arrayRW)

	a = 0
	w = 0
    nome_do_programa = array2[1]
   

    if ((nome_do_programa == "program\n") || (nome_do_programa == "var\n") || (nome_do_programa == "end\n") || (nome_do_programa == "begin\n") || (nome_do_programa == "loop\n"))
    	puts "O nome do programa não pode ser uma palavra reservada"
    else
    	array1.each_with_index do |item, index|
    		if ((item == "id\n") && (array1[index+1] == "point2P\n"))
    			puts "#{index}"
    			arrayId.push(index)
    		elsif ((item == "id\n") && (array1[index - 1] == "pointAP\n") && array1[index + 1] == "pointFP\n" )
    			arrayRW.push(index)
    		elsif ((item == "id\n") && ((array1[index - 1] == "attr\n")||(array1[index + 1] == "attr\n")))
    			arrayAttr.push(index)
    					

    		end
  			
		end

    end
end

arrayLexema = []
arrayLexemaAttr = []
arrayLexemaRW = []

def semantico2(array1,array2,arrayId,arrayLexema)
	arrayId.each do |id|
		array2.each_with_index do |lexema,index|
			if id == index
				arrayLexema.push(lexema)
			end
		end	
	end
end
 
 def semantico3(array1,array2,arrayAttr,arrayLexemaAttr)
	arrayAttr.each do |id|
		array2.each_with_index do |lexema,index|
			if id == index
				arrayLexemaAttr.push(lexema)
			end
		end	
	end
end
 
 def semantico4(array1,array2,arrayRW,arrayLexemaRW)
	arrayRW.each do |id|
		array2.each_with_index do |lexema,index|
			if id == index
				arrayLexemaRW.push(lexema)
			end
		end	
	end
end
 
 

def posFinal(arrayLexema)
	if arrayLexema.uniq.length == arrayLexema.length
		puts "Ids válidos"
	else
		puts "Variável duplicada"
		
	end
	
end

j = program(array1)

    main(array1,j)

   semantico1(array1,array2,arrayId,arrayAttr,arrayRW)


  semantico2(array1,array2,arrayId,arrayLexema)
  semantico3(array1,array2,arrayAttr,arrayLexemaAttr)
  semantico4(array1,array2,arrayRW,arrayLexemaRW)

  arrayLexema.each do |lexema|
  	puts "Variável declarada: #{lexema}"
  end	


  arrayLexemaRW.each do |rw|
  	puts "Variável de read ou write: #{rw}"
  end	


  arrayLexemaAttr.each do |at|
  	puts "Variável de atribuição: #{at}"
  end	

  posFinal(arrayLexema)




if (arrayLexema - arrayLexemaAttr).empty?
	puts "É zero"
else
	puts"ERRRROU"
end
lengthLexema = arrayLexema.uniq.length
lengthRW = arrayLexemaRW.uniq.length
lengthAttr = arrayLexemaAttr.uniq.length

if (arrayLexema - arrayLexemaAttr).length == (lengthLexema - lengthAttr)
	puts "Tudo certo nas Atribuições"
else
	puts "Erro nas atribuições"
end

if (arrayLexema - arrayLexemaRW).length == (lengthLexema - lengthRW)
	puts "Tudo certo nos Reads e Writes"
else
	puts "Erro nos Reads e Writes"
end
