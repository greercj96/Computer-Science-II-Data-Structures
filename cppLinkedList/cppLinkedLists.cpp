#include <iostream>

using namespace std; 

class node {
public: 
	int data;
	node *next;
};

class linkedList {
private:
	node* head, *tail;
public:
	linkedList() {
		head = NULL;
		tail = NULL;
	}
	void insertNode(int n) {
		node* newNode = new node;
		newNode->data = n;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next; 
		}

	}

	void getElementByIndex(int index) {
		node* current = head;
		int searchedElement; 
		int count = 0;
		while (current != NULL) {
			if (count == index) 
				cout << "\nThe data element in node " << index << " is " << current->data << endl;
			count++;
			current = current->next;
		}
	}
	void printList() {
		node* temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "-->"; 
			temp = temp->next; 
		}
		cout << "End of list";

	}


};


int main() {
	linkedList a;
	a.insertNode(1);
	a.insertNode(2);
	a.insertNode(3);
	a.insertNode(4);
	a.printList();
	a.getElementByIndex(1);

}
