#include <iostream>
#include <ctime>
#include <vector>
#include "windows.h"

using namespace std;

string stringRepeat(string text, int amountOfRepeat) {
	string newText;

	for (int i = 1; i <= amountOfRepeat; i++) {
		newText += text;
	}

	return newText;
}

vector<int> spin(vector<int> numbers) {
	vector<int> newNumbers;
	int indexOfNumber;
	bool isHasSameNumber;

	// Не верная реальзация!!
	/*for (int i = 0; i < numbers.size(); i++) {
		indexOfNumber = rand() % (numbers.size() - 1);
		for (int j = 0; j < i; j++) {
			while (newNumbers[j] == numbers[indexOfNumber]) {
				indexOfNumber = rand() % (numbers.size() - 1);
			}
		}
		newNumbers.push_back(numbers[indexOfNumber]);
	}*/

	for (int i = 0; i < numbers.size();) {
		isHasSameNumber = false;
		indexOfNumber = rand() % numbers.size();

		for (int j = 0; j < i; j++) {
			if (newNumbers[j] == numbers[indexOfNumber]) {
				isHasSameNumber = true;
				break;
			}
		}

		if (!isHasSameNumber) {
			newNumbers.push_back(numbers[indexOfNumber]);
			i++;
		}
	}

	return newNumbers;
}

void displayLototron(vector<int> numbers) {

	int size = numbers.size();

	if (numbers.size() < 10) {
		cout << "  " << stringRepeat("-", (size * 4) + 1) << endl;
	}
	else {
		cout << "  " << stringRepeat("-", (size * 4) + size - 8) << endl;
	}

	
	cout << "/";

	for(int i = 0; i < size; i++) {
		if (numbers[i] > 99) {
			cout << "   ~~~";
		}
		else if (numbers[i] > 9) {
			cout << "   ~~";
		}
		else {
			cout << "   ~";
		}
	}

	cout << "   \\" << endl;
	
	cout << "# ";

	for (int i = 0; i < size; i++) {
		cout << " |" << numbers[i] << '|';
	}

	cout << "  #" << endl;

	cout << "\\";

	for (int i = 0; i < size; i++) {
		if (numbers[i] > 99) {
			cout << "   ~~~";
		}
		else if (numbers[i] > 9) {
			cout << "   ~~";
		}
		else {
			cout << "   ~";
		}
	}

	cout << "   /" << endl;

	if (numbers.size() < 10) {
		cout << "  " << stringRepeat("-", (size * 4) + 1) << endl;
	}
	else {
		cout << "  " << stringRepeat("-", (size * 4) + size - 8) << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int amountOfMembers;
	int amountOfSpins;
	string waitingVar;
	char choice;
	vector<int> numbers;

	cout << "Введите количество участников в лотерее: ";
	cin >> amountOfMembers;

	for (int i = 1; i <= amountOfMembers; i++) {
		numbers.push_back(i);
	}

	while (numbers.size() != 0) {
		system("cls");

		if (numbers.size() == 1) {
			cout << "===Последнее число===" << endl;
			cout << "          ~" << endl;
			cout << "         |" << *numbers.begin() << "|" << endl;
			cout << "          ~" << endl;

			break;
		}
		displayLototron(numbers);

		cout << "Сколько раз перемешать лототрон: ";
		cin >> amountOfSpins;

		if (amountOfSpins == 0) {
			system("cls");
			displayLototron(numbers);
		}
		else {
			for (int i = 0; i < amountOfSpins; i++) {
				numbers = spin(numbers);

				system("cls");
				displayLototron(numbers); 

				Sleep(2000);
			}
		}

		cout << "y) Да \nn) Нет \nВытащить бумажку с числом: ";
		cin >> choice;

		system("cls");

		if (choice == 'y') {
			int randomNum = rand() % numbers.size();
			cout << "=== Вам выпало ===" << endl;
			cout << "         ~ " << endl;
			cout << "        |" << numbers[randomNum] << "|" << endl;
			cout << "         ~ " << endl;

			numbers.erase(numbers.begin() + randomNum);
		}
		else {
			cout << "Вы выбрали не перемешивать :D" << endl;
		}

		Sleep(2000);
	}
}