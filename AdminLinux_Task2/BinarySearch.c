#include <stdio.h>


int BinarySearch ( int* ptrToArray , int arraySize , int searchedElement )
{
	int leftPtr =  0;
	int rightPtr = arraySize - 1;
	int midPtr = (rightPtr + leftPtr) / 2 ;

	while (searchedElement != ptrToArray[midPtr])
	{

	 if (searchedElement > ptrToArray[leftPtr])
		{
			leftPtr = midPtr;
			midPtr = (rightPtr +  leftPtr) / 2;
		}
		else if (searchedElement < ptrToArray[rightPtr])
		{
			rightPtr = midPtr;
			midPtr = (rightPtr +  leftPtr) / 2;
		}
	}

	return midPtr;

}



int main()
{
	int arr[] = {1,2,3,4};
	printf("%d\n",BinarySearch (arr , 4 ,3));
}




	





