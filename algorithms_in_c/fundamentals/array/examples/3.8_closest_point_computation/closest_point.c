#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "point.h"

float rand_float(){
    return 0.1 * rand() / RAND_MAX;
}

int main(int argc, char *argv){
    float d = atof(argv[2]);
    int cnt = 0;
    int N = atoi(argv[1]);
    Point *a = malloc(N * sizeof(*a));

    for (int i = 0; i < N; i++){
        a[i].x = rand_float();
        a[i].y = rand_float();
    }

    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N;j++){
            if(distance(a[i],a[j]) < d){
                cnt++;
            }
        }
    }

    printf("%d edges shorter than %f\n", cnt, d);
    return 0;
}
