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

	set<double> usedNumbers = {}; // ��� � ��������������� �������

	vector<double> doubleHistory = {}; // ������ ����������� ���������� ������� �����
	vector<complex<double>> complexHistory = {}; // ������ ����������� ���������� ����������� �����

	// ����������� ���� (�����������)
	while (true) {
		cout << "1) ������� ����� \n2) ����������� ����� \n3) ������� ���������� \n4) �������������� ����� \n5) ��������� ���������� �����" << endl;
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

					usedNumbers.insert(num); // ����������� ����� � ���
				}
				else {
					double firstNum, secondNum;

					cout << "������� ������ �����: ";
					cin >> firstNum;

					cout << "������� ������ �����: ";
					cin >> secondNum;

					usedNumbers.insert(firstNum);
					usedNumbers.insert(secondNum);
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

				complexResult = SubComplexOperations(operation, realNum, imagNum);

				usedNumbers.insert(realNum);
				usedNumbers.insert(imagNum);
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

				cout << "1) + \n2) - \n3) *\n4) / \n";
				cout << "������� �������� ������� ������ ���������: ";
				cin >> operation;

				usedNumbers.insert(firstReal);
				usedNumbers.insert(firstImag);
				usedNumbers.insert(secondReal);
				usedNumbers.insert(secondImag);

				complexResult = ComplexOperations(operation, firstComplexOperation, secondComplexOperation, firstReal, firstImag, secondReal, secondImag);
			}

			complexHistory.push_back(complexResult); // ���������� ����� � �������

			cout << "��������� ����������: " << complexResult << endl;
			cout << "___________________________" << endl << endl;

		}
		else if (numeric == 3) {
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
		else if (numeric == 4) {
			// �������������� �����
			
			int operation;
			set<double>::iterator iter = usedNumbers.begin();

			cout << "---------- �������������� �����----------" << endl;
			cout << "[ ";
			for (int i = 1; iter != usedNumbers.end(); i++, iter++) {
				cout << *iter << ", ";
			}
			cout << "]" << endl << endl;

			cout << "0) ����� \n1) ��������" << endl;
			cout << "��������: ";
			cin >> operation;

			if (operation == 1) {
				usedNumbers.clear();
			}

			system("cls");
		}
		else if (numeric == 5) {
			srand(time(0));
			int randomNum = rand();
			
			cout << "���� ��������� �����: " << randomNum << endl << endl;
		}
	}
}