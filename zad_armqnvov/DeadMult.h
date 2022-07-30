#pragma once
#include "Multitude.h"
class DeadMult : public Multitude
{
public:
	DeadMult();
	DeadMult(const Vector<int>& other);
	void trim(Vector<int>& forTrim);
private:
	
};

