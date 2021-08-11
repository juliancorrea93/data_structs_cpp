#include <iostream>

using namespace std;

template<class T>
struct Node {
	Node<T> *next;
	T data;
};

template<class T>
class SingleLinkedList {
public:
	SingleLinkedList<T>() {
		head = NULL;
		size = 0;
	}
	void append(T data) {
		Node<T> *newnode = getNode(data);

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
	void insert(T data) {
		Node<T> *newnode = getNode(data);

		if (head == NULL) {
			head = newnode;
		}
		else {
			Node<T> *temp;
			temp = newnode;
			temp->next = head;
			head = newnode;
		}
		size += 1;
	}
	void insertAt(T data, int index) {
		if (index < 0 || index > size + 1) {
			cout << "Element cannot be inserted at this position as the location is invalid";
		}
		else {
			Node<T> *newnode = getNode(data);

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
	void printList() {
		Node<T> *temp = head;
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			do {
				cout << temp->data << "\t";
				temp = temp->next;
			} while (temp != NULL);
			cout << endl;
		}
	}
	void remove(T data) {
		Node<T> *temp = head;
		Node<T> *prev = NULL;
		while (temp) {
			while (temp->data == data) {
				Node<T> *old_temp = temp;
				temp = temp->next;
				if (old_temp == head) {
					head = temp;
				}
				if (prev) {
					prev->next = temp;
				}
				delete old_temp;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	
private:
	Node<T> *getNode(T data) {
		Node<T> *newnode;

		newnode = new Node<T>;

		newnode->data = data;
		newnode->next = NULL;

		return newnode;
	}

	Node<T> *head;
	int size;
};

int main() {
	SingleLinkedList<int> list;
	list.append(2);
	list.append(2);
	list.insert(3);
	list.append(5);
	list.printList();
	list.append(4);
	list.insert(8);
	list.remove(2);
	list.remove(3);
	list.remove(5);
	list.printList();
}