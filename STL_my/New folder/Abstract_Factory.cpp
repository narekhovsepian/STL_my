#include<iostream>



class Button
{
public:
	virtual ~Button() { };

	virtual const char* get_Name() = 0;
};


class WinButton :public  Button
{
public:
	const char* get_Name()
	{
		return "Windows_Button\n";
	}
};

class OsxButton : public Button
{
public:
	const char* get_Name()
	{
		return "Osx_Button\n";
	}
};





class Checkbox
{
public:
	virtual ~Checkbox() { };

	virtual const char* get_Name() = 0;
};


class WinCheckbox : public Checkbox
{
public:
	const char* get_Name()
	{
		return "Windows_Checkbox\n";
	}
};

class OsxCheckbox : public Checkbox
{
public:
	const char* get_Name()
	{
		return "Osx_Checkbox\n";
	}
};




class GuiFactory
{
public:
	virtual Button* CreateButton() = 0;
	virtual Checkbox* CreateCheckbox() = 0;
};


class WinFactory : public GuiFactory
{
public:
	Button* CreateButton()
	{
		return new WinButton();
	}

	Checkbox* CreateCheckbox()
	{
		return new WinCheckbox();
	}
};



class OsxFactory : public GuiFactory
{
public:
	Button* CreateButton()
	{
		return new OsxButton();
	}
	Checkbox* CreateCheckbox()
	{
		return new OsxCheckbox();
	}
};





