//
// Created by Yonatan Rappoport on 13/11/2023.
//

#include <iostream>
#include "exceptions.h"
#include "Board.h"
using namespace std;

int main() {
    Board b;
    pair<pos_t, pos_t> a;
    while(a.first.first != -1) {
        cout << b;
        while(a.first.first != -1) {
            a = b.getMove();
            try {
                b.move(a.first, a.second);
                break;
            } catch (const std::exception& e) {
                cout << e.what() << endl;
            }
        }
    }
    return 0;
}