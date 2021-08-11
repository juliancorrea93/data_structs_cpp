#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Container {
private:
	T* prev;
	T* data_ptr;
	T* next;
public:
	Container(T val);
	~Container();
};

template<typename T>
Container<T>::Container(T val) {
	data_ptr = &val;
}

template<typename T>
Container<T>::~Container() {
	delete[] data_ptr;
	delete[] prev;
	delete[] next;
}