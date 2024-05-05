#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows,columns;
    int **pointer;
    int i,j;

    printf("Number of rows and colums: ");
    scanf("%d %d",&rows,&columns);

    //Creating one dimentional array and checking is there enough space for it//
    pointer = malloc(rows*sizeof(int*));
    if (pointer == NULL){
        printf("Failed to allocate memory");
        exit(1);
    }

    //Creating second dimensional array and checking is there enough space for it//
    for (i=0; i<rows ; i++) {
        *(pointer + i) = malloc(columns * sizeof(int));
        if (*(pointer +i)== NULL){
        printf("Failed to allocate memory");
        exit(1);}
    }


    printf("Enter the elements of matrix:\n");
    for (i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            printf("Element at [%d][%d]: ",i,j);
            scanf("%d",&pointer[i][j]);
        }
    }

    //for printing all matrix//
    printf("\n");
    for (i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            printf("%d ",pointer[i][j]);
        }
        printf("\n");
    }

    free(pointer);

    return 0;
}