#pragma once

#include <queue>
#include <assert.h>

template <typename T>
struct Node
{
	Node* left = nullptr;
	Node* right = nullptr;
	T value;

	~Node()
	{
		delete left;
		delete right;
	}
};

template <typename T>
class binary_tree
{
public:
	binary_tree() = default;

	binary_tree(std::initializer_list<T> l);

	~binary_tree()
	{
		delete m_root;
	}

public:
	binary_tree(const binary_tree&) = delete;
	binary_tree(binary_tree&&) = delete;
	binary_tree& operator=(const binary_tree&) = delete;
	binary_tree& operator=(binary_tree&&) = delete;

public:
	Node<T>* const get_root() const
	{
		return m_root;
	}

private:
	Node<T>* m_root = nullptr;
};

template <typename T>
binary_tree<T>::binary_tree(std::initializer_list<T> list)
{
	const std::size_t size = list.size();
	assert(size > 0);
	std::queue<Node<T>*> q;
	m_root = new Node<T>();
	Node<T>* n = m_root;
	std::size_t i = 1;
	for (auto value : list) {
		n->value = value;
		if (i < size) {
			n->left = new Node<T>();
			q.push(n->left);
			++i;
			if (i < size) {
				n->right = new Node<T>();
				q.push(n->right);
				++i;
			}
		}
		if (!q.empty()) {
			n = q.front();
			q.pop();
		}
	}
}
