/*********************************************************************************************************
* 模块名称: packunpack.h
* 使用说明: 打包解包模块
* 摘   要: 类头文件
* 当前版本: 1.0.0
* 作   者: SZLY(COPYRIGHT 2018 - 2020 SZLY. All rights reserved.)
* 完成日期: 2019年09月23日
* 内   容:
* 注   意: none
**********************************************************************************************************
* 取代版本:
* 作   者:
* 完成日期:
* 修改内容:
* 修改文件:
*********************************************************************************************************/
#ifndef _PACKUNPACK_H_
#define _PACKUNPACK_H_

/*********************************************************************************************************
*                                            包含头文件
*********************************************************************************************************/
#include <QList>

/*********************************************************************************************************
*                                             类的定义
*********************************************************************************************************/
class PackUnpack
{

public:
    const int MAX_PACK_LEN = 10;

    //定义m_listBuf
    //m_listBuf[0]  : 对应packId
    //m_listBuf[1-8]: 对应arrData
    //m_listBuf[9]  : 对应checkSum
    QList<uchar> mListBuf;
    QList<int> mListPackLen;

    PackUnpack();
    int packData(QList<uchar> &listPack);
    bool unpackData(uchar data);
    QList<uchar> getUnpackRslt();

private:
    int  mPackLen;       //数据包长度
    bool mGotPackId;     //获取到ID的标志，获得正确的ID即为TRUE，否则为FALSE
    int  mRestByteNum;   //剩余字节数

    void packWithCheckSum(QList<uchar> &pack);
    bool unpackWithCheckSum(QList<uchar> &listPack);

};

#endif //_PACKUNPACK_H_
