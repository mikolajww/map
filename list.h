#ifndef B
#define B
#include <iostream>
#include "Map.h"

using namespace std;

template <typename T> class list {
private:
    struct node {
        node* next;
        T* val;
    };
    node* head;
    node* current;
public:
    list ();
    list (const list& l);
    list& operator=(const list& l);
    ~list ();
    void insert (T* a);
    void goToHead ();
    T* getCurrentData ();
    void advance ();
    bool moreData ();
};

template <typename T> list<T>::list () {
    head = nullptr;
    current = nullptr;
}

template <typename T> list<T>::~list () {
    while (head) {
        node* t = head->next;
        delete (head->val);
        delete head;
        head = t;
    };
}

template <typename T> void list<T>::insert (T* a) {
    auto * t = new node;
    t->next = head;
    head = t;
    head->val = a;
}

template <typename T> void list<T>::goToHead () {
    current = head;
}

template <typename T> T* list<T>::getCurrentData () {
    return current->val;
}

template <typename T> void list<T>::advance () {
    current = current->next;
}

template <typename T> bool list<T>::moreData () {
    return current != nullptr;
}

template <typename T> list<T>::list(const list& l) {
    current = NULL;
    node *src, **dst;
    head = NULL;
    src = l.head;
    dst = &head;
    while (src) {
        *dst = new node();
		delete ((*dst)->val);
        (*dst)->val = new T(*src->val);
        (*dst)->next = NULL;
        if(src == l.current) {
            current=*dst;
        }
        src = src->next;
        dst = &((*dst)->next);
    }
}

template <typename T> list<T>& list<T>::operator=(const list& l) {
    if (&l == this) {
        return *this;
    }
    current = NULL;
    node *src, **dst;
    src = l.head;
    dst = &head;
    while (src) {
        if(*dst == NULL) {
            *dst = new node();
            (*dst)->next = NULL;
        }
		delete ((*dst)->val);
        (*dst)->val = new T(*src->val);
        if(src == l.current) {
            current=*dst;
        }
        src = src->next;
        dst = &((*dst)->next);
    }

    while (*dst) {
        node *t = (*dst)->next;
        delete *dst;
        *dst = t;
    }
    return *this;
}
#endif
