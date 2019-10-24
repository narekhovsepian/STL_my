#include <iostream>
#include<vector>
#include<deque>
#include<queue>
#include"Heap.h"
#include<type_traits>
#include"type_traits.h"

class Tuna
{
public:
	Tuna() { std::cout << "Tunna construct\n\n"; }
	virtual ~Tuna() { std::cout << "Tunna Destructor\n\n"; }
	

};


class Fish : public Tuna
{
public:
	Fish() { std::cout << "fish construct\n\n"; }
	~Fish() { std::cout << "fish destructor\n\n"; }
	

};



void del(Tuna* ptr)
{
	delete ptr;
}



int main()
{
	std::vector<std::vector<int>> v{ {1, 2, 3, 4, 5},
									 {6, 7, 8, 9, 10},
									 {11,12,13,14,15},
									 {16,17,18,19,20},
									 {21,22,23,24,25} };


	{
		Tuna *f[1];
		f[0] = new Fish;
	}






	std::getchar();
	return 0;
}


