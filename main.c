#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 2
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente{
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente elenco[N];
    char fileName[MAX_STRLEN+1];
    FILE *puntaFile;
    int i, letti;
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da leggere: ");
    scanf("%s", fileName);
    
    // Codice per l'apertura del file e la lettura
    puntaFile = fopen(fileName, "rb");
    if(puntaFile) {
        letti = fread(elenco, sizeof(studente), N, puntaFile);
        while(letti) {
            for(i=0; i<letti; i++) {
                printf("%s; %s; %d; %s\n", elenco[i].nome, elenco[i].cognome, elenco[i].eta, elenco[i].classe);
            }
            letti = fread(elenco, sizeof(studente), N, puntaFile);
        }
    }else {
        printf("\nNon e' possibile aprire il file!");
    }
    fclose(puntaFile);
    
    return (EXIT_SUCCESS);
}