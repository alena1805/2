#include <iostream>
#include <string>
#include <limits> // Для std::numeric_limits

// Функция для сравнения двух чисел и формирования строки результата
std::string makeDecision(int x, int y) {
    if (x > y) {
        return std::to_string(x) + " > " + std::to_string(y);
    } else if (x < y) {
        return std::to_string(x) + " < " + std::to_string(y);
    } else {
        return std::to_string(x) + " = " + std::to_string(y);
    }
}

int main() {
    int x, y;

    // Запрашиваем ввод для x
    std::cout << "Введите первое целое число (x): ";
    while (true) {
        std::cin >> x;
        if (std::cin.fail()) {
            std::cin.clear(); // Сбрасываем состояние потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем входной буфер
            std::cout << "Неверный ввод. Пожалуйста, введите целое число: ";
        } else {
            break; // Ввод корректен, выходим из цикла
        }
    }

    // Запрашиваем ввод для y
    std::cout << "Введите второе целое число (y): ";
    while (true) {
        std::cin >> y;
        if (std::cin.fail()) {
            std::cin.clear(); // Сбрасываем состояние потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем входной буфер
            std::cout << "Неверный ввод. Пожалуйста, введите целое число: ";
