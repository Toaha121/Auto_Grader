#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordLength(char *filename);
int lines(char *filename);
void wordsLines(char *filename);

int main(int argc, char *argv[]) {
  int x, y, z;
  x = wordLength(argv[1]);
  y = lines(argv[1]);
  // wordsLines("poem");

  if (x == 1) {
    printf("%d word on %d line", x, y);
  }

  else {
    printf("%d words on %d lines", x, y);
  }

  // wordsLines("poem");

  return 0;
}









// part 1
int wordLength(char *filename) {

  char **pt;
  int i = 0;
  int x;

  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL) {

    printf("Error! File not found.");
  }

  while (!feof(fptr)) {
    if (i == 0) {
      pt = malloc(sizeof(char *));
      pt[i] = malloc(sizeof(char) * 20);
    } else {
      pt = realloc(pt, sizeof(char *) * (i + 1));
      pt[i] = malloc(sizeof(char) * 20);
    }

    fscanf(fptr, "%s", pt[i]);
    i++;
  }

  fclose(fptr);

  return i;
}





// part 2
int lines(char *filename) {

  char **pt;
  int i = 0;
  int x;
  int y;
  int z = 0;

  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL) {

    printf("Error! File not found.");
  }

  while (!feof(fptr)) {
    if (i == 0) {
      pt = malloc(sizeof(char *));
      pt[i] = malloc(sizeof(char) * 100);
    } else {
      pt = realloc(pt, sizeof(char *) * (i + 1));
      pt[i] = malloc(sizeof(char) * 100);
    }

    fgets(pt[i], 100, fptr);

    for (int z = 0; z <= i; z++) {
      for (int j = 0; j < 100; j++) {
        if (pt[z][j] == ' ')
          ;
        pt[i] = malloc(sizeof(char) * 100);
      }
    }

    i++;
  }

  fclose(fptr);

  return i;
}





void wordsLines(char * filename){



    char * pt;
    int i = 0;
    int x;
    int y;
    int z = 0;
    int length;
    int words = 0;


    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL) {

        printf("Error! File not found.");
    }


    while(!feof(fptr)){
        if(i == 0){
            pt = malloc(sizeof(char));
            //pt[i] = malloc(sizeof(char)*100);
        }
        else{
            pt = realloc(pt, sizeof(char)*(i+1));
            //pt[i] = malloc(sizeof(char) * 100);
        }

        fgets(pt, 100, fptr);
        length = strlen(pt);
        for(int i = 0; i<length; i++){
            if(pt[i] == ' ' || pt[i] == '\n' || pt[i] == '\t'){
            words++;
            }
        }
       printf("%d\n", words);

        i++;

        }


}

