#include <iostream>

template<typename T>
struct LLNode {
	T data;
	LLNode<T>* next;

	LLNode(const T _d = nullptr, LLNode* _n = nullptr) :
		data(_d), next(_n) { }
	LLNode& operator=(const LLNode&) = delete;
};

template <typename T>
struct LinkedList {
	LLNode<T>* head;
	LLNode<T>* tail;
	int size;

public:
	// Constructor
	LinkedList() :
		head(nullptr), tail(nullptr), size(0) { }

	// Destructor
	~LinkedList() {
		LLNode<T>* it = head->next;
		while (it) {
			LLNode<T>* next = it->next;
			delete it;
			it = next;
		}
		delete head;
	}

	// Prepend to head
	void prepend(const T element) {
		LLNode<T>* newHead = new LLNode<T>(element, nullptr);
		newHead->next = head;
		head = newHead;
		// Make tail the new head if it doesn't exist (empty list)
		if (!tail) { tail = head; }
		size++;
	}

	// Append to tail
	void append(const T element) {
		LLNode<T>* newTail = new LLNode<T>(element, nullptr);
		// Make the head the new tail if it doesn't exist (empty list)
		// Otherwise set a reference from the old tail to the new tail
		if (!head) { head = newTail; }
		else { tail->next = newTail; }
		tail = newTail;
		size++;
	}

	// Print values
	void print(std::ostream& stream = std::cout) const {
		LLNode<T>* it = head;
		while (it) {
			stream << it->data << " -> ";
			it = it->next;
		}
		stream << "null" << std::endl;
	}

};

int main() {
	std::cout << "Hello, world!" << std::endl;

	LinkedList<int> list;
	list.prepend(3);
	list.prepend(2);
	list.prepend(1);
	list.append(4);
	list.append(5);
	list.append(6);
	list.print();

	return 0;
}
