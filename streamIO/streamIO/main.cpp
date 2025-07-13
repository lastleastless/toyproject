/*
C++ uses type-safe input,output
c++ io operations are device independent.
stream: sequence of bytes flowing in and out of the program.
formatted io: bytes are grouped and converted to types such as int,double...
Buffered IO: data can be buffered and transmitted at once.
To output the address of a pointer instread of the data, cast -> void*

*/
#include <iostream>
using namespace std;

int main()
{
	int a{ 5 };
	int* aptr;
	aptr = &a;
	const char* word = "fjaksdfkla";
	cout << static_cast<const void*>(word) << endl;
	const void* v = word;
	cout << static_cast<const char*>(v) << endl;
	//istream: >> operator.
	//returns a reference to the istream obj.
	// if >> is used in condition clause, c++ casts the output of >> into void* ptr
	// true : non-void pointer, false : void pointer.
	//example:
	int b;
	if (cin >> b)
	{
		cout << b << endl;
	}
	else
	{
		cout << "fail." << endl;
	}
	//each stream obj vontains a set of state bits used to control the stream's state.
}