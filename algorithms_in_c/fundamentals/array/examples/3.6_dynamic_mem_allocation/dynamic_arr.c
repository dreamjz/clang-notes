#include <stdlib.h>
#include <stdio.h>

// arc:  counts of the args
// argv: value of the args, argv[0] 
// is the program name
int main(int arc, char *argv[]){
    long int i, j, N = atoi(argv[1]);
    // allocate memory
    int *a = malloc(N * sizeof(int));
    // failed to allocate memory
    if(a == NULL) {
        printf("failed to allocate memory");
        return 1;
    }
    printf("allocate memory success");
    return 0;
}