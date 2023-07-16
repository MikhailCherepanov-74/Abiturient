#include "NewInformationAS.h"
NewInformationAS::NewInformationAS(QString title, InfAboutSpecialisation* p,
                                   QWidget* parent)
    : QDialog(parent),
      regexName(::fsLastNameame_regex),
      regexEmail(::email_regex),
      regexPhone(::phone_regex),
      inpSpec(p),
      outSpec(nullptr),
      NFill(),
      notValidated()
{     this->setWindowTitle(title);
      this->resize(600, 800);
     // this->setFixedSize(600, 600);
      grid = new QGridLayout(this);

      label_name = new QLabel("Название университета  :", this);
      label_logo = new QLabel("Логотип  :", this);
      label_bal = new QLabel("Проходной балл :", this);
      label_contest = new QLabel("Конкурс :", this);
      label_cost = new QLabel("Стоимость :", this);
      label_adress = new QLabel("Почтовый адрес  : ", this);
      label_specialization = new QLabel("Специальность :", this);
     // info_about_already_added = new QLabel("При добавлении специальности вуза, который уже есть в списке,\n оставьте поля с информацией о нем пустыми.", this);
      LineEditd_name = new QLineEdit(this);
      LineEdit_logo = new QLineEdit(this);
      LineEditd_adress = new QLineEdit(this);
      LineEditd_specialization = new QLineEdit(this);
      LineEdit_bal = new QLineEdit(this);
      LineEditd_cost= new QLineEdit(this);
      LineEditd_contest = new QLineEdit(this);
      LineEditd_name->setText(p->str_name);
      LineEdit_logo->setText(p->str_logo);
      LineEditd_adress->setText(p->str_adress);
      LineEditd_specialization->setText(p->str_spec);
      LineEdit_bal->setText(p->str_ball);
      LineEditd_contest->setText(p->str_contest);
      LineEditd_cost->setText(p->str_cost);
      buttonOk = new QPushButton("OK", this);
      buttonCancel = new QPushButton("Cancel", this);
        label_form_of_study = new QLabel("Выберете форму обучения:", this);
        label_form_of_study->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        checkBox_daytime = new QCheckBox("Дневное", this);
        checkBox_evening = new QCheckBox("Вечернее", this);
        checkBox_distance = new QCheckBox("Заочное", this);
        if(p->vec_forms_study[0]==1)
            checkBox_daytime->setChecked(true);
        if(p->vec_forms_study[1]==1)
            checkBox_evening->setChecked(true);
        if(p->vec_forms_study[2]==1)
            checkBox_distance->setChecked(true);
      grid->addWidget(label_name, 1, 0);
      grid->addWidget(label_logo, 2, 0);
      grid->addWidget(label_adress, 3, 0);
      grid->addWidget(label_specialization, 4, 0);
      grid->addWidget(label_bal, 5, 0);
      grid->addWidget(label_contest, 6, 0);
      grid->addWidget(label_cost, 7, 0);
      grid->addWidget(LineEditd_name, 1, 1);
      grid->addWidget(LineEdit_logo, 2, 1);
      grid->addWidget(LineEditd_adress, 3, 1);
      grid->addWidget(LineEditd_specialization, 4, 1);
      grid->addWidget(LineEdit_bal, 5, 1);
      grid->addWidget(LineEditd_contest, 6, 1);
      grid->addWidget(LineEditd_cost, 7, 1);
      grid->addWidget(label_form_of_study, 8, 1);
      grid->addWidget(checkBox_daytime, 9, 0);
      grid->addWidget(checkBox_evening, 9, 1);
      grid->addWidget(checkBox_distance, 9, 2);
      grid->addWidget(buttonOk, 10, 0, 1, 2);
      grid->addWidget(buttonCancel, 10, 2, 1, 2);
   connect(buttonOk, SIGNAL(clicked()), SLOT(accept()));
   connect(buttonCancel, SIGNAL(clicked()), SLOT(reject()));
}
NewInformationAS::~NewInformationAS() {
    if(flag_delete)
        delete outSpec;
}
InfAboutSpecialisation* NewInformationAS::getPersonInf() { return outSpec; }
bool NewInformationAS::boolFillAll() {
    QList<QLineEdit*> widgets = { LineEditd_name,
                                  LineEdit_logo, LineEditd_adress, /*tmp,*/ LineEditd_specialization,
                                  LineEdit_bal, LineEditd_contest,LineEditd_cost };
    for (int i = 0; i < widgets.size(); i++) {
        if (widgets[i]->text() == "") {
            if (i == 0)
                NFill << "Название Университета";
            else if (i == 3)
                NFill << "Перечень специальностей";
            else if (i == 4)
                NFill << "Проходной балл";
            else if (i == 5)
                NFill << "Конкурс";
            else if (i == 6)
                NFill << "Стоимость";
        }
    }
    if(!checkBox_daytime->isChecked()
            &&!checkBox_evening->isChecked()
            &&!checkBox_distance->isChecked()){
        flag_able_form=0;
    }
    return (NFill.size() == 0);
}
bool NewInformationAS::IsEdited() {
    return !(*inpSpec == *outSpec);
}
void NewInformationAS::accept() {
    if(!(boolFillAll()&&flag_able_form)){
        QString str_err="";
        if(!boolFillAll()){
            str_err+="Заполните поля:\n";
            for( QString  s : NFill)
                str_err+=s+="\n";
        }
         if(!flag_able_form)
             str_err+="Добавьте хотя бы одну форму обучения!";
         NFill.clear();
         QMessageBox::critical(nullptr,"Ошибка!",str_err);
    }
    else{
        flag_delete=1;
        QVector<int> forms_study(3, 0);
        if (checkBox_daytime->isChecked())
            forms_study[0] = 1;
        if (checkBox_evening->isChecked())
            forms_study[1] = 1;
        if (checkBox_distance->isChecked())
            forms_study[2] = 1;
        outSpec = new
                InfAboutSpecialisation(LineEditd_name->text(), LineEdit_logo->text(), LineEditd_adress->text(),
                                       LineEditd_specialization->text(),
                                       LineEdit_bal->text(),
                                       LineEditd_contest->text(), LineEditd_cost->text(),forms_study);
        QDialog::accept();
        this->close();
    }
}
