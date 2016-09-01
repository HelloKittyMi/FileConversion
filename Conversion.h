#ifndef C_CONVERSION_H
#define C_CONVERSION_H
#include <QByteArray>
#include <QString>
#include <QVector>
#include <qdebug.h>
#include <QFile>
#define PDB_BASE_DEVINFO_OFFSET     (int)1756
#define PDB_BASE_DATA_OFFSET        (int)3604


#define PD2_HEAD_OFFSET             (int)0
#define PD2_HEAD_LENRHT             (int)336
#define PD2_PARA_BLOCK1_OFFSET      (int)(PD2_HEAD_OFFSET + PD2_HEAD_LENRHT)
//#define PD2_PARA_BLOCK1_LENGHT      (int)()

#define SAMPLE_RATE                 (float)100000000.0
#define SAMPLE_TIME                 (char)0x07   //2us（200个点）

#define POWER_FREQ                  (20.0/1000.0)

#define AMPLITUDE_STANDARD_CONSTANT (float)4.9225

#define AMPLITUDE_PARAM             1000
#define TIME_PARAM                  1

#define PULSE_NUM                   (int)200

#define UNIT_SAMPLE_POINT           (double)2000000
#define PHASE_CONCERSION(_x)        ((double)_x/UNIT_SAMPLE_POINT)*((double)360.0)

#define GET_SAMPLE_TIME(_x,_y,_z)   (((double)_x)/(double)_y)*(double)_z
typedef enum ePd2CircuitType{                   //Circuit type
    E_PD2_CIRCUIT_DIRECT = 1,
    E_PD2_CIRCUIT_INDIRECT
}ePd2CircuitType;


typedef enum ePd2AcquisitionType {              //Acquisitions
    E_PD2_ACQUISITION_TYPE_APTWTi = 0,
    E_PD2_ACQUISITION_TYPE_WFMs,
    E_PD2_ACQUISITION_TYPE_OTHER
}ePd2AcquisitionType;

typedef struct struPd2FilePara1Info{            //Little_Endian
    char head[PD2_HEAD_LENRHT];                 //const
    float trigger;                              //Pulse trigger voltage, V
    float sampleRate;                           //const, 100MHz
    char unknown158[8];
    int pulseNum;
    float acquisitionTime;                      //Token time in acquisition, s
    char circuitType;
    char channel;
    char acquisitionType;
    char bandwidth;                             //const 0x00
    char unknown16c[8];                         //const
    int dateTime;                               //datetime,s
    char unknownFix178[8];                      //const
    char sampleTime;                            //采集时长，及对应触发的脉冲事件长度，
                                                //09-10us(1000点)，0a-20us(2000点)
    char preTrigger;                            //触发前的长度占比
    char unknownFix182[182];                    //const
    int commentsLen;                            //采集说明长度
    QByteArray qbComments;                      //说明内容
    QByteArray qbUnknowFix4or12;                 //ATPWTi:4  WFMs:12
}struPd2FilePara1Info;

typedef QVector<double> qvFileDoubleData;
typedef QVector<float> qvFileIntData;

typedef struct struPd2FileData{                 //Little_Endian
    unsigned int dataLenght;                    //数据区总长度
    qvFileDoubleData vAmplitudeData;            //for APTWTi
    qvFileDoubleData vPhaseData;                //for WFMs&APTWTi
    qvFileDoubleData vEquTimeData;              //for APTWTi
    qvFileDoubleData vEquFrqData;               //for APTWTi
    qvFileDoubleData vSampleTime;
    qvFileIntData vPulseData;                   //脉冲采集的相对时间                   //for WFMs&APTWTi
}struPd2FileData;

typedef struct struPd2FilePara2Info{
    char unknowFixEnd8[8];                      //for APTWTi
    char unknowFixEnd48[48];
    float synchRMS;                             //appliedVoltage,v
    float synchFrequency;                       //工频同步信号的频率
    char fileTail[256];                         //const,文件尾部
}struPd2FilePara2Info;


typedef struct struPd2{
    struPd2FilePara1Info filePara1;
    struPd2FileData fileData;
    struPd2FilePara2Info filePara2;
}struPd2;

//#pragma pack(1)
typedef struct struDevInfo{
    int sampleTotal;                            //采集周期数
    int pls_total;                              //脉冲总数
    int start_time;                             //起始时间
    int end_time;                               //结束时间
    int amp;                                    //增益
    float thPulse;                              //脉冲阈值
}struDevInfo;

typedef struct struSampleConfig
{
    int sampletotal;                            //采样轮数
    int sampleNumPer;                           //每轮周期数
    int sampleInterval;                         //采样间隔
}struSampleConfig;


#pragma pack(1)
typedef struct struPdPulse{
    int id;
    unsigned char reserve1;
    unsigned char crestP;                                //波峰所在位置
    unsigned char startP;                                //起点位置
    unsigned char endP;                                  //结束点位置
    float baseline;                                      //基线大小
    short int reserve2;
    int realP;                                           //峰/谷顶点在原始信号中的位置
    int reserve3;
    double equivalT;                            //等效时长
    double equivalW;                            //等效带宽
    double reserve4;
    short int y[PULSE_NUM];                     //脉冲波形
    short int reserve5;
}struPdPulse;
#pragma pack()

typedef QVector<struPdPulse> qvPdbPulseData;

typedef struct struPdbFileData{
    unsigned int devOffset;                     //const,1756
    struDevInfo devInfo;
    unsigned int dataOffset;                    //const,7314
    qvPdbPulseData qvPdbData;                   //数据域
}struPdbFileData;


extern bool pdb_to_pd2(const char *srcFilePath, int srcLen, const char *drtFilePath, int drtLen, int type);

class C_Conversion{
public:
    C_Conversion();
    ~C_Conversion();

public:
    int ConversionData(const QByteArray qbInData, QString &qsDstFilePath, ePd2AcquisitionType eType);


private:
    int PdbToData(const QByteArray qbPdbData, struPdbFileData & struFileData, ePd2AcquisitionType &nType);
    int PdbToPd2Data(struPdbFileData& struSrcData, struPd2& struDrtData, ePd2AcquisitionType &nType);
    int Pd2DataToFile(struPd2& struSrcData, const QString qsDstFilePath, ePd2AcquisitionType &nType);
    double AmplitudeStandard(float fBaseline, float fSrcValue, int amp);
    bool SaveFile( QString filePathName, QByteArray &pBuffer);
};

#endif // C_CONVERSION_H
