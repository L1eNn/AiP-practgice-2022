#include <iostream>
#include "calculator.h"
#include "operations.h"
#include <complex>

using namespace std;

void Cycle() {
	int operation, numeric;
	double normalResult;
	complex<double> complexResult;

	while (true) {
		cout << "1) Обычные числа \n2) Комплексные числа" << endl;
		cout << "Выберите с чем работать: ";
		cin >> numeric;
		cout << endl;

		if (numeric == 1) {
			double firstNum, secondNum;

			cout << "Список операций: \n----------------------\n1) + \n2) - \n3) *\n4) / \n";
			cout << "-----------------------" << endl;

			cout << "Введите первое число: ";
			cin >> firstNum;

			cout << "Введите второе число: ";
			cin >> secondNum;

			cout << "Введите операцию которую хотите совершить: ";
			cin >> operation;

			if (operation == 0) {
				break;
			}
			else {
				normalResult = NormalOperations(operation, firstNum, secondNum);
			}

			cout << "Результат вычислений: " << normalResult << endl;
			cout << "___________________________" << endl << endl;
		}
		else {
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

			cout << "0) Выход \n1) + \n2) - \n3) *\n4) / \n";
			cout << "Введите операцию которую хотите совершить: ";
			cin >> operation;

			if (operation == 0) {
				break;
			}
			else {
				complexResult = ComplexOperations(operation, firstComplexOperation, secondComplexOperation, firstReal, firstImag, secondReal, secondImag);
			}

			cout << "Результат вычислений: " << complexResult << endl;
			cout << "___________________________" << endl << endl;
		}
	}
}