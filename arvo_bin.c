#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

/*
 * Agora sim um codigo organizado
 *
 ***********************************/



/*======================  NODO DA ARVORE  ====================================*/

/*------------------------------------------------------------------------------
 * Estrutura do Nodo
 *   pai: Ponteiro para o Nodo Pai
 *   filho: Caracter do Nodo
 *	 info: Vetor associado com os ponteitos do Nodos Filho 
 *   plvr:
 */
#define TAM 150

typedef struct node node;
//typedef struct no no;
typedef struct arvore arvore;

struct vetor{
	char letra[26];
	char chave;
};

typedef struct node{
	node *filho[TAM];
	node *palavras[TAM];
	char info;
	int isword;
        char palavra[4092];
}Node;

Node* new_nodes (Node *nodo, int n, struct vetor vector[]){
	int i, k=0;
	for (i=0; i< n; i++){
                nodo->filho[i] = malloc(sizeof (node));
                nodo->filho[i]->info = vector[k].chave;
		nodo->filho[i]->isword = 0;
                k++;
	}
	return nodo;
}

Node* inicia_arvore (int n){
	int i; 
	struct node *no;
        no = malloc(sizeof (node));
	for (i=0; i< n; i++){
	    no->filho[i] = NULL;
	}
	return no;
}

void Node_write (Node *node, char *numero, struct vetor vector[]){
        int i=0, j=0, k,tam;
        char n;
		    n = numero[i];
	tam = strlen (numero);
	tam--; //nao imprime \n
        while (numero[i] != '\n'){
		    
		  	if (node->filho[0]==NULL){
				return;
			}
		            n = numero[i];
			while (node->filho[j]->info!=n){
		            	j++;
			}
			node = node->filho[j];
		            i++;
			j=0;
		
		}
		    
		for (i=0;i<tam;i++) //imprime ate a ultima letra antes do \n
			printf("%c", numero[i]);
		printf (":\n"); //imprime o : e \n
		if (node->isword == 1 && node != NULL){
		i=0;
	    	while (node->palavras[i] != NULL){
	            	printf("%s\n", node->palavras[i]->palavra);
	            	i++;
		}
	    }
}

/*=============================  ARVORE  =====================================*/


/*------------------------------------------------------------------------------
 * Insere uma palavra na Arvore
 * Entrada:
 *   arvore: Arvore onde a palavra serah inserida
 *   palavra: string da palavra
 * Saida:
 *   nenhuma
 * */

void Arvore_insertWord(Node *ptr, char array[], char *palavra, int n, struct vetor vector[]){
	int i=0, j=0;
        i=0;
	while (array[i] != 0){
	  	if (ptr->filho[j] == NULL)
	  		ptr = new_nodes(ptr, n, vector);
	  	
		while (ptr->filho[j]->info != array[i]){
			j++;
		}
		ptr = ptr->filho[j];
		i++;
		j=0;
	}	
		i=0;
		while (ptr->palavras[i]!=NULL){
	  		i++;
		}
		ptr->palavras[i] = malloc (sizeof(struct node));
		strcpy(ptr->palavras[i]->palavra, palavra);  
        ptr->palavras[i+1] = NULL;
		ptr->isword = 1;
}


/*------------------------------------------------------------------------------
 * Mostra todas as palavras de uma Arvore
 * Entrada:
 *   arvore: Arvore a ser mostrada
 * Saida:
 *   nenhuma
 * */

/*void Arvore_write(Node *ptr, char numero){        
        Node_write(ptr, numero);
}*/


/******************************************************************************/



/***********************  ROTINA MAIN  ****************************************/ 

//-----------------------------------------------------------------------------------------
	

void main(int argc, char **argv) {
  	struct vetor vector[25];
	int i, j;
	char palavra[4092], numero[4092], frase[4092], array[100];
	char fpi, m;
	FILE *fp = fopen (argv[1],"r");
	fscanf(fp, "%s", frase);
	int n=0, k=0;
	while ( !feof(fp) ){                        
		
		j=0;
		m=frase[0];
		i=2;
		while (frase[i]!='\0'){
			vector[k].letra[j] = frase[i];
			vector[k].chave = m;
			i++; j++;
		}
		vector[k].letra[j] = '\0';
		k++;
		n++;
		i=0;
		
		fscanf(fp, "%s", frase);
		
		
	}
	fclose(fp);

//-----------------------------------------------------------------------------------------
	
	Node *raiz = inicia_arvore(n);
        
//-----------------------------------------------------------------------------------------        
	FILE *fp2 = fopen (argv[2],"r");
        i=0;
        j=0;
        int h=0, a, co=0; 
        k=0;
        fscanf(fp2, "%s", palavra);
		
        while ( !feof(fp2) ){
                  k=0;j=0;
                while (palavra[k]!='\0'){
                        
                        while ((h < n) && (co!=1)){
                            i=0;
                        	a = strlen(vector[h].letra);
		                    while ( (palavra[k] != vector[h].letra[i]) && (i < a)){
		                    		
		                            i++;
		                    }
		                    if (palavra[k] == vector[h].letra[i])
		                    			co = 1;
		                    h++;
		                }
		                h--;
                        array[j] = vector[h].chave;
                        i=0;
                        j++;
                        k++;   
                        h=0; 
                        co=0;
                }
                array[j]=0;
                Arvore_insertWord(raiz, array, palavra, n, vector);                	
                fscanf(fp2, "%s", palavra);
        }
        fclose(fp2);
//-----------------------------------------------------------------------------------------	
	

	while ( fgets(numero,4092,stdin)!=NULL ){                        
		if (numero[0] != '\n')
		Node_write(raiz, numero, vector);
	}

}
