#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void inputVector(std::vector<int>& vec) {
    int n;
    while (true) {
        std::cout << "Введите количество элементов (четное число): ";
        std::cin >> n;

        // Проверка на четность и корректность ввода
        if (std::cin.fail() || n <= 0 || n % 2 != 0) {
            std::cout << "Ошибка ввода. Пожалуйста, введите положительное четное число." << std::endl;
            std::cin.clear(); // Сброс состояния потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорирование некорректного ввода
        } else {
            break; // Успешный ввод
        }
    }

    vec.resize(n);
    std::cout << "Введите элементы вектора:\n";
    
    for (int i = 0; i < n; ++i) {
        while (true) {
            std::cout << "Элемент " << i + 1 << ": ";
            if (std::cin >> vec[i]) {
                break; // Успешный ввод
            } else {
                std::cout << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
                std::cin.clear(); // Сброс состояния потока
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорирование некорректного ввода
            }
        }
    }
}

void addZeroBeforeMatching(std::vector<int>& vec) {
    int halfSize = vec.size() / 2;
    
    std::vector<int> firstHalf(vec.begin(), vec.begin() + halfSize);
    std::vector<int> secondHalf(vec.begin() + halfSize, vec.end());

    auto it = std::find_first_of(firstHalf.begin(), firstHalf.end(), secondHalf.begin(), secondHalf.end());

    if (it != firstHalf.end()) {
        vec.insert(vec.begin() + (it - firstHalf.begin()), 0);
    }
}

void printVector(const std::vector<int>& vec) {
    std::cout << "Вектор: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;

    inputVector(vec); // Ввод вектора
    addZeroBeforeMatching(vec); // Обработка вектора
    printVector(vec); // Вывод результата

    return 0;
}
