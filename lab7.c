#include <stdio.h>
#include <stdlib.h>

int selectionSort(int arr[], int n)
{
  int *copy = malloc(n * sizeof(int));
  int *swaps = malloc(n * sizeof(int));
  if (copy == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  for (int k = 0; k < n; k++)
  {
    copy[k] = arr[k];
    swaps[k] = 0;
  }
  int i, j, min_idx, temp;
  int totalSwaps = 0;
  // One by one move boundary of the unsorted array
  for (i = 0; i < n - 1; i++)
  {
    // Find the minimum element in the unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (copy[j] < copy[min_idx])
        min_idx = j;
    // Swap the found minimum element with the first element
    temp = copy[i];
    copy[i] = copy[min_idx];
    copy[min_idx] = temp;

    if (min_idx != i)
    {
      totalSwaps++;
      temp = swaps[i] + 1;
      swaps[i] = swaps[min_idx] + 1;
      swaps[min_idx] = temp;
    }
  }

  for (int k = 0; k < n; k++)
  {
    printf("%d: %d\n", copy[k], swaps[k]);
  }

  free(copy);
  free(swaps);
  return totalSwaps;
}

int bubbleSort(int arr[], int n)
{
  int *copy = malloc(n * sizeof(int));
  int *swaps = malloc(n * sizeof(int));
  if (copy == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  for (int k = 0; k < n; k++)
  {
    copy[k] = arr[k];
    swaps[k] = 0;
  }
  int i, j, temp;
  int totalSwaps = 0;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (copy[j] > copy[j + 1])
      {
        temp = copy[j];
        copy[j] = copy[j + 1];
        copy[j + 1] = temp;
        totalSwaps++;

        temp = swaps[j];
        swaps[j] = swaps[j + 1] + 1;
        swaps[j + 1] = temp+1;
      }
    }
  }

  for (int k = 0; k < n; k++)
  {
    printf("%d: %d\n", copy[k], swaps[k]);
  }
  
  free(copy);
  free(swaps);
  return totalSwaps;
}

int main()
{
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int arr1Len = 9;

  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int arr2Len = 9;

  printf("array1 bubble sort:\n");
  printf("%d\n", bubbleSort(array1, arr1Len));
  printf("\narray2 bubble sort:\n");
  printf("%d\n", bubbleSort(array2, arr2Len));
  printf("\narray1 selection sort:\n");
  printf("%d\n", selectionSort(array1, arr1Len));
  printf("\narray2 selection sort:\n");
  printf("%d\n", selectionSort(array2, arr2Len));
}