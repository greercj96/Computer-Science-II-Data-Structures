#include <iostream>
using namespace std;

class BTree
{
public:
	int data;
	BTree* node;
	BTree* leftNode;
	BTree* rightNode;
	BTree* rootNode;

	BTree(int dataElement) {
		data = dataElement;
	}
};

BTree* insert(int dataElement, BTree* rootNode) {

	if (rootNode->data < dataElement && !rootNode->rightNode) { //case 1 : data Element greater than root and rightNode empty
		BTree* newNode = new BTree(dataElement); // make pointer for new node
		rootNode->rightNode = newNode; // assign newNode value to the right 
		cout << newNode->data << "---->\n";
	}
	else if (rootNode->data < dataElement && rootNode->rightNode) { //case 2 : data Element greater than root and right Node full 
		insert(dataElement, rootNode->rightNode);// recall funtion

	}
	if (rootNode->data > dataElement && !rootNode->leftNode) { //case 3: data element less than root and left node empty 
		BTree* newNode = new BTree(dataElement);
		rootNode->leftNode = newNode;
		cout << newNode->data << "<----\n";
	}
	else if (rootNode->data > dataElement&& rootNode->leftNode) { //case 4: data element less than root and right node full
		insert(dataElement, rootNode->leftNode); //recall function 
	}
	return 0;
}

BTree* findMinNode(BTree* rootNode) {
	while (rootNode->leftNode != NULL) {
		rootNode = rootNode->leftNode;
		return rootNode;
	}
}

BTree* deleteNode(BTree* rootNode, int data) {
	if (rootNode == NULL) {
		return rootNode;
	}
	else if (data < rootNode->data) {
		rootNode->leftNode = deleteNode(rootNode->leftNode, data);
	}
	else if (data < rootNode->data) {
		rootNode->rightNode = deleteNode(rootNode->rightNode, data);
	}
	else {
		if (rootNode->leftNode == NULL && rootNode->rightNode == NULL) {
			delete rootNode;
			rootNode = NULL;
		}

		else if (rootNode->leftNode == NULL) {
			BTree* tempNode = rootNode;
			rootNode = rootNode->rightNode;
			delete tempNode;
		}
		else if (rootNode->rightNode == NULL) {
			BTree* tempNode = rootNode;
			rootNode = rootNode->leftNode;
			delete tempNode;
		}
		else {
			BTree* minNode = findMinNode(rootNode->rightNode);
			rootNode->data = minNode->data;
			rootNode->rightNode = deleteNode(rootNode->rightNode, minNode->data);

		}
	}
	return rootNode;
}

BTree* updateNode(BTree* rootNode, int oldData, int newData) {
	rootNode = deleteNode(rootNode, oldData);

	rootNode = insert(newData, rootNode);

	return rootNode;
}





int main()
{

	BTree root(8);
	BTree* rootNode = &root;
	cout << rootNode->data << endl;
	insert(5, rootNode);
	insert(10, rootNode);
	insert(7, rootNode);
	insert(2, rootNode);
	insert(2, rootNode);
	insert(9, rootNode);
	insert(11, rootNode);


}