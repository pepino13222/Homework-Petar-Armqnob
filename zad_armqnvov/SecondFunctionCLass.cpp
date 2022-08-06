#include "SecondFunctionCLass.h"

SecondFunctionCLass::SecondFunctionCLass(Vector<int>& other,Vector<Multitude*>& others)
{
	Helper hp;
	if (others.isEmpty())return;
	for (size_t i = 0; i < others.getSize(); i++)
	{
		for (size_t j = 0; j < others[i]->getCollection().getSize(); j++)
		{
			other.add(others[i]->getCollection()[j]);
		}
	}
	collection = hp.trimm(other);
//	collection = other;
}
