#ifndef __DBCONNECTOR__
#define __DBCONNECTOR__

#include <string>
#include <vector>

#include <hiredis/hiredis.h>


namespace swss {

class DBConnector
{
public:
    /*
     * Connect to Redis DB wither with a hostname:port or unix socket
     * Select the database index provided by "db"
     *
     * Timeout - The time in milisecond until exception is been thrown. For
     *           infinite wait, set this value to 0
     */
    DBConnector(int db, std::string hostname, int port, unsigned int timeout);
    DBConnector(int db, std::string unixPath, unsigned int timeout);

    ~DBConnector();

    redisContext *getContext();
    int getDB();

    static void select(DBConnector *db);

private:
    redisContext *m_conn;
    int m_db;
};

}
#endif
