#ifndef LAUNCH_H
#define LAUNCH_H
#include "log.h"

class Launch : public Log
{
private:
    char Name_of_File[40];
public:
    Launch();
    Launch(const Launch&);
    char* get_Name_Of_File();
    void set_Name_Of_File(char*);
    void loadFromFile(FILE*);
    void operator ()(int, char*, char*, char*);
    ~Launch();
};

#endif // LAUNCH_H
