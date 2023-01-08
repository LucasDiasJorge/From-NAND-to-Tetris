#include <iostream>

int notGate(int A) {

    if (A == 1) {
        return 0;
    }

    return 1;

}

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

void fourBitAdder(int firstFourBitsInput[4], int secondFourBitsInput[4], int carry, int output[5]){

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

    //printf("The sum is %d %d %d %d , and the carry is %d", output[0], output[1], output[2], output[3], output[4]);

}

void ArithmeticLogicUnit(int firstFourBitsInput[4], int secondFourBitsInput[4], int operation){

    int outputAdder[5];

    int treatedSecondFourBitsInput[4];

    for(int i = 0; i < 4; i++){
        treatedSecondFourBitsInput[i] = exclusiveOr(secondFourBitsInput[i],operation);
    }

    fourBitAdder(firstFourBitsInput,treatedSecondFourBitsInput,operation,outputAdder);

    int output[7];

    output[0] = outputAdder[0]; // Number
    output[1] = outputAdder[1]; // Number
    output[2] = outputAdder[2]; // Number
    output[3] = outputAdder[3]; // Number

    output[4] = outputAdder[4]; // Carry
    output[5] = outputAdder[0]; // Is it negative ?
    output[6] = andGate(andGate(andGate(notGate(output[0]),notGate(output[1])), notGate(output[2])), notGate(output[3])); // Zero

    printf(" THE SUM IS %d %d %d %d \n THE CARRY IS %d \n IS IT NEGATIVE ? %d \n IS IT ZERO ? %d\n", output[0],output[1],output[2],output[3],output[4],output[5],output[6]);

}

int main() {

    int firstFourBitsInput[4] = {1,1,1,0};
    int secondFourBitsInput[4] = {1,1,0,0};

    ArithmeticLogicUnit(firstFourBitsInput,secondFourBitsInput, 0);

    return 0;

}
