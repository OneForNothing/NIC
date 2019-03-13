#include "database.h"
#include <QMessageBox>
#include<QDebug>
Database* Database::m_db = NULL;

Database::Database()
{
    m_sqldb = QSqlDatabase::addDatabase("QSQLITE");
    m_sqldb.setDatabaseName("lord.db");
    if (!m_sqldb.open()) {
        QMessageBox::warning(NULL, "error", m_sqldb.lastError().text());
    }

    QSqlQuery query;
    QString sql = "create table if not exists Friends (F_FriendID integer, F_UserID integer);";
    query.exec(sql);
    sql = QString("create table if not exists User_GroupS (UG_ID integer,UG_Name varchar(20),UG_CreateTime DATE,UG_AdminID integer);");
    query.exec(sql);
    sql = QString("create table if not exists UserState (US_ID integer, US_Name varchar(20), User_State boolean);");
    query.exec(sql);
    sql = QString("create table if not exists User (U_ID int, U_nickName varchar(20), U_passWord varchar(20),U_sex boolean,U_age int,U_signment varchar(100));");

    query.exec(sql);
}


//插入新用户
void Database::insertIntoUser(DBUser user) {//根据此种写法，在进行insertUser操作之前，就应该在结构体DBUser中获取完整的uid、name、pwd
    QSqlQuery query(m_sqldb);      //此处需不需要加(m_sqldb)？

    query.prepare("insert into User(U_ID, U_nickName, U_passWord,U_sex, U_age,U_signment)"
                        "values(:uid, :name, :pwd, :sex,:age,:sign)");

    query.bindValue(":uid", QVariant(user.uid));
    query.bindValue(":name", QVariant(user.name));
    query.bindValue(":pwd", QVariant(user.pwd));
    query.bindValue(":sex", QVariant(user.sex));
    query.bindValue(":age", QVariant(user.age));
    query.bindValue(":sign", QVariant(user.sign));

    int ret = query.exec();
    if (!ret)
    {
        qDebug()<<"插入用户信息错误 "<< query.lastError().text();
        return;
    }

    query.prepare("insert into UserState (US_ID,US_Name,User_State) values(:uid,:name,0)");
    query.bindValue(":uid", QVariant(user.uid));
    query.bindValue(":name", QVariant(user.name));



    ret = query.exec();
    if (!ret)
    {
        qDebug()<<"插入用户状态错误 "<< query.lastError().text();
        return;
    }

   qDebug()<<"插入用户信息*************";

}


//更新user的用户信息
void Database::updateUser(DBUser user)
{
    QSqlQuery query(m_sqldb);
    query.prepare("update User set U_ID = :ID,U_nickName =:name,U_passWord =:pwd,U_sex=:sex, U_age=:age,U_signment =:signment");
    query.bindValue(":ID",QVariant(user.uid));
    query.bindValue(":name",QVariant(user.name));
    query.bindValue(":pwd",QVariant(user.pwd));
    query.bindValue(":sex", QVariant(user.sex));
    query.bindValue(":age", QVariant(user.age));
    query.bindValue(":signment",QVariant(user.sign));
    int ret = query.exec();
    if(!ret)
    {
        qDebug()<<"更新用户信息失败"<<query.lastError();
        return;
    }

}

//查找所有在线人员,输出在线人员的ID和昵称
bool Database::queryUsersWithIsonline(QVector<DBUser> &users)
{
    QSqlQuery query(m_sqldb);
    query.prepare("select  User.U_ID ,User.U_nickName,User.U_passWord ,User.U_sex ,User.U_age from User, UserState where User.U_ID=UserState.US_ID and UserState.User_state = 1");
    int ret = query.exec();
    if(!ret)
    {
        qDebug()<<"查找用户信息失败"<<query.lastError();
        return false;
    }

    DBUser u;
    while(query.next())//必须调用next函数
    {
        u.uid = query.value(0).toInt();
        u.name = query.value(1).toString();
        u.pwd = query.value(2).toString();
        u.sex = query.value(3).toInt();
        u.age = query.value(4).toInt();
        u.sign = query.value(5).toString();
        users.push_back(u);
    }
    return true;
}


//根据用户ID查找用户
DBUser Database::queryUsersWithID(int id)
{
    DBUser user ;
    QSqlQuery query(m_sqldb);
    query.prepare("select *from User where U_ID = :id ;");
    query.bindValue(":id",id);
    int ret = query.exec();
    if (!ret)
    {
        DBUser notfound;
        notfound.uid = -1;
        notfound.name = QString("notfound");
        qDebug() << "没有查找到该用户" << query.lastError().text();
        return notfound;
    }
    while(query.next())//必须调用next函数
    {
        user.uid = query.value(0).toInt();
        user.name = query.value(1).toString();
        user.pwd = query.value(2).toString();
        user.sex = query.value(3).toInt();
        user.age = query.value(4).toInt();
        user.sign = query.value(5).toString();

    }
    return user;
}

//添加好友
bool Database::insertIntoFriend()
{

}

//删除好友
bool Database::deleteFromFriend()
{

}
//改变用户状态，显示离线
void Database::outlineState()
{
    QSqlQuery query(m_sqldb);
    query.prepare("update UserState set User_State = 0");

    int ret = query.exec();
    if (!ret)
    {
        qDebug()<<"update user_state failed: "<< query.lastError().text();
        return;
    }
    qDebug()<<"服务器关闭，所用用户已经设置为离线状态";


}

//改变用户状态，显示在线
void Database::onlineState(int uid)
{
    //QString sql;
    QSqlQuery query(m_sqldb);
    //sql =
    query.prepare("update UserState set User_State = 1 where US_ID = :uid;");
    query.bindValue(":uid",uid);

    int ret = query.exec();
    if (!ret)
    {
        qDebug()<<"update user_state failed: "<< query.lastError().text();
        return;
    }

}


int Database::getMaxUid() {
    QSqlQuery query;
    query.exec("select Max(U_ID) from User");
    if (!query.next()) {
        return -1;
    }
    qDebug()<<"数据库查询结果，最大的uid为："<<query.value(0).toInt();
    return query.value(0).toInt();
}

struct DBUser Database::getUserInfo(QString name , QString pwd) {
    QSqlQuery query(m_sqldb);//此处需不需要加(m_sqldb)？我们感觉要。。。
    query.prepare("select U_ID, U_nickName, U_passWord from User where U_nickName = :name and U_passWord = :pwd;");
    query.bindValue(":name", QVariant(name));
    query.bindValue(":pwd", QVariant(pwd));
    query.exec();
    DBUser ret;
    if (!query.next()) {
        ret.uid = -1;
        return ret;
    }

    QSqlRecord record = query.record();
    ret.uid = record.value("U_ID").toInt();
    ret.name = record.value("U_nickName").toString();
    ret.pwd = record.value("U_passWord").toString();

    qDebug()<<"数据库查询结果，uid、name、pwd分别为："<<ret.uid<<"--"<<ret.name<<"--"<<ret.pwd;
    return ret;
}

Database* Database::getInstance() {
    if (m_db == NULL) {
        m_db = new Database;
    }
    return m_db;
}











