#include "17.1.1.h"
#include "17.1.2.h"
#include "17.1.3.h"
#include "17.2.1.h"
#include "17.2.2.h"
#include "17.2.3.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int task;
	double a, b, y, x, result;

	cout << "1) 17.1.1 (N) \n2) 17.1.2 (H) \n3) 17.1.3 (T) \n4) 17.2.1 (Площадь тропеции) \n5) 17.2.2 (y) \n6) 17.2.3 (Числовая последовательность) \n";
	cout << "Выберите какую задачу хотите выбрать: ";
	cin >> task;
	cout << endl;

	switch (task) {
	case 1:
		cout << "Введите y: ";
		cin >> y;

		result = FirstEasy(y);

		cout << "N = " << result;
		break;
	case 2:
		double n;

		cout << "Ввеидте y: ";
		cin >> y;
		cout << "Введите n: ";
		cin >> n;

		result = FirstMedium(y, n);

		cout << "H = " << result;
		break;
	case 3:

		cout << "Введите a: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;
		cout << "Введите y: ";
		cin >> y;
		cout << "Введите x: ";
		cin >> x;

		result = FirstHard(a, b, y, x);

		cout << "T = " << result;
		break;
	case 4:
		double alpha;

		cout << "Введите a: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;
		cout << "Введите alpha: ";
		cin >> alpha;

		result = SecondEasy(a, b, alpha);

		cout << "S = " << result;
		break;
	case 5:
		result = SecondMedium();

		cout << "y = " << result;
		break;
	case 6:
		int len;

		cout << "Введите x: ";
		cin >> x;
		cout << "Введите длинну последовательности: ";
		cin >> len;

		result = SecondHard(x, len);

		cout << "Результат последовательности: " << result;
		break;
	}

	return 0;
}