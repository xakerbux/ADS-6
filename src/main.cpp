// Copyright 2025 NNTU-CS
#include <iostream>
#include "tpqueue.h"

int main() {
    TPQueue<SYM> pqueue;
    pqueue.push(SYM{'a', 4});
    pqueue.push(SYM{'b', 7});
    pqueue.push(SYM{'c', 5});
    pqueue.push(SYM{'d', 2});

    while (!pqueue.isEmpty()) {
        SYM s = pqueue.pop();
        std::cout << s.ch << "(" << s.prior << ") ";
    }
    std::cout << std::endl;

    return 0;
}
