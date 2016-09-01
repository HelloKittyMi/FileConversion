#include "FileHandle.h"

#include "Conversion.h"
#include "mainwindow.h"

C_FileHandle::C_FileHandle(QObject *parent):
       QObject(parent = 0)
{

}

C_FileHandle::~C_FileHandle()
{}

void C_FileHandle::OnOpenFile(const QString qsFilePathName, int mainWindow)
{

}

int C_FileHandle::StartConvSingleFile(QString qsFilePath, int mainWindow, int nType, bool &bFlag)
{
    MainWindow *window = (MainWindow *)mainWindow;
    if(qsFilePath == ""){
        //TODO 弹窗
        window->messageBox.boxCritical("文件目录不能为空");
        return -1;
    }
    if(qsFilePath.indexOf((QString)(".pdb")) < 0){
        //TODO 弹窗
        window->messageBox.boxCritical("文件格式错误,请重新选择！");
        return -1;
    }
    QString qsCloneFilePath = qsFilePath;
    QFile qfOperateFile(qsFilePath);


    int nPosition = qsCloneFilePath.lastIndexOf(".pdb");
    QString qsDrtFilePath = "";
    if(nType == 0){
        qsDrtFilePath = qsCloneFilePath.replace(nPosition, 4, "_APTWTi.pd2");
    }
    else if(nType == 1){
        qsDrtFilePath = qsCloneFilePath.replace(nPosition, 4, "_WFMs.pd2");
    }
    if(!qfOperateFile.open(QIODevice::ReadOnly)){
        window->messageBox.boxCritical("文件打开失败！");
        return -1;
    }

    QByteArray qbData = qfOperateFile.readAll();
    qfOperateFile.close();
    int ret = this->ConversionFile(qbData, qsDrtFilePath, nType);
    if( ret < 0){
//        window->messageBox.boxAbout(" 文件转换失败！ ");
        return -1;
    }
    else if(ret == 1){
        window->ShowLog("文件" + qsFilePath + "转换模式已被强制装换为WFMs模式");
        window->SetCombox("WFMs");
    }
    window->ShowLog("文件" + qsFilePath + "转换完成");
    window->ShowLog("生成文件" + qsDrtFilePath);
    window->ShowLog(" ");

    bFlag = true;
    return 0;
}


void C_FileHandle::OnStartConversion(QStringList &qsFilePathList, int mainWindow, int nType, bool &bFlag)
{
    MainWindow *window = (MainWindow *)mainWindow;
    int num = 0, faild_num = 0;
    QString msg = "";
    for(int i =0; i < qsFilePathList.size(); i++)
    {
        if(StartConvSingleFile(qsFilePathList.at(i), mainWindow, nType, bFlag) < 0)
        {
            qDebug()<<"file:"<<qsFilePathList.at(i)<<"conversion faild\n";
            faild_num ++;
        }
    }
    num = qsFilePathList.size();
    msg = "转换完成\n";
    msg.append(QString("文件总数:") + QString::number(num)+"\n");
    msg.append(QString("失败个数:") + QString::number(faild_num)+"\n");
    window->messageBox.boxAbout(msg);
    return;
}



bool C_FileHandle::PdbToPd2(const char *pInFnamePdb,
                            const char *pInFnamePd2,
                            int nInType)
{
//    if(pInFnamePdb == NULL){
//        return false;
//    }
//    const char *pData;
    return false;
}


int C_FileHandle::ConversionFile(const QByteArray &qbFileData, QString &qsDrtFilePath, int nType)
{
    if((qbFileData.length() == 0)||(qsDrtFilePath == "")){
        return -1;
    }
    C_Conversion *cConversion = new C_Conversion();
    int ret = cConversion->ConversionData(qbFileData, qsDrtFilePath, (ePd2AcquisitionType)nType);

    if(ret < 0){
        if(cConversion != NULL) delete(cConversion);
        return -1;
    }
    else if(ret == 1){
        if(cConversion != NULL) delete(cConversion);
        return 1;
    }
    delete(cConversion);
    return 0;
}




