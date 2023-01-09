#include <iostream>
#include "calculator.h"
#include "operations.h"
#include <complex>
#include <vector>
#include <set>

using namespace std;

void Cycle() {
	const double PI = 3.14159265359;

	int operation, numeric;
	double normalResult;
	complex<double> complexResult;

	set<double> usedNumbers = {}; // Сет с использованными числами

	vector<double> doubleHistory = {}; // Вектор результатов вычисления обычных чисел
	vector<complex<double>> complexHistory = {}; // Вектор результатов вычисления комплексных чисел

	// Бесконечный цикл (калькулятор)
	while (true) {
		cout << "1) Обычные числа \n2) Комплексные числа \n3) Истории вычислений \n4) Использованные числа \n5) Генерация случайного числа" << endl;
		cout << "Выберите с чем работать: ";
		cin >> numeric;
		cout << endl;

		system("cls"); // Очистка консоли

		if (numeric == 1) {
			// Операции над обычными числами

			// Вывод результатов вычислений обычных чисел
			cout << "[ ";
			for (double num : doubleHistory) {
				cout << num << ", ";
			}
			cout << "]" << endl << endl;


			cout << "Список операций: \n----------------------\n1) + \n2) - \n3) *\n4) / \n5) n * pi \n";
			cout << "-----------------------" << endl;

			cout << "Введите операцию которую хотите совершить: ";
			cin >> operation;

			if (operation == 0) {
				break;
			}
			else {
				if (operation == 5) {
					double num;

					cout << "Введите число для умножения на ПИ: ";
					cin >> num;

					normalResult = num * PI;

					usedNumbers.insert(num); // Добвавление числа в сет
				}
				else {
					double firstNum, secondNum;

					cout << "Введите первое число: ";
					cin >> firstNum;

					cout << "Введите второе число: ";
					cin >> secondNum;

					usedNumbers.insert(firstNum);
					usedNumbers.insert(secondNum);
					normalResult = NormalOperations(operation, firstNum, secondNum);
				}
			}

			doubleHistory.push_back(normalResult); // Добавление числа в исотрию

			cout << "Результат вычислений: " << normalResult << endl;
			cout << "___________________________" << endl << endl;
		}
		else if (numeric == 2) {
			// Операции над комплексными числами
			
			// Вывод результатов вычислений комплексных чисел
			cout << "История вычислений комплексных чисел - [ ";
			for (complex<double> num : complexHistory) {
				cout << num << ", ";
			}
			cout << "]" << endl << endl;


			int numbersAmount;

			cout << "1) Операции над одним комплексным числом \n2) Операции с двумя комплексными числами \n";
			cout << "Выберите: ";
			cin >> numbersAmount;

			if (numbersAmount == 1) {
				// Одно комплексное число
				int operation;
				double realNum, imagNum;

				cout << "Список операций: \n----------------------\n1) + \n2) - \n3) *\n4) / \n";
				cout << "-----------------------" << endl;

				cout << "Введите вещественную часть комплексного числа: ";
				cin >> realNum;

				cout << "Введите операцию: ";
				cin >> operation;

				cout << "Введите мнимую часть комплексного числа: ";
				cin >> imagNum;

				complexResult = SubComplexOperations(operation, realNum, imagNum);

				usedNumbers.insert(realNum);
				usedNumbers.insert(imagNum);
			}
			else {
				// Операции над двумя комплексными числами
				int firstComplexOperation, secondComplexOperation;
				double firstReal, firstImag, secondReal, secondImag;

				cout << "Список операций: \n----------------------\n1) + \n2) - \n3) *\n4) / \n";
				cout << "-----------------------" << endl;

				cout << "Введите вещественную часть первого комплексного числа: ";
				cin >> firstReal;

				cout << "Введите операцию первого комплексного числа: ";
				cin >> firstComplexOperation;

				cout << "Введите мнимое число первого комплексного числа: ";
				cin >> firstImag;

				cout << "Введите вещественную часть второго комплексного числа: ";
				cin >> secondReal;

				cout << "Введите операцию второго комплексного числа: ";
				cin >> secondComplexOperation;

				cout << "Введите мнимое число второго комплексного числа: ";
				cin >> secondImag;

				cout << "1) + \n2) - \n3) *\n4) / \n";
				cout << "Введите операцию которую хотите совершить: ";
				cin >> operation;

				usedNumbers.insert(firstReal);
				usedNumbers.insert(firstImag);
				usedNumbers.insert(secondReal);
				usedNumbers.insert(secondImag);

				complexResult = ComplexOperations(operation, firstComplexOperation, secondComplexOperation, firstReal, firstImag, secondReal, secondImag);
			}

			complexHistory.push_back(complexResult); // Добавление числа в исотрию

			cout << "Результат вычислений: " << complexResult << endl;
			cout << "___________________________" << endl << endl;

		}
		else if (numeric == 3) {
			// Работа с результатами вычислений
			int whichHistory, operation;

			cout << "1) История обычных вычислений \n"
				<< "2) История комплексных вычислений \n"
				<< "Выберите с какой историей работать: ";
			cin >> whichHistory;

			cout << "1) Очистить историю \n"
				<< "Выберите: ";
			// TODO: Доделать опции для истории
			cin >> operation;

			if (operation == 1) {
				if (whichHistory == 1) {
					doubleHistory.clear();
				}
				else {
					complexHistory.clear();
				}
			}

			system("cls"); // Очистка консоли
		}
		else if (numeric == 4) {
			// Использованные числа
			
			int operation;
			set<double>::iterator iter = usedNumbers.begin();

			cout << "---------- Использованные числа----------" << endl;
			cout << "[ ";
			for (int i = 1; iter != usedNumbers.end(); i++, iter++) {
				cout << *iter << ", ";
			}
			cout << "]" << endl << endl;

			cout << "0) Выход \n1) Очистить" << endl;
			cout << "Выберите: ";
			cin >> operation;

			if (operation == 1) {
				usedNumbers.clear();
			}

			system("cls");
		}
		else if (numeric == 5) {
			srand(time(0));
			int randomNum = rand();
			
			cout << "Ваше случайное число: " << randomNum << endl << endl;
		}
	}
}