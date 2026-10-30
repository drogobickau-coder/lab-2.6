#include "Complex.h"
#include <sstream>
#include <cmath>
#pragma execution_character_set("utf-8")

// --- Ініціалізація статичних полів ---
int Complex::counter = 0;
int Complex::Pair::counter = 0;

// ================= Реалізація Complex::Pair =================

Complex::Pair::Pair(double f, double s) : first(f), second(s) {
    counter++;
}

Complex::Pair::Pair(const Pair& other) : first(other.first), second(other.second) {
    counter++;
}

Complex::Pair::~Pair() {
    counter--;
}

double Complex::Pair::multiplyFields() const {
    return first * second;
}

Complex::Pair& Complex::Pair::operator=(const Pair& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Complex::Pair::operator string() const {
    stringstream ss;
    ss << "(" << first << ", " << second << ")";
    return ss.str();
}

Complex::Pair& Complex::Pair::operator++() {
    ++first;
    return *this;
}

Complex::Pair Complex::Pair::operator++(int) {
    Pair temp(*this);
    second++;
    return temp;
}

Complex::Pair& Complex::Pair::operator--() {
    --first;
    return *this;
}

Complex::Pair Complex::Pair::operator--(int) {
    Pair temp(*this);
    second--;
    return temp;
}

Complex::Pair operator+(const Complex::Pair& a, const Complex::Pair& b) {
    return Complex::Pair(a.first + b.first, a.second + b.second);
}

ostream& operator<<(ostream& out, const Complex::Pair& p) {
    out << string(p);
    return out;
}

istream& operator>>(istream& in, Complex::Pair& p) {
    cout << "  first = ? "; in >> p.first;
    cout << "  second = ? "; in >> p.second;
    return in;
}


// ================= Реалізація Complex =================

Complex::Complex(double r, double i) : pair(r, i) {
    counter++;
}

Complex::Complex(const Pair& p) : pair(p) {
    counter++;
}

Complex::Complex(const Complex& other) : pair(other.pair) {
    counter++;
}

Complex::~Complex() {
    counter--;
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        pair = other.pair;
    }
    return *this;
}

Complex::operator string() const {
    stringstream ss;
    double r = pair.getFirst();
    double i = pair.getSecond();
    ss << r << (i >= 0 ? " + " : " - ") << std::abs(i) << "i";
    return ss.str();
}

Complex& Complex::operator++() {
    ++pair;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    pair++;
    return temp;
}

Complex& Complex::operator--() {
    --pair;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    pair--;
    return temp;
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.pair.getFirst() - b.pair.getFirst(), a.pair.getSecond() - b.pair.getSecond());
}

Complex operator*(const Complex& a, const Complex& b) {
    double ac = a.pair.getFirst() * b.pair.getFirst();
    double bd = a.pair.getSecond() * b.pair.getSecond();
    double ad = a.pair.getFirst() * b.pair.getSecond();
    double bc = a.pair.getSecond() * b.pair.getFirst();
    return Complex(ac - bd, ad + bc);
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << string(c);
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    in >> c.pair;
    return in;
}