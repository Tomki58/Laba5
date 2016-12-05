#ifndef DEQUE_H
#define DEQUE_H
#include "log.h"
#include "launch.h"
template <class T1, class T2>
class Deque
{
private:
    struct node
    {
        T1* ll;
        node* next;
    };
    node *top, *last;

public:
    Deque();
//    Deque(int, char*, char*); == ()
    Deque(const Deque&);
    void addLast(T1*);
//    void  addFirst(Log*); == <<
//    void addFirst(Launch*); == <<
    void addLast(T2*);
//    bool delLast();
//    bool delFirst();
    T1* First();
    T1* Last();
    bool sort();
    bool reverse();
    bool isEmpty();
//    void saveToFile(FILE*); == >> (FILE*)
//    Log* getElement(int); == []
    int getCount();
    ~Deque();

    void operator <<(T1*);
    void operator <<(T2*);
    void operator >> (FILE*);
    void operator ()(int, char*, char*);
    T1* operator[](int);
    bool operator --(int);
    bool operator --();
    bool operator >(Deque *);
};

#endif // DEQUE_H
