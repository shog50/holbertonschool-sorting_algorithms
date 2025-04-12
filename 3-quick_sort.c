#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b)
{
int temp;

if (a != b)
{
temp = *a;
*a = *b;
*b = temp;
}
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of array
 * Return: final pivot position
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
swap(&array[i], &array[j]);
print_array(array, size);
}
}
if (array[i + 1] != array[high])
{
swap(&array[i + 1], &array[high]);
print_array(array, size);
}
return (i + 1);
}

/**
 * quick_sort_rec - Recursive quick sort helper
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: array size
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
int pi;

if (low < high)
{
pi = lomuto_partition(array, low, high, size);
quick_sort_rec(array, low, pi - 1, size);
quick_sort_rec(array, pi + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array using Quick Sort
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_rec(array, 0, size - 1, size);
}
