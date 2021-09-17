//
// Created by Mercurius on 11.09.2021.
// Edited by Daniiarkhodzhaev A.T.
//

#include "../headers/Subvector.h"


Subvector::Subvector() {
    top = 0;
    capacity = 0;
    mas = nullptr;
}


Subvector::~Subvector() {
    delete[] mas;
}


bool Subvector::resize(unsigned new_capacity) {
    unsigned i;

    if(new_capacity < top) {
        return false;
    }

    int *new_mas = new int[new_capacity];

    for (i = 0; i < top; ++i) {
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

    if (capacity > top) {
        *(sub + top) = d;
        ++top;
        return true;
    }

    if (capacity <= top) {
        resize(2 * capacity + 1);
        *(mas + top) = d;
        ++top;
        return true;
    }
    return false;
}

int Subvector::pop_back() {
    int* sub;
    int pop;

    sub = mas;
    if (top > 0) {
        top -= 1;
        pop = *(sub + top - 1);
        *(sub + top - 1) = 0;
        return (pop);
    } else {
        return (1);
    }
}

void Subvector::clear() {
    int* sub;
    unsigned i;

    sub = mas;
    top = 0;
    for (i = 0; i < top; ++i) {
        *(sub + i) = 0;
    }
}

void Subvector::shrink_to_fit() {
    resize(top);
}

int Subvector::get_el(unsigned n) {
    return *(mas + n);
}

void Subvector::set_el(unsigned n, int d) {
    *(mas + n) = d;
}

unsigned Subvector::size() {
    return top;
}
