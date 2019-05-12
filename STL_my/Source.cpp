#include<iostream>
#include<forward_list>
#include<list>
#include"forward_list.h"


int main()
{
	std_my::forward_list<int> f;

	for (int i = 0; i < 10; ++i)
	{
		f.push_front(i);
	}
	std_my::forward_list<int>::cf_iterator i = f.begin();
	
	f.insert_after(f.cend(), 456);

	f.insert_after(++i, 456);

	for (auto u : f)
		std::cout << u << "  ";


	std::cout << std::endl;
	std::getchar();
	return 0;
}