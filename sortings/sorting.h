#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void QuickSort(int arr[], size_t length);

void MergeSort(int arr[], size_t length);

void InsertSort(int arr[], size_t length);

void BubbleSort(int arr[], size_t length);

void SelectionSort(int arr[], size_t length);

void OptimizeBubbleSort(int arr[], size_t length);

#endif
