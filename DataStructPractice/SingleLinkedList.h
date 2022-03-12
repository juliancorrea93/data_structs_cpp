#pragma once
#include <iostream>
#include <utility>
#include <memory>
//#include "..\cryptopp850\sha3.h"

template<typename T>
struct Node {
	Node<T> *next;
	//std::unique_ptr<Node<T>> next;
	T data;
};

template<typename T>
class SingleLinkedList {
public:
	SingleLinkedList() :
		head(nullptr),
		size()
	{}
	void pushBack(T data);
	void pushFront(T data);
	void insertAt(T data, int index);
	void removeAt(int index);
	void removeIf(T _data);
	void print();
	T operator[](int index);
	Node<T>* getFront() const;
	std::size_t getSize() const;
	SingleLinkedList(const SingleLinkedList &obj);
	~SingleLinkedList();

private:
	Node<T>* getNode(T data);

	Node<T> *head;
	//std::unique_ptr<Node<T>> head;
	
	std::size_t size;
};