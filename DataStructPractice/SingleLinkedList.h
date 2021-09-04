#pragma once
#include <iostream>
//#include "..\cryptopp850\sha3.h"

template<class T>
struct Node {
	//Node();
	//Node(Node<T> *nextNode,T wrappedData);
	Node<T>* next;
	T data;
};

template<class T>
class SingleLinkedList {
public:
	SingleLinkedList();
	//insert at the end of the list
	void append(T data);
	//insert at front of the list
	void insert(T data);
	//insert at a certain location in the list. shift remaining nodes to the right
	void insertAt(T data, int index);
	Node<T>* getStart();
	//print the list
	void printList();
	//remove all nodes that match a value TODO: add support for user defined classes
	void removeAt(int index);
	void removeIf(T _data);
	T operator[](int index);
	//~SingleLinkedList();

private:
	Node<T>* getNode(T data);

	Node<T>* head;
	std::size_t size;
};


