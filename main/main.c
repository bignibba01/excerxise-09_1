/*
Scaricare e decomprimere i file .txt forniti su virtuale (cartella files.zip) all'interno di una cartella di progetto.
Si scriva un programma C, adeguatamente commentato, che verifichi per ogni file se il testo in esso contenuto è corrotto oppure no. 
In questo esercizio, un testo è definito corrotto se contiene caratteri diversi da "a-zA-Z" (alfabeto minuscolo e maiuscolo), "," (virgola) e "'" (apice singolo).

Attenzione: se un file non presenta caratteri corrotti e non ha il terminatore di riga non deve essere conteggiato come corrotto.
Alla fine dell'esercizio visualizzare i nomi dei file corrotti.

VENTRUCCI TOMAS, MARCHETTI DAVIDE, ZOLI FEREDEICO
*/

#define _CRT_SECURE_NO_WARNINGS				//usata per visual studio in modo tale che esegua i metodi sprintf, strcat, fopen, strcpy; considerate non sicure
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* changeFileName(char*, int);			//cambia il nome del file da aprire
_Bool checkValidity(char);			//controlla se il carattere è valido o meno
char* returnFileName(int);

int main() {

	int numberFile = 0;		//001 è il primo file

	while (numberFile <= 58) {

		FILE* fp;			//dichiaro il file da aprire
		char* name = "..\\File\\file";			//stringa da concatenare
		char result;		//carattere letto dal file
		_Bool validity = false;			//flag per indicare se è presente il terminatore di riga (\n)

		char* path = changeFileName(name, numberFile);		//path del file di testo 
		char* fileName = returnFileName(numberFile);		//nome del file di testo incrementato
		numberFile++;			//"indice" dei file di testo

		fp = fopen(path, "r");		//path è il nume del file che ogni volta viene modificato

		if (fp == NULL) {			//non ha avuto accesso al file
			printf("Errore -> Impossibile aprire il file.");
			return 0;
		}

		while ((result = fgetc(fp)) != EOF) {		//se leggendo i caratteri raggiunge la fine del file esce

			if (result == '\n') {			//se è arrivato al terminatore di riga esce dal ciclo, se non è presente il terminatore continua fino alla fine del file
				break;
			}else if (!checkValidity(result)) {		//controlla la vilidità del carattere
				validity = false;
				break;
			}
			else
				validity = true;


		}

		if (!validity) {			//se non è valido il file allora fa l'output
			printf("%s -> non valido\n", fileName);
		}
		
		validity = false;			//rinizializzo il flag a falso

		fclose(fp);
	}

	return 0;
}

char* changeFileName(char* name, int numberFile) {
	char *path;
	char index[8];			//nome del file di testo

	sprintf(index, "%03d", numberFile);			//converto il numero intero in un carattere con almeno 3 cifre e se non ci sono ritora degli 0

	strcat(index, ".txt");		//aggiungo il .txt al numero del file
	path = (char*)malloc((strlen(name) + sizeof(index)));				//alloco lo spazio per la stringa contenente il path del file
	strcpy(path, name);
	
	strcat(path, index);		//concateno il path iniziale con l' "indice" del file di testo
	return path;
}

_Bool checkValidity(char c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == ' ' || c == '\'' || c == ',')		//valore valido => 65-90 (A-Z), 97-122 (a-z), \n, "," , "\'"
		return true;
	else
		return false;
}

char* returnFileName(int numberFile) {			//ritorno soltanto il nome del file di testo, con lo stesso principio di changeFileName
	char* fileName;
	char index[8];

	sprintf(index, "%03d", numberFile);
	strcat(index, ".txt");		//aggiungo il .txt al numero del file

	fileName = (char*)malloc(strlen("file") + sizeof(index));			//alloco lo spazio per la stringa "file + numeroFile + .txt"

	strcpy(fileName, "file");
	strcat(fileName, index);

	return fileName;
}