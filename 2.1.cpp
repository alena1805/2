#include <iostream>
#include <vector>
#include <limits>

// Функция для заполнения вектора целыми числами
void fillVector(std::vector<int>& V) {
    int number;
    std::cout << "Введите целые числа (введите 'q' для завершения ввода):" << std::endl;
    
    // Чтение чисел до тех пор, пока пользователь не введет некорректное значение
    while (std::cin >> number) 
        V.push_back(number);
    
    // Очистка состояния потока и игнорирование некорректного ввода
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Функция для вставки пяти нулей в середину вектора, если его размер четный
void insertZeros(std::vector<int>& V) {
    if (V.size() % 2 == 0) 
        V.insert(V.begin() + V.size() / 2, 5, 0); // Вставка пяти нулей
}

// Функция для вывода элементов вектора
void printVector(const std::vector<int>& V) {
    for (const auto& elem : V) 
        std::cout << elem << " "; // Вывод каждого элемента
    std::cout << std::endl; // Переход на новую строку
}

// Функция для вывода элементов вектора в обратном порядке
void printVectorReverse(const std::vector<int>& V) {
    for (auto it = V.rbegin(); it != V.rend(); ++it) 
        std::cout << *it << " "; // Вывод каждого элемента в обратном порядке
    std::cout << std::endl; // Переход на новую строку
}

// Главная функция программы
int main() {
    std::vector<int> V; // Объявление вектора для хранения целых чисел
    fillVector(V); // Заполнение вектора
    insertZeros(V); // Вставка нулей, если размер четный
    printVector(V); // Вывод вектора
    printVectorReverse(V); // Вывод вектора в обратном порядке
    return 0; // Завершение программы
}
