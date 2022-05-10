#ifndef MYCOMMON_H
#define MYCOMMON_H

#include <QWidget>

//定义数据处理结果状态码
enum RET_CODE {
    RET_OK = 0, //成功
    RET_DBERR_OPEN, //数据库查询打开失败
    RET_DBERR_RUN, //SQL执行失败
    RET_PARAMERR, //参数错误
    RET_NOFUNC, //方法不存在
    RET_NOWORKTYPE //处理类型不存在
};

//定义数据处理结果状态码对应的信息
extern QStringList RET_MSG;

//定义命令参数数据结构
typedef struct _CmdData {
    QString func; //处理的函数名称
    QMap<QString, QString> params; //参数列表
} CmdData;

//定义命令处理结果数据结构
typedef struct _RstData {
    int retCode; //结果状态码
    QString func; //处理的函数名称
    QString msg; //结果信息
    QVector< QVector<QString> > result; //处理结果数据，二位数组
} RstData;

// MYSQL数据库信息
typedef struct _MysqlInfo
{
    int port;
    QString host, name, usr, pwd;
} MysqlInfo;

class MyCommon : public QWidget
{
    Q_OBJECT
public:
    explicit MyCommon(QWidget *parent = nullptr);
    ~MyCommon();

    static MyCommon *instance(); //定义单例类
    static void InitDataBase(const MysqlInfo &dbInfo); //初始化数据库

    static QSqlDatabase GetNewDatabase() //获取数据库实例
    {
        QSqlDatabase newDb;
        if (QSqlDatabase::contains("mysql_1"))
        {
            int n = QSqlDatabase::connectionNames().size();
            newDb = QSqlDatabase::cloneDatabase(mDatabase, QString("mysql_%1").arg(n));
        }
        else
        {
            newDb = QSqlDatabase::cloneDatabase(mDatabase, "mysql_1");
        }

        return newDb;
    }

signals:

public slots:

private:
    static float xScal, yScal;
    static QRect mScreenRect;
    static MyCommon *self;//单例模式
    static QSqlDatabase mDatabase;
    static MysqlInfo mDbInfo;
};


#endif // MYCOMMON_H
