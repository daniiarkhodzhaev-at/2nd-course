#include <iostream>
#include "subvector.h"
using namespace std;

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
