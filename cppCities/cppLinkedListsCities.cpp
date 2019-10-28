#include <iostream>

using namespace std;

class node {
public:
	string data;
	node* next;

};


class linkedList {
private:
	node* head, * tail;
	node* top = NULL;

public:

	linkedList() {
		head = NULL;
		tail = NULL;

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
			cout << "\n Removing " << top->data;
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
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "End of list";

	}

	void printStack() {
		node* temp = new node;
		temp = top;
		while (temp != NULL) {
			cout << "    \n";
			cout << "    " << temp->data << "    \n";
			cout << "    |\n";
			temp = temp->next;
		}
		cout << "End of list";
	}
};

//code for graph


int vertArr[20][20]; //the adjacency matrix initially 0
int count = 0;

void add_edge(string u, string v ) { //function to add edge into the matrix
	vertArr[u][v] = 1;
	vertArr[v][u] = 1;
}

void isConnected(string u, string v) {
	if (vertArr[u][v] != 0) {
		cout << "There is a connection between " << u << " and " << v << endl;
	}
	else {
		cout << "There is no connection between " << u << " and " << v << endl;
	}
}

int main(string argc, char* argv[]) {
	int v = 8; //there are 8 vertices in the graph
	add_edge("Jackson", "Oakland");
	add_edge("Jackson", "Mariposed");
	add_edge("Jackson", "Sonora");
	add_edge("Mariposed", "Sonora");
	add_edge("Mariposed", "Merced");
	add_edge("Mariposed", "San Jose");
	add_edge("Merced", "San Jose");
	add_edge("Oakland", "San Jose");
	add_edge("Redwood City", "San Jose");
	add_edge("Redwood City", "Santa Cruz");
	add_edge("Santa Cruz", "San Jose");
	
	isConnected("Jackson", "Mariposed")

	linkedList cityKeys[8];

	linkedList Jackson;
	Jackson.insertNode("Jackson");
	Jackson.insertNode("Oakland");
	Jackson.insertNode("Mariposed");
	Jackson.insertNode("Sonora");
	Jackson.printList();
	cityKeys[0] = Jackson;

	cout << "This is the first city" << cityKeys[0];




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
