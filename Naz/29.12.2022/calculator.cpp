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
		cout << "1) ������� ����� \n2) ����������� �����" << endl;
		cout << "�������� � ��� ��������: ";
		cin >> numeric;
		cout << endl;

		if (numeric == 1) {
			double firstNum, secondNum;

			cout << "������ ��������: \n----------------------\n1) + \n2) - \n3) *\n4) / \n";
			cout << "-----------------------" << endl;

			cout << "������� ������ �����: ";
			cin >> firstNum;

			cout << "������� ������ �����: ";
			cin >> secondNum;

			cout << "������� �������� ������� ������ ���������: ";
			cin >> operation;

			if (operation == 0) {
				break;
			}
			else {
				normalResult = NormalOperations(operation, firstNum, secondNum);
			}

			cout << "��������� ����������: " << normalResult << endl;
			cout << "___________________________" << endl << endl;
		}
		else {
			int firstComplexOperation, secondComplexOperation;
			double firstReal, firstImag, secondReal, secondImag;

			cout << "������ ��������: \n----------------------\n1) + \n2) - \n3) *\n4) / \n";
			cout << "-----------------------" << endl;

			cout << "������� ������������ ����� ������� ������������ �����: ";
			cin >> firstReal;

			cout << "������� �������� ������� ������������ �����: ";
			cin >> firstComplexOperation;

			cout << "������� ������ ����� ������� ������������ �����: ";
			cin >> firstImag;

			cout << "������� ������������ ����� ������� ������������ �����: ";
			cin >> secondReal;

			cout << "������� �������� ������� ������������ �����: ";
			cin >> secondComplexOperation;

			cout << "������� ������ ����� ������� ������������ �����: ";
			cin >> secondImag;

			cout << "0) ����� \n1) + \n2) - \n3) *\n4) / \n";
			cout << "������� �������� ������� ������ ���������: ";
			cin >> operation;

			if (operation == 0) {
				break;
			}
			else {
				complexResult = ComplexOperations(operation, firstComplexOperation, secondComplexOperation, firstReal, firstImag, secondReal, secondImag);
			}

			cout << "��������� ����������: " << complexResult << endl;
			cout << "___________________________" << endl << endl;
		}
	}
}