
#include "LSEcircular.c"

main () {
	
	CELULA *li; // cria uma lista do tipo celula
	DADOS temp;
	
    CELULA* Nocabecalho = criar(); //cria nó de cabeçalho
    Nocabecalho->next = Nocabecalho; 
    li = Nocabecalho;   
    Nocabecalho->info.contador=0; // o contador do nó cabeçalho recebe valor 0 
	
	int resp; // numero digitado pelo usuário no menu de opções
	
	do {
		resp=menu(); // chama a função Menu , e pega a opção escolhida pela usuário
		
		switch(resp) {
			
			case 1 : {
				
				preenche(&temp); // chama a função de preencher os dados
				inserir_inicio(&li,temp); // chama a função de inserir no inicio
				
				if(temp.mes==11){ // verifica se o mes do elemento inserido pertence ao mês de novembro
                	Nocabecalho->info.contador = Nocabecalho->info.contador + 1;  //soma mais 1 elemento do mes de novembro
				}	
				printf("\nInserido com sucesso!"); // informa ao usuário que o elemento foi inserido
				printf("\nNumeros de itens plantados no mes de novembro: %d\n", Nocabecalho->info.contador); //printa os números de itens plantados no mês de novembro
				system("pause >> null");
				break;
			}
			case 2 : {
				
				temp=func_remove_final(&li); // chama a função de remover no final
				printf("\nElemento Removido com sucesso!");
				
				if(temp.mes==11){ // verifica se o mes do elemento removido é o de novembro
                	Nocabecalho->info.contador = Nocabecalho->info.contador - 1; //subtrai menos 1 elemento do mes de novembro
				}
				// apos a remoção printa o novo valor do item do mes de novembro (caso a remoção tenha sido do mês de novembro)
				printf("\nNumeros de itens plantados no mes de novembro: %d\n", Nocabecalho->info.contador); 
				system("pause >> null");
				break;
			}
			case 3 : {
				todos(&li); // chama a função que printa todos os elementos da lista
				system("pause >> null");
				break;
			}
		}
	}while (resp!=0); // fica no laço de repetição do menu até o usuário digitar 0
	
	return 0;
	
}
