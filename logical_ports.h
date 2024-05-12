#ifndef LOGICAL_PORTS_H
#define LOGICAL_PORTS_H

int notGate(int A);

int andGate(int A, int B);

int nandGate(int A, int B);

int orGate(int A, int B);

int exclusiveOr(int A, int B);

int norGate(int A, int B);

void adder(int A, int B, int C, int output[2]);

void fourBitAdder(int firstFourBitsInput[4], int secondFourBitsInput[4], int carry, int output[5]);

void ArithmeticLogicUnit(int firstFourBitsInput[4], int secondFourBitsInput[4], int operation);

#endif