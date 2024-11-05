#include <stdio.h>
#include <stdlib.h>

int *taille(char *fichier){
    FILE *file=fopen(fichier,"r");
    int ligne=0;
    int colonne=0;
    char c;
    while (( c= fgetc(file)) != EOF){
        if ( c== '\n'){
            ligne++;
        }
        if ( (c==' ') && (ligne==0) ){
            colonne++;
        }
    }
    fclose(file);
    int *size1 = malloc(sizeof(int)*2);
    size1[0]=ligne; size1[1]=colonne;
    return size1;
}


void parser(char *fichier, int *tableau){
    FILE *file=fopen(fichier,"r");
    int i=0;
    int c;
    while (( c= fgetc(file)) != EOF){
        if ((c!=' ')&&(c!='\n')){
            tableau[i]=c;
            i++;
        }
    } 
}

unsigned char mapcrea(int *tableau){
    int *size=taille("carte.txt");
    unsigned char themap[size[0] *size[1]];
    int i=0;
    for (i=0; i<size[0]*size[1]; i++){
        if (themap[i]==5){
            themap[i]="CELL_EMPTY";
        }
        if (themap[i]==4){
            themap[i]="CELL_CITY";
        }
        if (themap[i]==3){
            themap[i]="CELL_STONE";
        }
        if (themap[i]==2){
            themap[i]="CELL_TREE";
        }
        if (themap[i]==1){
            themap[i]="CELL_WATER";
        }
    }
    free(size);
}


int main(int argc, char* argv){
    int *size=taille("carte.txt");
    int tableau[size[0]*size[1]];
    printf("%i",size[0]*size[1]);
    parser("carte.txt", tableau);
}
