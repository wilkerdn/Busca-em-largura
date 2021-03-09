#include "b-largura.h"

Vertice criaVertice(char vert){
	int i = 0;
	Vertice novoVertice = (Vertice)malloc(sizeof(Vertice));
	novoVertice->vert = vert;
	novoVertice->n_vizinhos = 0;
	novoVertice->visitado = 0;
	for(i=0;i<MAX_ARESTAS;i++){
		novoVertice->vizinhos[i]=0;
	}
	return novoVertice;
}

void ligaVertices(Vertice v1, Vertice v2){
	int aux = 0;
	while(v1->vizinhos[aux]!=0){
		aux++;
	}
	v1->vizinhos[aux] = v2;
	aux = 0;
	while(v2->vizinhos[aux]!=0){
		aux++;
	}
	v2->vizinhos[aux] = v1;
	v1->n_vizinhos++;
	v2->n_vizinhos++;
}

int buscaEmLargura(Vertice inicio, Vertice destino){
	int iniFila = 0;
	int tamFila = 1;
	int i = 0;
	Vertice FILA[MAX_VERTICES];
	for (i = 0; i < MAX_VERTICES; i++){
		FILA[i] = 0;
	}
	FILA[iniFila] = inicio;

	while(iniFila<tamFila){
		if(FILA[iniFila] == destino ) return iniFila;
		for (i = 0; i < FILA[iniFila]->n_vizinhos; i++){
			if(FILA[iniFila]->vizinhos[i]->visitado == 0){
				FILA[iniFila]->vizinhos[i]->visitado = 1;
				FILA[tamFila] = FILA[iniFila]->vizinhos[i];
				tamFila++;
			}
		}
		iniFila++;
	}
	return 0;
}
