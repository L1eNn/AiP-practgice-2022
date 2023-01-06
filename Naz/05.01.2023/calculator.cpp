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

	vector<double> doubleHistory = {}; // ������ ����������� ���������� ������� �����
	vector<complex<double>> complexHistory = {}; // ������ ����������� ���������� ����������� �����

	// ����������� ���� (�����������)
	while (true) {
		cout << "1) ������� ����� \n2) ����������� ����� \n3) ������� ����������" << endl;
		cout << "�������� � ��� ��������: ";
		cin >> numeric;
		cout << endl;

		system("cls"); // ������� �������

		if (numeric == 1) {
			// �������� ��� �������� �������

			// ����� ����������� ���������� ������� �����
			cout << "[ ";
			for (double num : doubleHistory) {
				cout << num << ", ";
			}
			cout << "]" << endl << endl;


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

			doubleHistory.push_back(normalResult); // ���������� ����� � �������

			cout << "��������� ����������: " << normalResult << endl;
			cout << "___________________________" << endl << endl;
		}
		else if (numeric == 2) {
			// �������� ��� ������������ �������

			// ����� ����������� ���������� ����������� �����
			cout << "������� ���������� ����������� ����� - [ ";
			for (complex<double> num : complexHistory) {
				cout << num << ", ";
			}
			cout << "]" << endl << endl;


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

			complexHistory.push_back(complexResult); // ���������� ����� � �������

			cout << "��������� ����������: " << complexResult << endl;
			cout << "___________________________" << endl << endl;

		}
		else {
			// ������ � ������������ ����������
			int whichHistory, operation;

			cout << "1) ������� ������� ���������� \n"
				<< "2) ������� ����������� ���������� \n"
				<< "�������� � ����� �������� ��������: ";
			cin >> whichHistory;

			cout << "1) �������� ������� \n"
				<< "��������: ";
			// TODO: �������� ����� ��� �������
			cin >> operation;

			if (operation == 1) {
				if (whichHistory == 1) {
					doubleHistory.clear();
				}
				else {
					complexHistory.clear();
				}
			}

			system("cls"); // ������� �������
		}
	}
}