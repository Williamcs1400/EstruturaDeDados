#include"ladae.h"

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

int insereInicioLADAE(LADAE **inicio, Data novo){
    LADAE *novono;
    
    novono = (LADAE *) malloc(sizeof(LADAE));
    if(novono == NULL)
        return 0;
    
    novono->prox = NULL;
    novono->elem = novo;
    
    if(ehVaziaLADAE(inicio))
    {
        *inicio = novono;
    }
    else
    {
        novono->prox = *inicio;
        *inicio = novono;
        /* .. faco outra coisa */
    }
    return 1;
}

int insereFinalLadae(LADAE **inicio, Data novo){
    
    LADAE *aux, *novono;
    aux = *inicio;
    novono = (LADAE*) malloc(sizeof(LADAE));
    
    if(novono == NULL)
        return 0;
    
    novono->prox = NULL;
    novono->elem = novo;
    
    
    if(ehVaziaLADAE(inicio))
    {
        *inicio = novono;
    }
    else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        
        aux->prox = novono;
    }
    return 1;
}

int RemoveInicio(LADAE **inicio){
	LADAE *aux;
	aux = *inicio;

	if(ehVaziaLADAE(inicio)){
		return 0;
	}
	if(aux->prox == NULL){
		inicio = NULL;
	}
	else{
		*inicio = aux->prox;
		free(aux);
	}
	return 1;
}

int RemoveFinal(LADAE **inicio){
    
    LADAE *aux, *ant;
    aux = *inicio;
    if(ehVaziaLADAE(inicio)){
        return 0;
    }
    if(aux->prox == NULL){
        inicio = NULL;
    }
    else{
        ant = aux;
        aux = aux->prox;
        
        while(aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = NULL;
    }
    free(aux);
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
    	return posi;
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