#include<iostream>


class Stooge
{
public:
	virtual void slap_stick() = 0;
};


class Larry : public Stooge
{
public:
	void slap_stick()
	{
		std::cout << "Larrry";
	}
};

class Moy :public Stooge
{
public:
	void slap_stick()
	{
		std::cout << "Moe";
	}
};


class Curly : public Stooge
{
public:
	virtual void slap_stick()
	{
		std::cout << "Curly";
	}
};



