#include "studentinfo.h"
#include "ui_studentinfo.h"

StudentInfo::StudentInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentInfo)
{
    ui->setupUi(this);
}

StudentInfo::~StudentInfo()
{
    delete ui;
}


void StudentInfo::setLname(const QString &newLname)
{
    lname = newLname;
}

void StudentInfo::setFname(const QString &newFname)
{
    fname = newFname;
}

void StudentInfo::showStudentData()
{
    ui->textFname->setText(fname);
    ui->textLname->setText(lname);
}
