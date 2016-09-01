#include "Conversion.h"
//#include "Logger.h"


static char gHead[(int)336] = {
    0x09,0x00,0x00,0x00,0xC8,0x00,0x00,0x00,0x54,0x65,0x63,0x68,0x69,0x6D,0x70,0x20,
    0x53,0x65,0x72,0x76,0x69,0x63,0x65,0x73,0x20,0x2D,0x20,0x50,0x44,0x32,0x20,0x66,
    0x69,0x6C,0x65,0x00,0x00,0x00,0x00,0x00,0x34,0x02,0x01,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x09,0x01,0x00,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x04,0x00,0x64,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
    0x0C,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB8,0x0B,0x00,0x00,
    0x08,0x0A,0xA8,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0xC2,0x5B,
    0xF5,0x36,0x30,0x35,0x30,0x33,0x39,0x39,0x31,0x30,0x2D,0x31,0x32,0x41,0x30,0x30,
    0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x06,0x00,
    0xF0,0x00,0x00,0x00,0xCD,0xCC,0xCC,0x3D,0x00,0x00,0x80,0x3F,0xAC,0xC5,0xA7,0x36
};

static char gUnknown158[8]={
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

static char gUnknown16c_1[8] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

static char gUnknown16c_2[8] = {
    0xF0,0xA7,0xC6,0x4B,0x37,0x89,0x41,0x00
};

static char gUnknownFix178[8] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F
};

static char gUnknownFix182[182] = {0};

/*说明文件，固定0x2c个字节*/
static char gIntroduce[44] = {
    0x49,0x65,0x63,0x20,0x46,0x49,0x6C,0x74,0x65,0x72,0x20,0x2D,0x2D,0x2D,0x0D,0x0A,
    0x43,0x61,0x6C,0x69,0x62,0x72,0x61,0x74,0x69,0x6F,0x6E,0x20,0x53,0x74,0x61,0x74,
    0x75,0x73,0x20,0x2D,0x2D,0x2D,0x0D,0x0A,0x43,0x48,0x5F,0x41
};

static char gUnknow23cFor4[4] = {
    0x03,0x00,0x01,0x00
};

static char gUnknow23cFor12[12] = {
    0x03,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00
};

static char gUnknowFixEnd8[8] = {
    0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

static char gUnknowFixEnd48[48] = {
    0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x01,0x00,0x50,0x00,0x00,0x00,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00
};

char gFileTail240[256] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x08,0x00,0x02,0x00,0xC8,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


bool pdb_to_pd2(const char *srcFilePath, int srcLen, const char *drtFilePath, int drtLen, int type)
{
    if(srcFilePath == NULL){
        //TODO 弹窗
        return false;
    }

    QString qsCloneFilePath = QString::fromLatin1(srcFilePath, srcLen);
    if(qsCloneFilePath.indexOf((QString)(".pdb")) < 0){
        //TODO 弹窗
        return false;
    }
    QFile qfOperateFile(qsCloneFilePath);
    QString qsDrtFilePath;
    if((drtFilePath != NULL) && (drtLen != 0)){
        qsDrtFilePath = QString::fromLatin1(drtFilePath, drtLen);
    }
    else if((drtFilePath == NULL)||(drtLen == 0))
    {
        int nPosition = qsCloneFilePath.lastIndexOf(".pdb");
        if(type == 0){
            qsDrtFilePath = qsCloneFilePath.replace(nPosition, 4, "_APTWTi.pd2");
        }
        else if(type == 1){
            qsDrtFilePath = qsCloneFilePath.replace(nPosition, 4, "_WFMs.pd2");
        }
    }
    if((type != 0)&&(type != 1)){
        return false;
    }
    if(!qfOperateFile.open(QIODevice::ReadOnly)){
        return false;
    }

    QByteArray qbData = qfOperateFile.readAll();
    qfOperateFile.close();
    C_Conversion *fileConversion = new C_Conversion();
    if(fileConversion->ConversionData(qbData, qsDrtFilePath, (ePd2AcquisitionType)type) != 0){
        if(fileConversion != NULL) delete fileConversion;
        return false;
    }
    if(fileConversion != NULL) delete fileConversion;
    return true;
}


C_Conversion::C_Conversion()
{
    memset(gUnknownFix182, 0, sizeof(gUnknownFix182));
    gUnknownFix182[178] = 0x02;
}

C_Conversion::~C_Conversion()
{
}

int C_Conversion::ConversionData(const QByteArray qbInData,
                             QString &qsDstFilePath,
                             ePd2AcquisitionType eType )
{
    struPdbFileData struFilePdbData;
    struPd2 struPd2Data;
    int ret = this->PdbToData(qbInData, struFilePdbData, eType);
    if(ret == 1){
        eType = E_PD2_ACQUISITION_TYPE_WFMs;
        qsDstFilePath.replace(QString("_APTWTi"), QString("_WFMs"));
    }
    else if(ret < 0){
        return -1;
    }
    if(this->PdbToPd2Data(struFilePdbData, struPd2Data, eType) < 0){
        return -1;
    }
    if(this->Pd2DataToFile(struPd2Data, qsDstFilePath, eType)){
        return -1;
    }
    if(ret == 1){
        return 1;
    }
    return 0;
}
/**
    @breif  将pdb文件流解析为结构体储存
    @param  pbPdbData--pdb文件流
    @param  struFileData--pdb文件结构体引用
    @return 0--ok   非零--err
*/
int C_Conversion::PdbToData(const QByteArray qbPdbData, struPdbFileData &struFileData,ePd2AcquisitionType &nType)
{
    char* pData = NULL;
    pData = (char*)qbPdbData.data();
    int nLen = qbPdbData.size();
    if((nLen < PDB_BASE_DATA_OFFSET) || (pData ==NULL)){
//        LOG_ERR("************qbd file err********\n");
//        qDebug()<<"文件长度错误\n";
        return -1;
    }
//    qDebug()<<"qbPdbData:"<<qbPdbData.size();

//    qDebug()<<"sizeof(struDevInfo):"<<sizeof(struDevInfo);
    memcpy((char *)&(struFileData.devInfo), (pData + PDB_BASE_DEVINFO_OFFSET), sizeof(struDevInfo));               // ??
//    qDebug()<<"struDevInfo.thPulse = "<<struFileData.devInfo.thPulse;

    struFileData.devOffset = PDB_BASE_DEVINFO_OFFSET;
    int nPulseCount = struFileData.devInfo.pls_total;
    struFileData.dataOffset = PDB_BASE_DATA_OFFSET;
//    qDebug()<<"sizeof(struPdPulse)"<<sizeof(struPdPulse);

    int nRealPulseCount = (nLen - struFileData.dataOffset - sizeof(struSampleConfig))/sizeof(struPdPulse);

//    qDebug()<<"nPulseCount is "<<nPulseCount;
//    qDebug()<<"nRealPulseCount is "<<nRealPulseCount;
    if((nPulseCount > nRealPulseCount) || (nRealPulseCount == 0) || (nPulseCount == 0)){
//        LOG_WRN("*****The pdb file may have been damaged ********\n");


//        qDebug()<<"文件已损坏\n";
        if(nPulseCount > nRealPulseCount){
            struFileData.devInfo.pls_total = nRealPulseCount;
            nPulseCount = nRealPulseCount;
//            qDebug()<<"文件已损坏\n";
        }
        if(nPulseCount <= 0 || nRealPulseCount <= 0)
            return -2;
    }
    pData += struFileData.dataOffset;
    nLen -= struFileData.dataOffset;
    struPdPulse struPulseData;
    struSampleConfig struSampleCtrl;
    struFileData.qvPdbData.clear();
    while(nLen > 0){
        memcpy((char*)&(struSampleCtrl), (pData), sizeof(struSampleConfig));
        pData += sizeof(struSampleConfig);
        nLen -= sizeof(struSampleConfig);            
        for(int i = 0; i < struSampleCtrl.sampleNumPer; i ++){
            memcpy((char*)&(struPulseData), (pData), sizeof(struPdPulse));
            pData += sizeof(struPdPulse);
            nLen -= sizeof(struPdPulse);
            struFileData.qvPdbData.append(struPulseData);
            if((pData == NULL)&&(nLen != 0)){
                return -3;
            }
        }
    }
    if((struFileData.qvPdbData.at(0).equivalT == -1) &&\
            (struFileData.qvPdbData.at(0).equivalW == -1)&&\
            (nType == E_PD2_ACQUISITION_TYPE_APTWTi)){
        nType = E_PD2_ACQUISITION_TYPE_WFMs;            //若无等效T和等效W值则将转换模式强制转换为WFMs模式
//        qDebug()<<"转换模式强制变为WFMs模式";
        return 1;
    }
    return 0;
}

/**
    @breif  将pdb文件结构体装换为pd2文件结构体
    @param  Pdb文件结构体和pd2文件结构体引用
    @return 0--转换成功
*/
int C_Conversion::PdbToPd2Data(struPdbFileData &struSrcData, struPd2 &struDrtData, ePd2AcquisitionType &nType)
{
    memcpy(struDrtData.filePara1.head, gHead, sizeof(gHead));

    struDrtData.filePara1.trigger = (float)AmplitudeStandard(0,\
                                                             (float)struSrcData.devInfo.thPulse,\
                                                             struSrcData.devInfo.amp);
    struDrtData.filePara1.sampleRate = SAMPLE_RATE;
    memcpy(struDrtData.filePara1.unknown158, gUnknown158, sizeof(gUnknown158));
    struDrtData.filePara1.pulseNum = struSrcData.devInfo.pls_total;
//    struDrtData.filePara1.acquisitionTime = \
//            (float)(struSrcData.devInfo.end_time - struSrcData.devInfo.start_time)/TIME_PARAM;
    struDrtData.filePara1.acquisitionTime = struSrcData.devInfo.sampleTotal * POWER_FREQ;
    struDrtData.filePara1.circuitType = (char)E_PD2_CIRCUIT_DIRECT;
    struDrtData.filePara1.channel     = (char)0x01;
    struDrtData.filePara1.acquisitionType = (char)nType;
    struDrtData.filePara1.bandwidth = 0x00;
    /** unknow16c可能为gUnknow16c_1或gUnknow16c_2 */
    if(struDrtData.filePara1.acquisitionType == 0x00){
        memcpy(struDrtData.filePara1.unknown16c, gUnknown16c_1, sizeof(gUnknown16c_1));
    }
    else{
        memcpy(struDrtData.filePara1.unknown16c, gUnknown16c_2, sizeof(gUnknown16c_2));
    }
    struDrtData.filePara1.dateTime = struSrcData.devInfo.start_time;
    memcpy(struDrtData.filePara1.unknownFix178, gUnknownFix178, sizeof(gUnknownFix178));
    struDrtData.filePara1.sampleTime = SAMPLE_TIME;
    struDrtData.filePara1.preTrigger = 0x14;        //TODO
    memcpy(struDrtData.filePara1.unknownFix182, gUnknownFix182, sizeof(gUnknownFix182));
    /*将采集说明的长度固定为0x2c, 内容固定*/
    struDrtData.filePara1.commentsLen = 0x2c;
    struDrtData.filePara1.qbComments.clear();
    struDrtData.filePara1.qbComments.append((const char *)gIntroduce, sizeof(gIntroduce));
    struDrtData.filePara1.qbUnknowFix4or12.clear();
    double amplitudeData = 0;
    double phaseData = 0;
    double sampleTime = 0;
    if(nType == E_PD2_ACQUISITION_TYPE_APTWTi){     //4Bytes
        struDrtData.filePara1.qbUnknowFix4or12.append((const char *)gUnknow23cFor4, sizeof(gUnknow23cFor4));
        struDrtData.fileData.dataLenght = 5*8*struDrtData.filePara1.pulseNum;
        /////////////////////////////////////////////////////
        for(int i =0; i < struDrtData.filePara1.pulseNum; i++){
            amplitudeData = AmplitudeStandard(struSrcData.qvPdbData.at(i).baseline,\
                                              (float)struSrcData.qvPdbData.at(i).y[struSrcData.qvPdbData.at(i).crestP],\
                                              struSrcData.devInfo.amp);
            struDrtData.fileData.vAmplitudeData.append(amplitudeData);

            phaseData = PHASE_CONCERSION(struSrcData.qvPdbData.at(i).realP);
            struDrtData.fileData.vPhaseData.append(phaseData);

            struDrtData.fileData.vEquTimeData.append(struSrcData.qvPdbData.at(i).equivalT);

            struDrtData.fileData.vEquFrqData.append(struSrcData.qvPdbData.at(i).equivalW);


            sampleTime = GET_SAMPLE_TIME(i,struDrtData.filePara1.pulseNum,\
                                         struDrtData.filePara1.sampleTime);
            struDrtData.fileData.vSampleTime.append(sampleTime);
        }
        /////////////////////////////////////////////////////
    }
    else if(nType == E_PD2_ACQUISITION_TYPE_WFMs){
        struDrtData.filePara1.qbUnknowFix4or12.append((const char *)gUnknow23cFor12, sizeof(gUnknow23cFor12));
        struDrtData.fileData.dataLenght = (2*sizeof(double) + PULSE_NUM*(sizeof(float)))*\
                struDrtData.filePara1.pulseNum;
        for(int i =0; i < struDrtData.filePara1.pulseNum; i++){
            phaseData = PHASE_CONCERSION(struSrcData.qvPdbData.at(i).realP);
            struDrtData.fileData.vPhaseData.append(phaseData);
            sampleTime = GET_SAMPLE_TIME(i,struDrtData.filePara1.pulseNum,\
                                         struDrtData.filePara1.sampleTime);
            struDrtData.fileData.vSampleTime.append(sampleTime);
            float pulseData = 0;
            for(int j=0; j < PULSE_NUM; j++){
                pulseData = (float)AmplitudeStandard(struSrcData.qvPdbData.at(i).baseline,\
                                              (float)struSrcData.qvPdbData.at(i).y[j],\
                                              struSrcData.devInfo.amp);
                struDrtData.fileData.vPulseData.append(pulseData);
            }
        }
    }
    /////////////////////////////////////////////////////////////////////////////
    if(nType == E_PD2_ACQUISITION_TYPE_APTWTi){
        memcpy(struDrtData.filePara2.unknowFixEnd8, gUnknowFixEnd8, sizeof(gUnknowFixEnd8));
    }
    memcpy(struDrtData.filePara2.unknowFixEnd48, gUnknowFixEnd48, sizeof(gUnknowFixEnd48));

    struDrtData.filePara2.synchRMS = 0.01;
    struDrtData.filePara2.synchFrequency = 6000.0;

    memcpy(struDrtData.filePara2.fileTail, gFileTail240, sizeof(gFileTail240));
    //TODO
    return 0;
}

/**
    @breif  将pd2文件结构体转换为文件
*/
int C_Conversion::Pd2DataToFile(struPd2 &struSrcData, const QString qsDstFilePath, ePd2AcquisitionType &nType)
{
    QByteArray qbBuf = "";
    QFile pd2File(qsDstFilePath);
    if(QFile::exists(qsDstFilePath)){
//        qDebug()<<"the file is exist.\r\n";
        pd2File.remove();
        pd2File.close();
    }

    if(pd2File.open(QIODevice::WriteOnly )){
        //    out << qvBuffer.at(i);
    }
    else{
        pd2File.close();
        return false;
    }

    qbBuf.append((const char*)struSrcData.filePara1.head, sizeof(struSrcData.filePara1.head));
//    qDebug()<<"struDrtData.filePara1.head:"<<qbBuf.toHex().toUpper().data();
    qbBuf.append((const char*)&struSrcData.filePara1.trigger, sizeof(float));
    qbBuf.append((const char*)&struSrcData.filePara1.sampleRate, sizeof(float));
    qbBuf.append((const char*)struSrcData.filePara1.unknown158, sizeof(struSrcData.filePara1.unknown158));
    qbBuf.append((const char*)&struSrcData.filePara1.pulseNum, sizeof(int));
    qbBuf.append((const char*)&struSrcData.filePara1.acquisitionTime, sizeof(float));
    qbBuf.append(struSrcData.filePara1.circuitType);
    qbBuf.append(struSrcData.filePara1.channel);
    qbBuf.append(struSrcData.filePara1.acquisitionType);
    qbBuf.append(struSrcData.filePara1.bandwidth);
    qbBuf.append((const char*)struSrcData.filePara1.unknown16c, sizeof(struSrcData.filePara1.unknown16c));
    qbBuf.append((const char*)&struSrcData.filePara1.dateTime, sizeof(int));
    qbBuf.append((const char*)struSrcData.filePara1.unknownFix178, sizeof(struSrcData.filePara1.unknownFix178));
    qbBuf.append(struSrcData.filePara1.sampleTime);
    qbBuf.append(struSrcData.filePara1.preTrigger);
    qbBuf.append((const char*)struSrcData.filePara1.unknownFix182, sizeof(struSrcData.filePara1.unknownFix182));
    qbBuf.append((const char*)&struSrcData.filePara1.commentsLen, sizeof(int));

    qbBuf.append(struSrcData.filePara1.qbComments);
    qbBuf.append(struSrcData.filePara1.qbUnknowFix4or12);
//    qbBuf.append((char*)&, sizeof(float));
    qbBuf.append((const char*)&struSrcData.fileData.dataLenght, sizeof(int));
//    qDebug()<<"struDrtData.filePara1.head:"<<qbBuf.toHex().toUpper().data();
    pd2File.write(qbBuf);
    qbBuf = "";
    int i = 0;
    if(nType == E_PD2_ACQUISITION_TYPE_APTWTi){
        for(i=0; i<struSrcData.fileData.vAmplitudeData.size(); i++){
            qbBuf.append((const char*)&(struSrcData.fileData.vAmplitudeData.at(i)), sizeof(double));
        }
        for(i=0; i<struSrcData.fileData.vPhaseData.size(); i++){
            qbBuf.append((const char*)&(struSrcData.fileData.vPhaseData.at(i)), sizeof(double));
        }
        for(i=0; i<struSrcData.fileData.vEquTimeData.size(); i++){
            qbBuf.append((const char*)&(struSrcData.fileData.vEquTimeData.at(i)), sizeof(double));
        }
        for(i=0; i<struSrcData.fileData.vEquFrqData.size(); i++){
            qbBuf.append((const char*)&(struSrcData.fileData.vEquFrqData.at(i)), sizeof(double));
        }
        for(i=0; i<struSrcData.fileData.vSampleTime.size(); i++){
            qbBuf.append((const char*)&(struSrcData.fileData.vSampleTime.at(i)), sizeof(double));
        }
        qbBuf.append((const char*)struSrcData.filePara2.unknowFixEnd8, sizeof(struSrcData.filePara2.unknowFixEnd8));
    }
    else if(nType == E_PD2_ACQUISITION_TYPE_WFMs){
        for(i=0; i<struSrcData.fileData.vPhaseData.size(); i++){
            qbBuf.append((const char*)&(struSrcData.fileData.vPhaseData.at(i)), sizeof(double));
        }
        pd2File.write(qbBuf);
        qbBuf = "";
        for(i=0; i<struSrcData.fileData.vSampleTime.size(); i++){
            qbBuf.append((const char*)&(struSrcData.fileData.vSampleTime.at(i)), sizeof(double));
        }
        pd2File.write(qbBuf);
        qbBuf = "";
        for(i=0; i<struSrcData.fileData.vPulseData.size(); i++){
            qbBuf.append((const char*)&(struSrcData.fileData.vPulseData.at(i)), sizeof(float));
            if((i % 10000) == 0){
                pd2File.write(qbBuf);
                qbBuf = "";
            }
        }
    }
    qbBuf.append((const char*)struSrcData.filePara2.unknowFixEnd48, sizeof(struSrcData.filePara2.unknowFixEnd48));
    qbBuf.append((const char*)&struSrcData.filePara2.synchRMS, sizeof(float));
    qbBuf.append((const char*)&struSrcData.filePara2.synchFrequency, sizeof(float));
    qbBuf.append((char *)&struSrcData.filePara2.fileTail, sizeof(struSrcData.filePara2.fileTail));
    pd2File.write(qbBuf);
    qbBuf = "";

//    QString qsBuf;
//    qsBuf = QString::fromLatin1(qbBuf.toHex().toUpper().data(), qbBuf.size());
//    if(SaveFile(qsDstFilePath, qbBuf) == false){
//        return -1;
//    }
    pd2File.flush();
    pd2File.close();
//    qDebug()<<"转换完成\n";
    return 0;
}

bool C_Conversion::SaveFile( QString filePathName, QByteArray &qbBuffer)
{
    QFile pd2File(filePathName);
    if(pd2File.open(QIODevice::WriteOnly )){
        //    out << qvBuffer.at(i);
        pd2File.write(qbBuffer);

        pd2File.flush();
        pd2File.close();
//        qDebug()<<"转换完成\n";
        return true;
    }
    else{
        pd2File.close();
        return false;
    }
    return false;
}



/**
    @breif  将无量纲的数据转换为mv数据
*/
double C_Conversion::AmplitudeStandard(float fBaseline, float fSrcValue, int amp)
{
    float fAmpVal = 0;
    switch(amp){
    case 0: fAmpVal = 0.08; break;
    case 1: fAmpVal = 0.16; break;
    case 2: fAmpVal = 0.32; break;
    case 3: fAmpVal = 0.63; break;
    case 4: fAmpVal = 1.26; break;
    case 5: fAmpVal = 2.52; break;
    case 6: fAmpVal = 5.01; break;
    case 7: fAmpVal = 10.0; break;
    default:
        break;
    }
    return (double)((fSrcValue - fBaseline)/(AMPLITUDE_STANDARD_CONSTANT * fAmpVal))/AMPLITUDE_PARAM;
}
