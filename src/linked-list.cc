#include <iostream>
using namespace std;

class NoElement{};

template<class T> class Node {
public:
	T data;
	Node *next = nullptr;
	Node(T d) : data(d){}
};

template <class T> class LinkedList {
Node<T> *start = nullptr;
size_t length = 0;
public:
	LinkedList(){}
	void insertAtBegin(T data){
		insertAtPos(0, data);
	}
	void insert(T data){
		insertAt(length, data);
	}
	void insertAtEnd(T data){
		insertAtPos(length, data);
	}
	void insertAt(int pos, T data){
		Node<T> *node = new Node<T>(data);
		length++;

		if(pos == 0){
			node->next = start;
			start = node;
			return;
		}

		Node<T> *s = start;
		for(int count = 0; count < pos-1 && (s && s->next); s = s->next, count ++);
		if(s){
			node->next = s->next;
			s->next = node;
		} else start = node;
	}
	void remove(int pos){
		Node<T> *prev = getNode(pos-1);
		Node<T> *cur  = prev->next;
		prev-> next = cur -> next;
		delete cur;
	}
	Node<T> *getNode(int pos){
		Node<T> *temp = start;
		for(int i = 0; (temp && temp->next) && i < pos; i++)
			temp = temp->next;
		return temp;
	}
	T get(size_t pos){
		if(pos >= length)
			throw out_of_range("Please specify index within range.");
		return getNode(pos)->data;
	}
	size_t size(){
		return length;
	}
};

int main(){
	LinkedList<int> l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insertAt (10, 5);

	cout << l.get(0) << endl;
	cout << l.get(1) << endl;
	cout << l.get(2) << endl;
	cout << l.get(3) << endl;

	return 0;
}
