// zad_armqnvov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include "DeadMult.h"
#include "PreedicateMulti.h"
#include <fstream>
//Checks if the element is divisible by one of the args
bool predicateOne(int element, Vector<int>& args) {
    const size_t size = args.getSize();
    for (size_t i = 0; i < size; i++)
    {
        if (element % args[i] == 0) return true;
    }
    return false;
}

//Checks if the element is divisible by all args
bool predicateTwo(const int& element, Vector<int>& args) {
   const size_t size = args.getSize();
   bool flag = true;
    for (size_t i = 0; i < size; i++)
    {
        if (element % args[i] != 0)flag = false;
    }
    return flag;
}


int main()
{
    Vector <int> testVector;

    testVector.add(1);
    testVector.add(2);
    testVector.add(2);
    testVector.add(2);
    testVector.add(6);

    testVector.add(3);
    testVector.add(4);

    Vector<int> testArgs;
   // testArgs.add(3);
    testArgs.add(2);
   // Multitude* test = new DeadMult(testVector);
    Multitude* testPred = new PreedicateMulti(predicateTwo, testVector, testArgs);

   // printf("%d\n", testPred->getSize());
    testPred->getCollection().print();
    //printf("%d %d \n", testVector[0], testVector[1]);0

    std::ifstream is;
    is.open("Input.txt");
    if (is.is_open()) {
        while (is) {
            char buffer[256];
            is.getline(buffer, 255);
            std::ifstream isb;
            isb.open(buffer);
        }
    }

    return 0;
}

