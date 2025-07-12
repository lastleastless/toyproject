#include <iostream>
using namespace std;

class Tmp
{
	friend Tmp operator+(int num, Tmp& right)
	{
		return right + num;
	}
	
public:
	explicit Tmp(int a = 1) : _t{ a } {};

	Tmp operator + (int num)
	{
		return Tmp{ _t + num };
	}
	Tmp operator -(const Tmp& T)
	{
		this->_t -= T._t;
		return *this;
	}
	bool operator ==(const Tmp& T)
	{
		if (_t != T._t)
			return false;
		return true;
	}
	bool operator !=(const Tmp& T)
	{
		return !(*this != T);
	}
	Tmp& operator +=(int num)
	{
		for (int i = 0; i < num; i++)
		{
			_t++;
		}
		return *this;
	}
	void print()
	{
		cout << _t << endl;
	}
private:
	int _t;
};

int main()
{
	Tmp t1{ 3 };
	Tmp t2 = 3 + t1;
	Tmp t3 = 10 + t2;
	Tmp t4 = t1 + 30;
	t4.print();
	t3.print();
	t2.print();
	t1.print();
}