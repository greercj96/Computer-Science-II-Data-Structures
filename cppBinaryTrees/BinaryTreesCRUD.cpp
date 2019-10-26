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

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == nullptr)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void printTree(BTree *rootNode, Trunk *prev, bool isLeft)
{
    if (rootNode == nullptr)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(rootNode->rightNode, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isLeft)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << rootNode->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(rootNode->leftNode, trunk, false);
}


int main()
{
    

	BTree root(8);
	BTree* rootNode = &root;
	rootNode->leftNode = new BTree(5);
	rootNode->rightNode = new BTree(10);
	rootNode->leftNode->rightNode = new BTree(7);
	rootNode->leftNode->leftNode = new BTree(2);
	rootNode->rightNode->leftNode = new BTree(9);

	
	printTree(rootNode, nullptr, false);
	return 0;
	
	

}
