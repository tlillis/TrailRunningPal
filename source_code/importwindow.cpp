#include "importwindow.h"
#include "ui_importwindow.h"

ImportWindow::ImportWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImportWindow)
{
    ui->setupUi(this);
}

void ImportWindow::use_observer(FileUpdater *updater)
{
    _updater = updater;
}

void ImportWindow::use_user(std::string username)
{
    _user = username;
}

void ImportWindow::on_pushButton_Import_clicked()
{
    QString route_s = ui->lineEdit_Route->text();
    QString time_s = ui->lineEdit_Time->text();
    QString avr_s = ui->lineEdit_AVR->text();
    QString cals_s = ui->lineEdit_Cals->text();
    QString mhr_s = ui->lineEdit_MHR->text();
    QString miles_s = ui->lineEdit_Miles->text();
    QString egain_s = ui->lineEdit_EGain->text();
    QString fastest_s = ui->lineEdit_Fastest->text();
    QString tags_s = ui->lineEdit_Tags->text();

    if(route_s != "" && time_s != "")
    {
        if(_updater != NULL)
        {
            std::string run_data = "11/24/18,";
            run_data += time_s.toStdString() + ",";
            run_data += miles_s.toStdString() + ",";
            run_data += egain_s.toStdString() + ",";
            run_data += mhr_s.toStdString() + ",";
            run_data += avr_s.toStdString() + ",";
            run_data += cals_s.toStdString() + ",";
            run_data += fastest_s.toStdString() + ",";
            run_data += tags_s.toStdString() + "\n";

            std::string::size_type sz;

            LoadAthlete load_athlete;
            AthleteDataContainer old;
            LoadFile file_loader(&load_athlete);
            file_loader.load(_user,&old);

            int miles = 0;
            miles += std::stoi(miles_s.toStdString(), &sz);
            miles += std::stoi(old.get_miles(), &sz);

            int ytd_miles = 0;
            ytd_miles += std::stoi(miles_s.toStdString(), &sz);
            ytd_miles += std::stoi(old.get_ytd_miles(), &sz);

            int last_miles = 0;
            last_miles += std::stoi(miles_s.toStdString(), &sz);
            last_miles += std::stoi(old.get_last_miles(), &sz);

            int pace = 0;
            //pace += std::stoi(miles.toStdString(), &sz);
            pace += std::stoi(old.get_pace(), &sz);

            int ytd_pace = 0;
            //ytd_pace += std::stoi(miles.toStdString(), &sz);
            ytd_pace += std::stoi(old.get_ytd_pace(), &sz);

            int ascent = 0;
            ascent += std::stoi(egain_s.toStdString(), &sz);
            ascent += std::stoi(old.get_ascent(), &sz);

            int ytd_ascent = 0;
            ytd_ascent += std::stoi(egain_s.toStdString(), &sz);
            ytd_ascent += std::stoi(old.get_ytd_ascent(), &sz);

            std::string mile1 = old.get_mile1();
            if(std::stoi(fastest_s.toStdString(), &sz) < std::stoi(mile1, &sz))
            {
                mile1 = fastest_s.toStdString();
            }

            std::string stat_data = _user + ",";
            stat_data += std::to_string(miles) + ",";
            stat_data += std::to_string(ytd_miles) + ",";
            stat_data += std::to_string(last_miles) + ",";
            stat_data += std::to_string(pace) + ",";
            stat_data += std::to_string(ytd_pace) + ",";
            stat_data += std::to_string(ascent) + ",";
            stat_data += std::to_string(ytd_ascent) + ",";
            stat_data += mile1 + ",";
            stat_data += old.get_mile2() + ",";
            stat_data += old.get_k5() + ",";
            stat_data += old.get_k10() + ",";
            stat_data += old.get_half_mar() + ",";
            stat_data += old.get_mar() + ",";
            stat_data += old.get_mile50() + "\n";

            _updater->write(_user,"runs.csv",run_data);
            _updater->write(_user,"stats.txt",stat_data);
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
    delete ui;
}
