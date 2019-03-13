#include "common.h"

Server* Common::_server = NULL;

Common::Common()
{
}

Server *Common::getServerInstance()
{
    if( NULL == _server)
    {
        _server = new Server;
    }
    return _server;
}
