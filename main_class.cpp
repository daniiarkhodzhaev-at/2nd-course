#include <iostream>
using namespace std;



class subvector {
public:
    int* mas;
    unsigned int top;
    unsigned int capacity;

    bool init(subvector* qv) {
        qv->mas = NULL;
        qv->top = 0;
        qv->capacity = 0;
        return true;
    }

    bool resize(subvector* qv, unsigned int new_capacity) {
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
            cerr << "/I'm here/" << top << '/' << new_capacity << '/' << sizeof(old_sub) << '/' << endl;
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

    bool push_back(subvector* qv, int d) {
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

    int pop_back(subvector* qv) {
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

    void clear(subvector* qv) {
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

    void shrink_to_fit(subvector* qv) {
        int top, capacity;
        int* sub;
        sub = qv->mas;
        top = qv->top;
        capacity = qv->capacity;
        resize(qv, top);
    }

    void destructor(subvector* qv) {
        int top, capacity;
        int* sub;
        sub = qv->mas;
        top = qv->top;
        capacity = qv->capacity;
        delete[] qv->mas;
    }
};


int main() {
    subvector s;
    s.init(&s);

    cerr << "init success" << endl;

    s.push_back(&s, 11);
    cerr << "push_back success" << endl;

    s.resize(&(s), 255);

    cerr << "resize success" << endl;

    for (int i = 0; i < 255; i++) {
        s.push_back(&s, i);
    }
    for (int i = 0; i < 255; i++) {
        cout << *(s.mas + i) << ' ';
    }
    cout << endl;
    cout << s.pop_back(&(s));
    cout << endl;
    for (int i = 0; i < 255; i++) {
        cout << *(s.mas + i) << ' ';
    }
    s.clear(&(s));
    cout << endl;
    for (int i = 0; i < 255; i++) {
        cout << *(s.mas + i) << ' ';
    }
    s.shrink_to_fit(&(s));
    s.destructor(&(s));
    return 0;
}
