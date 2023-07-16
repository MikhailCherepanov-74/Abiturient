#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "specialinfo.h"
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
class University
{
public:
    University();
private:
    QVector<SpecialInfo> vec_spec;
};

#endif // UNIVERSITY_H
