/*
Készítő:
	rolux  

Rendezési algoritmusok

Funkciók:
		
		bubbleSort(array,array mérete) 
		mdbubbleSort(array,array mérete) 
		selectionSort(array,array mérete) 
		insertionSort(array,array mérete) 
		heapSort(array,array mérete) 
		mergeSort(array,minimum,maximum)
*/

#if defined _r_sort_included
  #endinput
#endif
#define _r_sort_included

#define MERGE_TEMP_SIZE (50)
#pragma disablerecursion


//@Bubble sort
//https://en.wikipedia.org/wiki/Bubble_sort
//http://doyle.wcdsb.ca/ICS4MI/notes/notes%20sort%20bubble.htm
stock bubbleSort(array[],n)
{
	for(new x=0; x<n; x++)
	{
		for(new y=0; y<n-1; y++)
		{
			if(array[y]>array[y+1])
			{

				new temp = array[y+1];
				array[y+1] = array[y];
				array[y] = temp;
			}
		}
	}
}
//@Modified Bubble Sort
// http://doyle.wcdsb.ca/ICS4MI/notes/notes%20sort%20modified%20bubble.htm
stock mdbubbleSort(array[],n)
{
	for(new i=0; i<n; i++)
	{
		new swaps=0;
		for(new j=0; j<n-i-1; j++)
		{
			if(array[j]>array[j+1])
			{
				new t = array[j];
				array[j]=array[j+1];
				array[j+1]=t;
				swaps++;
 			}
  		}
    	if(swaps==0)
			break;
   	}
}

//@Selection Sort
//https://en.wikipedia.org/wiki/Selection_sort
//http://doyle.wcdsb.ca/ICS4MI/notes/notes%20sort%20selection.htm
stock selectionSort(array[],n)
{
    for(new x=0; x<n; x++)
	{
		new index_of_min = x;
		for(new y = x; y < n; y++)
		{
			if(array[index_of_min] > array[y])
			{
				index_of_min = y;
			}
		}
		new temp = array[x];
		array[x] = array[index_of_min];
		array[index_of_min] = temp;
	}
}
//@Insertion sort
//https://en.wikipedia.org/wiki/Insertion_sort
stock insertionSort(array[],n)
{
   new i, key, j;
   for (i = 1; i < n; i++)
   {
       key = array[i];
       j = i-1;
       while (j >= 0 && array[j] > key)
       {
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key;
   }
}
//@Heap Sort
//https://en.wikipedia.org/wiki/Heapsort
stock heapSort(array[],n)
{
    for (new i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (new i=n-1; i>=0; i--)
    {
		new temp = array[0];
		array[0] = array[i];
		array[i] = temp;
        heapify(array, i, 0);
    }
}

stock heapify(array[],n,i)
{
   	new largest = i;
    new l = 2*i + 1;  
    new r = 2*i + 2;  

    if (l < n && array[l] > array[largest])
        largest = l;

    if (r < n && array[r] > array[largest])
        largest = r;

    if (largest != i)
    {
        new temp = array[largest];
		array[largest] = array[i];
		array[i] = temp;
        heapify(array, n, largest);
    }
}

//@Merge Sort
//https://en.wikipedia.org/wiki/Merge_sort
stock mergeSort(array[],min, max)
{
	if (min < max)
	{
		new Float:f_mid = (max+min)/2;
		new mid = floatround(f_mid,floatround_round);
		mergeSort(array, min, mid) ;
		mergeSort(array, mid+1, max) ;
		merge(array, min, max, mid) ;
	}
}
stock merge(array[],min,max,mid)
{
	new firstIndex = min ;
	new secondIndex = mid + 1 ;
	new index = min ;
	new tempArray[MERGE_TEMP_SIZE] ;

	while ((firstIndex <= mid) && (secondIndex <= max))
	{
		if (array[firstIndex] < array[secondIndex])
		{
			tempArray[index] = array[firstIndex] ;
			index++ ;
			firstIndex++ ;
		}
		else
		{
			tempArray[index] = array[secondIndex] ;
			index++ ;
			secondIndex++ ;
		}
	}
	while (firstIndex <= mid)
	{
		tempArray[index] = array[firstIndex] ;
		index++ ;
		firstIndex++ ;
	}
	while (secondIndex <= max)
	{
		tempArray[index] = array[secondIndex] ;
		index++ ;
		secondIndex++ ;
	}
	for (new i = min ; i < index ; i++)
		array[i] = tempArray[i] ;
}