#include "mycommon.h"

MyCommon *MyCommon::self = nullptr;
QSqlDatabase MyCommon::mDatabase;
MysqlInfo MyCommon::mDbInfo;

QStringList RET_MSG = QStringList() << "成功" << "数据库查询打开失败" << "SQL执行失败" << "参数错误" << "方法不存在" << "处理类型不存在";

MyCommon::MyCommon(QObject *parent) : QObject(parent)
{
    //注册元类型:主要是在定义信号槽的时候，传递的参数类型不一定是QT所识别的
    qRegisterMetaType<CmdData>("CmdData");
    qRegisterMetaType<RstData>("RstData");

    mDbInfo.port = 3306;
    mDbInfo.host = "127.0.0.1";
    mDbInfo.name = "test_db";
    mDbInfo.usr = "root";
    mDbInfo.pwd = "123456";
    InitDataBase(mDbInfo);
}

MyCommon::~MyCommon()
{
    if (self != nullptr)
    {
        delete self;
    }
}

void MyCommon::InitDataBase(const MysqlInfo &dbInfo)
{
    mDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mDatabase.setHostName(dbInfo.host);//设置主机地址
    mDatabase.setPort(dbInfo.port);  //设置端口
    mDatabase.setDatabaseName(dbInfo.name);  //设置数据库名称
    mDatabase.setUserName(dbInfo.usr);  //设置用户名
    mDatabase.setPassword(dbInfo.pwd);  //设置密码
}
