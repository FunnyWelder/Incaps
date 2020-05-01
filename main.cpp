/*1. Продемонстрировать различные уровни инкапсуляции данных (указать комментарием):
a. Отсутствие инкапсуляции (public свойства)
b. Инкапсуляция с помощью set/get
c. Инкапсуляция с помощью специализированных протоколов/методов
d. Инкапсуляция за счёт абстракций

p.s. использовать механизмы исключений, если нарушается инвариант или не соблюдаются пост/пред-условия

2. Продемонстрировать различные варианты инкапсуляции поведения
a. За счёт позднего связывания
b. Замена поведения (тут тоже используется позднее связывание)
c. Расширения поведения (тут тоже используется позднее связывание)*/

#include <iostream>
#include <string>

using namespace std;

//инкапсуляция через абстракцию
class SuperHero {
protected:
    string Name;
    string Abilities;
    string Vulnerabilities;

public:
    unsigned int Toplist;
    string Description; //отсутствие инкапсуляции

    string setName(const string &name){ //инкапсуляция при помощи сетера
        Name = name;
    }

    string getName(){ //инкапсуляция при помощи гетера
        return Name;
    }

    virtual void add_abilities(string abilities) {
        Abilities = Abilities + ", " + abilities;
    };

    virtual void increase_place_in_toplist() { //инкапсуляция через специальный протокол
        Toplist = Toplist + 1;
    }

    void print_hero_profile() {
        cout << "Имя: " << getName() << endl;
        cout << "Способности: " << Abilities << endl;
        cout << "Слабости: " << Vulnerabilities << endl;
        cout << "Описание: " << Description << endl;
        cout << "Место в рейтинге: " << Toplist << endl;
        cout << endl;
    }
};


class SuperMan: public SuperHero {
public:
    void increase_place_in_toplist() { //замена поведения
        Toplist = 1;
    }

    SuperMan(const unsigned int &Toplist) {
        this->Name = "Супермен";
        this->Abilities = "Очень сильный";
        this->Vulnerabilities = "Криптонит";
        this->Description = "Супергерой";
        this->Toplist = Toplist;
    }
};

class BatMan: public SuperHero  {
private:
    string Equipment;

public:

    BatMan(const string &equipment, const unsigned int &Toplist) {
        this->Name = "Бэтмен";
        this->Abilities = "Умный";
        this->Vulnerabilities = "Человек";
        this->Description = "Человек летучая мышь";
        this->Equipment = equipment;
        this->Toplist = Toplist;
    }

};

class Avengers: public SuperHero   {
public:
    Avengers(const string &Name, const string &Abilities, const string &Vulnerabilities, const string &Description, const unsigned int &Toplist) {
        this->Name = Name;
        this->Abilities = Abilities;
        this->Vulnerabilities = Vulnerabilities;
        this->Description = Description;
        this->Toplist = Toplist;
    }

    void Add_Name_and_Abilities(string name, string abilities){ //расширение поведения
        add_abilities(abilities);
        Name = Name + ", " + name;
    }
};

void increase_place_in_toplist_more(SuperHero &hero){ //позднее динамическое связывание
    hero.increase_place_in_toplist();
    hero.increase_place_in_toplist();
    hero.increase_place_in_toplist();
    hero.increase_place_in_toplist();
    hero.increase_place_in_toplist();
}

int main() {
    setlocale(LC_ALL, "Russian");
    BatMan batman("Бумерангер", 2);
    SuperMan superman(100);
    Avengers aveng("Человек-паук, Железный человек", "Работа в команде", "Разногласия", "Защитники человечества", 0);

    superman.print_hero_profile();
    batman.print_hero_profile();
    aveng.print_hero_profile();
    cout << "------------------------------------" << endl;

    aveng.increase_place_in_toplist();
    increase_place_in_toplist_more(aveng);
    batman.add_abilities("Крутой");
    aveng.Add_Name_and_Abilities("Капитан Америка", "Тактичные");
    superman.increase_place_in_toplist();

    superman.print_hero_profile();
    batman.print_hero_profile();
    aveng.print_hero_profile();

    return 0;
}