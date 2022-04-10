#include <iostream>
//#include "..\cryptopp850\sha3.h"
#include "Person.h"
#include "SingleLinkedList.h"

template<typename T>
void SingleLinkedList<T>::pushBack(T data) {
	Node<T>* newnode = getNode(std::move(data));

	if (head == nullptr) {
		head = newnode;
	}
	else {
		Node<T> *temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
	size++;
}

template<typename T>
void SingleLinkedList<T>::pushFront(T data) {
	Node<T>* newnode = getNode(std::move(data));

	if (head == nullptr) {
		head = newnode;
	}
	else {
		Node<T>* temp;
		temp = newnode;
		temp->next = head;
		head = newnode;
	}
	size++;
}

template<typename T>
void SingleLinkedList<T>::insertAt(T data, int index) {
	if (index < 0 || index > size + 1) {
		std::cout << "Element cannot be inserted at this position as the location is invalid" << std::endl << std::flush;
	}
	else {
		//Node<T> *newnode = getNode(data);

		Node<T>* newnode = new Node<T>;

		newnode->data = data;

		if (index == 0) {
			newnode->next = head;
			head = newnode;
		}
		else {
			Node<T> *temp;
			int count = 1;
			temp = head;
			while (count != index) {
				temp = temp->next;
				count++;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}
		size++;
	}
}


template<typename T> 
void SingleLinkedList<T>::removeAt(int index) {
	if (index < 0 || index > size + 1) {
		std::cout << "Element cannot be inserted at this position as the location is invalid";
	}
	else {
		Node<T> *temp = head;
		Node<T> *prev = temp;
		if (index == 0 && size > 0) {
			head = temp->next;
		}
		else {
			while (index > 0) {
				prev = temp;
				temp = temp->next;
				index--;
			}
			prev->next = temp->next;
		}
		
		delete temp;
		size--;
	}
}


template<typename T> 
void SingleLinkedList<T>::removeIf(T _data) {
	
	while (head->data == _data) {
		head = head->next;
		size--;
	}

	Node<T> *temp = head;

	while (temp->next != nullptr) {
		if (temp->next->data == _data) {
			temp->next = temp->next->next;
			size--;
		}
		else {
			temp = temp->next;
		}
	}
}

template<typename T>
void SingleLinkedList<T>::print()
{
	Node<T> *temp = head;
	if (size == 0) {
		std::cout << "here" << std::endl;
		std::cout << "List is empty" << std::endl << std::flush;
	}
	else {
		std::cout << "-----PRINTING LIST-----" << std::endl << std::flush;
		while (temp != nullptr) {
			std::cout << temp->data << std::endl << std::flush;
			temp = temp->next;
		}
		std::cout << "List size is: " << size << std::endl << std::flush;
		std::cout << "-----END OF LIST-----" << std::endl << std::flush;
	}
}

template<typename T>
Node<T>* SingleLinkedList<T>::getFront() const
{
	return head;
}

template<typename T>
std::size_t SingleLinkedList<T>::getSize() const
{
	return size;
}

template<typename T> 
Node<T>* SingleLinkedList<T>::getNode(T data) {
	Node<T> *newnode;

	newnode = new Node<T>;

	newnode->data = std::move(data);
	newnode->next = nullptr;

	return newnode;
}

template<typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	Node<T>* current = head;

	while (current != nullptr) {
		
		Node<T>* next_node = current->next;
		delete current;
		current = next_node;
	}
	
}

template<typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T> &obj)
{
	Node<T> *current = obj.getFront();
	Node<T> *newnode = getNode(current->data);
	head = newnode;
	while (current->next != nullptr) {
		pushBack(current->next->data);
		current = current->next;
	}
	size = obj.size;
}



template<typename T>
T SingleLinkedList<T>::operator[](int index) {
	Node<T>* current = head;

	while (current != nullptr && index > 0) {
		current = current->next;
		index--;
	}
	return current->data;
}

void testForObj() {
	Person p1;
	Person p2 = Person("John", "Somewhere", 20);
	Person p3 = Person("Jane", "Nowhere", 35);

	SingleLinkedList<Person> list;
	list.print();
	list.pushBack(p1);
	list.pushBack(p2);
	list.pushBack(p3);
	list.pushFront(Person("Arelly", "Somewhere", 22));
	list.print();
	list.removeIf(Person("John", "Somewhere", 20));
	list.removeAt(1);
	list.removeAt(0);
	list.print();
}
void testForPrim() {

	SingleLinkedList<int> listInt;
	listInt.pushBack(2);
	listInt.pushBack(2);
	listInt.pushFront(20);
	listInt.pushBack(5);
	listInt.pushBack(4);
	listInt.insertAt(44, 1);
	listInt.removeAt(0);
	listInt.removeIf(2);
	listInt.print();
}

void tests() {
	testForObj();
	
	testForPrim();
	
}