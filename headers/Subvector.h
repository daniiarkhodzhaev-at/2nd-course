//
// Created by Mercurius on 11.09.2021.
//

#ifndef INC_2ND_COURSE_SUBVECTOR_H
#define INC_2ND_COURSE_SUBVECTOR_H

#include <iostream>
using namespace std;


class Subvector {
private:
    int* mas;
    unsigned int top;
    unsigned int capacity;

public:
    Subvector();


    bool resize(unsigned int new_capacity);


    bool push_back(int d);


    int pop_back();


    void clear();


    void shrink_to_fit();


    int get_el(int n);


    void destructor();
};


#endif //INC_2ND_COURSE_SUBVECTOR_H
