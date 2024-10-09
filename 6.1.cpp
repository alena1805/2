#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// Функция для ввода чисел A и B с проверкой
void inputAB(int& A, int& B) {
    std::cout << "Введите целое число A: ";
    while (!(std::cin >> A)) {
        std::cerr << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введите целое число B: ";
    while (!(std::cin >> B)) {
        std::cerr << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Функция для заполнения вектора V1
void fillVectorV1(std::vector<int>& V1, int A, int B) {
    if (V1.size() < 10) {
        std::cerr << "Вектор V1 должен содержать не менее 10 элементов." << std::endl;
        return;
    }
    std::fill(V1.begin(), V1.begin() + 5, A); // Заполнение первых 5 элементов
    std::fill(V1.end() - 5, V1.end(), B); // Заполнение последних 5 элементов
}

// Функция для заполнения вектора V2
void fillVectorV2(std::vector<int>& V2, int A, int B) {
    if (V2.size() < 10) {
        std::cerr << "Вектор V2 должен содержать не менее 10 элементов." << std::endl;
        return;
    }
    std::fill_n(V2.begin(), 5, A); // Заполнение первых 5 элементов
    std::fill_n(V2.end() - 5, 5, B); // Заполнение последних 5 элементов
}

// Функция для вывода вектора
void printVector(const std::vector<int>& vec) {
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Главная функция
int main() {
    int A, B;
    inputAB(A, B); // Ввод A и B

    std::vector<int> V1(10); // Создание вектора V1
    std::vector<int> V2(10); // Создание вектора V2

    fillVectorV1(V1, A, B); // Заполнение V1
    fillVectorV2(V2, A, B); // Заполнение V2

    std::cout << "Вектор V1: ";
    printVector(V1); // Вывод V1

    std::cout << "Вектор V2: ";
    printVector(V2); // Вывод V2

    return 0; // Успешное завершение программы
}
