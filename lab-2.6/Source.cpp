#include <iostream>
#include <windows.h>
#include "Complex.h"
#pragma execution_character_set("utf-8")


// Структура для демонстрації розміру з вирівнюванням
#pragma pack(push, 1)
struct PackedComplex {
    double first;
    double second;
};
#pragma pack(pop)

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    {
        setlocale(LC_ALL, "uk_UA.UTF-8");
    }



    cout << "Початкова кількість об'єктів Complex: " << Complex::getCounter() << endl;
    cout << "Початкова кількість об'єктів Complex::Pair: " << Complex::Pair::getCounter() << endl;

    {
        cout << "\n--- Створення та введення об'єктів ---" << endl;
        Complex c1;
        cout << "Введіть c1:" << endl;
        cin >> c1;

        Complex c2(3.0, 4.0); // Конструктор ініціалізації
        Complex c3 = c1;      // Конструктор копіювання

        cout << "\nc1: " << c1 << endl;
        cout << "c2: " << c2 << endl;
        cout << "c3 (копія c1): " << c3 << endl;

        cout << "\n--- Перевірка операцій (варіант 17) ---" << endl;
        Complex c_sub = c1 - c2;
        Complex c_mul = c1 * c2;
        cout << "c1 - c2 = " << c_sub << endl;
        cout << "c1 * c2 = " << c_mul << endl;

        cout << "\n--- Перевірка інкрементів/декрементів ---" << endl;
        cout << "До префіксного ++c1: " << c1 << endl;
        ++c1;
        cout << "Після префіксного ++c1: " << c1 << endl;

        cout << "До постфіксного c1++: " << c1 << endl;
        c1++;
        cout << "Після постфіксного c1++: " << c1 << endl;

        cout << "\n--- Робота з вкладеним класом Pair ---" << endl;
        Complex::Pair p1(2.5, 3.5);
        Complex::Pair p2(1.5, 2.5);
        cout << "p1 = " << p1 << ", p2 = " << p2 << endl;
        cout << "p1 + p2 = " << (p1 + p2) << endl;
        cout << "Множення полів p1: " << p1.multiplyFields() << endl;

        cout << "\n--- Демонстрація масиву об'єктів ---" << endl;
        Complex arr[3] = { Complex(1, 1), Complex(2, 2), Complex(3, 3) };
        for (int i = 0; i < 3; i++) {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }

        cout << "\nПоточна кількість об'єктів Complex: " << Complex::getCounter() << endl;
        cout << "Поточна кількість об'єктів Complex::Pair: " << Complex::Pair::getCounter() << endl;
    } // Тут викличуться деструктори локальних об'єктів

    cout << "\n--- Після знищення локальних об'єктів ---" << endl;
    cout << "Кількість об'єктів Complex: " << Complex::getCounter() << endl;
    cout << "Кількість об'єктів Complex::Pair: " << Complex::Pair::getCounter() << endl;

    cout << "\n--- Розмір класу ---" << endl;
    cout << "Розмір Complex без #pragma pack(1): " << sizeof(Complex) << " байт" << endl;
    cout << "Розмір запакованого варіанту (PackedComplex): " << sizeof(PackedComplex) << " байт" << endl;

    return 0;
}