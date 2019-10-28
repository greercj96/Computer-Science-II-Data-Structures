#include <iostream>

using namespace std; 

class node {
public: 
	string data;
	node *next;
	
};


class linkedList {
	private:
		node* head, *tail;
		node* top= NULL;

	public:
		linkedList* cityKeys[8];

		linkedList() {
			head= NULL;
			tail= NULL;
			
		}


	bool isempty() {
		if (top == NULL) {
			return true;
		}
		else {
			return false;
		}

	}

	void push(int data) {
		cout << "\n Adding " << data;
		node* newNode = new node();
		newNode->data = data;
		newNode->next = top;
		top = newNode;
	}

	void pop() {
		if (isempty()) {
			cout << "Stack is Empty";
		}
		else {
		cout <<"\n Removing " << top->data;
			node* temp = top;
			top = top->next;
			delete(temp);
		
		}
	}

		void insertNode(string n) {
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
				cout << temp->data << "->" ;
				temp = temp->next;
			}
			cout << "End of list";

		}

		void printStack() {
			node* temp = new node;
			temp = top;
			while (temp != NULL) {
				cout << "    \n";
				cout << "    "<< temp->data<< "    \n";
				cout << "    |\n";
				temp = temp->next;
			}
			cout << "End of list";
		}
	};

int main() {

	linkedList cityKeys[8];

	linkedList Jackson;
	Jackson.insertNode("Jackson");
	Jackson.insertNode("Oakland");
	Jackson.insertNode("Mariposed");
	Jackson.insertNode("Sonora");
	Jackson.printList();
	cityKeys[0] = Jackson;

	cout << cityKeys[0];
	

	//linkedList a;
	//a.insertNode(1);
	//a.insertNode(2);
	//a.insertNode(3);
	//a.insertNode(4);
	//a.printList();
	//a.getElementByIndex(1);

	//linkedList b;
	//b.insertNode(")
	///*a.push(1);
	//a.push(2);
	//a.push(3);
	//a.push(4);
	//a.printStack();
	//a.pop();
	//a.printStack();
	//a.pop();
	//a.printStack();
	//*/
	return 0;
}