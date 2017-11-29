#include <memory>

class Test
{
public:
   Test():m_value(0) { std::cout << "Test::Test" << std::endl; }
   ~Test() { std::cout << "Test::~Test destructor" << std::endl; }

   int m_value;
};

void doSomethig(std::auto_ptr<Test> myPtr) {
    myPtr->m_value = 11;
}

void AutoPtrTest() {
    std::auto_ptr<Test> myTest(new Test());
    doSomethig(myTest);
    myTest->m_value = 10;
}

int main()
{
	AutoPtrTest();
}