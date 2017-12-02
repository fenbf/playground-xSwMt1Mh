#include <memory>
#include <iostream>

class MyType
{
public:
	MyType() { std::cout << "MyType::MyType\n"; }
	~MyType() { std::cout << "MyType::~MyType\n"; }
}

bool process() { return true; }
bool processSecond() { return true; }

void FuncLeaky()
{
    MyType* pFirst = new MyType();
    
    if (!process())
    {
        delete pFirst;
        return;
    }
    
    MyType* pSecond = new MyType();
    
    if (!processSecond())
    {
        delete pFirst;
        delete pSecond;
        return;
    }
    
    process();
    delete pFirst;
    delete pSecond;
}


void FuncNoLeaks()
{
    auto pFirst = std::make_unique<MyType>();
    
    if (!process())
        return;
    
    auto pSecond = std::make_unique<MyType>();
    
    if (!processSecond())
        return;
    
    process();
}

int main()
{
	FuncLeaky();
	FuncNoLeaks();
}