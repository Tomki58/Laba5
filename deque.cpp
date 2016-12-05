#include "deque.h"
#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdlib>
template <class T1, class T2>
Deque<T1,T2>::Deque()///////////?????????????????????????????? +
{
    top = NULL;
    last = NULL;
}

//Deque::Deque(int a, char *s, char *str)
//{
//    Log *l1 = new Log;
//    (*l1)(a, s, str);
//    *top->ll = *l1;
//    top->next = NULL;
//    last = top;
//}

//Deque::Deque(const Deque &obj)
//{
//    top->ll = (obj.top->ll);
//    top->next = obj.top->next;
//    //////?????????????
//    Deque *D1 = new Deque;

//}
template <class T1, class T2>
Deque<T1,T2>::~Deque()
{
    delete top;
    delete last;
}

//void Deque::addFirst(Log* obj)
//{
//    node *cur = new node;
//    cur->ll = obj;
//    if (top == NULL)
//    {
//        top = cur;
//        last = top;
//        top->next = NULL;
//    }
//    else
//    {
//        cur->next = top;
//        top = cur;
//    }
//}
template <class T1, class T2>
void Deque<T1,T2>::addLast(T1* obj)
{
    node *cur = new node;
    cur->ll = obj;
    cur->next = NULL;
    if (top == NULL)
    {
        top = cur;
        last = top;
        top->next = NULL;
    }
    else
    {
        last->next = cur;
        last = cur;
    }
}

//bool Deque::delFirst()
//{
//    if (top == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        node* cur;
//        cur = top;
//        top = top->next;
//    }
//    return 1;
//}

//bool Deque::delLast()
//{
//    if (top == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        node* cur;
//        cur = top;
//        if (cur == last)
//        {
//            top = NULL;
//            last = NULL;
//        }
//        else
//        {
//            while (cur->next != last)
//                cur = cur->next;
//            last = cur;
//            last->next = NULL;
//        }
//    }
//    return 1;
//}
template <class T1, class T2>
bool Deque<T1,T2>::sort()
{
    node *cur;
    T1 buf;
    bool swap = 1;
    cur = top;
    if (cur == NULL)
    {
        return 0;
    }
    else
    {
        while (swap)
        {
            swap = 0;
            while (cur != last)
            {
                if(strcmp((*cur->ll).get_Description(),(*cur->next->ll).get_Description()) > 0)
                {
                    buf = *cur->ll;
                    *cur->ll = *cur->next->ll;
                    *cur->next->ll =  buf;
                    swap = 1;
                    cur = cur->next;
                }
                else
                    cur = cur->next;
            }
            cur = top;
        }
        return 1;
    }
}

template <class T1, class T2>
bool Deque<T1,T2>::reverse()
{
    T1 buf;
    node *cur1, *cur2, *ptr;
    cur1 = top;
    cur2 = last;
    if (cur1 == NULL)
    {
        return 0;
    }
    else
    {
        if(cur2 != cur1)
        {
            while (cur2->next != cur1 || cur2!=cur1)
            {
                T1 *buf = new T1(*cur1->ll);
                *cur1->ll = *cur2->ll;
                *cur2->ll = *buf;
                cur1 = cur1->next;
                ptr = top;
                while (ptr->next != cur2)
                    ptr = ptr->next;
                cur2 = ptr;
                delete buf;
            }
        }
        return 1;
    }
}

template <class T1, class T2>
T1* Deque<T1,T2>::First()
{
    {
        return this->top->ll;
    }
}

template <class T1, class T2>
T1* Deque<T1,T2>::Last()
{
    {
        return this->last->ll;
    }
}

//void Deque::addFirst(Launch* obj)
//{
//    node *cur = new node;
//    cur->ll = obj;
//    if (top == NULL)
//    {
//        top = cur;
//        last = top;
//        top->next = NULL;
//    }
//    else
//    {
//        cur->next = top;
//        top = cur;
//    }
//}

template <class T1, class T2>
void Deque<T1,T2>::addLast(T2* obj)
{
    node *cur = new node;
    cur->ll = obj;
    cur->next = NULL;
    if (top == NULL)
    {
        top = cur;
        last = top;
        top->next = NULL;
    }
    else
    {
        last->next = cur;
        last = cur;
    }
}

template <class T1, class T2>
bool Deque<T1,T2>::isEmpty()
{
    return (top == NULL) ? 1 : 0;
}

//void Deque::saveToFile(FILE *F)
//{
//    node* cur = top; char id[15], description[40], username[40], filename[40];
//    for (cur = top; cur != last->next; cur = cur->next)
//    {
//        Launch *D = dynamic_cast<Launch*>(cur->ll);
//        if (D == NULL)
//        {
//            itoa(cur->ll->get_Event_ID(), id, 10);
//            fputs("Log\n", F);
//            strcat(id, "\n"); strcpy(description, cur->ll->get_Description()); strcpy(username, cur->ll->get_User_Name());
//            strcat(description, "\n"); strcat(username, "\n");
//            fputs(id, F);
//            fputs(description,F);
//            fputs(username,F);
//        }
//        else
//        {
//            itoa(D->get_Event_ID(), id, 10);
//            strcpy(description, D->get_Description()); strcpy(username, D->get_User_Name()); strcpy(filename, D->get_Name_Of_File());
//            strcat(id, "\n"); strcat(description, "\n"); strcat(username, "\n"); strcat(filename, "\n");
//            fputs("Launch\n", F);
//            fputs(id, F);
//            fputs(description, F);
//            fputs(username,F);
//            fputs(filename, F);
//        }
//    }
//}

//Log* Deque::getElement(int number)
//{
//    node* cur; int count;
////    if (this->isEmpty())
////        return NULL;
////    else
////        for (cur = this->top, count = 1; cur != this->last->next || count < number; cur = cur->next, count++);
////    if (count < number || cur == last->next)
////        return NULL;
////    else
////        return cur->ll;
//    for (cur = top, count = 0; count < number; cur = cur->next, count++);
//    return cur->ll;
//}

template <class T1, class T2>
int Deque<T1,T2>::getCount()
{
    node* cur; int count;
    if (this->isEmpty())
        return 0;
    else
    {
        for (cur = top, count = 0; cur != last->next; cur = cur->next, count++);
        return count;
    }
}

template <class T1, class T2>
void Deque<T1,T2>::operator <<(T1* obj)
{
    {
        node *cur = new node;
        cur->ll = obj;
        if (top == NULL)
        {
            top = cur;
            last = top;
            top->next = NULL;
        }
        else
        {
            cur->next = top;
            top = cur;
        }
    }
}

template <class T1, class T2>
T1* Deque<T1,T2>::operator [](int number)
{
    node* cur; int count;
    for (cur = top, count = 0; count < number; cur = cur->next, count++);
    return cur->ll;
}

template <class T1, class T2>
void Deque<T1,T2>::operator <<(T2* obj)
{
    {
        node *cur = new node;
        cur->ll = obj;
        if (top == NULL)
        {
            top = cur;
            last = top;
            top->next = NULL;
        }
        else
        {
            cur->next = top;
            top = cur;
        }
    }
}

template <class T1, class T2>
void Deque<T1,T2>::operator >>(FILE *F)
{
    node* cur = top; char id[15], description[40], username[40], filename[40];
    for (cur = top; cur != last->next; cur = cur->next)
    {
        T2 *D = dynamic_cast<T2*>(cur->ll);
        if (D == NULL)
        {
            itoa(cur->ll->get_Event_ID(), id, 10);
            fputs("Log\n", F);
            strcat(id, "\n"); strcpy(description, cur->ll->get_Description()); strcpy(username, cur->ll->get_User_Name());
            strcat(description, "\n"); strcat(username, "\n");
            fputs(id, F);
            fputs(description,F);
            fputs(username,F);
        }
        else
        {
            itoa(D->get_Event_ID(), id, 10);
            strcpy(description, D->get_Description()); strcpy(username, D->get_User_Name()); strcpy(filename, D->get_Name_Of_File());
            strcat(id, "\n"); strcat(description, "\n"); strcat(username, "\n"); strcat(filename, "\n");
            fputs("Launch\n", F);
            fputs(id, F);
            fputs(description, F);
            fputs(username,F);
            fputs(filename, F);
        }
    }
}

template <class T1, class T2>
void Deque<T1,T2>::operator ()(int id, char *descr, char *userName)
{
    T1 *l1 = new T1;
    (*l1)(id, descr, userName);
    *top->ll = *l1;
    top->next = NULL;
    last = top;
}

template <class T1, class T2>
bool Deque<T1,T2>::operator --(int idx)
{
    if (top == NULL)
    {
        return 0;
    }
    else
    {
        node* cur;
        cur = top;
        if (cur == last)
        {
            top = NULL;
            last = NULL;
        }
        else
        {
            while (cur->next != last)
                cur = cur->next;
            last = cur;
            last->next = NULL;
        }
    }
    return 1;
}

template <class T1, class T2>
bool Deque<T1,T2>::operator --()
{
    if (top == NULL)
    {
        return 0;
    }
    else
    {
        node* cur;
        cur = top;
        top = top->next;
    }
    return 1;
}
