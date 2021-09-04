#include <iostream>
//#include "..\cryptopp850\sha3.h"
#include "Person.h"
#include "SingleLinkedList.h"



template<class T> SingleLinkedList<T>::SingleLinkedList() : 
	head(nullptr),
	size(0) {
}

template<class T>
void SingleLinkedList<T>::append(T data) {
	Node<T>* newnode = getNode(data);
	//Node<T>* newnode = new Node<T>;

	if (head == NULL) {
		head = newnode;
	}
	else {
		Node<T> *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
	size += 1;
}

template<class T>
void SingleLinkedList<T>::insert(T data) {
	//Node<T>* newnode = getNode(data);
	Node<T>* newnode = new Node<T>;

	if (head == NULL) {
		head = newnode;
	}
	else {
		Node<T>* temp;
		temp = newnode;
		temp->next = head;
		head = newnode;
	}
	size += 1;
}

template<class T>
void SingleLinkedList<T>::insertAt(T data, int index) {
	if (index < 0 || index > size + 1) {
		cout << "Element cannot be inserted at this position as the location is invalid";
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
			Node<T> temp;
			int count = 1;
			temp = head;
			while (count != index) {
				temp = temp->next;
				count++;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
}

template<class T>
Node<T>* SingleLinkedList<T>::getStart()
{
	return head;
}

template<class T>
void SingleLinkedList<T>::printList() {
	Node<T> *temp = head;
	if (head == NULL) {
		std::cout << "List is empty" << std::endl;
	}
	else {
		do {
			std::cout << temp->data << std::endl <<std::flush;
			temp = temp->next;
		} while (temp != NULL);
		std::cout << std::endl << std::flush;
	}
}


template<typename T> void SingleLinkedList<T>::removeAt(int index) {
	if (index < 0 || index > size + 1) {
		std::cout << "Element cannot be inserted at this position as the location is invalid";
	}
	else {
		
	}
}


template<typename T> void SingleLinkedList<T>::removeIf(T _data) {
	Node<T> *temp = head;
	
	while (head->data == _data) {
		head = head->next;
		size -= 1;
	}
	while (temp->next != NULL) {
		if (temp->next->data == _data) {
			temp->next = temp->next->next;
			size -= 1;
		}
		else {
			temp = temp->next;
		}
	}
}

template<class T>
T SingleLinkedList<T>::operator[](int index) {
	return T();
}

template<class T> Node<T>* SingleLinkedList<T>::getNode(T data) {
	Node<T> *newnode;

	newnode = new Node<T>;

	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}

void testForObj() {
	Person p1;
	Person p2 = Person("John", "Somewhere", 20);
	Person p3 = Person("Jane", "Nowhere", 35);

	SingleLinkedList<Person> list;

	list.append(p1);
	list.append(p2);
	list.append(p3);
	list.printList();
	//std::cout << list[1] << std::endl << std::flush;
	list.removeIf(Person("John", "Somewhere", 20)); //TODO: BUG here
	list.printList();
}
void testForPrim() {

	SingleLinkedList<int> listInt;
	listInt.append(2);
	listInt.append(2);
	listInt.append(5);
	listInt.printList();
	listInt.append(4);
	listInt.removeIf(2);
	listInt.printList();
}

int main() {
	testForObj();
	
	testForPrim();
}