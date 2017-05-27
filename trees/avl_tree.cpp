#include <algorithm>
#include "tree_utils.cpp"

// TODO tree utils, in order traversal

template<typename K>
struct AVLNode {
	K key;

	int _height;
	AVLNode<K>* left;
	AVLNode<K>* right;

	bool deleted;

	AVLNode(K k) :
		key(k),
		_height(0), left(nullptr), right(nullptr),
		deleted(false) { } 
};

template<typename K>
struct AVLTree {
	AVLNode<K>* root;

public:
	AVLTree(): root(nullptr) { }

	void makeEmpty() { root = nullptr;}
	bool isEmpty() { return root == nullptr; }

	void insert(K k) { root = insert(root, k); }
	K* find(K k) { return find(root, k); }
	void remove(K k) { root = remove(root, k); }

	int height() { return height(root); }


private:
	// Check if different of height of children is at most 1
	static bool isValidAVL(AVLNode<K>* t) {
		if (t == nullptr) return true;
		return abs(height(t->left) - height(t->right)) <= 1;
	}

	// Insert
	// Return pointer to the new root
	static AVLNode<K>* insert(AVLNode<K>* t, K k) {
		if (t == nullptr) return new AVLNode<K>(k);
		// less than: insert left
		if (k < t->key) t->left = insert(t->left, k);
		// greater than: insert right
		else if (k > t->key) t->right = insert(t->right, k);
		// same: replace data
		else {
			// Mark as not deleted, since it could have been marked as deleted previously
			t->deleted = false;
		}
		return balance(t);
	}

	// Find
	static K find(AVLNode<K>* t, K k) {
		if (t == nullptr) return nullptr;
		if (k < t->key) return find(t->left, k);
		else if (k > t-> key) return find(t->right, k);		
		else {
			// Return if not deleted
			if (!t->deleted) { return t->data; }
			else { return nullptr; }
		}
	}

	// Find min
	// TODO use lazy delete
	static AVLNode<K>* findMin(AVLNode<K>* t) {
		if (t->left == nullptr) { return t; }
		return findMin(t->left);
	}

	// Remove
	static AVLNode<K>* remove(AVLNode<K>* t, K k) {
		if (t == nullptr) return nullptr;
		if (k < t->key) t->left = remove(t->left, k);
		else if (k > t->key) t->right = remove(t->right, k);
		else { t->deleted = true; }
		return t;
	}

	// Height of null is -1. Height of an empty tree is 0.
	static int height(AVLNode<K>* t) {
		return (t == nullptr) ? -1 : t->_height;
	}

	// Balance
	static AVLNode<K>* balance(AVLNode<K>* t) {
		if (t == nullptr) return t;
		if (height(t->left) - height(t->right) > 1) {
			if (height(t->left->left) >= height(t->left->right)) {
				t = rotateLL(t); // do an LL rotation
			} else {
				t = rotateLR(t); // do an LR rotation
			}
		}
		else if (height(t->right) - height(t->left) > 1) {
			if (height( t->right->right) >= height(t->right->left)) {
				t = rotateRR(t); // do an RR rotation
			}
			else {
				t = rotateRL(t); // do an RL rotation
			}
		}

		t->_height = 1 + std::max(height(t->left), height(t->right));
		return t;
	}

	/* Single rotations */

	/* LL rotation */
	/* Insert C. Unbalanced at C. Rotate left with pivot at k1. */
	/*       A k2  |    B k1
	 *      /      |   / \
	 *     B k1    |  C   A k2
	 *    / \      |     /
	 *  |C|  D     |    D
	 */
	static AVLNode<K>* rotateLL(AVLNode<K>* k2) {
		AVLNode<K>* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->_height = 1 + std::max(height(k2->left), height(k2->right));
		k1->_height = 1 + std::max(height(k1->left), height(k1->right));
		return k1;
	}

	/* RR rotation */
	/* Insert D. Unbalanced at A. Rotate left with pivot at k1. */
	/*  A k2    |       B k1
	 *   \      |      / \
	 *    B k1  |  k2 A   D
	 *   / \    |      \
	 *  C  |D|  |       C
	 */
	static AVLNode<K>* rotateRR(AVLNode<K>* k2) {
		AVLNode<K>* k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		k2->_height = 1 + std::max(height(k2->left), height(k2->right));
		k1->_height = 1 + std::max(height(k1->left), height(k1->right));
		return k1;
	}

	/* Double rotations */

	/* LR rotation */
	/* Insert 4. Unbalanced at 5. Rotate left, then right. */
	/*       5 k2    |         5 k2  |        4 k1
	 *      / \      |        / \    |       / \
	 *  k3 3   A     |    k1 4   A   |      /   \
	 *    / \        |      / \      |  k2 3     5 k3
	 *   B  |4| k1   |  k3 3   D     |    / \   / \
	 *      / \      |    / \        |   B   C D   A
	 *     C   D     |   B   C       |
	 */
	static AVLNode<K>* rotateLR(AVLNode<K>* k2) {
		AVLNode<K>* k3 = k2->left;
		AVLNode<K>* k1 = k3->right;

		// Rotate left with pivot at k1
		k3->right = k1->left;
		k1->left = k3;
		k2->left = k1;

		// Rotate right with pivot at k1
		k2->left = k1->right;
		k1->right = k2;

		// Recalculate height
		k2->_height = 1 + std::max(height(k2->left), height(k2->right));
		k3->_height = 1 + std::max(height(k3->left), height(k3->right));
		k1->_height = 1 + std::max(height(k1->left), height(k1->right));

		return k1;
	}

	/* RL rotation */
	/* Insert 4. Unbalanced at 3. Rotate right, then left. */
	/*       3 k2    |    3 k2       |        4 k1
	 *      / \      |   / \         |       / \
	 *     A   5 k3  |  A   4 k1     |      /   \
	 *        / \    |     / \       |  k2 3     5 k3
	 *   k1 |4|  B   |    D   5 k3   |    / \   / \
	 *      / \      |       / \     |   A   D C   B
	 *     D   C     |      C   B    |
	 */
	static AVLNode<K>* rotateRL(AVLNode<K>* k2) {
		AVLNode<K>* k3 = k2->right;
		AVLNode<K>* k1 = k3->left;
		
		// Rotate right with pivot at k1
		k3->left = k1->right;
		k1->right = k3;
		k2->right = k1;

		// Rotate left with pivot at k1
		k2->right = k1->left;
		k1->left = k2;

		// Recalculate height
		k2->_height = 1 + std::max(height(k2->left), height(k2->right));
		k3->_height = 1 + std::max(height(k3->left), height(k3->right));
		k1->_height = 1 + std::max(height(k1->left), height(k1->right));

		return k1;
	}

};

// TODO tmp
#include <iostream>

int main() {
	AVLTree<int> tree;
	int val;
	do {
		std::cin >> val;
		tree.insert(val);
		// inorder(tree.root);
		bfs(tree.root);
		std::cout << std::endl;
	} while (val != -1);
}
