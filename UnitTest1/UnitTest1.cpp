#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-2.6/Complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Complex c1(5.0, 2.0);
			Complex c2(3.0, 4.0);
			Complex res_mul = c1 * c2;
			Complex res_sub = c1 - c2;

			Assert::AreEqual(7.0, res_mul.getPair().getFirst());
			Assert::AreEqual(26.0, res_mul.getPair().getSecond());

			Assert::AreEqual(2.0, res_sub.getPair().getFirst());
			Assert::AreEqual(-2.0, res_sub.getPair().getSecond());
		}
	};
}