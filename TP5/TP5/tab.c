#include <stdlib.h>
#include <stdio.h>

#define TAILLEAJOUT 50

int initTab(int* tab, int size) { // Initialise un tableau avec des zéros
	if ((tab == NULL) || (size < 0)) {
		return(-1);
	}
	else {
		for (int i = 0; i < size; i++) {
			*(tab + i) = 0;
		}
	}
	return(size);
}

int afficheTab(int* tab, int size, int nbElts) {
	if ((tab == NULL) || (size < 0) || (size < nbElts)) {
		return(-1);
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("| %d |", *(tab + i));
		}
	}
	return(0);
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if ((tab == NULL) || (size == NULL) || (nbElts == NULL) || (*size < 0) || (*nbElts < 0)) {
		return(-1);
	}
	if (*size == *nbElts) {
		int* save = tab;
		tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));
		if (tab == NULL) {
			tab = save;
			free(save);
			return(NULL);
		}
	}
	*(tab + (*nbElts)) = element;
	*(nbElts) += 1;
	return(tab);
}