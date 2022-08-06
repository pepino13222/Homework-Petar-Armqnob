#include "FirstFunctionClass.h"

FirstFunctionClass::FirstFunctionClass(Vector<int>& other, Vector<Multitude*>& others)
{
	Helper hp;
	for (size_t i = 0; i < other.getSize(); i++)
	{
		if (others[0]->getCollection().contains(other[i])) {
			collection.add(other[i]);
		}
	}
	collection = hp.trimm(collection);
}
