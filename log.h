#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <cstring>

class Launch;

class Log
{
protected:
    int Event_ID;
    char Description[40];
    char User_Name[40];
public:
    Log();
//    Log(int, char*, char*);
    Log(const Log&);
    void set_Event_ID(int);
    int get_Event_ID();
    void set_Description(char*);
    char* get_Description();
    void set_User_Name(char*);
    char* get_User_Name();
    virtual void loadFromFile(FILE*);
    virtual ~Log();
    friend Log& operator+=(Log& obj1, Log& obj2)
    {
        obj1.Event_ID = obj1.Event_ID + obj2.Event_ID;
        strcat(obj1.Description, obj2.Description);
        strcat(obj1.User_Name, obj2.User_Name);
        return obj1;
    }

    Log& operator++()
    {
        this->Event_ID += 1;
        return *this;
    }

    Log& operator+(char* decr)
    {
        strcat(this->Description, decr);
        return *this;
    }

    void operator()(int, char*, char*);

    Log operator++(int);
    Log& operator ^(int);
    Log& operator &(int);
    Log& operator |(int);
    Log& operator =(int);
    Log& operator =(char*);
    bool operator >=(Log*);

};

#endif // LOG_H
