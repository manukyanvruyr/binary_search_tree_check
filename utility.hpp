#pragma once

#include <limits>
#include "binary_tree.hpp"

template<typename T>
bool is_binary_search_tree(Node<T>* const n, const T& max, const T& min)
{
	if (n->value > max || n->value < min || (nullptr != n->left && !is_binary_search_tree(n->left, n->value, min))
			|| (nullptr != n->right && !is_binary_search_tree(n->right, max, n->value))) {
		return false;
	}
	return true;
}

template<typename T>
bool is_binary_search_tree(const binary_tree<T>& t)
{
	return is_binary_search_tree(t.get_root(), std::numeric_limits<T>::max(), std::numeric_limits<T>::min());
}
