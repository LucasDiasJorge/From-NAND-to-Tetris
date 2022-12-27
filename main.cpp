#include <iostream>
#include <array>

int andGate(int A, int B) {

    if ((A && B) == 1) {
        return 1;
    }

    return 0;

}


int nandGate(int A, int B){

    if(andGate(A,B) == 1){
        return 0;
    }

    return 1;

}

int orGate(int A, int B){

    if(A == 1 && B == 0){
        return nandGate(A,B);
    } else if(A == 0 && B == 1){
        return nandGate(A,B);
    } else if((A && B) == 1){
        return 1;
    }

    return 0;

}

int exclusiveOr(int A, int B){

    int C = nandGate(A,B);
    int D = orGate(A,B);

    return andGate(C,D);

}

void adder(int A, int B, int C, int output[2]){

    output[0] = exclusiveOr(exclusiveOr(A,B),C); //sum
    output[1] = orGate(andGate(exclusiveOr(A,B), C),andGate(A,B)); //carry

}


int main() {

    int output[2];

    adder(1,1,1,output);

    printf("Sum : %d\n", output[0]);

    printf("Carry : %d\n", output[1]);

    return 0;

}
