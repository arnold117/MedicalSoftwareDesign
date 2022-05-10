#include "cdataclass.h"

CDataClass::CDataClass(QObject *parent) : QObject(parent)
{
    Worker *worker = new Worker; //定义数据处理类
    worker->moveToThread(&mWorkerThread); //把数据处理类移到线程
    connect(&mWorkerThread, &QThread::finished, worker, &QObject::deleteLater);
    //定义信号槽，把命令发送到线程里面的槽函数
    connect(this, &CDataClass::operate, worker, &Worker::doWork);
    //定义信号槽，接收线程里面发送的结果
    connect(worker, &Worker::resultReady, this, &CDataClass::handleResults);
    mWorkerThread.start(); //开启线程

    //初始化命令处理函数映射关系
    mFuncMap["checkUserPwd"] = &CDataClass::checkUserPwd;
    mFuncMap["getUsersData"] = &CDataClass::getUsersData;
    mFuncMap["addUsersData"] = &CDataClass::addUsersData;
    mFuncMap["editUsersData"] = &CDataClass::editUsersData;
    mFuncMap["getLogsData"] = &CDataClass::getLogsData;
}

void CDataClass::handleResults(const RstData &rstData)
{
    if (rstData.func == "checkUserPwd")
    {
        if (rstData.result.size() > 0)
        {
            emit signalLoginResult(true);
        }
        else
        {
            emit signalLoginResult(false);
        }
    }
    else
    {
        emit operateResult(rstData);
    }
}

void CDataClass::handleCmdDataQML(const QString &func, const QStringList &keys,
                                  const QStringList &values)
{
    qDebug() << "[CDataClass::handleCmdDataQML]" << func << keys << values;
    CmdData argcs;
    argcs.func = func;
    if (keys.size() != values.size())
    {
        return;
    }
    for (int var = 0; var < keys.size(); ++var)
    {
        argcs.params[keys[var]] = values[var];
    }
    handleCmdData(argcs);
}

void CDataClass::handleCmdData(const CmdData &argcs)
{
    RstData rstData;
    if (!mFuncMap.contains(argcs.func))
    {
        rstData.retCode = RET_NOFUNC;
        rstData.msg = RET_MSG[rstData.retCode];
        rstData.func = argcs.func;
        emit signalMeaasge(rstData.msg);
        return;
    }

    (this->*mFuncMap[argcs.func])(argcs);
}
