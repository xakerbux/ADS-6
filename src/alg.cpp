// Copyright 2021 NNTU-CS
// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

 public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty() || item.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr &&
               current->next->data.prior >= item.prior) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    T pop() {
        if (isEmpty()) {
            return T();
        }
        Node* temp = head;
        T result = head->data;
        head = head->next;
        delete temp;
        return result;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    T get() const {
        if (isEmpty()) {
            return T();
        }
        return head->data;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
