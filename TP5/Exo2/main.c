#include <stdlib.h>
#include <stdio.h>

#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;

TABLEAU newArray() {   //Créé un nouveau tableau
	TABLEAU elt;
	elt.size = TAILLEINITIALE;
	elt.elt = (int*)malloc(elt.size * sizeof(int));
	if (elt.elt == NULL) {
		printf("Pas assez de mémoire");
		elt.eltsCount = -1;
		return(elt);
	}
	else {
		for (int i = 0; i < elt.size; i++) {
			*(elt.elt) = 0;
		}
	}
	elt.eltsCount = 0;
	return(elt);
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {    //Augmente la taille du tableau de incrementValue
	int* save = tab->elt;
	tab->elt = (int*)realloc((tab->elt), ((tab->size) + incrementValue) * sizeof(int));
	if (tab->elt == NULL) {
		tab->elt = save;
		printf("Pas assez de mémoire");
		return(-1);
	}
	else {
		tab->size += incrementValue;
		return(tab->size);
	}
}

int setElement(TABLEAU* tab, int pos, int element) {    //Insère un élément à l'emplacement pos du tableau
	if (pos > tab->size) {
		int* save = tab->elt;
		tab->elt = (int*)realloc(tab->elt, ((pos-1) * sizeof(int)));
		if (tab->elt == NULL) {
			printf("Pas assez de mémoire");
			return(0);
		}
		else {
			for (int i = tab->eltsCount; i < pos - 1; i++) {
				*((tab->elt) + i) = 0;
			}
			*((tab->elt) + pos - 1) = element;
		}
	}
	else {
		*((tab->elt) + pos - 1) = element;
	}
	return(pos);
}

//On suppose désormais qu'on retourne a une indication des positions à partir de 0 des éléments d'un tableau

int displayElements(TABLEAU* tab, int startPos, int endPos) {   //Affiche les éléments du tabmeau de startPos à endPos
	if ((tab == NULL) || (startPos >= tab->size) || (endPos >= tab->size) || (endPos < 0) || (startPos < 0)) {
		return(-1);
	}
	else {
		if (startPos < endPos) {
			for (int i = startPos; i < endPos; i++) {
				printf("| %d |", *((tab->elt) + i));
			}
		}
		else {
			for (int i = endPos; i < startPos; i++) {
				printf("| %d |", *((tab->elt) + i));
			}
		}
	}
	return(0);
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {    //Supprime les éléments du tableau de startPos à endPos puis compacteles deux sous-tableau engendré
	if ((tab == NULL) || (startPos >= tab->size) || (endPos >= tab->size) || (endPos < 0) || (startPos < 0)) {
		return(-1);
	}
	else {
		//On écrit les dernières valeurs à la suite du début du tableau que l'on conserve
		if (startPos < endPos) {
			for (int i = 0; i < (endPos - startPos); i++) {
				*(tab->elt + startPos + i) = *(tab->elt + endPos + i);
			}
			tab->size += startPos - endPos;
		}
		else {
			for (int i = 0; i < (startPos - endPos); i++) {
				*(tab->elt + endPos + i) = *(tab->elt + startPos + i);
			}
			tab->size += endPos - startPos;
		}

		tab->elt = (int*)realloc(tab->elt, tab->size * sizeof(int));
		if (tab->elt == NULL) {
			return(-1);
		}
		return(tab->size);
	}
}

int main() {
	TABLEAU tableau;
	tableau = newArray();
	for (int i = 0; i < 100; i++) {
		*(tableau.elt + i) = i;
	}
	incrementArraySize(&tableau, 10);
	setElement(&tableau, 105, 20);
	displayElements(&tableau, 90, 105);
	printf("\n");
	deleteElements(&tableau, 50, 75);
	displayElements(&tableau, 1, 88);

}