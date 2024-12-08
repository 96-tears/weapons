//
//  main.cpp
//  weapons
//
//  Created by Евгений Тишкин on 01.12.2024.
//

#include <iostream>
#include "weapons.hpp"
using namespace std;

int main() {
    
    //динамический полиморфизм
    shipWeapon* m2 = new mine;
    m2->install();
    //m2->defuse();
    dynamic_cast<mine*>(m2)->defuse();
    delete m2;
    airDefence a2;
    a2.install();
    shipWeapon test = a2;
    cout << "\nКол-во установок в тесте = " << test.quantity() << endl;
    
    
    airDefence a1;     //объявление объекта ПВО
    a1.install();       //установка ПВО
    a1.use();           //использование ПВО
    cout << "\nКол-во пво = " << a1.quantity() << endl;
    
    
    mine m1;            //объявление объекта мины
    m1.install();       //установка мины
    m1.install();       //установка мины
    m1.use();           //использование мины
    m1.uninstall();     //снятие мины
    cout << "\nКол-во мин = " << m1.quantity() << endl;
    return 0;
}
