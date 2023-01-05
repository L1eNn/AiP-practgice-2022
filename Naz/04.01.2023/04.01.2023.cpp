#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

void displayArray(array<int, 12> v) {
    for (int num : v) {
        cout << num << ' ';
    }
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    array<int, 12> numbers = { 5, 38, 7, 23, -8, 35, 0, -16, 3, 70, -9, 7 };

    cout << "Изначальный вектор: " << endl;
    displayArray(numbers);

    sort(numbers.begin(), numbers.end());

    cout << "Отсортированный вектор: " << endl;
    displayArray(numbers);

    array<int, 12>::iterator maxElement = max_element(numbers.begin(), numbers.end());
    array<int, 12>::iterator minElemnt = min_element(numbers.begin(), numbers.end());

    swap(*minElemnt, *maxElement);

    cout << "Вектор в котором максимальный и минимальный элемент поменялись местами: " << endl;
    displayArray(numbers);

    remove(numbers.begin(), numbers.end(), 70);

    cout << "Вектор с удаленным максимальным элементом: " << endl;
    displayArray(numbers);

    reverse(numbers.begin(), numbers.end());

    cout << "Перевернутый вектор: " << endl;
    displayArray(numbers);
}
