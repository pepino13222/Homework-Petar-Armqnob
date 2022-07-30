#include "Multitude.h"

 void Multitude::add(const int& toAdd) 
{
	 collection.add(toAdd);
}
 Multitude::Multitude() 
 {
	 simpleName[0] = 'a';
 }

 int Multitude::getSize()
 {
	 return collection.getSize();
 }
