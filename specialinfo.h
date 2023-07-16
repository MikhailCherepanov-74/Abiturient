#ifndef SPECIALINFO_H
#define SPECIALINFO_H
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QStringList>
#include <QDialog>
#include <QLineEdit>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDateEdit>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>
#include "MyRegExp.h"
#include "InfAboutSpecialisation.h"

class SpecialInfo
{
public:
    SpecialInfo();
private:
    QString university_name;
    QString university_logo;
    QString university_adress;
    QString specialization;
    QString d_ball;
    QString v_ball;
    QString z_ball;
    QString d_contest;
    QString v_contest;
    QString z_contest;
    QString d_cost;
    QString v_cost;
    QString z_cost;

};

#endif // SPECIALINFO_H
