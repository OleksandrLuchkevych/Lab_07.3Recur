#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.3Recur/Lab_07.3Recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int** T = new int* [3];
            for (int i = 0; i < 3; i++) {

                T[i] = new int[3];
            }
            T[0][0] = 1;
            T[0][1] = 0;
            T[0][2] = -3;

            T[1][0] = 0;
            T[1][1] = 5;
            T[1][2] = -6;

            T[2][0] = 0;
            T[2][1] = 0;
            T[2][2] = 9;

            int art[3] = { 0,1,2 };
            int index = 0;
            int t = result(T, art, 3, 0, 0, index);
            Assert::AreEqual(t, 1);
		}
	};
}
