#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};

class SinglyLinkedList{
	private:
		Node *head;
		Node *tail;
		int length;
	public:
		SinglyLinkedList(){
			this->head = NULL;
			this->tail = NULL;
			this->length = 0;
		}
		int getLength();
		int getHeadData();
		int getTailData();
		bool isEmpty();
		void addNewNode(Node *node);
		void removeHead();
		void removeTail();
		void removeNodeByData(int data);
};

int SinglyLinkedList::getLength(){
	return this->length;
}

int SinglyLinkedList::getHeadData(){
	if(this->head != NULL)
		return this->head->data;
	else
		return -10000;
}

int SinglyLinkedList::getTailData(){
	if(this->tail != NULL)
		return this->tail->data;
	else
		return -10000;
}

bool SinglyLinkedList::isEmpty(){
	if (this->head == NULL)
		return true;
	return false;
}

void SinglyLinkedList::addNewNode(Node *node){
	if(this->isEmpty()){
		this->head = node;
		this->tail = node;
		this->length += 1;
	}else{
		Node *current_head = this->head;
		node->next = current_head;
		this->head = node;
		this->length += 1;
	}
	return;
}

void SinglyLinkedList::removeHead(){
	Node *current_head = this->head;
	this->head = current_head->next;
	delete current_head;
	this->length -= 1;
}

void SinglyLinkedList::removeTail(){
	Node *iterator = this->head;
	Node *current_tail = this->tail;
	while(iterator){
		if(iterator->next->next == NULL){
			this->tail = iterator;
			break;
		}
		iterator = iterator->next;
	}
	delete current_tail;
	this->length -= 1;
}


void SinglyLinkedList::removeNodeByData(int data){
	int headData = this->getHeadData();
	int tailData = this->getTailData();
	if(data == headData)
		this->removeHead();
	else if (data == tailData)
		this->removeTail();
	else{
		Node *iterator = this->head;
		while(iterator){
			if (iterator->next->data == data){
				Node *next_node = iterator->next;
				Node *next_2node = iterator->next->next;
				iterator->next = next_2node;
				delete next_node;
				this->length -= 1;
				break;
			}
			iterator = iterator->next;
		}
	}
}

int main(){
	SinglyLinkedList sll;
	cout << "LENGTH:" << sll.getLength() << "\n";
	cout << sll.getHeadData() << "\n";
	sll.addNewNode(new Node(1));
	sll.addNewNode(new Node(2));
	sll.addNewNode(new Node(3));
	sll.addNewNode(new Node(4));
	sll.addNewNode(new Node(5));
	sll.addNewNode(new Node(6));
	sll.addNewNode(new Node(7));
	sll.removeHead();
	cout << "LENGTH:" << sll.getLength() << "\n";
	sll.removeNodeByData(5);
	cout << "LENGTH:" << sll.getLength() << "\n";
	return 0;
}
