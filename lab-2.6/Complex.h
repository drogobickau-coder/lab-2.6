#pragma once
#include <string>
#include <iostream>

using namespace std;

class Complex
{
public:
    class Pair
    {
    private:
        double first;
        double second;
        static int counter; // Лічильник об'єктів Pair
    public:
        Pair(double f = 0.0, double s = 0.0);
        Pair(const Pair& other);
        ~Pair();

        double getFirst() const { return first; }
        double getSecond() const { return second; }
        void setFirst(double f) { first = f; }
        void setSecond(double s) { second = s; }

        double multiplyFields() const;

        static int getCounter() { return counter; }

        // Перевантаження операцій для Pair
        Pair& operator=(const Pair& other);
        operator string() const;

        Pair& operator++();    // Префіксний інкремент (first)
        Pair operator++(int);  // Постфіксний інкремент (second)
        Pair& operator--();    // Префіксний декремент (first)
        Pair operator--(int);  // Постфіксний декремент (second)

        // Дружні функції
        friend Pair operator+(const Pair& a, const Pair& b);
        friend ostream& operator<<(ostream& out, const Pair& p);
        friend istream& operator>>(istream& in, Pair& p);
    };

private:
    Pair pair;
    static int counter; // Лічильник об'єктів Complex

public:
    Complex(double r = 0.0, double i = 0.0);
    Complex(const Pair& p);
    Complex(const Complex& other);
    ~Complex();

    Pair getPair() const { return pair; }
    void setPair(const Pair& p) { pair = p; }

    static int getCounter() { return counter; }

    // Перевантаження операцій для Complex
    Complex& operator=(const Complex& other);
    operator string() const;

    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    // Дружні функції (варіант 17)
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);

    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};