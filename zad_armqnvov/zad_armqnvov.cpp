// zad_armqnvov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include "DeadMult.h"
#include "FirstFunctionClass.h"
#include "SecondFunctionCLass.h"
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
    Vector<int> finalVector;

    Multitude* currentMultitude;

    testVector.add(1);
    testVector.add(2);
    testVector.add(3);
   // testVector.add(2);
   // testVector.add(2);
   // testVector.add(6);

    //testVector.add(3);
  //  testVector.add(4);

    Vector<int> testArgs;
    testArgs.add(3);
    testArgs.add(2);
    
    Multitude* test = new DeadMult(testVector);
    Multitude* test2 = new DeadMult(testArgs);
   // Multitude* testPred = new PreedicateMulti(predicateTwo, testVector, testArgs);
    Vector<Multitude*> testCollection;
    testCollection.add(test2);
  //  test->getCollection().print();
  // Multitude* testSecond = new SecondFunctionCLass(testVector,testCollection);
   Multitude* testFirst = new FirstFunctionClass(testVector,testCollection);
    Vector<int> result = testFirst->getCollection();
    result.print();
   // printf("%d\n", testPred->getSize());
   // testPred->getCollection().print();
    //printf("%d %d \n", testVector[0], testVector[1]);0

    std::ifstream is;
    is.open("Input.txt");
    if (is.is_open()) {
        while (is) {
            char buffer[256];
            is.getline(buffer, 255);
            std::ifstream isb;
            isb.open(buffer, std::ios::out | std::ios::binary);
            uint16_t N, T;
            if (isb.is_open()) {
                isb.read((char*)&N, sizeof(N));
                isb.read((char*)&T, sizeof(T));
                int n = (int)N;
                int t = (int)T;
                Vector<int> tempVector;
                for (size_t i = 0; i < n; i++)
                {
                    uint32_t readed;
                    isb.read((char*)&readed, sizeof(readed));
                    tempVector.add((int)readed);
                }
                if (t == 0) {
                    Multitude* temp = new DeadMult(tempVector);
                    Vector<Multitude*> collectionMultitudes;
                    collectionMultitudes.add(temp);
                    Multitude* temp2 = new SecondFunctionCLass(finalVector, collectionMultitudes);
                    finalVector = temp2->getCollection();
                }
                else if (t == 1) {
                    Multitude* temp = new PreedicateMulti(predicateTwo, finalVector, tempVector);
                    Vector<Multitude*> collectionMultitudes;
                    collectionMultitudes.add(temp);
                    Multitude* temp2 = new SecondFunctionCLass(finalVector, collectionMultitudes);
                    finalVector = temp2->getCollection();
                }
                else if (t == 2) {
                    Multitude* temp = new PreedicateMulti(predicateOne, finalVector, tempVector);
                    Vector<Multitude*> collectionMultitudes;
                    collectionMultitudes.add(temp);
                    Multitude* temp2 = new SecondFunctionCLass(finalVector, collectionMultitudes);
                    finalVector = temp2->getCollection();
                }
                else if (t == 8) {
                    Multitude* temp = new DeadMult(tempVector); Vector<Multitude*> collectionMultitudes;
                    collectionMultitudes.add(temp);
                    Multitude* temp2 = new FirstFunctionClass(finalVector, collectionMultitudes);
                    finalVector = temp2->getCollection();
                }
                else if (t == 9) {
                    Multitude* temp = new PreedicateMulti(predicateTwo, finalVector, tempVector);
                    Vector<Multitude*> collectionMultitudes;
                    collectionMultitudes.add(temp);
                    Multitude* temp2 = new FirstFunctionClass(finalVector, collectionMultitudes);
                    finalVector = temp2->getCollection();
                }
                else if (t == 10) {
                    Multitude* temp = new PreedicateMulti(predicateOne, finalVector, tempVector);
                    Vector<Multitude*> collectionMultitudes;
                    collectionMultitudes.add(temp);
                    Multitude* temp2 = new FirstFunctionClass(finalVector, collectionMultitudes);
                    finalVector = temp2->getCollection();
                }
            }
        }
    }

    int first = 0, second = 0;

    std::cin >> first >> second;

    for (size_t i = 0; i < finalVector.getSize(); i++)
    {
        if (finalVector[i] > first && finalVector[i] < second)printf("%d", finalVector[i]);
    }

    return 0;
}

