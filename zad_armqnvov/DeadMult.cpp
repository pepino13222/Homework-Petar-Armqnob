#include "DeadMult.h"
DeadMult::DeadMult( Vector<int>& other)
{
	Helper hp;
	//collection = other;
	collection = hp.trimm(other);
}


