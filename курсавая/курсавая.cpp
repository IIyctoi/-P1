// курсавая.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include<string>

using namespace std;
// Функция определяет значение функции для заданного аргумента.
double func(double x) {
    // здесь можно добавить другую функцию, которую введет пользователь
    return sin(x) + cos(x / 2);
}
double minFunc(double a, double b, double step, double (*f)(double)) { // функция для нахождения минимума функции на заданном интервале
    double minVal = f(a); // начальное значение минимума
    for (double x = a + step; x <= b; x += step) { // перебор значений функции на интервале
        double val = f(x);
        if (val < minVal) { // если значение меньше текущего минимума
            minVal = val; // обновляем минимум
        }
    }
    return minVal; // возвращаем минимум
}
int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, step;
    cout << "Введите левую границу интервала: ";
    cin >> a;
    cout << "Введите правую границу интервала: ";
    cin >> b;
    cout << "Введите шаг изменения аргумента: ";
    cin >> step;
    double minVal = minFunc(a, b, step, func);
    cout << "Минимум функции на интервале [" << a << ", " << b << "] равен " << minVal << std::endl;
    return 0;
}
