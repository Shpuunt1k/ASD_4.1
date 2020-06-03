#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "Map.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestaistr1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Insert_Find)
		{
			Map<string, int> test;
			test.insert("Bob", 100);
			test.insert("Sam", 1000);
			test.insert("Joe", 10000);
			try
			{
				test.insert("Bob", 100);
			}
			catch (const std::exception & ex)
			{
				Assert::AreEqual(ex.what(), "Error: such key already exists");
			}
			Assert::AreEqual(3, test.getSize());
			Assert::AreEqual(100, test.find("Bob"));
			Assert::AreEqual(1000, test.find("Sam"));
			Assert::AreEqual(10000, test.find("Joe"));
		}
		TEST_METHOD(TestRemove)
		{
			Map<string, int> test;
			test.insert("Bob", 100);
			test.insert("Sam", 1000);
			test.insert("Joe", 10000);
			test.remove("Sam");
			Assert::AreEqual(NULL, test.find("Sam"));
			test.remove("Sam");
			Assert::AreEqual(2, test.getSize());
		}
		TEST_METHOD(TestClear)
		{
			Map<string, int> test;
			test.insert("Bob", 100);
			test.insert("Sam", 1000);
			test.insert("Joe", 10000);
			test.clear();
			Assert::AreEqual(0, test.getSize());
		}
		TEST_METHOD(TestGetValues_GetKeys)
		{
			Map<string, int> test;
			test.insert("Bob", 100);
			test.insert("Sam", 1000);
			test.insert("Joe", 10000);
			List<string> kys;
			test.get_keys(kys);
			List<int> vls;
			test.get_values(vls);
			Assert::AreEqual(3, kys.GetSize());
			Assert::AreEqual(3, vls.GetSize());
			string bo = "Bob";
			string jo = "Joe";
			string sa = "Sam";
			Assert::AreEqual(bo, kys[0]);
			Assert::AreEqual(jo, kys[1]);
			Assert::AreEqual(sa, kys[2]);
			Assert::AreEqual(100, vls[0]);
			Assert::AreEqual(10000, vls[1]);
			Assert::AreEqual(1000, vls[2]);
		}
	};
}