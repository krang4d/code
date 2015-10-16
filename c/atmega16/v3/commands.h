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
    size_t GetSize();
    char* GetName(int i);
};

#endif // COMMANDS_H
