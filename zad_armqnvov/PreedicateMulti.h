#pragma once
#include "Multitude.h"


class PreedicateMulti : public Multitude
{
public:
	template <typename Predicate>
	PreedicateMulti(Predicate& predicate, Vector<int>& finalmULT, Vector<int>& args);
};

template<typename Predicate>
inline PreedicateMulti::PreedicateMulti(Predicate& predicate, Vector<int>& finalMult, Vector<int>& args)
{
	Vector<int> tempVector;
	size_t sizeOfFinalVector = finalMult.getSize();
	for (size_t i = 0; i < sizeOfFinalVector; i++)
	{
		if (predicate(finalMult[i], args))tempVector.add(finalMult[i]);
	}
	collection = tempVector;
}
