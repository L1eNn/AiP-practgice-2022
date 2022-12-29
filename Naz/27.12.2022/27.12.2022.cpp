#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;

//Задание на первый день практики по АиП (Калькулятор)

int main() {
	setlocale(LC_ALL, "Russian");

	float a;
	float b;
	float c;
	float d;
	float e;
	float f;


	cout << "Введите число для квадратного корня: ";
	cin >> b;
	cout << "Введите число для синуса: ";
	cin >> c;
	cout << "Введите число для логорифма: ";
	cin >> d;
	cout << "Введите число для арктангенса: ";
	cin >> e;
	cout << "Введите число для возведения в 5 степень: ";
	cin >> f;


	a = sqrt(b);
	cout << "Корень числа b: " << a << endl;
	a = sin(c);
	cout << "Синус числа c: " << a << endl;
	a = log(d);
	cout << "Логарифм числа d: " << a << endl;
	a = atan(e);
	cout << "Арктангенс числа e: " << a << endl;
	a = pow(f, 5);
	cout << "Число f в 5 степени: " << a << endl;
}