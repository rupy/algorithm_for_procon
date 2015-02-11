#include <iostream>

using namespace std;

typedef struct ss
{
	struct ss* next;
	struct ss* prev;
	int key;
} Node;

class LinkedList{

	Node* root;

public:
	LinkedList(){
		root = NULL;
	}

	void insertNode(int key){
		Node* node = new Node();
		node->key = key;
		if (root == NULL){
			node->next = node;
			node->prev = node;
			root = node;
		}else{
			node->next = root;
			node->prev = root->prev;
			root->prev->next = node;
			root->prev = node;
		}
	}
	void deleteNode(int key){
		Node* node = root;
		if(node->key == key){
			deleteFirst();
			return;
		}
		while(node->next != root){
			node = node->next;
			if(node->key == key){
				node->prev->next = node->next;
				node->next->prev = node->prev;
				delete(node);
				break;
			}
		};

	}
	void deleteFirst(){
		Node* node = root;
		root = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete(node);
	}
	void deleteLast(){
		Node* node = root->prev;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete(node);
	}

	void printNodes(){
		Node* node = root;
		cout << node->key;
		while(node->next != root){
			node = node->next;
			cout << " " << node->key;
		}
		cout << endl;
	}
	void printNodesRev(){
		Node* node = root->prev;
		cout << node->key;
		while(node != root){
			node = node->prev;
			cout << " " << node->key;
		}
		cout << endl;
	}

};


int main(){

	LinkedList list;
	int n;
	string str;
	int num;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> str >> num;
		if (str == "insert"){
			list.insertNode(num);
		}else if(str == "delete"){
			list.deleteNode(num);
		}else{
			;
		}
	}

	list.printNodesRev();

	return 0;
}

/*
5 100
p1 150
p2 80
p3 200
p4 350
p5 20
*/