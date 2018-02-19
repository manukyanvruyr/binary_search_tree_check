#pragma once

#include <limits>
#include <queue>

#include "binary_tree.hpp"

template <typename T>
bool is_binary_search_tree(Node<T>* const n, Node<T>* const left, Node<T>* const right)
{
	if ((nullptr != left && n->value < left->value) || (nullptr != right && n->value > right->value)
		|| (nullptr != n->left && !is_binary_search_tree(n->left, left, n))
		|| (nullptr != n->right && !is_binary_search_tree(n->right, n, right))) {
		return false;
	}
	return true;
}

template <typename T>
bool is_binary_search_tree(const binary_tree<T>& t)
{
	return is_binary_search_tree(t.get_root(), static_cast<Node<T>*>(nullptr), static_cast<Node<T>*>(nullptr));
}

template <typename T>
std::vector<T> BFS(const binary_tree<T>& t)
{
	std::vector<int> v;
	auto root = t.get_root();
	if (nullptr == root) {
		return v;
	}
    std::queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        v.push_back(node->value);
        q.pop();
        if (nullptr != node->left) {
            q.push(node->left);
        }
        if (nullptr != node->right) {
            q.push(node->right);
        }
    }
    return v;
}

template <typename T>
void get_largest_values_in_rows(Node<T>* const node, std::vector<T>& v, std::size_t d)
{
	if (nullptr == node) {
        return;
    }
    if (v.size() == d) {
        v.push_back(node->value);
    } else if (node->value > v[d]) {
        v[d] = node->value;
    }
    get_largest_values_in_rows(node->left, v, d + 1);
    get_largest_values_in_rows(node->right, v, d + 1);
}

template <typename T>
std::vector<T> get_largest_values_in_rows(const binary_tree<T>& t)
{
	std::vector<T> v;
	auto root = t.get_root();
	if (nullptr == root) {
		return v;
	}
	get_largest_values_in_rows(root, v, 0);
	return v;
}
