#include <iostream>
#include <stdio.h>

#include "gtest/gtest.h"
#include "TestLib.h"
//#include "gmock/gmock.h"

int main(int argc, char** argv)
{
    //testing::InitGoogleMock(&argc, argv);
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}