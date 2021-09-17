//
// Created by Mercurius on 11.09.2021.
// Edited by Daniiarkhodzhaev A.T.
//

#include <climits>


#include <Subvector.h>


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
    int pop;

    if (top > 0) {
        top -= 1;
        pop = *(mas + top - 1);
        return pop;
    } else {
        return INT_MAX;
    }
}

void Subvector::clear() {
    top = 0;
    capacity = 0;
    delete[] mas;
    mas = nullptr;
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
