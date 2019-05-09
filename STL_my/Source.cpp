#include<iostream>
#include<forward_list>
#include<list>
#include"forward_list.h"


int main()
{
	std::forward_list<int> f;
	std::list<int> l;
	
   


	std_my::forward_list<int> m;
	std_my::forward_list<int> n;
	
	for (size_t i = 0; i < 10; i++)
	{
		m.push_front(i);
		f.push_front(i);
	}
	std::forward_list<int>::iterator it = f.begin();
	std_my::forward_list<int>::forward_iterator iw = m.begin();
	for (int i = 0; i < 5; ++i)
	{
		std::cout << *(iw) << "  "; iw++;
	}

	std::cout << std::endl;
	std::getchar();
	return 0;
}