#pragma once
#include "Vector.h"
class Helper {
public:
    Vector<int> trimm(Vector<int>& forTrim)
    {
        Vector <int> tempVector;
        size_t size = forTrim.getSize();
        for (size_t i = 0; i < size; i++)
        {
            if (!tempVector.isEmpty() && tempVector.contains(forTrim[i]))continue;
            tempVector.add(forTrim[i]);
        }
        forTrim = tempVector;
        return forTrim;
    }
};
