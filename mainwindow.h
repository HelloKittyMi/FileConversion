#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QFileInfo>
#include <QFileDialog>
#include <FileHandle.h>
#include <QLabel>


struct _sample_config
{
    int sampletotal;//采样轮数
    int sampleNumPer;//每轮周期数
    int sampleInterval;//采样间隔
};

struct _sample_para
{
    time_t s_t; //采样起始时间
    time_t e_t; //采样结束时间
    unsigned char amp; //增益
    int the; //脉冲阀
     char filter[512];//滤波器参数
    int th_q;//pvt 阀
    int th_n;//pvt 重复次数

};

struct _pcInfo
{
    char pcName[100];//计算机名称
    char pcType[100]; //计算机类型
    char pcConfig[100];//计算机配置
};
struct _dInfo
{
    char dName[100];//d名称
    char dType[100]; //d的类型
    int dRatedV; //d额定电压
};
struct _sensorInfo
{
    //char sensorName[100];//传感器名称
    //char sensorType[100];//传感器类型
   // int sensorZ; //传感器阻抗
   // int sensorFreq; //传感器平率
    int typeA;
    int typeB;
    int typeC;
};
struct _cableInfo
{
    char cableName[200]; //电缆名称
    char type[100]; //电缆类型
    int ratedV; //电缆额定电压
    int ratedPm; //额定功率
    int len; //长度
    int age; //寿命
    char metrial[100];//材料
};

struct _dev_baseInfo
{
    char stationName[400];//客户名称
    char workerName[200];//检测人
    char leader[200]; //监督人
    time_t check_t; //测试时间
    int temp;  //温度
    int humidity; //湿度
};

struct _compound_report
{
    int id; //序号
    time_t s_t; //起始时间
    time_t e_t; //结束时间
    int avg_q; //平均放电量
    int repeat_inteval;//平均放电次数
    int speed;//综合价量趋势
    int ispvt;//预警
    float u[3];//类型识别
};
struct tw_para
{
        double t;
        double w;
        double t_percent;
        double w_percent;


};
struct tw_t
{
    double T;
    double W;
};


struct DevInfo
{

   struct _dev_baseInfo devBaseInfo;    //812
   struct _cableInfo cableInfo;     //416
   struct _sensorInfo sensorInfo;   //12
   struct _dInfo dInfo;             //204
   struct _pcInfo pcinfo;           //300
   struct _sample_config config;    //12
};



typedef struct Pls_HeadInfo
{
     struct DevInfo cable_i;    //1756
     int sample_total;          //4
     int pls_total;             //4
     time_t s_t;            //4
     time_t e_t;            //4
    char amp;               //1
    float thPulse; //脉冲阈值 //4
    int thQ;//放电阈值         //4
    int thN;//重复阈值          //4
    int thPvt; //pvt阈值       //4
    char cls_id_total;          //1
    char filter[512];           //512
    struct tw_t  center_point[16];  //256
    char reserve[256];         //256
}Pls_HeadInfo;

//#define

namespace Ui {
class MainWindow;
}

class C_MessageBox : public QMainWindow
{
public:
    C_MessageBox();
    ~C_MessageBox();
private:
    QLabel *label;

public:
    void boxQuestion(QString qsMessage);
    void boxInformation(QString qsMessage);
    void boxWarning(QString qsMessage);
    void boxCritical(QString qsMessage);
    void boxAbout(QString qsMessage);
    void boxAboutQt(QString qsMessage);
    void boxCustom(QString qsMessage);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void ShowLog(QString log);
    void SetCombox(QString index);

    C_MessageBox messageBox;
private slots:
    void on_OpenFilePathButton_clicked();

    void on_StartConversionButton_clicked();

    void on_ClearDataButton_clicked();

    void on_OpenDirButton_clicked();

signals:
    void event_OpenFile(QString filePath, int mainWindow);
    void event_StartConversion(QStringList &filePathList, int mainWindow, int type, bool &bConversionFlag);
    void event_onClearData();

private:
    QString qsLastFileName;        //最后打开的文件路径
    QStringList qslLastFileNameList;
    C_FileHandle *mFileHandle;

private:
    int GetDirFile(QString dirPath, QStringList& qsFileList);

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
