#include "TestLibTestsSetup.h"

TEST_F(TestLibTest, MaxInts)
{
    EXPECT_EQ(1, MathsUtils::Max(-4, 1));
}

TEST_F(TestLibTest, MaxDoubles)
{
    EXPECT_EQ(1.43, MathsUtils::Max(-4.34, 1.43));
}

TEST_F(TestLibTest, MaxFloats)
{
    EXPECT_EQ(1.5f, MathsUtils::Max(-4.4f, 1.5f));
}