#include "launch.h"
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>

Launch::Launch() : Log()
{
    strcpy(this->Name_of_File, "NULL");
}

Launch::~Launch()
{
}

Launch::Launch(const Launch &obj)
{
    this->Event_ID = obj.Event_ID;
    strcpy(this->Description, obj.Description);
    strcpy(this->User_Name, obj.User_Name);
    strcpy(this->Name_of_File, obj.Name_of_File);
}

void Launch::set_Name_Of_File(char* Name)
{
    strcpy(this->Name_of_File, Name);
}

char* Launch::get_Name_Of_File()
{
    char *tmp = new char[40];
    strcpy(tmp, this->Name_of_File);
    return tmp;
}

void Launch::loadFromFile(FILE* F)
{
    int i;
    int count = 0; char id[40], userName[40], description[40] , fileName[40], buf[40];
    fgets(id,40,F);
    i = atoi(id);
    fgets(userName, 40, F), fgets(description, 40, F), fgets(fileName, 40, F);
    this->set_Event_ID(i);
    for (i = 0; *(userName + i) != '\n'; i++);
    *(userName + i ) = '\0';
    for (i = 0; *(description + i) != '\n'; i++);
    *(description + i ) = '\0';
    for (i = 0; *(fileName + i) != '\n'; i++);
    *(fileName + i ) = '\0';
    this->set_Description(description);
    this->set_User_Name(userName);
    this->set_Name_Of_File(fileName);
}

void Launch::operator ()(int id, char *descr, char *userName, char *fileName)
{
    this->Event_ID = id;
    strcpy(this->Description, descr);
    strcpy(this->User_Name, userName);
    strcpy(this->Name_of_File, fileName);
}
