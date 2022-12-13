#include "ordvetor.h"
//Cria um vetor de tamanha n 
VETORORD* VETORD_create(int n, COMP* compara) {
	VETORORD* vetor = malloc(sizeof(VETORORD)); //Cria e aloca na mem´oria espaço para o vetor vazio
	vetor->elems = malloc(n * sizeof(void*));//Aloca na memória os espaços correspondetes ao tamanho do vetor
	vetor->N = n;//aloca os parametros do vetor 
	vetor->P = 0;
	vetor->comparador = compara;

	return vetor;
}

void VETORD_add(VETORORD* vetor, void* newelem) {
	if (vetor->P < vetor->N) { //se ouver espaço
		int i, pos = vetor->P;

		for (i = 0; i < vetor->P; i++) {
			if (vetor->comparador(vetor->elems[i], newelem) < 0) {  //onde add
				pos = i;
				break;
			}
		}                                                   // adiciona o novo elemento no vetor, de forma ordenada 

		for (i = vetor->P; i > pos; i--) {
			vetor->elems[i] = vetor->elems[i - 1]; //realiza as trocas
		}

		vetor->elems[pos] = newelem;  //adiciona o novo elemento no local correto
		vetor->P++;
	}	
}

void* VETORD_remove(VETORORD* vetor) {
	if (vetor->P > 0) {
		void* min = vetor->elems[0]; //remove o menor elemento 

		for (int i = 0; i < vetor->P - 1; i++) {
			vetor->elems[i] = vetor->elems[i + 1];   // realoca os outros no vetor 
		}
		
		vetor->P--;

		return min;
	}
}