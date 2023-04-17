#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_6/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Node* front = nullptr;
			Node* rear = nullptr;

			string t = "time";
			string l = "lover";
			string c = "cappuchino";
			string w = "world";

			enqueue(front, rear, t);
			enqueue(front, rear, l);
			enqueue(front, rear, c);
			enqueue(front, rear, w);

			Assert::AreEqual(findLongest(front), c);

		}
	};
}
