#include "cpp_pimpl2.h"
#include <iostream>
#include <vector>

int main()
{
	MyClass myObject;
	myObject.DoSth();
	
	const MyClass secondObject;
	secondObject.DoConst();
}