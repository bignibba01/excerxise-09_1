/*
Scaricare e decomprimere i file .txt forniti su virtuale (cartella files.zip) all'interno di una cartella di progetto.
Si scriva un programma C, adeguatamente commentato, che verifichi per ogni file se il testo in esso contenuto � corrotto oppure no. 
In questo esercizio, un testo � definito corrotto se contiene caratteri diversi da "a-zA-Z" (alfabeto minuscolo e maiuscolo), "," (virgola) e "'" (apice singolo).

Attenzione: se un file non presenta caratteri corrotti e non ha il terminatore di riga non deve essere conteggiato come corrotto.
Alla fine dell'esercizio visualizzare i nomi dei file corrotti.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char* changeFileName(char*, int);			//cambia il nome del file da aprire
_Bool checkValidity(char);			//controlla se il carattere � valido o meno

int main() {
	FILE* fp;
	char* name = "..\\File\\file";			//stringa da concatenare								//strionga finale
	char result;
	_Bool validity = false;			//flag per indicare se � presente il terminatore di riga (\n)
	int numberFile = 001;		//001 � il primo file

	char *path = changeFileName(name, numberFile);
	printf("%s\n", path);
	numberFile++;

	fp = fopen(path, "r");		//path � il nume del file che ogni volta viene modificato

	if (fp == NULL) {
		printf("Errore -> Impossibile aprire il file.");
		return 0;
	}

	while (!feof(fp)) {		//se raggiunge la fine del file esce
		result = fgetc(fp);		//legge un singolo carattere

		if (!checkValidity(result)) {		//controlla la vilidit� del carattere
			validity = false;
			break;
		} else
			validity = true;
		if (result == '\n')			//se � arrivato al terminatore di riga esce dal ciclo, se non � presente il terminatore continua fino alla fine del file
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
	char* path, path1[50];
	path = name;

	printf("%s\n", path);

	char index[7];
	sprintf(index, "%d", numberFile);

	strcat(index, ".txt");		//aggiungo il .txt al numero del file
	printf("%s\n", index);
	strcpy(path1, name);

	strcat(path1, index);

	/*path1 = (char*)malloc(sizeof(path) + sizeof(index));

	strcpy(path1, path);		//creo il path
	strcpy(path1, index);

	printf("%s\n", path1);*/

	return path1;
}

_Bool checkValidity(char c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == '\'' || c == ',' || c == '\n')		//valore valido => 65-90 (A-Z), 97-122 (a-z), \n, "," , "\'"
		return true;
	else
		return false;
}
