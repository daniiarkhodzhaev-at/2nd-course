//
// Created by Mercurius on 11.09.2021.
//

#include "../headers/Subvector.h"


Subvector::Subvector() {
    top = 0;
    capacity = 0;
    mas = NULL;
}


bool Subvector::resize(unsigned int new_capacity) {
    if(new_capacity <  top) {
        return false;
    }

    int *new_mas = new int[new_capacity];

    for (int i = 0; i <  top; ++i) {
        *(new_mas + i) = *( mas + i);
    }

    delete[]  mas;

    mas = new_mas;
    capacity = new_capacity;

    return true;
}

bool Subvector::push_back(int d) {
    int* sub;
    sub = mas;
    top += 1;


    if (capacity > top) {
        *(sub + top) = d;
        return true;
    }

    if (capacity <= top) {
        resize(capacity + 1);
        *(mas + top) = d;
        return true;
    }
    return false;
}

int Subvector::pop_back() {
    int* sub;
    sub = mas;
    if (top > 0) {
        top -= 1;
        int pop = *(sub + top - 1);
        *(sub + top - 1) = 0;
        return (pop);
    } else {
        return (1);
    }
}

void Subvector::clear() {
    int* sub;
    sub = mas;
    top = 0;
    int i;
    for (i = 0; i < top; i++) {
        *(sub + i) = 0;
    }
}

void Subvector::shrink_to_fit() {
    resize(top);
}

void Subvector::destructor() {
    delete[] mas;
    top = 0;
    capacity = 0;
    mas = NULL;
}

int Subvector::get_el(int n) {
    return *(mas + n);
}
