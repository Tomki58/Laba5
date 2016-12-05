#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "log.h"

void Log::set_Event_ID( int a)
{
        Event_ID = a;
}

Log::Log()
{
    Event_ID = 0;
    strcpy(Description, "NULL");
    strcpy(User_Name, "NULL");
}

Log::~Log()
{
}

//Log::Log(int a, char *s, char *str)
//{
//    Event_ID = a;
//    strcpy(Description, s);
//    strcpy(User_Name, str);
//}

Log::Log(const Log &obj)
{
    Event_ID = obj.Event_ID;
    strcpy(Description, obj.Description);
    strcpy(User_Name, obj.User_Name);
}

int Log::get_Event_ID()
{
    if (Event_ID < 0)
    {
        return 0;
    }
    else
        return Event_ID;
}

void Log::set_Description(char* s)
{
    strcpy(Description, s);
}

char* Log::get_Description()
{
    char* tmp = new char[40];
    strcpy(tmp, Description);
    return tmp;
}

void Log::set_User_Name(char* s)
{
    strcpy(User_Name, s);
}

char* Log::get_User_Name()
{
    char* tmp = new char[40];
    strcpy(tmp, User_Name);
    return tmp;
}

void Log::loadFromFile(FILE* F)
{
    int i;
    int count = 0; char id[40], userName[40], description[40], buf[40];
    fgets(id, 40, F);
    fgets(userName, 40, F), fgets(description, 40, F);
    for (i = 0; id[i] != '\n'; i++);
    id[i] = '\0';
    if (!strcmp(id, "123"))
        this->set_Event_ID(123);
    this->set_Event_ID(atoi(id));
    for (i = 0; *(userName + i) != '\n'; i++);
    *(userName + i ) = '\0';
    for (i = 0; *(description + i) != '\n'; i++);
    *(description + i ) = '\0';
    this->set_Description(description);
    this->set_User_Name(userName);
}

void Log::operator ()(int id, char *desc, char* name)
{
    *this = id;
//    strcpy(this->Description, desc);
    *this = desc;
    strcpy(this->User_Name, name);
}

Log Log::operator ++(int i)
{
    Log *L1 = new Log(*this);
    this->Event_ID = this->Event_ID + 1;
    return *L1;
}

Log& Log::operator ^(int a)
{
    this->Event_ID = this->Event_ID ^ a;
    return *this;
}

Log& Log::operator &(int a)
{
    this->Event_ID = this->Event_ID & a;
    return *this;
}

Log& Log::operator |(int a)
{
    this->Event_ID = this->Event_ID & a;
    return *this;
}

Log& Log::operator =(int id)
{
    this->Event_ID = id;
    return *this;
}

Log& Log::operator =(char *descr)
{
    strcpy(this->Description, descr);
    return *this;
}

bool Log::operator >=(Log *obj)
{
    return (this->Event_ID >= obj->Event_ID) ? 1 : 0;
}
