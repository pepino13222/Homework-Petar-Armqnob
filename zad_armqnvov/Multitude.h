#pragma once
#include "Vector.h"
#include "Helpers.h"
class Multitude
{

public:
	virtual bool contains(const int& toSearch) {
		return collection.contains(toSearch);
	}

	virtual void add(const int& toAdd);

	Multitude();
	virtual int getSize();
	virtual Vector<int>& getCollection() { return collection; }

private:
	char simpleName[4];
protected:
	Vector<int> collection;
	
};

