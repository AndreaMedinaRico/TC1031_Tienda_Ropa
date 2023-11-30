/*
* doublelist.h
* By: Andrea Medina Rico
* 14.10.23
* version: 1
* Linked List Class
*/

#ifndef DOUBLELIST_H_
#define DOUBLELIST_H_

#include <iostream>
#include <string>
#include <sstream>
#include <ostream>

template <class T> class DList;
template <class T> class Sort;
class Archivo;

template <class T>
class DLink {
    private:
        DLink(T);
	    DLink(T, DLink<T>*, DLink<T>*);
        DLink(const DLink<T>&); 

        T value;
        DLink<T> *previous;
        DLink<T> *next;

        friend class DList<T>;
        friend class Archivo;
        friend class Sort<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {};

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {};

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {};

template <class T>
class DList {
    private:
        DLink<T> *head;
        DLink<T> *tail;
        int size;

        friend class Archivo;

    public:
        DList();
        DList(const DList<T> &);
        ~DList();               // Destructor

        void clear();
        bool empty();
        int length();

        void addFirst(T);
        void add(T);

        bool find(T) const;
        void removeFirst();
        void removeLast();
        void remove(T);

        std::string toString() const;
        std::string toStringBackward() const;
        std::string toStringA() const;

        void swap(DLink<T>*, DLink<T>*);
        void bubbleSort();

        friend class Sort<T>;
};

template <class T>
DList<T>::DList(): head(0), tail(0), size(0) {}

template <class T>
DList<T>::DList(const DList<T> &source) : head(0), tail(0), size(0) {
    DLink<T> *p;

    p = source.head;
    while (p != 0) {
        add(p->value);
        p = p->next;
    }
}

template <class T>
DList<T>::~DList() {
    clear();
}

template <class T>
void DList<T>::clear() {
    DLink<T> *p, *q;

    p = head;
    while (p != 0) {
        q = p->next;
        delete p;
        p = q;
    }
    head = 0;
    tail = 0;
    size = 0;
}

template <class T>
bool DList<T>::empty() {
    return size == 0;
}

template <class T>
int DList<T>::length() {
    return size;
}

template <class T>
void DList<T>::addFirst(T val) {
    DLink<T> *newLink;

    newLink = new DLink<T>(val);
    if (newLink == 0) {
        std::cout << "No hay memoria" << std::endl;
        return;
    }

    newLink->next = head;
    head = newLink;
    tail = newLink;
    size++;
}

template <class T>
void DList<T>::add(T val)  {
	DLink<T> *newLink;

	newLink = new DLink<T>(val);	// Object created in HEAP
	
	if(newLink == 0) {
		std::cout << "No hay memoria" << std::endl;
        return;
	}
	if (empty() == true) {
		addFirst(val);
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
    size++;
}

template <class T>
bool DList<T>::find(T val) const {
    int pos = 0;
    int pos2 = size;
    DLink<T> *p, *q;

    p = head;
    q = tail;
    while (p != 0 && q != 0) {
        if (p->value == val) {
            return true;
        } else if (q->value == val) {
            return true;
        }
        p = p->next;
        q = q->previous;
        pos++;
        pos2--;
    }
    return false;  // Not found
}

template <class T>
void DList<T>::removeFirst() {
    DLink<T> *p;

    if (empty() == true) {
        std::cout << "Error: Lista vacia" << std::endl;
        return;
    }
    if (size == 1) {
        head = 0;
        tail = 0;
    } else {
        p = head;
        head = p->next;
        p->next->previous = 0;
        delete p;
        size--;
    }
}

template <class T>
void DList<T>::removeLast() {
    DLink<T> *p;

    if (empty() == true) {
        std::cout << "Error: Lista vacia" << std::endl;
        return;
    }
    if (size == 1) {
        head = 0;
        tail = 0;
    } else {
        p = tail;
        tail = p->previous;
        p->previous->next = 0;
        delete p;
        size--;
    }
}

template <class T>
void DList<T>::remove(T val) {
    int pos = find(val);
    DLink<T> *p;

    if (pos == -1)
        return;     // Not found
    if (pos == 0) {
        removeFirst();
        return;
    } else if (pos == size - 1) {
        removeLast();
        return;
    } else {
        p = head;
        for (int i = 0; i <= pos; i++) {
            p = p->next;
        }
        p->previous->next = p->next;
        p->next->previous = p->previous;
        delete p;
        size--;
    }
}

template <class T>
std::string DList<T>::toString() const {
	std::stringstream ss;
        DLink<T>* temp = head;
        while (temp) {
            T val = temp->value;
            ss << val << " ";
            temp = temp->next;
        }
        return ss.str();
}

template <class T> 
std::string DList<T>::toStringA() const {
    std::stringstream ss;
    DLink<T>* temp = head;
    int i = 1;
    while (temp) {
        T val = temp->value;
        ss << i << ". " << val << "\n";
        temp = temp->next;
        i++;
    }
    return ss.str();
}

template <class T>
void DList<T>::swap(DLink<T> *a, DLink<T> *b) {
    // CASE 1: a and b are the same
    if (a == b)
        return;
        
    // CASE 2: There is no a or b
    if (a == 0 || b == 0)
        return;

    // CASE 3: If node A is previous of node B
    if (a->next == b) {
        a->previous->next = b;
        b->next->previous = a;

        b->previous = a->previous;
        a->next = b->next;

        b->next = a;
        a->previous = b;

    // CASE 4: If node B is previous of node A
    } else if (b->next == a) {
        b->previous->next = a;
        a->next->previous = b;

        a->previous = b->previous;
        b->next = a->next;

        a->next = b;
        b->previous = a;

    } else {
        DLink<T> *p, *q, *r;

        p = a->previous;
        q = a->next;
        r = b->previous;

        a->previous = b->previous;
        a->next = b->next;
        b->previous = p;
        b->next = q;

        if (a->next != 0)
            a->next->previous = a;
        if (a->previous != 0)
            a->previous->next = a;
        if (b->next != 0)
            b->next->previous = b;
        if (b->previous != 0)
            b->previous->next = b;
    }
}

template <class T>
void DList<T>::bubbleSort() {
    if (head == NULL || head->next == NULL) {
        return; 
    }

    bool swapped;
    do {
        swapped = false;
        DLink<T>* prev = NULL;
        DLink<T>* current = head;
        DLink<T>* next = head->next;

        while (next != NULL) {
            if (current->value > next->value) {
                if (prev == NULL) {
                    head = next;
                } else {
                    prev->next = next;
                }
                current->next = next->next;
                current->previous = next; ///
                next->next = current;
                next->previous = prev; ///
                swapped = true;
                current = next;
                next = current->next;
            }

            prev = current;
            current = next;
            if (next == NULL) 
                next = NULL;
            else 
                next = next->next;
        }
    } while (swapped);
}

#endif