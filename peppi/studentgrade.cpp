#include "studentgrade.h"
#include "ui_studentgrade.h"

StudentGrade::StudentGrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentGrade)
{
    ui->setupUi(this);
}

StudentGrade::~StudentGrade()
{
    delete ui;
}

void StudentGrade::setGrades(const QString &newGrades)
{
    grades = newGrades;
}

void StudentGrade::showGrades(QString value)
{
    ui->textGrades->setText(value);
}
