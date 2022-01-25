#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s number",argv[0]);
        return 1;
    }
    
    // convert input to double
    const double inputValue = atof(argv[1]);
    
    // calculate square root
    const double ouputValue = sqrt(inputValue);
    printf("The square root of %f is %f", inputValue, ouputValue);
    
    return 0;
}