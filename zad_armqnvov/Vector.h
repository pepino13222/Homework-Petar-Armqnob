#pragma once


template <typename T>
class Vector
{
public:
	Vector();
	
	void add(const T& toAdd);
	int getSize();
	bool isEmpty();~Vector();
	T operator [](const int& index);
	Vector<T>& operator =(const Vector<T>& other);
	bool contains(const T& toSearch);
	void print();
private:
	T* collection;
	size_t size;
	size_t last_index;
	void resize();
	void destroy();
	void copy(const Vector<T>& other);


};

template<typename T>
 Vector<T>::Vector()
{
	collection = nullptr;
	size = 0;
	last_index = -1;
}




template<typename T>
 void Vector<T>::add(const T& toAdd)
{
	last_index++;
	if (size == last_index)resize();
	collection[last_index] = toAdd;
}

template<typename T>
 int Vector<T>::getSize()
{
	return last_index + 1;
}

template<typename T>
 bool Vector<T>::isEmpty()
{
	if (last_index == -1)return true;
	else return false;
}

template<typename T>
 void Vector<T>::resize()
{
	size += 5;
	T* tempCollection = collection;
	collection = new T[size];
	for (size_t i = 0; i < last_index; i++)
	{
		collection[i] = tempCollection[i];
	}
}

template<typename T>
 void Vector<T>::destroy()
{
	 if (this->collection) {
	//	 delete[] collection;
		 collection = nullptr;
	 }
}

 template<typename T>
 void Vector<T>::copy(const Vector<T>& other)
 {
	 this->collection = new T[other.last_index+1];
	 size_t size = other.last_index+1;
	 for (size_t i = 0; i < size; i++)
	 {
		 this->collection[i] = other.collection[i];
	 }
 }

template<typename T>
 Vector<T>::~Vector()
{
	destroy();
}

 template<typename T>
 inline T Vector<T>::operator[](const int& index)
 {
	 return collection[index];
 }

 template<typename T>
 Vector<T>& Vector<T>::operator=(const Vector<T>& other)
 {
	 this->destroy();
	 this->copy(other);
	 this->last_index = other.last_index;
	 this->size = other.size;
	 return *this;
 }

 template<typename T>
 inline bool Vector<T>::contains(const T& toSearch)
 {
	 for (size_t i = 0; i <= this->last_index; i++)
	 {
		 if (toSearch == collection[i])return true;
	 }
	 return false;
 }

 template<typename T>
 inline void Vector<T>::print()
 {
	 for (size_t i = 0; i < last_index+1; i++)
	 {
		 printf("%d ", collection[i]);
	 }
 }
