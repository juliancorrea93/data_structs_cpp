#include <iostream>
#include <string>

using namespace std;

template <typename T>
class SingleLinkedList {
private:
	T* start;
	T* next;
public:
	SingleLinkedList();
	void insert_at_beginning(T* val);
	void remove(T* val);
	T findNode();
};

template<typename T>
SingleLinkedList<T>::SingleLinkedList() {
	start = NULL;
	next = NULL;
}

template<typename T>
void SingleLinkedList<T>::insert_at_beginning(T* val) {
	if (start == NULL) {
		start = val;
	}
	else {
		T* aux = start;
		start = val;
		next = aux;
	}
}