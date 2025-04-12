#include "sort.h"

/**
 * swap - Swap two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
int temp;

if (a != b && *a != *b)
{
temp = *a;
*a = *b;
*b = temp;
}
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array to partition
 * @low: Start index
 * @high: End index
 * @size: Array size
 * Return: The index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int i = low;
int j;
int pivot = array[high];

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
if (i != j && array[i] != array[j])
{
swap(&array[i], &array[j]);
print_array(array, size);
}
else
swap(&array[i], &array[j]);
i++;
}
}
if (i != high && array[i] != array[high])
{
swap(&array[i], &array[high]);
print_array(array, size);
}
else
swap(&array[i], &array[high]);
return (i);
}

/**
 * quick_sort_recursive - Recursive helper for Quick Sort
 * @array: Array
 * @low: Start index
 * @high: End index
 * @size: Array size
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
int pivot;

if (low < high)
{
pivot = lomuto_partition(array, low, high, size);
quick_sort_recursive(array, low, pivot - 1, size);
quick_sort_recursive(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - Sort array using Quick Sort algorithm
 * @array: The array to sort
 * @size: Array size
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_recursive(array, 0, size - 1, size);
}
