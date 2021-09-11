#include <iostream>
#include "headers/Subvector.h"

using namespace std;


int main() {
    Subvector s;

    cerr << "init success" << endl;

    s.push_back(11);
    cerr << "push_back success" << endl;

    s.resize(255);

    cerr << "resize success" << endl;

    for (int i = 0; i < 255; i++) {
        s.push_back(i);
    }
    for (int i = 0; i < 255; i++) {
        cout << s.get_el(i) << ' ';
    }
    cout << endl;
    cout << s.pop_back();
    cout << endl;
    for (int i = 0; i < 255; i++) {
        cout << s.get_el(i) << ' ';
    }
    s.clear();
    cout << endl;
    for (int i = 0; i < 255; i++) {
        cout << s.get_el(i) << ' ';
    }
    s.shrink_to_fit();
    s.destructor();
    return 0;
}
