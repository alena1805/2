#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <limits>

// Функция для ввода целых чисел в вектор
void inputNumbers(std::vector<int>& numbers) {
    int number;
    std::cout << "Введите целые числа (введите 'q' для завершения ввода):" << std::endl;
    while (std::cin >> number) {
        numbers.push_back(number);
    }
    std::cin.clear(); // Сброс состояния потока ввода
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорирование оставшегося ввода
}

// Функция для записи чисел в файл с заменой 0 на 10 и добавлением пробелов
void writeToFile(const std::string& name, const std::vector<int>& numbers) {
    std::ofstream outFile(name);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    // Использование std::replace_copy для замены 0 на 10
    std::transform(numbers.begin(), numbers.end(), std::ostream_iterator<int>(outFile, "  "), 
                   [](int n) { return n == 0 ? 10 : n; });

    outFile.close(); // Закрытие файла
}

// Главная функция
int main() {
    std::string name;
    std::cout << "Введите имя файла (без расширения): ";
    std::cin >> name;
    name += ".txt"; // Добавление расширения .txt

    std::vector<int> numbers; // Вектор для хранения чисел
    inputNumbers(numbers); // Ввод чисел

    writeToFile(name, numbers); // Запись чисел в файл

    std::cout << "Числа записаны в файл " << name << std::endl;

    return 0; // Успешное завершение программы
}
