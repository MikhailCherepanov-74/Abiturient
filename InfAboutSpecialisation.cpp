#include "InfAboutSpecialisation.h"
InfAboutSpecialisation::InfAboutSpecialisation(QString lastName, QString firstName,
                               QString secName, QString birth, QString address, QString email,
                               QString phone,QVector<int> forms)
    : str_name(lastName),
      str_logo(firstName),
      str_adress(secName),
      str_spec(birth),
      str_ball(address),
      str_contest(email),
      str_cost(phone),
      vec_forms_study(forms)
{}
InfAboutSpecialisation::InfAboutSpecialisation(QStringList list)
    : str_name(list[0]),
      str_logo(list[1]),
      str_adress(list[2]),
      str_spec(list[4]),
      str_ball(list[4]),
      str_contest(list[7]),
      str_cost(list[6])
{}
QString InfAboutSpecialisation::IASgetName() {
    return str_name;
}
QString InfAboutSpecialisation::IASGetLogo() {
    return str_logo;
}
QString InfAboutSpecialisation::IAPGetAdress() {
    return str_adress;
}
QString InfAboutSpecialisation::IAPGetSpec() {
    return str_spec;
}
QString InfAboutSpecialisation::IAPgetBall() {
    return str_ball;
}
QString InfAboutSpecialisation::IASgetContest() {
    return str_contest;
}
QString InfAboutSpecialisation::IASgetCost() {
    return str_cost;
}
QString InfAboutSpecialisation::IAPgetStrForm() {
    QString str_form="";
    if(vec_forms_study[0]==1)
        str_form+="Дневная\n";
    if(vec_forms_study[1]==1)
        str_form+="Вечерняя\n";
    if(vec_forms_study[2]==1)
        str_form+="Заочная\n";
    str_form.chop(1);
    return str_form;
}
QStringList InfAboutSpecialisation::IAPgetAll() {

    QString str_form="";
    if(vec_forms_study[0]==1)
        str_form+="Дневная\n";
    if(vec_forms_study[1]==1)
        str_form+="Вечерняя\n";
    if(vec_forms_study[2]==1)
        str_form+="Заочная\n";
    str_form.chop(1);
    return QStringList() << str_name << str_logo <<
                            str_adress << str_spec << str_ball << str_contest <<
                            str_cost<<str_form;
}
bool InfAboutSpecialisation::operator==(const InfAboutSpecialisation& p) const {
    return (str_name == p.str_name) && (str_logo ==
                                              p.str_logo) && (str_adress == p.str_adress) &&
            (str_spec == p.str_spec) && (str_ball ==
                                         p.str_ball) && (str_contest == p.str_contest) &&
            (str_cost == p.str_cost);
}
QTextStream& operator<<(QTextStream& stream, const InfAboutSpecialisation& p)
{
    stream << p.str_name << ","
           << p.str_logo << ","
           << p.str_adress << ","
           << p.str_spec << ","
           << p.str_ball << ","
           << p.str_contest << ","
           << p.str_cost;
    return stream;
}
