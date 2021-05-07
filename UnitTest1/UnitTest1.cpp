#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 12.2(Recur)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* start = NULL;
			Elem* last = NULL; 

			enqueue(start, last, 1, 2, 50); 

			Assert::AreEqual(start->info, 50); 
		}
	};
}
