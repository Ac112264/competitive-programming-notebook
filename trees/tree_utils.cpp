#ifndef TREE_UTILS_CPP
#define TREE_UTILS_CPP

#include <iostream>
#include <queue>

// Depth-first in-order traversal
template<typename T>
void inorder(T* t) {
	if (t != nullptr) {
		inorder(t->left);
		std::cout << t->key << std::endl;
		inorder(t->right);
	}
}

// Depth-first pre-order traversal
template<typename T>
void preorder(T* t) {
	if (t != nullptr) {
		std::cout << t->key << std::endl;
		preorder(t->left);
		preorder(t->right);
	}
}

// Depth-first post-order traversal
template<typename T>
void postorder(T* t) {
	if (t != nullptr) {
		postorder(t->left);
		postorder(t->right);
		std::cout << t->key << std::endl;
	}
}

// Breadth-first search traversal
template<typename T>
void bfs(T* t) {
	std::queue<T*> q;
	int lastLevel = 1;
	int currLevel = 0;
	q.push(t);
	while (!q.empty()) {
		T* node = q.front(); q.pop();
		std::cout << node->key << " ";
		if (node->left != nullptr) {
			q.push(node->left);
			currLevel++;
		}
		if (node->right != nullptr) {
			q.push(node->right);
			currLevel++;
		}

		lastLevel--;
		if (lastLevel == 0) {
			lastLevel = currLevel;
			currLevel = 0;
			std::cout << std::endl;
		}
	}

}

#endif
