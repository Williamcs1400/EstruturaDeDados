#include <stdio.h>
#include <stdlib.h>

struct dados
{
    char comida[20];
};

typedef struct dados Data;

struct node
{
    Data elem;
    struct node *prox;
};

int ListaExiste(LADAE **inicio){
    if(inicio == NULL){
        return 0;
    }
    return 1;
}

LADAE** criaLADAE(){
    LADAE **novo;

    novo = (LADAE **) malloc(sizeof(LADAE *));
    
    *novo = NULL;

    return novo;
}

int ehVaziaLADAE(LADAE **inicio){
    if(*inicio == NULL)
        return 1;
    return 0;
}

int insereLADAE(LADAE **inicio, Data novo){
    LADAE *novono, *aux, *ant;

    aux = *inicio;

    novono = (LADAE *) malloc(sizeof(LADAE));

    if(novono == NULL)
        return 0;
    
    novono->prox = NULL;
    novono->elem = novo;
    
    if(ehVaziaLADAE(inicio)){
        *inicio = novono;
    }

    else{
    	while(aux != NULL){
    		if((novono->elem).info[0] <= (aux->elem).info[0]){
    			if(aux == *inicio){
    				novono->prox = aux;
    				*inicio = novono;
    			}
    			else{
    				novono->prox = aux;
    				ant->prox = novono;
    			}
    			break;
    		}
    		else{
    			if(aux->prox == NULL){
 					aux->prox = novono;
 					break;
    			}
    		}
    		ant = aux;
    		aux = aux->prox;
    	}	
    }
    return 1;
}

int RemoveElemento(LADAE **inicio, int remove){
	LADAE *aux, *ant;
	aux = *inicio;
	int flag = 0;

	if(ehVaziaLADAE(inicio)){
		return 0;
	}
	if((aux->elem).info == remove){
		*inicio = aux->prox;
	}

	ant = aux;
	aux = aux->prox;

	while(aux != NULL){
		if((aux->elem).info == remove){
			ant->prox = aux->prox;
			free(aux);
			flag = 1;
			break;
		}	
		else{
			ant = aux;
			aux = aux->prox;			
		}
	}
	if(flag == 1){
		return 1;			
	}
	else 
		return 0;
}

int BuscarElemento(LADAE **inicio, int busca){
	LADAE *aux;
	aux = *inicio;
	int posi = 0, flag = 0;

	if(ehVaziaLADAE(inicio)){
        return -2;
    }
    else{
    	while(aux != NULL){
    		if((aux->elem).info == busca){
    			flag = 1;
    			break;
    		}
    		else{
    			posi++;
    			aux = aux->prox;
    		}
    	}
    }
    if(flag == 1){
    	return posi+1;
    }
    else
    	return -1;
}

int ZeraLista(LADAE **inicio){
	LADAE *aux, *post;
	post = *inicio;
	if(ehVaziaLADAE(inicio)){
        return 0;
    }
    else{
		do{
			aux = post;
			post = aux->prox;
			free(aux);
		}while(aux->prox != NULL);

		free(aux);
		*inicio = NULL;
	}
	return 1;
}

void imprimeLADAE(LADAE **inicio){
    LADAE *aux;
    aux = *inicio;
    
    
    if(&inicio == NULL){
        printf("A lista não existe\n");
    }
    
    else{
        if(aux == NULL)
        {
            printf("Lista vazia\n");
        }
        else
        {
            while(aux != NULL)
            {
                printf("%d => ",(aux->elem).info);
                aux = aux->prox;
            }
        }
        printf("\n\n\n");
    }
}


void liberaLADAE(LADAE **inicio){
    LADAE *aux,*liberar;
    aux = *inicio;    
    
    while(aux!=NULL)
    {
        liberar = aux;
        free(liberar);
        aux=aux->prox;
    }
    free(inicio);
    inicio = NULL;
}

int main(){
    int n, i;
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        
    }
}