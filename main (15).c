#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 3

typedef struct datiStudente{
  char nome[20];
  char cognome[20];
  int matematica;
  int italiano;
  int inglese;
  int storia;
  float media;
} Studente;

void leggiFile(FILE*fp, Studente* v[], char* nomeFile){
  fp=fopen(nomeFile,"r");

  char line[100];
  int i=0;
  

  while(fgets(line,sizeof(line), fp)!=NULL){
    int newLine=strcspn(line,"\n");
    line[newLine]=0;
    v[i]=(Studente*)malloc(sizeof(Studente));

    sscanf(line,"%[^,],%[^,],%d,%d,%d,%d",
      v[i]->nome,
      v[i]->cognome,
      &v[i]->matematica,
      &v[i]->italiano,
      &v[i]->inglese,
      &v[i]->storia
       );
    /*int media=(v[i]->matematica+
      v[i]->italiano+
      v[i]->inglese+
      v[i]->storia)/4;
    v[i]->media=media;*/
    int media=calcolaMedia(v,i);
      v[i]->media=media;
    i++;


      
  }
  fclose(fp);
  
  
}

int calcolaMedia(Studente* vet[],int cnt){
  float media;
  media = (vet[cnt]->matematica+vet[cnt]->italiano+vet[cnt]->inglese+vet[cnt]->storia)/4;
  return media;
}

void stampaFile(Studente* vet[], FILE *fp){
fp=fopen("studentiMedia.csv","w");
  for(int i=0; i<3; i++){
    fprintf(fp, "%s,%s,%d,%d,%d,%d, %0.2f\n", vet[i]->nome, vet[i]->cognome, vet[i]->matematica, vet[i]->italiano, vet[i]->inglese, vet[i]->storia, vet[i]->media);

  }

fclose(fp);
}

int main () {
  FILE* fpr,*fpw;
  Studente* s[DIM];
  char *nomeFile="studenti.csv";

  leggiFile(fpr,s, nomeFile);
  stampaFile(s,fpw);

    
  
}