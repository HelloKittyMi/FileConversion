#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qDebug.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    qsLastFileName = "";
    mFileHandle = new C_FileHandle();
    qsLastFileName = "";
    connect(this,SIGNAL(event_StartConversion(QStringList&, int, int, bool&)), mFileHandle, SLOT(OnStartConversion(QStringList&, int, int, bool&)));

    qDebug()<<"sizeof(header):"<<sizeof(Pls_HeadInfo);
}

MainWindow::~MainWindow()
{
    delete(mFileHandle);
    delete ui;
}

void MainWindow::ShowLog(QString log)
{
    QString s;
    this->ui->LogTextEdit->append(log);
}

void MainWindow::on_OpenFilePathButton_clicked()
{
    const QString dir;
    QFileInfo qfFileinfo;
    QString qsUpdatafilename;
    QStringList qslFileNames = QFileDialog::getOpenFileNames(this, tr("打开需要转换的pdb文件"), dir, "*.pdb");
    qslLastFileNameList.clear();
    QString qsBuf = "";
    if (qslFileNames.count()) {
        for(int i=0; i < qslFileNames.size(); i++){
            qfFileinfo =QFileInfo(qslFileNames.at(i));
            qsUpdatafilename=qfFileinfo.filePath();
            qsBuf += qsUpdatafilename + " ";
            ui->FilePathEdit->setText(qsBuf);
            if(qsUpdatafilename.indexOf((QString)(".pdb")) <= 0){
                //TODO 弹窗
                this->messageBox.boxCritical(qsUpdatafilename +"\n"+"文件格式错误,请重新选择！");
                return ;
            }
        }
        qslLastFileNameList = qslFileNames;
        this->ShowLog("打开文件"+qsUpdatafilename);
    }
}

int MainWindow::GetDirFile(QString dirPath, QStringList& qsFileList)
{
    QDir dstDir = QDir(dirPath);
    int tmp = 0;
    QStringList qslFileNames = dstDir.entryList();
    qslFileNames.removeOne(".");
    qslFileNames.removeOne("..");
    if (qslFileNames.count())
    {
        for(int i=0; i < qslFileNames.size(); i++)
        {
            QFileInfo qfFileinfo =QFileInfo(dirPath + "/" + qslFileNames.at(i));
            if(qfFileinfo.isFile())
            {
                if((tmp = qslFileNames.at(i).lastIndexOf((QString)(".pdb"))) > 0)
                {
                    if((tmp + 4) == qslFileNames.at(i).size())
                        qsFileList.append(dirPath + "/" + qslFileNames.at(i));
                }
            }
            if(qfFileinfo.isDir())
            {
                GetDirFile((dirPath + "/" + qslFileNames.at(i)), qsFileList);
            }
        }
    }
    return 0;
}

void MainWindow::on_OpenDirButton_clicked()
{
    const QString dir;
    QString qsDir = QFileDialog::getExistingDirectory(this, tr("打开需要转换文件夹"), dir,\
                                                               QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    this->ShowLog("打开文件夹"+qsDir);
    QStringList qslFileNames;
    qslFileNames.clear();
    qslLastFileNameList.clear();
    GetDirFile(qsDir, qslLastFileNameList);
    qDebug()<<"qsDir: "<<qsDir;
    QString qsMsgBuf = "";
    if (qslLastFileNameList.count()) {
        for(int i=0; i < qslLastFileNameList.size(); i++){
            qsMsgBuf += qslLastFileNameList.at(i) + ";";
            ui->FilePathEdit->setText(qsMsgBuf);
//            if(qsUpdatafilename.indexOf((QString)(".pdb")) < 0){
//                this->messageBox.boxCritical(qsUpdatafilename +"\n"+"文件格式错误,请重新选择！");
//                return ;
//            }
        }
//        emit event_OpenFile(qsUpdatafilename, (int)this);
    }
}

void MainWindow::SetCombox(QString qsText)
{
    if(qsText == "WFMs"){
        this->ui->comboBox_2->setCurrentIndex(1);
    }
    else if(qsText == "APTWTi"){
        this->ui->comboBox_2->setCurrentIndex(0);
    }
}

/**
    @func   on_StartConversionButton_clicked
    @breif  开始转换按键槽函数
*/
void MainWindow::on_StartConversionButton_clicked()
{
    int nType=this->ui->comboBox_2->currentIndex();
    bool flag = true;

    if(flag){
        flag = false;
        emit event_StartConversion(qslLastFileNameList, (int)this, nType, flag);
    }
}

void MainWindow::on_ClearDataButton_clicked()
{
    this->ui->LogTextEdit->clear();
}

C_MessageBox::C_MessageBox()
{
    label = new QLabel();
}

C_MessageBox::~C_MessageBox()
{
    delete label;
}

void C_MessageBox::boxQuestion(QString qsMessage)
{
    switch(QMessageBox::question(this,"Question",tr("It's end of document,search from begin?"),
        QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        label->setText(" Question button / Ok ");
        break;
    case QMessageBox::Cancel:
        label->setText(" Question button / Cancel ");
        break;
    default:
        break;
    }
    return;
}

void C_MessageBox::boxInformation(QString qsMessage)
{
    QMessageBox::information(this,"Information",tr(qsMessage.toUtf8().data()));
    return;
}

void C_MessageBox::boxWarning(QString qsMessage)
{
    switch(QMessageBox::warning(this,"Warning",tr("Save changes to document?"),
        QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save))
    {
    case QMessageBox::Save:
        label->setText(" Warning button / Save ");
        break;
    case QMessageBox::Discard:
        label->setText(" Warning button / Discard ");
        break;
    case QMessageBox::Cancel:
        label->setText(" Warning button / Cancel ");
        break;
    default:
        break;
    }
    return;

}

void C_MessageBox::boxCritical(QString qsMessage)
{
    QMessageBox::critical(this,"Critical",tr(qsMessage.toUtf8().data()));
    label->setText(qsMessage);
    return;
}

void C_MessageBox::boxAbout(QString qsMessage)
{
    QMessageBox::about(this,"About",tr(qsMessage.toUtf8().data()));
    label->setText(qsMessage);
    return;
}

void C_MessageBox::boxAboutQt(QString qsMessage)
{
    QMessageBox::aboutQt(this,"About Qt");
    label->setText(" About Qt MessageBox ");
    return;
}

void C_MessageBox::boxCustom(QString qsMessage)
{
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle("Custom message box");
    QPushButton *lockButton = customMsgBox.addButton(tr("Lock"),QMessageBox::ActionRole);
    QPushButton *unlockButton = customMsgBox.addButton(tr("Unlock"),QMessageBox::ActionRole);
    QPushButton *cancelButton = customMsgBox.addButton(QMessageBox::Cancel);
    customMsgBox.setIconPixmap(QPixmap(":/images/linuxredhat.png"));
    customMsgBox.setText(tr("This is a custom message box"));
    customMsgBox.exec();

    if(customMsgBox.clickedButton() == lockButton)
        label->setText(" Custom MessageBox / Lock ");
    if(customMsgBox.clickedButton() == unlockButton)
        label->setText(" Custom MessageBox / Unlock ");
    if(customMsgBox.clickedButton() == cancelButton)
        label->setText(" Custom MessageBox / Cancel ");

    return;
}




	file_offset = ftell(stream);
	file_len = get_file_len(stream, file_offset);
	while (1)
	{	
		if(file_offset != PDDATA_BLOCK_OFFSET(file_offset))
		{
			file_offset = PDDATA_BLOCK_OFFSET(file_offset);
			if(fseek(stream, file_offset, SEEK_SET) != 0)
			{
				break;
			}
		}
		
		if (fread(&stor_loop_pddata, sizeof(stor_loop_pddata), 1, stream) != 1)
		{
			ALOG(ALOG_INFO,"get the stor_pddata_head err\n");
			break;
		}
		if(stor_loop_pddata.magic != STOR_MAGIC_NUM)					//提升容错性
		{
			ALOG(ALOG_INFO, "find_pddata_file err, the magic is err \n");
			file_offset += MIN_PDDATA_BODY;
			continue;
		}
		uint32_t real_block_len = PDDATA_BLOCK_OFFSET(stor_loop_pddata.sunnum * sizeof(int));
		if(check_pddata_head(stream, real_block_len, file_offset + sizeof(stor_pddata_head_t), file_len) ==-1)
		{
			ALOG(ALOG_INFO, "find_pddata_file err, the num is err \n");
			file_offset += MIN_PDDATA_BODY;
			continue;
		}
		if((pdtime = stor_loop_pddata.sample_time) > endtime)
		{
			goto end;
		}
		uint32_t L = 0;
		uint32_t Q = 0;
		uint32_t PH = 0;
		uint32_t read_num = 0;
		uint32_t leave_num = stor_loop_pddata.sunnum;
		do
		{
			read_num = MIN(leave_num, MAX_READ_DATA_NUM);
			if(fread(&stor_pddata, read_num * sizeof(struct pddata_tag), 1, stream) != 1)
			{
				ALOG(ALOG_INFO, "read_qphdata err, get stor_pddata faild \n");
				goto end;
			}
			for(i = 0; i < read_num; i++)
			{
				L = stor_pddata[i].L;
				Q = stor_pddata[i].Q;
				PH = stor_pddata[i].PH;
				if (L >= sl && L <= el)
				{
					if (first == 1)
					{
						first = 0;
					}
					else
					{
						fprintf(stdout, ",");
					}
					fprintf(stdout, "[%d,%d]", PH, Q);
					fflush(stdout);
					if (Q > response_info->qmax)
					{
						response_info->qmax = Q;
					}
					if (Q < response_info->qmin) 
					{
						response_info->qmin = Q;
					}
					recordnum++;
					if((limitnum != (unsigned int)(-1))
						&&(response_info->records_num + recordnum >= limitnum))
					{
						response_info->status= E_IS_LIMITED_COMPLETE;
						break;
					}
				}
			}
			if(response_info->status== E_IS_LIMITED_COMPLETE)
				break;
			leave_num -= read_num; 
		}
		while(leave_num > 0)
		if (response_info->tmax < pdtime)
		{
			response_info->tmax = pdtime;
		}
		if (response_info->tmin > pdtime) 
		{
			response_info->tmin = pdtime;
		}
		if(response_info->status== E_IS_LIMITED_COMPLETE)
			break;
	}
end:
	return recordnum;

