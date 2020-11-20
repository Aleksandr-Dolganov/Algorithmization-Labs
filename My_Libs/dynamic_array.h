#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// <summary>
/// Show array
/// </summary>
/// <param name="A"> - Pointer to array</param>
/// <param name="Size"> - Size of array</param>
void array_show(int* A, int size);

/// <summary>
/// Creates an array of the specified size, filled with random numbers
/// </summary>
/// <param name="size"> - Size of array</param>
/// <param name="random"> - The upper limit of the random numbers</param>
/// <returns>Pointer to array</returns>
int* array_rand(int size, int random);

/// <summary>
/// Creates an array of the specified size filled with keyboard-typed numbers
/// </summary>
/// <param name="size"> - Size of array</param>
/// <returns>Pointer to array</returns>
int* array_enter(int size);

/// <summary>
/// Search function for number X in an array
/// </summary>
/// <param name="a"> - Pointer to array</param>
/// <param name="size"> - Size of array</param>
/// <param name="x"> - The number we are looking for</param>
/// <returns>Ordinal X or -1 if the number is not in the array</returns>
int array_search(int* a, int size, int x);

/// <summary>
/// Creates an matrix of the specified size, filled with random numbers
/// </summary>
/// <param name="x"> - Number of matrix rows</param>
/// <param name="y"> - Number of matrix columns</param>
/// <param name="random"> - The upper limit of the random numbers</param>
/// <returns>Pointer to matrix</returns>
int** matr_rand(int x, int y, int random);

/// <summary>
/// Show matrix
/// </summary>
/// <param name="a"> - Pointer to array</param>
/// <param name="x"> - Number of matrix rows</param>
/// <param name="y"> - Number of matrix columns</param>
void matr_show(int** a, int x, int y);