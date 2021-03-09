#include <stdio.h>
#include <malloc.h>

#define MAX_VERTICES 8
#define MAX_ARESTAS (MAX_VERTICES*(MAX_VERTICES-1))

typedef struct vertice{
	char vert;
	int n_vizinhos;
	struct vertice* vizinhos[MAX_ARESTAS];
	int visitado;
}*Vertice;

Vertice criaVertice(char vert);
void ligaVertices(Vertice v1, Vertice v2);
int buscaEmLargura(Vertice inicio, Vertice destino);
