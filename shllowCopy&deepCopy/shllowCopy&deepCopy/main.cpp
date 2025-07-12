#include <iostream>
#include <cstring>
using namespace std;
class Tmp {
public:
	Tmp(const char* name) : _name{ new char[strlen(name) + 1] }
	{
		for (int i = 0;name[i] != '\0'; ++i)
		{
			_name[i] = name[i];
		}
		_name[strlen(name)] = '\0';
	}
	Tmp(const Tmp& t) :Tmp{t._name}
	{

	}
	
	void display() const
	{
		cout << _name << '\t' << static_cast<void*>(_name) << endl;
	}
	~Tmp() {
		delete[] _name;
	}
private:
	char* _name;
};
inline static void func(int* mem)
{
	cout << "inside func: " << *mem << endl;
	*mem = 2;
}
int main()
{
	/*
	int* p1{ new int{5} };
	int* p2{ p1 };
	cout << *p1 << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << *p2 << endl;
	delete p1;
	cout << p2 << endl;
	cout << *p2 << endl;
	int* p3{ new int{5} };
	int* p4{ new int{*p3} };
	cout << "addr: " << p3 << "\t value: " << *p3 << endl;
	cout << "addr: " << p4 << "\t value: " << *p4 << endl;
	delete p3;
	cout << "addr: " << p4 << "\t value: " << *p4 << endl;
	*/
	Tmp* ptr{ new Tmp{"pby"} };
	Tmp t{ *ptr };
	cout << "addr: " << &ptr << endl;
	cout << "addr: " << &t << endl;
	ptr->display();
	delete ptr;
	t.display();
	int** dptr = new int*[2];
	dptr[0] = new int[4];
	dptr[1] = new int[4];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4;j++)
		{
			cout << dptr[i][j] << "\t";
		}
		cout << endl;
	}
	void (*fptr)(int*);
	int *mem = new int;
	fptr = func;
	(fptr)(mem);
	cout << "data: " << *mem << endl;


}