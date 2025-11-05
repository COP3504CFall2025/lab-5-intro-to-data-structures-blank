#pragma once
#include <iostream>
using namespace std;




template <typename T>
class LinkedList {
private:
	// Stores pointers to first and last nodes and count

	struct Node {
		T data;
		Node* prev;
		Node* next;
		Node() = default;
	};
	Node* head;
	Node* tail;
	unsigned int count;
public:
	// Behaviors
	void printForward() const {
		Node* current = head;
		for (int i=0; i<count; ++i) {
			std::cout << current->data << std::endl;
			current = current->next;
		}
	}
	void printReverse() const {
		Node* current = tail;
		for (int i=0; i<count; ++i) {
			std::cout << current->data << std::endl;
			current = current->prev;
		}
	}
	// Accessors
	[[nodiscard]] unsigned int getCount() const {
		return count;
	}
	Node* getHead() {
		return head;
	}
	const Node* getHead() const {
		return head;
	}
	Node* getTail() {
		return tail;
	}

	const Node* getTail() const {
		return tail;
	}

	// Insertion
	void addHead(const T& data) {
		Node* temp = new Node();
		temp->next = head;
		temp->prev = nullptr;
		temp->data = head->data;
		head = temp;
		count +=1;

	}
	void addTail(const T& data) {
		Node* temp = new Node();
		temp->prev = tail;
		temp->next = nullptr;
		temp->data = tail->data;
		tail = temp;
		count +=1;
	}

	// Removal
	bool removeHead() {
		Node* temp = head->next;
		temp->prev = nullptr;
		delete head;
		head = temp;
		count -=1;
		return true;
	}
	bool removeTail() {
		Node* temp = tail->prev;
		temp->next = nullptr;
		delete tail;
		tail = temp;
		count -=1;
		return true;
	}
	void Clear() {
		Node* current = head;
		Node* next = head->next;
		for (int i=0; i<count; ++i) {
			delete current;
			current = next;
			next = current->next;
		}
		count =0;
	}

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept {
		this->count = other->count;
		if (other == this) {
			return *this;
		}
		else {
			count = other->count;
			head = other->head;
			tail = other->tail;
			other->head = nullptr;
			other->tail = nullptr;

		}
		return *this;
	}
	LinkedList<T>& operator=(const LinkedList<T>& rhs) {
		if (this == rhs) {
			return *this;
		}
		Node* current = head;
		Node* currentOther = rhs->head;
		for (int i =0; i<count;i++) {
			current-> data = currentOther->data;
			currentOther = currentOther->next;
			current = current->next;
		}
		return *this;
	}

	// Construction/Destruction
	LinkedList(){
		head = nullptr;
		tail = nullptr;
		count = 0;

	}
	LinkedList(const LinkedList<T>& list) {
		head = new Node();

		count = list->count;
		Node* current = head;
		Node* prevCurrent = nullptr;
		Node* listCurrent = list.getHead();
		for (int i =0; i<count; i++) {
			current->prev = prevCurrent;
			current->data = listCurrent->data;
			current->next = new Node();
			prevCurrent = current;
			current = current->next;

		}

		tail = current;
	}
	LinkedList(LinkedList<T>&& other) noexcept {
		this->count = other->count;


			count = other->count;
			head = other->head;
			tail = other->tail;
			other->head = nullptr;
			other->tail = nullptr;


	}

	~LinkedList() {
		Node* current = head->next;
		for (int i=0; i<count; ++i) {
			delete current->prev;
			current->prev = nullptr;
			current = current->next;

		}
	}



};


