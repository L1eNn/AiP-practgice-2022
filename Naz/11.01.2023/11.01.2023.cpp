#include "windows.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <thread>
#include <future>

using namespace std;

vector<int> numbers;

string stringRepeat(string text, int amountOfRepeat) {
	string newText;

	for (int i = 1; i <= amountOfRepeat; i++) {
		newText += text;
	}

	return newText;
}

int getRandomIndex(int size) {
	int randomNum = rand() % size;
	return randomNum;
}

vector<int> spin(vector<int> numbers) {
	vector<int> newNumbers;
	int indexOfNumber;
	bool isHasSameNumber;

	for (int i = 0; i < numbers.size();) {
		isHasSameNumber = false;
		future<int> temporaryIndexOfNumber = async(getRandomIndex, numbers.size());
		indexOfNumber = temporaryIndexOfNumber.get();

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

void deleteNum(vector<int>::iterator iterator) {
	numbers.erase(iterator);
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int amountOfMembers;
	int amountOfSpins;
	string waitingVar;
	char choice;

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
				future<vector<int>> temporaryNumbers = async(spin, numbers);
				numbers = temporaryNumbers.get();

				system("cls");

				thread th(displayLototron, numbers);
				th.join();

				Sleep(2000);
			}
		}

		cout << "y) Да \nn) Нет \nВытащить бумажку с числом: ";
		cin >> choice;

		system("cls");

		if (choice == 'y') {
			future<int> temporaryRandomNum = async(getRandomIndex, numbers.size());

			cout << "=== Вам выпало ===" << endl;
			cout << "         ~ " << endl;
			int randomNum = temporaryRandomNum.get();
			thread thDeleter(deleteNum, numbers.begin() + randomNum);
			cout << "        |" << numbers[randomNum] << "|" << endl;
			cout << "         ~ " << endl;

			thDeleter.join();
		}
		else {
			cout << "Вы выбрали не перемешивать :D" << endl;
		}
		Sleep(2000);
	}
}