#include "b-largura.h"

int main(){
	int res = 0;

	Vertice R = criaVertice('R');
	Vertice S = criaVertice('S');
	Vertice T = criaVertice('T');
	Vertice U = criaVertice('U');
	Vertice V = criaVertice('V');
	Vertice W = criaVertice('W');
	Vertice X = criaVertice('X');
	Vertice Y = criaVertice('Y');
	
	ligaVertices(U, T);
	ligaVertices(U, X);
	ligaVertices(U, Y);
	ligaVertices(X, T);
	ligaVertices(X, W);
	ligaVertices(W, S);
	ligaVertices(X, Y);
	ligaVertices(W, T);
	ligaVertices(R, S);
	ligaVertices(R, V);

	R->visitado = 0;
	S->visitado = 0;
	T->visitado = 0;
	U->visitado = 0;
	V->visitado = 0;
	W->visitado = 0;
	X->visitado = 0;
	Y->visitado = 0;

	res = buscaEmLargura(R, Y);
	if(res!=0){
		printf("Encontrou distancia: %d\n", res);
	}else
		printf("Nao encontrou\n");

	Vertice GRAFO[MAX_VERTICES];
	GRAFO[0] = criaVertice('S');
	GRAFO[1] = criaVertice('R');
	GRAFO[2] = criaVertice('T');
	GRAFO[3] = criaVertice('U');
	GRAFO[4] = criaVertice('V');
	GRAFO[5] = criaVertice('W');
	GRAFO[6] = criaVertice('X');
	GRAFO[7] = criaVertice('Y');

	ligaVertices(GRAFO[3], GRAFO[2]);
	ligaVertices(GRAFO[3], GRAFO[6]);
	ligaVertices(GRAFO[3], GRAFO[7]);
	ligaVertices(GRAFO[6], GRAFO[2]);
	ligaVertices(GRAFO[2], GRAFO[5]);
	ligaVertices(GRAFO[5], GRAFO[6]);
	ligaVertices(GRAFO[5], GRAFO[0]);
	ligaVertices(GRAFO[0], GRAFO[1]);
	ligaVertices(GRAFO[6], GRAFO[7]);
	ligaVertices(GRAFO[5], GRAFO[7]);
	
	res = buscaEmLargura(GRAFO[0], GRAFO[7]);
	if(res!=0){
		printf("Encontrou, distancia: %d\n", res);
	}else
		printf("Nao encontrou\n");

	return 0;
}
