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