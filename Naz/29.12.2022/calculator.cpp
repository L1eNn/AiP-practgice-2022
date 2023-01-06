#include <iostream>
#include "calculator.h"
#include "operations.h"
#include <complex>
#include <vector>

using namespace std;

void Cycle() {
	const double PI = 3.14159265359;

	int operation, numeric;
	double normalResult;
	complex<double> complexResult;

	// ����������� ���� (�����������)
	while (true) {
		cout << "1) ������� ����� \n2) ����������� �����" << endl;
		cout << "�������� � ��� ��������: ";
		cin >> numeric;
		cout << endl;

		if (numeric == 1) {
			// �������� ��� �������� �������


			cout << "������ ��������: \n----------------------\n1) + \n2) - \n3) *\n4) / \n5) n * pi \n";
			cout << "-----------------------" << endl;

			cout << "������� �������� ������� ������ ���������: ";
			cin >> operation;

			if (operation == 0) {
				break;
			}
			else {
				if (operation == 5) {
					double num;

					cout << "������� ����� ��� ��������� �� ��: ";
					cin >> num;

					normalResult = num * PI;
				}
				else {
					double firstNum, secondNum;

					cout << "������� ������ �����: ";
					cin >> firstNum;

					cout << "������� ������ �����: ";
					cin >> secondNum;

					normalResult = NormalOperations(operation, firstNum, secondNum);
				}
			}

			cout << "��������� ����������: " << normalResult << endl;
			cout << "___________________________" << endl << endl;
		}
		else if (numeric == 2) {
			// �������� ��� ������������ �������

			int numbersAmount;

			cout << "1) �������� ��� ����� ����������� ������ \n2) �������� � ����� ������������ ������� \n";
			cout << "��������: ";
			cin >> numbersAmount;

			if (numbersAmount == 1) {
				// ���� ����������� �����
				int operation;
				double realNum, imagNum;

				cout << "������ ��������: \n----------------------\n1) + \n2) - \n3) *\n4) / \n";
				cout << "-----------------------" << endl;

				cout << "������� ������������ ����� ������������ �����: ";
				cin >> realNum;

				cout << "������� ��������: ";
				cin >> operation;

				cout << "������� ������ ����� ������������ �����: ";
				cin >> imagNum;

				if (operation == 0) {
					break;
				}
				else {
					complexResult = SubComplexOperations(operation, realNum, imagNum);
				}
			}
			else {
				// �������� ��� ����� ������������ �������
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
			}

			cout << "��������� ����������: " << complexResult << endl;
			cout << "___________________________" << endl << endl;

		}
	}
}