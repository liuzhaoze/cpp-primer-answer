/**
 * 编写你自己版本的用 shared_ptr 管理 connection 的函数。
 */

#include <iostream>
#include <memory>
#include <string>

/**
 * @brief 使用连接所需的信息
 *
 */
struct connection
{
    std::string ip;
    int port;
    connection(std::string ip_, int port_) : ip(ip_), port(port_)
    {
    }
};

/**
 * @brief 表示我们正在连接什么
 *
 */
struct destination
{
    std::string ip;
    int port;
    destination(std::string ip_, int port_) : ip(ip_), port(port_)
    {
    }
};

/**
 * @brief 打开连接
 *
 * @param pDest
 * @return connection
 */
connection connect(destination *pDest)
{
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

/**
 * @brief 关闭给定的连接
 *
 * @param pConn
 */
void disconnect(connection pConn)
{
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

/**
 * @brief 删除器
 *
 * @param pConn
 */
void end_connection(connection *pConn)
{
    disconnect(*pConn);
}

void f(destination &d)
{
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, end_connection);
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
    destination dest("202.118.176.67", 3316);
    f(dest);

    return 0;
}
