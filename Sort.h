#ifndef SORT_H_
#define SORT_H_

#include "Ropa.h"

// Merge Sort para ordenar por precio
template <class T>
class Sort {
    private:
        void copyArray(std::vector<Ropa> &A, std::vector<Ropa> &B, int low, int high);
        void mergeArrayPre(std::vector<Ropa> &A, std::vector<Ropa> &B, int low, int mid, int high);
        void mergeSplit(std::vector<Ropa> &A, std::vector<Ropa> &B, int low, int high);
    public:
        std::vector<Ropa> mergeSort(const std::vector<Ropa> &arr);
};

template <class T>
void Sort<T>::copyArray(std::vector<Ropa> &A, std::vector<Ropa> &B, int low, int high) {
    for (int i = low; i <= high; i++) 
        A[i] = B[i];
}

template <class T> 
void Sort<T>::mergeArrayPre(std::vector<Ropa> &A, std::vector<Ropa> &B, int low, int mid, int high) {
    int i = low;        // Low A
    int j = mid + 1;    // Segunda mitad A
    int k = low;        // Low B

    while (i <= mid && j  <= high) {
        if (A[i].getPrecio() < A[j].getPrecio()) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sort<T>::mergeSplit(std::vector<Ropa> &A, std::vector<Ropa> &B, int low, int high) {
    int mid;

    if ( (high - low) < 1)
        return;
    
    mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArrayPre(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

template <class T>
std::vector<Ropa> Sort<T>::mergeSort(const std::vector<Ropa> &arr) {
    std::vector<Ropa> v(arr);
    std::vector<Ropa> temp(arr.size());

    mergeSplit(v, temp, 0, arr.size() - 1);
    return v;
}

#endif