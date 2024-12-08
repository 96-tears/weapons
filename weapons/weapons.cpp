//
//  weapons.cpp
//  weapons
//
//  Created by Евгений Тишкин on 01.12.2024.
//
//  Данный модуль содержит базовый класс ShipWeapon с набором виртуальных функций и protected-полей
//  Поля: double weight(вес), size_t _quantity(кол-во установок), double price (цена в $), string typeTarget (тип цели)
//  Методы: void install(установка оружия), void use(применение оружия), void uninstall(снятие оружия),
//  bool checked(проверка оружия), size_t quantity(возвращает кол-во установок) -- являются virtual и
//  переопределены в производных классах
//  Из данного базового класса следуют 2 производных: defensiveWeapon и attackWeapon
//  Поля defensiveWeapon: double performance(быстродействие в часах), double chanceToRepel(шанс отражения атаки в %)
//  Поля attackWeapon: double range(дистанция), double velocity(скорость полета снаряда в м/с), double accuracy(класс точности)
//  Из класса defensiveWeapon следуют 2 производных: mine и airDefence
//  У каждого из них есть 2 конструктора: пустой, который заполняет средние значения, и конструктор с аргументами
//  В данных классах переопределены методы базового класса shipWeapon
//  В классе mine есть собственный метод void defuse(обезвредить мину)
//  Поля класса mine: double chargePower(мощность заряда в кг), string triggerType(тип взрывателя)
//  Поля класса airDefence: double range(дальность)
//  Из класса attackWeapon происходит класс torpedo
//  Класс torpedo имеет 2 конструктора, как и предыдущие
//  Поля класса torpedo: double power(мощность в кг), double lenght(длина в м)

#include "weapons.hpp"
#include <iostream>
using namespace std;

    ///безвозвратная функция установки оружия
    void shipWeapon::install()
    {
        _quantity++;
        cout << "\nОрудие установлено\n";
    }
    
    ///безвозвратная функция использования оружия
    void shipWeapon::use()
    {
        cout << "\nОрудие использовано\n";
    }
    
    ///безвозвратная функция снятия оружия
    void shipWeapon::uninstall()
    {
        _quantity--;
        cout << "\nОрудие снято\n";
    }
    
    ///bool функция проверки оружия
    bool shipWeapon::checked()
    {
        cout << "\nОрудие проверено\n";
        return true;
    }
    
    ///size_t функция, возвращающая кол-во установок
    size_t shipWeapon::quantity()
    {
        return _quantity;
    }


    ///пустой конструктор, задающий значения по умолчанию
    mine::mine()
    {
        weight = 1120;
        price = 5000;
        performance = 0.1;
        chanceToRepel = 50;
        typeTarget = "underwater";
        chargePower = 230;
        triggerType = "magnetic field";
    }
    
    ///конструктор с параметрами: вес, цена, быстродействие, шанс отражения, мощность заряда, тип детонатора
    mine::mine(double wght, double prc, double prf, double chrpl, double chpwr, string trtp)
    {
        weight = wght;
        price = prc;
        performance = prf;
        chanceToRepel = chrpl;
        typeTarget = "underwater";
        chargePower = chpwr;
        triggerType = "magnetic field";
    }
    
    ///безвозвратная функция установки
    void mine::install()
    {
        _quantity++;
        cout << "\nМина загружена\n";
    }
    
    ///безвозвратная функция использования
    void mine::use()
    {
        _quantity--;
        cout << "\nМина установлена\n";
    }
    
    ///безвозвратная функция снятия
    void mine::uninstall()
    {
        _quantity--;
        cout << "\nМина разгружена\n";
    }
    
    void mine::defuse()
    {
        cout << "\nМина обезврежена\n";
    }
    
    ///bool функция проверки
    bool mine::checked()
    {
        cout << "\nМина осмотрена\n";
        return true;
    }



    ///пустой конструктор, задающий значения по умолчанию
    airDefence::airDefence()
    {
        weight = 42000;
        price = 635000000;
        performance = 0.01;
        chanceToRepel = 90;
        typeTarget = "air";
        range = 160;
    }
    
    ///конструктор с параметрами: вес, цена, быстродействие, шанс отражения, дальность
    airDefence::airDefence(double wgh, double prc, double prf, double chrpl, double rng)
    {
        weight = wgh;
        price = prc;
        performance = prf;
        chanceToRepel = chrpl;
        typeTarget = "air";
        range = rng;
    }
    
    ///безвозвратная функция установки
    void airDefence::install()
    {
        _quantity++;
        cout << "\nПВО установлено\n";
    }
    
    ///безвозвратная функция снятия
    void airDefence::uninstall()
    {
        _quantity--;
        cout << "\nПВО снято\n";
    }
    
    ///безвозвратная функция использования
    void airDefence::use()
    {
        cout << "\nПВО активировано\n";
    }
    
    ///bool функция проверки
    bool airDefence::checked()
    {
        cout << "\nПВО осмотрено\n";
        return true;
    }


    torpedo::torpedo()
    {
        weight = 42000;
        price = 635000000;
        range = 9;
        velocity = 100;
        accuracy = 70;
        typeTarget = "water/underwater";
    }
    
    ///конструктор с параметрами: вес, цена, скорость торпеды, точность, дальность
    torpedo::torpedo(double wgh, double prc, double vlc, double acr, double rng)
    {
        weight = wgh;
        price = prc;
        velocity = vlc;
        accuracy = acr;
        typeTarget = "water/underwater";
        range = rng;
    }
    
    ///безвозвратная функция установки
    void torpedo::install()
    {
        _quantity++;
        cout << "\nТорпеда загружена\n";
    }
    
    ///безвозвратная функция снятия
    void torpedo::uninstall()
    {
        _quantity--;
        cout << "\nТорпеда снята\n";
    }
    
    ///безвозвратная функция использования
    void torpedo::use()
    {
        cout << "\nТорпеда запущена\n";
        _quantity--;
    }
    
    ///bool функция проверки
    bool torpedo::checked()
    {
        cout << "\nТорпеда осмотрена\n";
        return true;
    }
