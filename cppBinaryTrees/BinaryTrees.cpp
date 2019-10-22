#include <iostream>
using namespace std;
class BTree
{
public:
	int data;
	BTree* leftNode;
	BTree* rightNode;
	BTree* rootNode;

	BTree(int dataElement) {
		data = dataElement;
	}
};

int counter = 0;
void insert(int dataElement, BTree* rootNode) {
	
	if (rootNode->data < dataElement && !rootNode->rightNode) { //case 1 : data Element greater than root and rightNode empty
		BTree* newNode = new BTree(dataElement); // make pointer for new node
		rootNode->rightNode = newNode; // assign newNode value to the right 
		cout << "\n ------------>" << newNode->data;
	}
	else if (rootNode->data < dataElement && rootNode->rightNode) { //case 2 : data Element greater than root and right Node full 
		insert(dataElement, rootNode->rightNode);// recall funtion

	}
	if (rootNode->data > dataElement && !rootNode->leftNode) { //case 3: data element less than root and left node empty 
		BTree* newNode = new BTree(dataElement);
		rootNode->leftNode = newNode;
		cout << "\n <----------" << newNode->data;
	}
	else if (rootNode->data > dataElement&& rootNode->leftNode) { //case 4: data element less than root and right node fulll
		insert(dataElement, rootNode->leftNode); //recall function 
	}
};

int main()
{

	BTree root(8);
	BTree* rootNode = &root;
	cout << root.data;
	insert(5, rootNode);
	insert(10, rootNode);
	insert(7, rootNode);
	insert(2, rootNode);
	insert(2, rootNode);
	insert(9, rootNode);
	insert(11, rootNode);

}