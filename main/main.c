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
#include <string.h>

char* changeFileName(char*, int);			//cambia il nome del file da aprire
_Bool checkValidity(char);			//controlla se il carattere è valido o meno

int main() {
	FILE* fp;
	char* name = "..\\File\\file";			//stringa da concatenare								//strionga finale
	char result;
	_Bool validity = false;			//flag per indicare se è presente il terminatore di riga (\n)
	int numberFile = 1;		//001 è il primo file

	char *path = changeFileName(name, numberFile);
	printf("%s\n", path);
	numberFile++;

	fp = fopen(path, "r");		//path è il nume del file che ogni volta viene modificato

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



	return 0;
}

char* changeFileName(char* name, int numberFile) {
	char *path1;
	char index[20];

	sprintf(index, "%03d", numberFile);

	strcat(index, ".txt");		//aggiungo il .txt al numero del file
	printf("%s\n", index);

	printf("%d\n", (strlen(name) + sizeof(index)));

	path1 = (char*)malloc((strlen(name) + sizeof(index)));
	strcpy(path1, name);
	
	strcat(path1, index);

	return path1;
}

_Bool checkValidity(char c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == ' ' || c == '\'' || c == ',' || c == '\n')		//valore valido => 65-90 (A-Z), 97-122 (a-z), \n, "," , "\'"
		return true;
	else
		return false;
}
