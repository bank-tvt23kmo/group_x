#ifndef STUDENTGRADE_H
#define STUDENTGRADE_H

#include <QDialog>

namespace Ui {
class StudentGrade;
}

class StudentGrade : public QDialog
{
    Q_OBJECT

public:
    explicit StudentGrade(QWidget *parent = nullptr);
    ~StudentGrade();

    void setGrades(const QString &newGrades);
    void showGrades(QString value);

private:
    Ui::StudentGrade *ui;
    QString grades;
};

#endif // STUDENTGRADE_H
