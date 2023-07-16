#pragma once
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QLineEdit>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDateEdit>
#include <QMessageBox>
#include <QCheckBox>
#include "MyRegExp.h"
#include "InfAboutSpecialisation.h"
class NewInformationAS : public QDialog {
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
    QCheckBox *checkBox_daytime; // CheckBox для дневной формы обучения
    QCheckBox *checkBox_evening; // CheckBox для вечерней формы обучения
    QCheckBox *checkBox_distance; // CheckBox для заочной формы обучения
    QPushButton* buttonOk;
    QPushButton* buttonCancel;
    QRegExp regexName;
    QRegExp regexEmail;
    QRegExp regexPhone;
    InfAboutSpecialisation* inpSpec;
    InfAboutSpecialisation* outSpec;
    QStringList NFill;
    QStringList notValidated;
    bool flag_delete=0;
    bool flag_able_form=1;
    bool boolFillAll();
    bool IsEdited();
public: NewInformationAS(QString title, InfAboutSpecialisation* inpPerson,
                         QWidget* parent = Q_NULLPTR);
    ~NewInformationAS();
    InfAboutSpecialisation* getPersonInf();
public slots:
    void accept() override;
};
