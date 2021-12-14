
#include "LSEcircular.c"

main () {
	
	CELULA *li; // cria uma lista do tipo celula
	DADOS temp;
	
    CELULA* Nocabecalho = criar(); //cria n� de cabe�alho
    Nocabecalho->next = Nocabecalho; 
    li = Nocabecalho;   
    Nocabecalho->info.contador=0; // o contador do n� cabe�alho recebe valor 0 
	
	int resp; // numero digitado pelo usu�rio no menu de op��es
	
	do {
		resp=menu(); // chama a fun��o Menu , e pega a op��o escolhida pela usu�rio
		
		switch(resp) {
			
			case 1 : {
				
				preenche(&temp); // chama a fun��o de preencher os dados
				inserir_inicio(&li,temp); // chama a fun��o de inserir no inicio
				
				if(temp.mes==11){ // verifica se o mes do elemento inserido pertence ao m�s de novembro
                	Nocabecalho->info.contador = Nocabecalho->info.contador + 1;  //soma mais 1 elemento do mes de novembro
				}	
				printf("\nInserido com sucesso!"); // informa ao usu�rio que o elemento foi inserido
				printf("\nNumeros de itens plantados no mes de novembro: %d\n", Nocabecalho->info.contador); //printa os n�meros de itens plantados no m�s de novembro
				system("pause >> null");
				break;
			}
			case 2 : {
				
				temp=func_remove_final(&li); // chama a fun��o de remover no final
				printf("\nElemento Removido com sucesso!");
				
				if(temp.mes==11){ // verifica se o mes do elemento removido � o de novembro
                	Nocabecalho->info.contador = Nocabecalho->info.contador - 1; //subtrai menos 1 elemento do mes de novembro
				}
				// apos a remo��o printa o novo valor do item do mes de novembro (caso a remo��o tenha sido do m�s de novembro)
				printf("\nNumeros de itens plantados no mes de novembro: %d\n", Nocabecalho->info.contador); 
				system("pause >> null");
				break;
			}
			case 3 : {
				todos(&li); // chama a fun��o que printa todos os elementos da lista
				system("pause >> null");
				break;
			}
		}
	}while (resp!=0); // fica no la�o de repeti��o do menu at� o usu�rio digitar 0
	
	return 0;
	
}
