#include <iostream>
#include <iomanip>
#include <list>
#include <locale>

using namespace std;

// Функция для вывода меню и получения выбора пользователя
int showMenu() {
    int choice;
    cout << "\nМеню действий:\n";
    cout << "0 - выход из программы\n";
    cout << "1 - добавить указанный элемент в конец списка\n";
    cout << "2 - удалить последний элемент из списка\n";
    cout << "Выберите действие: ";
    cin >> choice;
    return choice;
}

// Функция для вычитания из каждого числа суммы чисел с использованием итераторов
void subtractSumFromEachElement(list<double>& myList, double sum) {
    for (list<double>::iterator it = myList.begin(); it != myList.end(); ++it) {
        *it -= sum;
    }
}

int main() {
    locale::global(locale("")); // Устанавливаем локаль по умолчанию (UTF-8)

    list<double> resultList; // Используем список для хранения элементов

    int size;
    cout << "Введите размерность исходного списка: ";
    cin >> size;

    cout << "Введите элементы списка через пробел:" << endl;
    for (int i = 0; i < size; ++i) {
        double element;
        cin >> element;
        resultList.push_back(element);
    }

    double sum = 0.0;
    for (const double& element : resultList) {
        sum += element;
    }

    double average = sum / size;

    cout << fixed << setprecision(3); // Устанавливаем фиксированный формат вывода с тремя знаками после запятой

    cout << "Результаты выполнения опытов:" << endl;

    cout << "Размерность исходного списка: " << size << endl;
    cout << "Исходные элементы списка: ";
    for (const double& element : resultList) {
        cout << element << " ";
    }
    cout << endl;

    resultList.push_back(sum);
    resultList.push_back(average);

    int choice;
    do {
        cout << "Результат: ";
        for (const double& element : resultList) {
            cout << fixed << setprecision(3) << element << " ";
        }
        cout << endl;

        choice = showMenu(); // Отображаем меню и получаем выбор пользователя
        switch (choice) {
        case 0:
            cout << "Программа завершена." << endl;
            break;
        case 1:
            double newElement;
            cout << "Введите элемент для добавления в конец списка: ";
            cin >> newElement;
            resultList.push_back(newElement);
            break;
        case 2:
            if (!resultList.empty()) {
                resultList.pop_back(); // Удаляем последний элемент из списка
            }
            else {
                cout << "Список пуст, нельзя удалить элемент." << endl;
            }
            break;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите действие из меню." << endl;
        }
    } while (choice != 0);

    // Вызываем функцию для вычитания суммы из каждого элемента списка
    subtractSumFromEachElement(resultList, sum);

    cout << "Финальный результат после вычитания суммы:" << endl;
    for (const double& element : resultList) {
        cout << fixed << setprecision(3) << element << " ";
    }
    cout << endl;

    return 0;
}
