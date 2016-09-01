#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include <QCoreApplication>
#include <QObject>
#include <QDir>
#include <QFile>
#include <QByteArray>



class C_FileHandle : public QObject{
    Q_OBJECT
public:
    explicit C_FileHandle(QObject *parent = 0);
    ~C_FileHandle();
     bool PdbToPd2(const char *in_fname_pdb, const char *in_fname_pd2, int in_type);
public slots:
    void OnOpenFile(QString qsFilePath, int mainWindow);
    void OnStartConversion(QStringList &qsFilePath, int mainWindow, int nType, bool &bFlag);

private:
    int ConversionFile(const QByteArray &qbFileData, QString &drtFilePath, int nType);
    int StartConvSingleFile(QString qsFilePath, int mainWindow, int nType, bool &bFlag);
};

#endif // FILEHANDLE_H
