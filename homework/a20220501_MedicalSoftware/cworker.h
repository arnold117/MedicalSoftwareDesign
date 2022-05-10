#ifndef CWORKER_H
#define CWORKER_H

#include <QObject>

class CWorker : public QObject
{
    Q_OBJECT
public:
    explicit CWorker(QObject *parent = nullptr);

signals:

};

#endif // CWORKER_H
