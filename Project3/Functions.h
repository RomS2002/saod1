#pragma once
#include <iostream>

//Сортировка выбором
template <class T>
void selectionSort(T* arr, int len) {
	for (int i = 0; i < len; i++) {

		T m = arr[i];
		T m_ind = i;

		for (int j = i + 1; j < len; j++) {
			if (arr[j] < m) {
				m_ind = j;
				m = arr[j];
			}
		}
		if (m_ind != i) {
			T temp = arr[i];
			arr[i] = m;
			arr[m_ind] = temp;
		}
	}
}

//Сортировка пузырьком
template <class T>
void bubbleSort(T* arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i; j < len - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//Сортировка вставками
template <class T>
void insertSort(T* arr, int len) {
	for (int i = 2; i < len; i++) {
		T key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//Функция ввода массива с клавиатуры
template <class T>
void input_from_keyboard(T* arr, int len) {
	for (int i = 0; i < len; i++) {
		std::cout << "A[" << i << "] = ";
		std::cin >> arr[i];
	}
}

//Создание копии массива
template <class T>
void copyArray(T* arr_from, T* arr_to, int len) {
	for (int i = 0; i < len; i++) {
		arr_to[i] = arr_from[i];
	}
}

//Заполнение массива случайными числами
void gen_random_array(int* arr, int len, int val_min, int val_max) {
	for (int i = 0; i < len; i++) {
		arr[i] = rand()%(val_max - val_min + 1) + val_min;
	}
}

//Вывод массива на экран
template <class T>
void printArray(T* arr, int len) {
	for (int i = 0; i < len; i++) {
		std::cout << "A[" << i << "] = " << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

//Бинарный поиск
template <class T>
int binSearch(T* arr, int len, T elem) {
	int low = 0;
	int high = len - 1;

	while (low <= high) {
		int mid = (high + low) / 2;
		T midval = arr[mid];

		if (midval < elem) {
			low = mid + 1;
		}
		else if (midval > elem) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

//Сортировка подсчётом (только целые числа)
template <class T>
void countSort(T* arr, int len) {
	T a_min = arr[0];
	T a_max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] < a_min)
			a_min = arr[i];
		if (arr[i] > a_max)
			a_max = arr[i];
	}
	T r = a_max - a_min;
	int* temp = new int[r + 1];
	for (int i = 0; i < r + 1; i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < len; i++) {
		temp[arr[i] - a_min] += 1;
	}
	int k = 0;
	for (int i = 0; i < r + 1; i++) {
		for (int j = 0; j < temp[i]; j++) {
			arr[k] = i + a_min;
			k++;
		}
	}
	delete[] temp;
}

//Функция, преобразующая двоичную кучу в max-heap
template <class T>
void heapify(T* arr, int len, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < len && arr[l] > arr[largest])
		largest = l;
	if (r < len && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		T temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		heapify(arr, len, largest);
	}
}

//Пирамидальная сортировка
template <class T>
void heapSort(T* arr, int len) {
	for (int i = len / 2 - 1; i >= 0; i--)
		heapify(arr, len, i);

	for (int i = len - 1; i >= 0; i--) {
		T temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}