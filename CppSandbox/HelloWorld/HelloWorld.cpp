#include <Windows.h>
#include <iostream>
#include <vector>
#include "TestLib.h"
#include "MathFuncs.h"

typedef struct
{
    LPCTSTR field1;
    DWORD field2;
} test_struct_t, *p_test_struct_t;

int main(void)
{
	std::cout << "Hello, World!" << std::endl;

    auto res = MathsUtils::Max(1.4, 4.2);
    auto res2 = MathsUtils::Max(1.0f, 5.2f);

    LPCTSTR exampleStr = L"ExampleString";
    DWORD exampleDword = 0UL;

    test_struct_t structure = { exampleStr, exampleDword };
    exampleStr = nullptr;

    std::vector<test_struct_t> vec;
    vec.push_back(structure);

    for (const auto& i : vec)
    {
        std::wcout << i.field1 << L", " << i.field2 << std::endl;
        wprintf(L"%ws\n", i.field1);
    }
    
    std::cin.ignore();

    return 0;
}