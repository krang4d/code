#ifndef COMMANDS_H
#define COMMANDS_H
#include stdlib.h

class commands
{
private:
    char *cmd[];
    size_t c_size;

public:
    commands();
    ~commands();
    size_t get_size();
    char* get_name(int i);
};

#endif // COMMANDS_H
