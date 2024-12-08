//
//  weapons.hpp
//  weapons
//
//  Created by Евгений Тишкин on 01.12.2024.
//

#include <iostream>
using namespace std;
///базовый класс корабельного вооружения
class shipWeapon
{
protected:
    double weight;                      //вес
    size_t _quantity = 0;               //кол-во установок
    double price;                       //цена
    string typeTarget;                  //тип цели
public:
    
    ///безвозвратная функция установки оружия
    virtual void install();
    
    ///безвозвратная функция использования оружия
    virtual void use();
    
    ///безвозвратная функция снятия оружия
    virtual void uninstall();
    
    ///bool функция проверки оружия
    virtual bool checked();
    
    ///size_t функция, возвращающая кол-во установок
    virtual size_t quantity();
    
};

///производный от корабельного вооружения класс защитного вооружения
class defensiveWeapon : public shipWeapon
{
protected:
    double performance;     //быстродействие
    double chanceToRepel;   //шанс отражения
};

///производный от корабельного вооружения класс атакующего вооружения
class attackWeapon : public shipWeapon
{
protected:
    double range;           //дальность
    double velocity;        //скорость снаряда
    double accuracy;        //точность
};

//производный от защитного вооружения класс мин
class mine : public defensiveWeapon
{
private:
    double chargePower;    //мощность заряда
    string triggerType;    //тип детонатора
public:
    
    ///пустой конструктор, задающий значения по умолчанию
    mine();
    
    ///конструктор с параметрами: вес, цена, быстродействие, шанс отражения, мощность заряда, тип детонатора
    mine(double wght, double prc, double prf, double chrpl, double chpwr, string trtp);
    
    ///безвозвратная функция установки
    void install() override;
    
    ///безвозвратная функция использования
    void use() override;
    
    ///безвозвратная функция снятия
    void uninstall() override;
    
    void defuse();
    
    ///bool функция проверки
    bool checked() override;
};

///производный от защитного вооружения класс ПВО
class airDefence : public defensiveWeapon
{
private:
    double range;       //дальность
public:
    
    ///пустой конструктор, задающий значения по умолчанию
    airDefence();
    
    ///конструктор с параметрами: вес, цена, быстродействие, шанс отражения, дальность
    airDefence(double wgh, double prc, double prf, double chrpl, double rng);
    
    ///безвозвратная функция установки
    void install() override;
    
    ///безвозвратная функция снятия
    void uninstall() override;
    
    ///безвозвратная функция использования
    void use() override;
    
    ///bool функция проверки
    bool checked() override;
};

class torpedo : public attackWeapon
{
private:
    double power;
    double lenght;
public:
    torpedo();
    
    ///конструктор с параметрами: вес, цена, скорость торпеды, точность, дальность
    torpedo(double wgh, double prc, double vlc, double acr, double rng);
    
    ///безвозвратная функция установки
    void install() override;
    
    ///безвозвратная функция снятия
    void uninstall() override;
    
    ///безвозвратная функция использования
    void use() override;
    
    ///bool функция проверки
    bool checked() override;
    
};
