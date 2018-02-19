#include <iostream>
#include <vector>

#include "binary_tree.hpp"
#include "utility.hpp"

namespace
{

bool binary_search_tree()
{
	binary_tree<int> t1{15, 5, 20, 2, 6, 18, 23};
	binary_tree<int> t2{15, 5, 20, 2, 17, 18, 23};
	binary_tree<int> t3{1, 5};
	binary_tree<int> t4{5};
	return is_binary_search_tree(t1) && !is_binary_search_tree(t2)
		&& !is_binary_search_tree(t3) && is_binary_search_tree(t4);
}

bool BFS_test()
{
	binary_tree<int> t1{15, 5, 20, 2, 6, 18, 23};
	auto v1 = BFS(t1);
	std::vector<int> r1{15, 5, 20, 2, 6, 18, 23};
	bool t = v1 == r1;
	binary_tree<int> t2{15, 5, 20, 2};
	auto v2 = BFS(t2);
	std::vector<int> r2{15, 5, 20, 2};
	t = t && v2 == r2;
	return t;
}

bool largest_values_in_rows_test()
{
	binary_tree<int> t1{15, 5, 20, 2, 6, 18, 23};
	auto v1 = get_largest_values_in_rows(t1);
	std::vector<int> r1{15, 20, 23};
	bool t = v1 == r1;
	return t;
}

}

namespace test
{

void run()
{
	bool t = binary_search_tree();
	t = t && BFS_test();
	t = t && largest_values_in_rows_test();
	if (t) {
		std::cout << "Passed\n";
	} else {
		std::cout << "Failed\n";
	}
}

}
