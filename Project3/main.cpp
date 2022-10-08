#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include "Functions.h"

using namespace std;

int main() {
	/*int* a = new int[100];
	gen_random_array(a, 100, -50, 50);
	printArray(a, 100);
	quickSort<int>(a, 0, 99);
	printArray(a, 100);
	delete[] a;*/
	ofstream out("M:\\funcdata5.txt");

	for(int i = 100000; i < 201000; i += 1000) {
		int* arr = new int[i];
		gen_random_array(arr, i, -i / 2, i / 2);
		
		int* arr1 = new int[i];
		copyArray<int>(arr, arr1, i);

		auto t_start = chrono::steady_clock::now();
		quickSort<int>(arr1, 0, i-1);
		auto t_end = chrono::steady_clock::now();
		auto t_duration = chrono::duration_cast<chrono::nanoseconds>(t_end - t_start);

		if (out.is_open()) {
			out << t_duration.count() << endl;
		}
		delete[] arr;
		delete[] arr1;
	}
	out.close();
/*
	cout << "Input element to search: ";
	int elem;
	cin >> elem;
	int ind = binSearch<int>(arr, 10, elem);
	if (ind == -1) {
		cout << "Is not such element in array";
	}
	else {
		cout << "Index of element in array: " << ind;
	}	*/
}