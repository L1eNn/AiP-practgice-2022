#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

void displayArray(vector<int> v) {
    for (int num : v) {
        cout << num << ' ';
    }
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    vector<int> numbers = { 5, 38, 7, 23, -8, 35, 0, -16, 3, 70, -9, 7 };

    cout << "Изначальный вектор: " << endl;
    displayArray(numbers);

    sort(numbers.begin(), numbers.end());

    cout << "Отсортированный вектор: " << endl;
    displayArray(numbers);

    vector<int>::iterator maxElement = max_element(numbers.begin(), numbers.end());
    vector<int>::iterator minElemnt = min_element(numbers.begin(), numbers.end());

    swap(*minElemnt, *maxElement);

    cout << "Вектор в котором максимальный и минимальный элемент поменялись местами: " << endl;
    displayArray(numbers);

    remove(numbers.begin(), numbers.end(), 70);
    numbers.resize(11);

    cout << "Вектор с удаленным максимальным элементом: " << endl;
    displayArray(numbers);

    reverse(numbers.begin(), numbers.end());

    cout << "Перевернутый вектор: " << endl;
    displayArray(numbers);
}
