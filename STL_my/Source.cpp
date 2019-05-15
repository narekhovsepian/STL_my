#include<iostream>
#include<forward_list>
#include<list>
#include<algorithm>
#include<vector>
#include"forward_list.h"
#include"list.h"

int main()
{

	std_my::list<int> li;
	std_my::list<int> d;
	std_my::forward_list<int> f;
	std_my::forward_list<int> u;

	for (int i = 0; i < 10; ++i)
	{
		//li.push_back(i);
		d.push_front(i);
		f.push_front(i);


	}

	li = std::move(d);
	for (auto t : li)
		std::cout << t << "  ";






	std::cout << std::endl;
	std::getchar();
	return 0;
}