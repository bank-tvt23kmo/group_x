#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QDialog>

namespace Ui {
class StudentInfo;
}

class StudentInfo : public QDialog
{
    Q_OBJECT

public:
    explicit StudentInfo(QWidget *parent = nullptr);
    ~StudentInfo();

    QString getFname() const;

    void setLname(const QString &newLname);

    void setFname(const QString &newFname);

    void showStudentData();

private:
    Ui::StudentInfo *ui;
    QString fname;
    QString lname;

};

#endif // STUDENTINFO_H
