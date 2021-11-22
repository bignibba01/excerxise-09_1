/*
Scaricare e decomprimere i file .txt forniti su virtuale (cartella files.zip) all'interno di una cartella di progetto.
Si scriva un programma C, adeguatamente commentato, che verifichi per ogni file se il testo in esso contenuto è corrotto oppure no. 
In questo esercizio, un testo è definito corrotto se contiene caratteri diversi da "a-zA-Z" (alfabeto minuscolo e maiuscolo), "," (virgola) e "'" (apice singolo).

Attenzione: se un file non presenta caratteri corrotti e non ha il terminatore di riga non deve essere conteggiato come corrotto.
Alla fine dell'esercizio visualizzare i nomi dei file corrotti.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void changeFileName(char*);			//cambia il nome del file da aprire
_Bool checkValidity(char);			//controlla se il carattere è valido o meno

int main() {
	FILE* fp;
	char* name = "..\\File\\file000.txt";
	char result = NULL;
	_Bool validity = false;			//flag per indicare se è presente il terminatore di riga (\n)
	int numberFile = 001;		//001 è il primo file

	fp = fopen(name, "r");		//files è il nume del file che ogni volta viene modificato

	if (fp == NULL) {
		printf("Errore -> Impossibile aprire il file.");
		return 0;
	}

	while (!feof(fp)) {		//se raggiunge la fine del file esce
		result = fgetc(fp);		//legge un singolo carattere

		if (!checkValidity(result)) {		//controlla la vilidità del carattere
			validity = false;
			break;
		} else
			validity = true;
		if (result == '\n')			//se è arrivato al terminatore di riga esce dal ciclo, se non è presente il terminatore continua fino alla fine del file
			break;
	}
	if (validity) {
		//stringa valida, contiene sia i caratteri giusti che il temrinatore
		printf("valido");
	}
	else {
		printf("non valido");
	}

	validity = false;
	changeFileName(name);

	return 0;
}

void changeFileName(char *name) {
	
}

_Bool checkValidity(char c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == '\'' || c == ',' || c == '\n')		//valore valido => 65-90 (A-Z), 97-122 (a-z), \n, "," , "\'"
		return true;
	else
		return false;
}
