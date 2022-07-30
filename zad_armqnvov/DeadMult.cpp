#include "DeadMult.h"

DeadMult::DeadMult(const Vector<int>& other)
{
	collection = other;
	trim(collection);
}

void DeadMult::trim( Vector<int>& forTrim)
{
	Vector <int> tempVector;
	size_t size = forTrim.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if(!tempVector.isEmpty()&&tempVector.contains(forTrim[i]))continue;
		tempVector.add(forTrim[i]);
	}
	collection = tempVector;
}
