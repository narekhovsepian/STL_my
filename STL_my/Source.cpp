#include<iostream>
#include <queue>

#include"AVL_Tree.h"



int main()
{
	avl::avl<int> a;
	int arr[] = { 45,36,63,54,72,89 };
	for (size_t i = 0; i < 6; i++)
	{
		a.insert(arr[i]);
	}
	a.inorder_print();
	a.remove(63);
	std::cout << "\n\n\n";
	a.inorder_print();


	std::cout << "\n\n\n";
	std::getchar();
	return 0;
}