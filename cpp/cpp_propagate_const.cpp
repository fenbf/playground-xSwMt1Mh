#include <functional>
#include <memory>
#include <experimental/propagate_const>

class Object
{
public:
    void Foo() { }
    void FooConst() const { }
};

class Test
{
private:
     std::experimental::propagate_const<std::unique_ptr<Object>> m_pObj;
    
public:
    Test() : m_pObj(std::make_unique<Object>()) { }
    
    void Foo() { 
        m_pObj->Foo();
        m_pObj->FooConst();
    }
    
    void FooConst() const { 
        //m_pObj->Foo(); // cannot call now!
        m_pObj->FooConst();
    }
};

int main()
{
    Test t;
}