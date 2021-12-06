#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#include <chrono>


using namespace std;

															//Array length
int const maxValue = 100;									//The maximum value for an array element of type integer

bool isSortedInt(int* array, int length)					//Is the array sorted?
{
	bool temp = 0;

	for (int i = 0; i <length - 1; i++)						//Comparing the current element with the next one
	{
		if (array[i] > array[i + 1])
		{
			temp = 1;
			break;
		}
	}
	if (temp)
		return 0;
	else
		return 1;
}

void QuickSort(int* array, int first, int last) {
	int middle;
	int tempFirst = first;
	int tempLast = last;

	middle = array[(tempFirst + tempLast) / 2];
	
	do
	{
		while (array[tempFirst] < middle)
			tempFirst++;
		
		while (array[tempLast] > middle) 
			tempLast--;

		if (tempFirst <= tempLast) 
		{
			swap(array[tempFirst], array[tempLast]);
				
			tempFirst++;
			tempLast--;
		}
	}while (tempFirst < tempLast);
	
	if (first < tempLast)
		QuickSort(array, first, tempLast); 

	if (tempFirst < last) 
		QuickSort(array, tempFirst, last);
}



void BubbleSort(int* array, int length)					//Bubble sorting in ascending order
{
	int temp;											//Variable for saving an array element when swapping

	for (int i = 0; i < length; i++) 
	{
		for (int j = 0; j < length - 1; j++) 
		{
			if (array[j] > array[j + 1]) 
			{
				temp = array[j];						// Saving the element
				array[j] = array[j + 1];				// Swapping the elements
				array[j + 1] = temp;
			}
		}
	}
}

void BogoSort(int* array, int length)
{
	
	while (true)
	{
		if (isSortedInt(array, length))                                  //If the array have already been sorted, then we finish sorting
			break;
		else
		{
			swap(array[rand() % length], array[rand() % length]);        //Swapping elements with random indexes
		}
	}
}

int BinarySearch(int* array, int value, int length)
{
	
	
	int first = 0; // Left border
	int last = length - 1; // Right border
	int middle;
	
	
	if (isSortedInt(array, length)==0)
		BubbleSort(array, length);
	
	while ((first <= last)) 
	{
		middle = (first + last) / 2;				//Calculating the median index

		if (array[middle] == value)					//ñhecking the element with the index
		{
			return middle;
		}
				
		if (array[middle] > value)					//Choosing the right part
			last = middle - 1; 
		if (array[middle] < value)
			first = middle + 1;
	

		
		
	}
	cout << "Element not found" << endl;
	return 404;
	
}

void CountingSort(char* array, int length)
{ 
	char number[256] = { 0 };
	int index = 0;

	for (int i = 0; i < length; i++) {
		number[array[i]]; 
	}

	
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < array[i]; ++j) 
		{
			index++;
			array[index++] = i;
		}
	}
		
}

void cheakTime() 
{
	//Comparison of time complexity for 10 elements
	
	int const Ten = 10;
	int length;
	float avgQuick = 0.0;
	float avgBubble = 0.0;
	
	for (int j = 1; j < 6; j++)
	{
		length = pow(Ten, j);
		int* array = new int[length];
		for (int i = 0; i < length; i++)
			array[i] = rand() % maxValue;
	
		cout << "\nTen time tests for an array of " << length << " elements for QuickSort: " << endl;
		for (int i = 0; i < 10; i++)
		{
			auto begin = chrono::high_resolution_clock::now();
			QuickSort(array, 0, length - 1);
			auto finish = chrono::high_resolution_clock::now();
			chrono::duration<float> temp = finish - begin;
			cout << temp.count() << " ";
			avgQuick += temp.count();
		}
		cout << endl;
		avgQuick /= 10;
		cout << "\nAverage time for an array of  " << length << " elements for QuickSort:" << avgQuick << endl;
	
		cout << "\nTen time tests for an array of  " << length << " elements for BubbleSort: " << endl;
		for (int i = 0; i < 10; i++)
		{
			auto begin = chrono::high_resolution_clock::now();
			BubbleSort(array,length);
			auto finish = chrono::high_resolution_clock::now();
			chrono::duration<float> temp = finish - begin;
			cout << temp.count() << " ";
			avgBubble += temp.count();
		}
		cout << endl;
		avgBubble /= 10;
		cout << "\nAverage time for an array of  " << length << " elements for BubbleSort:" << avgBubble << endl;
		delete[]array;
	}

}
int main() 
{
	cheakTime();
	_getch();
}