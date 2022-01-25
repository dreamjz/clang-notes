#include <stdio.h>
#include <string.h>

#define N 10000

const int INT_BIT_SIZE = sizeof(int) * 8;
const int ARR_LEN = (N / INT_BIT_SIZE) + 1;

void set_bit(int a[], int k);
void clear_bit(int a[], int k);
int test_bit(int a[], int k);
void print_bit(int n);
void print_bit_arr(int a[]);
void print_arr(int a[]);

int main(){
    // set all elements to 0
    int a[ARR_LEN];
    memset(a, 0, sizeof(int) * ARR_LEN);

    // assume that every one is prime
    for (int i = 2; i < N; i++){
        set_bit(a, i);
    }

    for (int i = 2; i < N; i++){
        for (int j = i; (i * j) < N; j++){
            // set ele to 0 if it is nonprime
            clear_bit(a, i * j);
        }
    }

    printf("Primes: [");
    for (int i = 2; i < N; i++)
    {
        if(test_bit(a,i)){
            printf("%d ", i);
        }
    }
    printf("]\n");

    print_bit_arr(a);

    printf("Size of arr: %d bytes",sizeof(a));

    return 0;
}

void set_bit(int a[], int k){

    int i = k / INT_BIT_SIZE;
    int pos = k % INT_BIT_SIZE;

    // 0000 ... 0001
    unsigned int flag = 1;
    // shifted pos positions
    flag = flag << pos; 
    // set the bit at the k-th position in a[i]
    a[i] = a[i] | flag;
}

void clear_bit(int a[], int k){
    int i = k / INT_BIT_SIZE;
    int pos = k % INT_BIT_SIZE;

    unsigned int flag = 1;
    flag = ~(flag << pos);
    a[i] = a[i] & flag;
}

int test_bit(int a[], int k){
    int i = k / INT_BIT_SIZE;
    int pos = k % INT_BIT_SIZE;
    
    unsigned int flag = 1;
    flag = flag << pos;

    return (a[i] & flag) != 0;
}

void print_bit(int n){
    printf("[");
    for (int i = INT_BIT_SIZE - 1; i >= 0; i--)
    {
        printf("%u", (n >> i) & 1);
    }
    printf("]\n");
}

void print_bit_arr(int a[]){
    for (int i = 0; i < ARR_LEN; i++){
        printf("%d: ", i);
        print_bit(a[i]);
    }
}

void print_arr(int a[]){
    printf("[");
    for (int i = 0; i < ARR_LEN; i++)
    {
        printf("%d ", a[i]);
    }
    printf("]\n");
}