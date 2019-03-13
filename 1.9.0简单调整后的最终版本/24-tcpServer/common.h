#ifndef COMMON_H
#define COMMON_H

#include "server.h"
//单例化，作用仅仅是保证serve这个类的对象仅有一个
class Common
{
public:
    Common();

    static Server* getServerInstance(void);

private:
    static Server* _server;
};

#endif // COMMON_H
