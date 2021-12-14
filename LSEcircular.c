#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sCelula {
	char nome[30]; // nome do item 
	int mes;	 // mes que o item deve ser plantado
	int contador; // número de itens plantados
}DADOS;

typedef struct sLista {
	DADOS info; // campo com as informações dos dados inseridos
	struct sLista *next; // compo que a ponta para o proximo elemento 
	
}CELULA;

//função para inicializar a lista  
void iniciar(CELULA **lista){
	(*lista)=NULL;
}

//função para criar uma nova celula
CELULA* criar() {
	
	CELULA *nova; // cria uma celula nova
	nova=(CELULA *)malloc(sizeof(CELULA)); // reserva um espaço de memoria para nova celula
	
	//verifica se a espaço na memoria
	if(nova == NULL){
		printf("\nErro ao alocar memoria!");
		return 0;
	}	
	return nova; // retorna a nova celula criada
}

//função para verificar a lista encontra-se vazia
int vazia(CELULA **lista) {
	
	if ((*lista)==(**lista).next){
		return 1; // retorna 1 verdadeira 
	}
	return 0; // retorna 0 falsa 
}

//função para inserir elementos no inicio lista
int inserir_inicio(CELULA **lista,DADOS dados) {
	
	CELULA *nova=criar(); // cria uma nova celula
	
	//verifica se a nova celula é válida
	if(nova == NULL)
        return 0;
	
	//insere os dados na nova celula
	nova->info = dados;  
    nova->next = NULL;
	
	//verifica se a lista esta vazia para inserir
	if (vazia(lista)) {
		
		(*lista)->next = nova; // ptr lista->proximo recebe a nova celula
		nova->next=(*lista);
		return 1;
	}
	//caso a lista nao estiver vazia (possuir elementos)
	nova->next = (*lista)->next; // o ponteiro da nova celula  recebe o proximo elemento apontado pelo prt lista 
    (*lista)->next = nova;  // o prt lista->proximo recebe a nova celula 
    return 1;
    
}

//funcão para remover elemento no final da lista
DADOS func_remove_final(CELULA **lista) {
	
	//cria um removido 
	DADOS removido;
	removido.mes=-1;
	strcpy(removido.nome,"nulo");
	
	if (vazia(lista)) { 
		// se não possui elementos para remover retorna os dados do removido	
		return removido;
	}	
	CELULA *aux,*prev;
	aux=*lista;
	if (aux->next==aux) {
		removido=aux->info;
		free(aux);
		*lista=NULL;
		return removido;
	}
		while (aux->next!=(*lista)) { // percorre o auxiliar enquanto ele for diferente do ptr lista
			prev=aux;
			aux=aux->next;
		}
		prev->next=aux->next;
		removido=aux->info; // removido recebe a informação do auxiliar
		free(aux); // libera o auxiliar 
		return removido; // retorna o elemento removido
}


// função para pegar os dados para preencher a celula
void preenche(DADOS *dados) {
	
	printf("\nDigite o nome do item: "); //pega o nome do item
	fflush(stdin);
	gets(dados->nome);
	printf("\nDigite a mes a ser plantado: "); // pega o nome do mes 
	fflush(stdin);
	scanf("%d",&dados->mes);
}

//função para imprimir as informações dos elementos da lista
printar(DADOS dados) {
	printf("\n**********************");
	printf("\nNOME : %s || mes: %d",dados.nome,dados.mes); // informa o nome do item e o mês 
	printf("\n**********************\n");
	
}

//função que printa todos os elementos da lista
void todos(CELULA **lista) {
	
	CELULA *aux; // cria um auxiliar
	aux=(*lista); // auxiliar recebe lista
	
	if(vazia(lista)) {  // caso não possui elemento na lista para Printar
        printf("\nNao ha elementos para imprimir!");
        return;
    }
	
	while (aux->next!=(*lista)){ // auxiliar percorre enquanto não chegar no ptrlista
		
		aux=aux->next; // auxiliar recebe o auxiliar próximo
		printar(aux->info); // imrprime a informação do Item cada vez que o auxiliar chega em um elemento da lista
	}	
}


//função menu principal
int menu() {
	
	int op;
	system("cls");
	printf("[1] Inserir elemento no inicio\n");
	printf("[2] Remover elemento no fim\n");
	printf("[3] Imprimir todos os elementos\n");
	printf("[0] Sair\n");
	scanf("%d",&op); // pega a opção escolhida pela usuário 
	return op; // retorna a opção que o usuário escolheu
}
