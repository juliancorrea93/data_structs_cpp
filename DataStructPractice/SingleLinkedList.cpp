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
	size += 1;
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
	size += 1;
}

template<typename T>
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




template<typename T> 
void SingleLinkedList<T>::removeAt(int index) {
	if (index < 0 || index > size + 1) {
		std::cout << "Element cannot be inserted at this position as the location is invalid";
	}
	else {
		Node<T> *temp = head;
		while (index > 0) {
			temp = temp->next;
		}
		//remove element and check for end of list
	}
}


template<typename T> 
void SingleLinkedList<T>::removeIf(T _data) {
	
	while (head->data == _data) {
		head = head->next;
		size -= 1;
	}

	Node<T> *temp = head;

	while (temp->next != nullptr) {
		if (temp->next->data == _data) {
			temp->next = temp->next->next;
			size -= 1;
		}
		else {
			temp = temp->next;
		}
	}
}

template<typename T>
T SingleLinkedList<T>::operator[](int index) {
	return T();
}

template<typename T>
Node<T>* SingleLinkedList<T>::getFront() const
{
	return head;
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
}

template<typename T>
void print(SingleLinkedList<T> list) {
	Node<T> *temp = list.getFront();
	if (temp == nullptr) {
		std::cout << "List is empty" << std::endl << std::flush;
	}
	else {
		std::cout << "-----PRINTING LIST-----" << std::endl << std::flush;
		while (temp != nullptr) {
			std::cout << temp->data << std::endl << std::flush;
			temp = temp->next;
		}
		std::cout << "-----END OF LIST-----" << std::endl << std::flush;
	}
}

void testForObj() {
	Person p1;
	Person p2 = Person("John", "Somewhere", 20);
	Person p3 = Person("Jane", "Nowhere", 35);

	SingleLinkedList<Person> list;

	list.pushBack(p1);
	list.pushBack(p2);
	list.pushBack(p3);
	print(list);
	//std::cout << list[1] << std::endl << std::flush;
	list.removeIf(Person("John", "Somewhere", 20)); //TODO: BUG here
	print(list);
}
void testForPrim() {

	SingleLinkedList<int> listInt;
	listInt.pushBack(2);
	listInt.pushBack(2);
	listInt.pushBack(5);
	//print(listInt);
	listInt.pushBack(4);

	listInt.removeIf(2);
	
	print(listInt);
}

int main() {
	testForObj();
	
	testForPrim();
	
}