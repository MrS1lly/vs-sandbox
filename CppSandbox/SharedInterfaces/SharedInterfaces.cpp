// SharedInterfaces.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <memory>

class ITestClass
{
public:
    virtual ~ITestClass() = 0 {};
    virtual void SomeFunction(void) = 0;
};

class TestClass : public ITestClass
{
public:
    TestClass() {};
    ~TestClass() {};
    void SomeFunction(void) override { std::cout << "Constructing TestClass" << std::endl; };
};

class UsesTestClass
{
public:
    UsesTestClass(std::shared_ptr<ITestClass> pTestClass) : m_pTestClass(pTestClass) { m_pTestClass->SomeFunction(); };
    ~UsesTestClass() {};

private:
    std::shared_ptr<ITestClass> m_pTestClass;
};

int main()
{
    auto pTestClass = std::make_shared<TestClass>();
    UsesTestClass a(pTestClass);

    std::cin.ignore();
    return 0;
}

