/*
* Sort.h
* By: Andrea Medina Rico
* 22.11.23
* versio: 4
* Sort algorithm 
*/

#ifndef SORT_H_
#define SORT_H_

// MERGE SORT
template <class T>
class Sort {
    public:
        DList<T> selectionSort(DList<T> &arr);
};

template <class T>
DList<T> Sort<T>::selectionSort(DList<T> &arr) {
    DList<T> sorted;
    DLink<T> *temp = arr.head;
    DLink<T> *min = arr.head;
    DLink<T> *temp2 = arr.head;
    int size = arr.size;

    for (int i = 0; i < size; i++) {
        while (temp != 0) {
            if (temp->value < min->value) {
                min = temp;
            }
            temp = temp->next;
        }
        sorted.add(min->value);
        temp2 = arr.head;
        while (temp2 != 0) {
            if (temp2->value == min->value) {
                arr.remove(temp2->value); // value
            }
            temp2 = temp2->next;
        }
        temp = arr.head;
        min = arr.head;
    }
    return sorted;
}

#endif