#include <iostream>
#include <iomanip>
#include <list>
#include <locale>

int showMenu() {
    int choice;
    std::cout << "\nМеню действий:\n";
    std::cout << "0 - выход из программы\n";
    std::cout << "1 - добавить указанный элемент в конец списка\n";
    std::cout << "2 - удалить последний элемент из списка\n";
    std::cout << "Выберите действие: ";
    std::cin >> choice;
    return choice;
}

void subtractSumFromEachElement(std::list<double>& myList, double sum) {
    for (std::list<double>::iterator it = myList.begin(); it != myList.end(); ++it) {
        *it -= sum;
    }
}

int main() {
    std::locale::global(std::locale("")); // Устанавливаем локаль по умолчанию (UTF-8)

    std::list<double> resultList;

    int size;
    std::cout << "Введите размерность исходного списка: ";
    std::cin >> size;

    std::cout << "Введите элементы списка через пробел:" << std::endl;
    for (int i = 0; i < size; ++i) {
        double element;
        std::cin >> element;
        resultList.push_back(element);
    }

    double sum = 0.0;
    for (const double& element : resultList) {
        sum += element;
    }

    double average = sum / size;

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "Результаты выполнения опытов:" << std::endl;

    std::cout << "Размерность исходного списка: " << size << std::endl;
    std::cout << "Исходные элементы списка: ";
    for (const double& element : resultList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    resultList.push_back(sum);
    resultList.push_back(average);

    int choice;
    do {
        std::cout << "Результат: ";
        for (const double& element : resultList) {
            std::cout << std::fixed << std::setprecision(3) << element << " ";
        }
        std::cout << std::endl;

        choice = showMenu();
        switch (choice) {
            case 0:
                std::cout << "Программа завершена." << std::endl;
                break;
            case 1:
                double newElement;
                std::cout << "Введите элемент для добавления в конец списка: ";
                std::cin >> newElement;
                resultList.push_back(newElement);
                break;
            case 2:
                if (!resultList.empty()) {
                    resultList.pop_back();
                } else {
                    std::cout << "Список пуст, нельзя удалить элемент." << std::endl;
                }
                break;
            default:
                std::cout << "Некорректный выбор. Пожалуйста, выберите действие из меню." << std::endl;
        }
    } while (choice != 0);

    subtractSumFromEachElement(resultList, sum);

    std::cout << "Финальный результат после вычитания суммы:" << std::endl;
    for (const double& element : resultList) {
        std::cout << std::fixed << std::setprecision(3) << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
