#include<iostream>
#include<forward_list>
#include"forward_list.h"


int main()
{
	std::forward_list<int> f;
	
    


	std_my::forward_list<int> m;
	std_my::forward_list<int> n;
	for (size_t i = 0; i < 10; i++)
	{
		m.push_front(i);
	}
	n = m;
	while (!m.empty())
	{
		std::cout << m.front() << "  ";
		m.pop_front();
	}
	std::cout << "\n\n\n";
	while (!n.empty())
	{
		std::cout << n.front() << "  ";
		n.pop_front();
	}
	





	std::cout << std::endl;
	std::getchar();
	return 0;
}