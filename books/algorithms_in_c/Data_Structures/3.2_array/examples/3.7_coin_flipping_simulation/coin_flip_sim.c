// programs 3.7
#include <stdlib.h>
#include <stdio.h>

int heads(){
    return rand() < RAND_MAX / 2;
}

void print_arr(int a[], int len){
    printf("\n[");
    for (int i = 0; i < len; i++){
        printf("%d ", a[i]);
    }
    printf("]\n");
}

int main(int argc, char *argv[]){
    int i, j, cnt;
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    int *f = malloc((N + 1) * sizeof(int));

    // init array with 0
    for(j = 0; j <= N; j++){
        f[j] = 0;
    }

    print_arr(f, N + 1);

    
    for (i = 0; i < M; i++, f[cnt]++){
        for (cnt = 0, j = 0; j <= N; j++){
            if(heads()){
                cnt++;
            }
        }
    }

    print_arr(f, N + 1);

    for (j = 0; j <= N; j++){
        printf("%2d", j);
        for (i = 0; i < f[j]; i+=10){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}