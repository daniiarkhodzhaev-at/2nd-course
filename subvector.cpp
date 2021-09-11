#include "subvector.h"

bool subvector::init(subvector* qv) {
    qv->mas = 0;
    qv->top = 0;
    qv->capacity = 0;
    return true;
}

bool subvector::resize(subvector* qv, unsigned int new_capacity) {
    int* new_sub = new int[new_capacity];
    int* old_sub;
    int top, capacity;
    old_sub = qv->mas;
    top = qv->top;
    capacity = qv->capacity;
    int i;

    if (new_capacity == 0) {
        qv->mas = new_sub;
        qv->capacity = new_capacity;
        delete[](old_sub);
        return true;
    }
    if (new_capacity >= capacity) {
        for (i = 0; i < capacity; i++) {
            new_sub[i] = *(old_sub + i);
        }
        for (i = capacity; i < new_capacity; i++) {
            new_sub[i] = 0;
        }
        qv->mas = new_sub;
        qv->capacity = new_capacity;
        delete[](old_sub);

        return true;
    }
    if (new_capacity < capacity) {
        for (i = 0; i < new_capacity; i++) {
            new_sub[i] = *(old_sub + i);
        }
        qv->mas = new_sub;
        qv->capacity = new_capacity;
        delete[](old_sub);
        return false;
    }

    delete[](old_sub);
    return false;
}

bool subvector::push_back(subvector* qv, int d) {
    int top, capacity;
    int* sub;
    sub = qv->mas;  // null
    top = qv->top;  // 0
    qv->top += 1;   //
    capacity = qv->capacity;

    if (capacity > top) {
        *(sub + top) = d;
        return true;
    }
    //
    if (capacity <= top) {
        resize(qv, capacity + 1);
        *(qv->mas + top) = d;
        return true;
    }
    return false;
}

int subvector::pop_back(subvector* qv) {
    int top, capacity;
    int* sub;
    sub = qv->mas;
    top = qv->top;
    capacity = qv->capacity;
    if (top > 0) {
        qv->top -= 1;
        int pop = *(sub + top - 1);
        *(sub + top - 1) = 0;
        return (pop);
    } else {
        return (1);
    }
}

void subvector::clear(subvector* qv) {
    int top, capacity;
    int* sub;
    sub = qv->mas;
    top = qv->top;
    capacity = qv->capacity;
    qv->top = 0;
    int i;
    for (i = 0; i < top; i++) {
        *(sub + i) = 0;
    }
}

void subvector::shrink_to_fit(subvector* qv) {
    int top, capacity;
    int* sub;
    sub = qv->mas;
    top = qv->top;
    capacity = qv->capacity;
    resize(qv, top);
}

void subvector::destructor(subvector* qv) {
    int top, capacity;
    int* sub;
    sub = qv->mas;
    top = qv->top;
    capacity = qv->capacity;
    delete[] qv->mas;
}

