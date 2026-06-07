// Copyright 2025 NNTU-CS
#include "tpqueue.h"

int main() {
    TPQueue<SYM> pqueue;
    pqueue.push(SYM{'a', 4});
    pqueue.push(SYM{'b', 7});
    pqueue.push(SYM{'c', 5});
    pqueue.push(SYM{'d', 2});
    
    // Извлечение: b (prior 7), c (prior 5), a (prior 4), d (prior 2)
    SYM c1 = pqueue.pop();  // b
    SYM c2 = pqueue.pop();  // c
    SYM c3 = pqueue.pop();  // a
    SYM c4 = pqueue.pop();  // d
    
    return 0;
}
