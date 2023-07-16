#pragma once
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QTableWidget>
#include <QHeaderView>
#include <QDate>
#include <QLineEdit>
#include <QList>
#include <QTextStream>
#include <algorithm>
#include <QJsonDocument>
#include <QJsonObject>
#include "InfAboutSpecialisation.h"
#include "AddingSpecialization.h"
#include "NewInformationAS.h"
#include "MyRegExp.h"
class MyProject : public QWidget {
    Q_OBJECT
private:QGridLayout* grid;
    QTableWidget* table;
    QPushButton* buttonAdd;
    QPushButton* buttonEdit;
    QPushButton* buttonDel;
    QPushButton* buttonLoad;
    QPushButton* buttonSort;
    QPushButton* buttonSave;
    QPushButton* buttonExit;
    QLineEdit* LineEditeSearch;
    QPushButton* buttonSearch;
    QPushButton* buttonNext;
    QPushButton* buttonPrev;
    QList<InfAboutSpecialisation> IAP;
    QList<QTableWidgetItem*> find;
    QList<QTableWidgetItem*>::iterator iteratorFind;
    void LineFilling(int index);
public: MyProject(QWidget* parent = Q_NULLPTR);
    void AddingToTable(InfAboutSpecialisation person);
public slots:
    void AddClick();
    void EditClick();
    void LoadClick();
    void SaveClick();
    void LoadFromFile();
    void DelClick();
    void UpdAfterSort(int, Qt::SortOrder order);
    void LEUpdate(const QString& text);
    void SearchClick();
    void NextClick();
    void PrevClick();
};
class SortFunctor {
private:int col;
    Qt::SortOrder order;
public: SortFunctor(int c, Qt::SortOrder o);
    bool operator()(InfAboutSpecialisation& p1, InfAboutSpecialisation& p2);
};


