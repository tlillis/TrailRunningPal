#include "importwindow.h"
#include "ui_importwindow.h"

ImportWindow::ImportWindow(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::ImportWindow)
{
    _ui->setupUi(this);
}

void ImportWindow::setObserver(FileUpdater *updater)
{
    _updater = updater;
}

void ImportWindow::setUser(std::string username)
{
    _user = username;
}

void ImportWindow::on_pushButton_Import_clicked()
{
    QString routeS = _ui->lineEdit_Route->text();
    QString timeS = _ui->lineEdit_Time->text();
    QString avrS = _ui->lineEdit_AVR->text();
    QString calsS = _ui->lineEdit_Cals->text();
    QString mhrS = _ui->lineEdit_MHR->text();
    QString milesS = _ui->lineEdit_Miles->text();
    QString egainS = _ui->lineEdit_EGain->text();
    QString fastestS = _ui->lineEdit_Fastest->text();
    QString tagsS = _ui->lineEdit_Tags->text();

    if(routeS != "" && timeS != "")
    {
        if(_updater != NULL)
        {
            std::string runData = "11/24/18,";
            runData += timeS.toStdString() + ",";
            runData += milesS.toStdString() + ",";
            runData += egainS.toStdString() + ",";
            runData += mhrS.toStdString() + ",";
            runData += avrS.toStdString() + ",";
            runData += calsS.toStdString() + ",";
            runData += fastestS.toStdString() + ",";
            runData += tagsS.toStdString() + "\n";

            std::string::size_type sz;

            LoadAthlete load_athlete;
            AthleteDataContainer old;
            LoadFile file_loader(&load_athlete);
            file_loader.load(_user,&old);

            int miles = 0;
            miles += std::stoi(milesS.toStdString(), &sz);
            miles += std::stoi(old.getMiles(), &sz);

            int ytdMiles = 0;
            ytdMiles += std::stoi(milesS.toStdString(), &sz);
            ytdMiles += std::stoi(old.getYtdMiles(), &sz);

            int lastMiles = 0;
            lastMiles += std::stoi(milesS.toStdString(), &sz);
            lastMiles += std::stoi(old.getLastMiles(), &sz);

            int pace = 0;
            //pace += std::stoi(miles.toStdString(), &sz);
            pace += std::stoi(old.getPace(), &sz);

            int ytdPace = 0;
            //ytd_pace += std::stoi(miles.toStdString(), &sz);
            ytdPace += std::stoi(old.getYtdPace(), &sz);

            int ascent = 0;
            ascent += std::stoi(egainS.toStdString(), &sz);
            ascent += std::stoi(old.getAscent(), &sz);

            int ytdAscent = 0;
            ytdAscent += std::stoi(egainS.toStdString(), &sz);
            ytdAscent += std::stoi(old.getYtdAscent(), &sz);

            std::string mile1 = old.getMile1();
            if(std::stoi(fastestS.toStdString(), &sz) < std::stoi(mile1, &sz))
            {
                mile1 = fastestS.toStdString();
            }

            std::string statData = _user + ",";
            statData += std::to_string(miles) + ",";
            statData += std::to_string(ytdMiles) + ",";
            statData += std::to_string(lastMiles) + ",";
            statData += std::to_string(pace) + ",";
            statData += std::to_string(ytdPace) + ",";
            statData += std::to_string(ascent) + ",";
            statData += std::to_string(ytdAscent) + ",";
            statData += mile1 + ",";
            statData += old.getMile2() + ",";
            statData += old.getK5() + ",";
            statData += old.getK10() + ",";
            statData += old.getHalfMar() + ",";
            statData += old.getMar() + ",";
            statData += old.getMile50() + "\n";

            _updater->write(_user,"runs.csv",runData);
            _updater->write(_user,"stats.txt",statData);
            _updater->notify(_user);
            QMessageBox::information(this, "Imported", "Imported Run Saved");
            this->close();
        }
    }
    else
    {
        QMessageBox::information(this, "Import Failed", "Must input at least route and time");
    }
}

ImportWindow::~ImportWindow()
{
    delete _ui;
}
