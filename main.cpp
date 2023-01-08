#include <iostream>

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

void fourBitAdder(int firstFourBitsInput[4], int secondFourBitsInput[4], int carry){

    int output[5];

    int aux[2];

    adder(firstFourBitsInput[3], secondFourBitsInput[3], carry, aux);
    output[3] = aux[0];
    adder(firstFourBitsInput[2],secondFourBitsInput[2],aux[1],aux);
    output[2] = aux[0];
    adder(firstFourBitsInput[1],secondFourBitsInput[1],aux[1],aux);
    output[1] = aux[0];
    adder(firstFourBitsInput[0],secondFourBitsInput[0],aux[1],aux);
    output[0] = aux[0];

    output[4] = aux[1];

    printf("The sum is %d %d %d %d , and the carry is %d", output[0], output[1], output[2], output[3], output[4]);

}

int main() {

    int firstFourBitsInput[4] = {0,0,1,1};
    int secondFourBitsInput[4] = {0,0,0,1};

    fourBitAdder(firstFourBitsInput,secondFourBitsInput,0);

    return 0;

}
