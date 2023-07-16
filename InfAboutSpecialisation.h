#pragma once
#include <QTextStream>
#include <QDate>
#include <QString>
#include <QStringList>
#include "MyRegExp.h"
class NewInformationAS;
class MyProject;
class InfAboutSpecialisation {
private:
    QString str_name;
    QString str_logo;
    QString str_adress;
    QString str_spec;
    QString str_ball;
    QString str_contest;
    QString str_cost;
    QVector<int> vec_forms_study{1,0,0};// дневная, вечерняя, заочная
public:
    InfAboutSpecialisation(QString str_name = "",
                   QString str_logo = "",
                   QString str_adress = "",
                   QString str_spec = "",
                   QString str_ball = "",
                   QString str_contest = "",
                   QString str_cost = "",
                   QVector<int> forms_study={1,0,0}
            );
    InfAboutSpecialisation(QStringList list);
    QString IASgetName();
    QString IASGetLogo();
    QString IAPGetAdress();
    QString IAPGetSpec();
    QString IAPgetBall();
    QString IASgetContest();
    QString IASgetCost();
    QStringList IAPgetAll();
    QString IAPgetStrForm();
    bool operator==(const InfAboutSpecialisation& p) const;
    friend QTextStream& operator<<(QTextStream& s, const
    InfAboutSpecialisation& p);
    friend class NewInformationAS;
    friend class MyProject;
};
QTextStream& operator<<(QTextStream& stream, const InfAboutSpecialisation& p);
