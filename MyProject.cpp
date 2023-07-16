#include "MyProject.h"
MyProject::MyProject(QWidget* parent) : QWidget(parent) {
    this->setWindowTitle("Lab 8");
    this->setMinimumSize(1600, 900);
    this->setMaximumSize(1600, 900);
    this->resize(1600, 900);
    grid = new QGridLayout(this);
    table = new QTableWidget(this);
    buttonAdd = new QPushButton("Add", this);
    buttonEdit = new QPushButton("Edit", this);
    buttonDel = new QPushButton("Delete", this);
    buttonLoad = new QPushButton("Load from file", this);
    buttonSave = new QPushButton("Save to file", this);
    buttonExit = new QPushButton("Exit", this);
    grid->addWidget(table, 0, 0, 20, 10);
    grid->addWidget(buttonAdd, 0, 21, 1, 1);
    grid->addWidget(buttonEdit, 1, 21, 1, 1);
    grid->addWidget(buttonDel, 2, 21, 1, 1);
    grid->addWidget(buttonLoad, 3, 21, 1, 1);
    grid->addWidget(buttonSave, 4, 21, 1, 1);
    grid->addWidget(buttonExit, 21, 21, 1, 1);
    table->setSortingEnabled(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);//для запрета редактирования
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);//для того чтобы, выбирать только одно поле втаблице

    table->setColumnCount(ColumnCount);
    table->setHorizontalHeaderLabels(QStringList() << "Название университета"
                                     << "Логотип"
                                     << "Почтовый адресс"
                                     << "Перечень специальностей"
                                     << "Проходной балл "
                                     << "Конкурс"
                                     << "Стоимость"
                                     << "Формы обучения");
    table->setColumnWidth(0, 200);
    table->setColumnWidth(1, 150);
    table->setColumnWidth(2, 167);
    table->setColumnWidth(3, 200);
    table->setColumnWidth(4,  200);
    table->setColumnWidth(6,  200);
    table->setColumnWidth(7,  200);
    table->setColumnWidth(8,  200);
    QObject::connect(
                table->horizontalHeader(),
                SIGNAL(sortIndicatorChanged(int, Qt::SortOrder)),
                this, SLOT(UpdAfterSort(int, Qt::SortOrder)));
    QObject::connect(buttonAdd, SIGNAL(clicked()), this,
                     SLOT(AddClick()));
    QObject::connect(buttonEdit, SIGNAL(clicked()), this,
                     SLOT(EditClick()));
    QObject::connect(buttonDel, SIGNAL(clicked()), this,
                     SLOT(DelClick()));
    QObject::connect(buttonLoad, SIGNAL(clicked()), this,
                     SLOT(LoadFromFile()));
    //QObject::connect(buttonSort, SIGNAL(Click()), this,SLOT(UpdAfterSort(int, Qt::SortOrder)));
    QObject::connect(buttonSave, SIGNAL(clicked()), this,
                     SLOT(SaveClick()));
    QObject::connect(buttonExit, SIGNAL(clicked()), qApp,
                     SLOT(quit()));
    LineEditeSearch = new QLineEdit(this);
    buttonSearch = new QPushButton("Search", this);
    buttonNext = new QPushButton("Next", this);
    buttonPrev = new QPushButton("Prev", this);
    grid->addWidget(LineEditeSearch, 20, 0, 4, 1);
    grid->addWidget(buttonSearch, 21, 1, 1, 1);
    grid->addWidget(buttonNext, 21, 2, 1, 1);
    grid->addWidget(buttonPrev, 21, 4, 1, 1);
    LineEditeSearch->setMaximumWidth(200);
    buttonSearch->setEnabled(false);
    buttonNext->setEnabled(false);
    buttonPrev->setEnabled(false);
    QObject::connect(LineEditeSearch, SIGNAL(textChanged(const QString&)), this, SLOT(LEUpdate(const QString&)));
    QObject::connect(buttonSearch, SIGNAL(clicked()), this,
                     SLOT(SearchClick()));
    QObject::connect(buttonNext, SIGNAL(clicked()), this,
                     SLOT(NextClick()));
    QObject::connect(buttonPrev, SIGNAL(clicked()), this,
                     SLOT(PrevClick()));
}
void MyProject::LineFilling(int index) {
    for (int i = 0; i < ColumnCount; i++) {
        QTableWidgetItem* item = table->item(index, i);
        delete item;
        item = new
                QTableWidgetItem(IAP[index].IAPgetAll()[i]);
        table->setItem(index, i, item);
    }
}
void MyProject::AddingToTable(InfAboutSpecialisation p) {
   // table->setSortingEnabled(false);
    IAP.append(p);
    table->insertRow(IAP.size() - 1);
    LineFilling(IAP.size() - 1);
    for(int i=0;i<table->rowCount();i++)
        table->setRowHeight(i, 80);
 //   table->setSortingEnabled(true);
}
void MyProject::AddClick() {
  //  table->setSortingEnabled(false);
    AddingSpecialisation* add = new AddingSpecialisation("Add", this);
    if (add->exec() == QDialog::Accepted) {
        if (add->getPersonInf() != nullptr) {
            AddingToTable(*add->getPersonInf());
        }
    }
    delete add;
    int column =table->horizontalHeader()->sortIndicatorSection();
    auto ord = table->horizontalHeader()->sortIndicatorOrder();
    if (column != 8) {// тут поменял
        table->sortItems(column, Qt::DescendingOrder);
        table->sortItems(column, Qt::AscendingOrder);
        table->sortItems(column, ord);
    }
}
void MyProject::EditClick() {
  //  table->setSortingEnabled(false);
    QItemSelectionModel* select = table->selectionModel();
    if (select->hasSelection()) {
        int row = select->selectedRows()[0].row();
        NewInformationAS* edit = new NewInformationAS("Edit",
                                                      &IAP[row], this);
        if (edit->exec() == QDialog::Accepted) {
            if (edit->getPersonInf() != nullptr) {
                IAP[row] = *edit->getPersonInf();
                LineFilling(row);
            }
        }
        delete edit;
    }
 //   table->setSortingEnabled(true);
    int column =table->horizontalHeader()->sortIndicatorSection();
    auto ord = table->horizontalHeader()->sortIndicatorOrder();
    if (column != 8) {
        table->sortItems(column, Qt::DescendingOrder);
        table->sortItems(column, Qt::AscendingOrder);
        table->sortItems(column, ord);
    }
}
void MyProject::LoadClick() {
  //  table->setSortingEnabled(false);
    QFile file("input.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream inp(&file);
        QString line;
        while (!inp.atEnd()) {
            line = inp.readLine();
            QStringList fields = line.split(",");
            AddingToTable(fields);
        }
    }
    file.close();
  //  table->setSortingEnabled(true);
    int column =table->horizontalHeader()->sortIndicatorSection();
    auto ord = table->horizontalHeader()->sortIndicatorOrder();
    if (column != 7) {
        table->sortItems(column, Qt::DescendingOrder);
        table->sortItems(column, Qt::AscendingOrder);
        table->sortItems(column, ord);
    }
}
void MyProject::SaveClick() {
    // Запись JSON в файл
    QJsonArray jsonArray;
    QList<InfAboutSpecialisation>::Iterator it=IAP.begin();
    for(;it!=IAP.end();it++){
        QJsonObject jsonObject;
        jsonObject["University"] = it->str_name;
        jsonObject["Logo"] = it->str_logo;
        jsonObject["Adress"] = it->str_adress;
        jsonObject["Specialization"] = it->str_spec;
        jsonObject["Ball"] = it->str_ball;
        jsonObject["Contest"] = it->str_contest;
        jsonObject["Cost"] = it->str_cost;
        QString help_str="";
        QString::number(it->vec_forms_study[0]);
        help_str+=QString::number(it->vec_forms_study[0]);
        help_str+=QString::number(it->vec_forms_study[1]);
        help_str+=QString::number(it->vec_forms_study[2]);
        jsonObject["Forms"] = help_str;
        jsonArray.append(jsonObject);
    }
    QJsonDocument jsonDocument(jsonArray);
    QFile file("data.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDocument.toJson(QJsonDocument::Indented));
        file.close();
    }
}

void MyProject::LoadFromFile(){
    QFile file("data.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray jsonData = file.readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
        QJsonArray jsonArray = jsonDocument.array();
        IAP.clear();
        table->setRowCount(0);
        for (const QJsonValue &value : jsonArray) {
            QJsonObject jsonObject = value.toObject();
            QString name = jsonObject["University"].toString();
            QString logo = jsonObject["Logo"].toString();
            QString address = jsonObject["Adress"].toString();
            QString specialization = jsonObject["Specialization"].toString();
            QString ball = jsonObject["Ball"].toString();
            QString contest = jsonObject["Contest"].toString();
            QString cost = jsonObject["Cost"].toString();
            QString forms_str = jsonObject["Forms"].toString();
            QVector<int> forms(3);
            forms[0]=forms_str.at(0).unicode() - '0';
            forms[1]=forms_str.at(1).unicode() - '0';
            forms[2]=forms_str.at(2).unicode() - '0';
            InfAboutSpecialisation person(name, logo, address, specialization, ball, contest, cost, forms);
            //   table->setSortingEnabled(false);
            IAP.append(person);
            table->insertRow(IAP.size() - 1);
            LineFilling(IAP.size() - 1);
            for(int i=0;i<table->rowCount();i++)
                table->setRowHeight(i, 80);
            //   table->setSortingEnabled(true);

        }
    }
}
void MyProject::DelClick() {
    QItemSelectionModel* select = table->selectionModel();
    if (select->hasSelection()) {
        int row = select->selectedRows()[0].row();
        IAP.removeAt(row);
        table->removeRow(row);
    }
}
void MyProject::UpdAfterSort(int col, Qt::SortOrder order) {
    std::sort(IAP.begin(), IAP.end(), SortFunctor(col, order));
}
void MyProject::LEUpdate(const QString& text) {
    if (!text.isEmpty()) {
        buttonSearch->setEnabled(true);
    }
    else { buttonSearch->setEnabled(false);
        buttonNext->setEnabled(false);
        buttonPrev->setEnabled(false);
    }
}
void MyProject::SearchClick() {
    find = table->findItems(LineEditeSearch->text(), Qt::MatchExactly);
    iteratorFind = find.begin();
    if (iteratorFind != find.end()) {
        table->selectRow((*iteratorFind)->row());
        if ((iteratorFind + 1) != find.end()) {
            buttonNext->setEnabled(true);
        }
    }
}
void MyProject::NextClick() {
    iteratorFind++;
    table->selectRow((*iteratorFind)->row());
    buttonPrev->setEnabled(true);
    if ((iteratorFind + 1) != find.end()) {
        buttonNext->setEnabled(true);
    }
    else {
        buttonNext->setEnabled(false);
    }
}
void MyProject::PrevClick() {
    iteratorFind--;
    table->selectRow((*iteratorFind)->row());
    buttonNext->setEnabled(true);
    if ((iteratorFind) != find.begin()) {
        buttonPrev->setEnabled(true);
    }
    else { buttonPrev->setEnabled(false);
    }
}
SortFunctor::SortFunctor(int c, Qt::SortOrder o) : col(c), order(o)
{
}
bool SortFunctor::operator()(InfAboutSpecialisation& p1, InfAboutSpecialisation& p2) {
    if (col != 4) { // != Birth
        if (order == Qt::AscendingOrder) {
            return p1.IAPgetAll()[col] < p2.IAPgetAll()[col];
        }
        else {
            return p1.IAPgetAll()[col] >p2.IAPgetAll()[col];
        }
    }
    else {
        if (order == Qt::AscendingOrder) {
            return QDate::fromString(p1.IAPGetSpec(),::DateMask) < QDate::fromString(p2.IAPGetSpec(), ::DateMask);
        }
        else { return QDate::fromString(p1.IAPGetSpec(),::DateMask) > QDate::fromString(p2.IAPGetSpec(), ::DateMask);
        }
    }
}
