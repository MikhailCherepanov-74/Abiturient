#pragma once
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
#include <QDebug>
#include <QCheckBox>
#include "MyRegExp.h"
#include "InfAboutSpecialisation.h"
class AddingSpecialisation : public QDialog {
    Q_OBJECT
private:QGridLayout* grid;
    QLabel* label_name;
    QLabel* label_logo;
    QLabel* label_adress;
    QLabel* label_specialization;
    QLabel* label_bal;
    QLabel* label_contest;
    QLabel* label_cost;
    QLabel* info_about_already_added;
    QLabel *label_form_of_study; // Новая метка для формы обучения
    QLineEdit* LineEditd_name;
    QLineEdit* LineEdit_logo;
    QLineEdit* LineEditd_adress;
    QLineEdit* LineEditd_specialization;
    QLineEdit* LineEdit_bal;
    QLineEdit* LineEditd_contest;
    QLineEdit* LineEditd_cost;
    QPushButton* buttonOk;
    InfAboutSpecialisation inpPerson;
    InfAboutSpecialisation* outPerson;
    QPushButton* buttonCancel;
    QStringList NFill;
    QStringList notValidated;
    QCheckBox *checkBox_daytime; // CheckBox для дневной формы обучения
    QCheckBox *checkBox_evening; // CheckBox для вечерней формы обучения
    QCheckBox *checkBox_distance; // CheckBox для заочной формы обучения
    bool flag_delete=0;
    bool flag_able_form=1;
    bool boolFillAll();
public:
    AddingSpecialisation(QString title, QWidget* parent = Q_NULLPTR);
    ~AddingSpecialisation();
    InfAboutSpecialisation* getPersonInf();
public slots:
    void accept() override;
};
