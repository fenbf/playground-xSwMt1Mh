#include <memory>

bool process() { return true; }
bool processSecond() { return true; }

void FuncLeaky()
{
    int* pFirst = new int(10);
    
    if (!process())
    {
        delete pFirst;
        return;
    }
    
    int* pSecond = new int(10);
    
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
    auto pFirst = std::make_unique<int>(10);
    
    if (!process())
        return;
    
    auto pSecond = std::make_unique<int>(10);
    
    if (!processSecond())
        return;
    
    process();
}

int main()
{
	FuncLeaky();
	FuncNoLeaks();
}