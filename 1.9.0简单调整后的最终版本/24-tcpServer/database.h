#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>

struct DBUser {
    int uid = 0;        // 用户id
    QString pwd = "";    // 密码
    QString name = "";   // 用户昵称
    bool sex = 1;        //性别，男性为1，女性为0
    int age = 0;         //年龄
    QString sign = "";   //用户个签
};


class Database
{
public:
    static Database* getInstance();//单例化，对于一个服务器只需要一个数据库就行了

    void insertIntoUser(struct DBUser user);  //插入新用户
    void updateUser(struct DBUser user);//修改用户信息


    bool queryUsersWithIsonline(QVector<DBUser>&users);//查找所有在线人员
    DBUser queryUsersWithID(int id);//根据ID查找用户

    bool insertIntoFriend();  //添加好友
    bool deleteFromFriend();  //删除好友


    void outlineState(void);  //显示离线状态
    void onlineState(int uid);   //显示在线状态


    int getMaxUid();
    struct DBUser getUserInfo(QString name, QString pwd);

private:
    Database();
    QSqlDatabase m_sqldb;
    static Database* m_db;
};

#endif // DATABASE_H

