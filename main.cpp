#include <iostream>

#include "binary_tree.hpp"
#include "utility.hpp"

bool test()
{
	binary_tree<int> t1{15, 5, 20, 2, 6, 18, 23};
	binary_tree<int> t2{15, 5, 20, 2, 17, 18, 23};
	binary_tree<int> t3{1, 5};
	binary_tree<int> t4{5};
	return is_binary_search_tree(t1) && !is_binary_search_tree(t2)
		&& !is_binary_search_tree(t3) && is_binary_search_tree(t4);
}

int main()
{
	if (test()) {
		std::cout << "Passed\n";
	} else {
		std::cout << "Failed\n";
	}
}
