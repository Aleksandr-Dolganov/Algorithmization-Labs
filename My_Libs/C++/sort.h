#pragma once
#include <iostream>

/// <summary>
/// Selection sort
/// </summary>
/// <param name="a"> - Pointer to array</param>
/// <param name="size"> - Size of array</param>
void selection_sort(int* a,int size);

/// <summary>
/// Bubble sort
/// </summary>
/// <param name="a"> - Pointer to array</param>
/// <param name="size"> - Size of array</param>
void bubble_sort(int* a, int size);

/// <summary>
/// Quick sort
/// </summary>
/// <param name="a"> - Pointer to array</param>
/// <param name="left"> - Left limit (0)</param>
/// <param name="right"> - Right limit (size of array-1)</param>
void quick_sort(int* a, int left, int right);

/// <summary>
/// Heapsort
/// </summary>
/// <param name="a"> - Pointer to array</param>
/// <param name="size"> - Size of array</param>
void heap_sort(int* a, int size);