// Exmaple: c library function - getchar()
#include <stdio.h>

int main() {
    char c;

    printf("Enter character:");
    c = getchar();

    printf("Character entered:");
    putchar(c);

    return(0);
}