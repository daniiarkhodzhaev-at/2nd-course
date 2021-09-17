//
// Created by Mercurius on 11.09.2021.
// Edited by Daniiarkhodzhaev A.T
//

#ifndef INC_2ND_COURSE_SUBVECTOR_H
#define INC_2ND_COURSE_SUBVECTOR_H

class Subvector {
private:
    int* mas;
    unsigned top;
    unsigned capacity;

public:
    Subvector();


    ~Subvector();


    /** Dangerous function: uninitialized values!
     */
    bool resize(unsigned new_capacity);


    bool push_back(int data);


    int pop_back();


    void clear();


    void shrink_to_fit();


    int get_el(unsigned position);


    void set_el(unsigned position, int data);


    unsigned size();
};


#endif //INC_2ND_COURSE_SUBVECTOR_H
