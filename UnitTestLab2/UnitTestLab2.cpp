#include "pch.h"
#include "CppUnitTest.h"
#include "..\Aisd2lab\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab2
{
	TEST_CLASS(UnitTestLab2)
	{
	public:
		
		TEST_METHOD(QuickSortTest)
		{
			const int length = 10;
			int* array = new int[length];
			int first = 0; 
			int last = length - 1;
			for (int i = 0; i < length; i++)
			{
				array[i] = rand() % 100;
			}
			QuickSort(array, first, last);
			for (int i = 0; i < length - 1; i++)
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
			delete[]array;
		}
		
		

		TEST_METHOD(BubbleSortTest)
		{
			const int length = 10000;
			int* array = new int[length];
			for (int i = 0; i < length; i++)
			{
				array[i] = rand() % 100;
			}
			BubbleSort(array, length);
			for (int i = 0; i < length - 1; i)
			{
				Assert::IsTrue(array[i] <= array[i]);
			}
			delete[]array;

		}
		TEST_METHOD(BogoSortTest)
		{
			const int length = 10;
			int* array = new int[length];
			for (int i = 0; i < length; i++)
			{
				array[i] = rand() % 100;
			}
			BogoSort(array, length);
			for (int i = 0; i < length - 1; i++)
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
			delete[]array;
		}
		
		TEST_METHOD(CountingSortTest)
		{
			const int length = 10;
			char* array = new char[length];
			array[0] = 'j';
			array[1] = 'i';
			array[2] = 'h';
			array[3] = 'g';
			array[4] = 'a';
			array[5] = 'e';
			array[6] = 'd';
			array[7] = 'c';
			array[8] = 'b';
			array[9] = 'f';
			CountingSort(array, length);
			Assert::IsTrue(array[0] == 'a');
			Assert::IsTrue(array[1] == 'b');
			Assert::IsTrue(array[2] == 'c');
			Assert::IsTrue(array[3] == 'd');
			Assert::IsTrue(array[4] == 'e');
			Assert::IsTrue(array[5] == 'f');
			Assert::IsTrue(array[6] == 'g');
			Assert::IsTrue(array[7] == 'h');
			Assert::IsTrue(array[8] == 'i');
			Assert::IsTrue(array[9] == 'j');
			delete[]array;
		}
		TEST_METHOD(BinarySearchTest)
		{
			const int length = 10;
			int* array = new int[length];
			array[0] = 9;                            //Array[9,0,1,2,3,4,5,6,7,8] - not sorted
			for (int i = 1; i < length; i++)
			{
				array[i] = i-1;
			}
			Assert::IsTrue(isSortedInt(array, length) == 0);
			Assert::IsTrue(BinarySearch(array, 1, length) == 1);
			Assert::IsTrue(BinarySearch(array, 11, length) == 404);
			delete[]array;
		}
	};
}
