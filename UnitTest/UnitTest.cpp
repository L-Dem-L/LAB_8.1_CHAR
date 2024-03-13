#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_8.1_CHAR/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestCount) {
			char str1[] = "***bbbbcccc***";
			char str2[] = "***abcdabcdabcd";
			char str3[] = "abcdefg";

			int count1 = Count(str1);
			int count2 = Count(str2);
			int count3 = Count(str3);

			Assert::AreEqual(2, count1);
			Assert::AreEqual(1, count2);
			Assert::AreEqual(0, count3);
		}

        TEST_METHOD(TestChange) {
            char str1[] = "a***bc***def***";
			char exp1[] = "a!!bc!!def!!";
            Change(str1);
            Assert::AreEqual(exp1, str1);

			char str2[] = "******";
			char exp2[] = "!!!!";
			Change(str2);
			Assert::AreEqual(exp2, str2);
        }
	};
}
