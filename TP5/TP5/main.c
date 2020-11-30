#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TAB2SIZE 100

int main() {
	int* myTab1 = malloc(10 * sizeof(int));

	//Cr�ation d'un tableau myTab2
	int* myTab2 = NULL;

	//test de la fonction d'initialisation du tableau
	int tabSize = TAB2SIZE;

	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) {
		initTab(myTab2, tabSize);
	}
	else {
		printf("m�moire insuffisante"); 
		return(-1);
	}
	
	//On remplit les 20 premi�res cases du tableau avec les nombres de 1 � 20
	int nbElts = 20;
	for (int i = 0; i < nbElts; i++) {
		*(myTab2 + i) = i + 1;
	}

	afficheTab(myTab2,tabSize,nbElts); //Affichage des premiers �l�ments du tableau

	free(myTab2); //Destruction du tableau
}