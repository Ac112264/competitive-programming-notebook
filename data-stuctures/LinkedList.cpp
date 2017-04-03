#include <iostream>

template <typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;

		// Constructor
		Node(const T data, Node* next = nullptr) : data(data), next(next) { }

		// Disable assignment operator
		Node& operator=(const Node&) = delete;

	};

	Node* head;
	Node* tail;

	int size;

public:
	// Constructor
	LinkedList() : head(nullptr), tail(nullptr), size(0) { }

	// Destructor
	~LinkedList() {
		// TODO
	}

	// Prepend to head
	void prepend(const T element) {
		Node* newHead = new Node(element, nullptr);
		newHead->next = head;
		head = newHead;
		// Make tail the new head if it doesn't exist (empty list)
		if (!tail) { tail = head; }
		size++;
	}

	// Append to tail
	void append(const T element) {
		Node* newTail = new Node(element, nullptr);
		// Make the head the new tail if it doesn't exist (empty list)
		// Otherwise set a reference from the old tail to the new tail
		if (!head) { head = newTail; }
		else { tail->next = newTail; }
		tail = newTail;
		size++;
	}

	// Print values
	void print(std::ostream& stream = std::cout) const {
		Node* curr = head;
		while (curr) {
			stream << curr->data << " -> ";
			curr = curr->next;
		}
		stream << "null" << std::endl;
	}

};

int main(int argc, const char *argv[]) {
	std::cout << "Hello, world!" << std::endl;

	LinkedList<int> list{};
	list.prepend(3);
	list.prepend(2);
	list.prepend(1);
	list.append(4);
	list.append(5);
	list.append(6);
	list.print();


	return 0;
}
