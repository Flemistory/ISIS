﻿#include <iostream>
#include <cmath>
using namespace std;

class Poligon {
protected:
    int* x = 0;
    int* y = 0;
    int size;

public:
    Poligon() {
        // Вводим количество вершин многоугольника
        cin >> size;
        x = new int[size];
        y = new int[size];

        // Вводим координаты x для каждой вершины
        cout << "Enter x-coordinates: ";
        for (int i = 0; i < size; i++) {
            cin >> x[i];
        }

        // Вводим координаты y для каждой вершины
        cout << "Enter y-coordinates: ";
        for (int i = 0; i < size; i++) {
            cin >> y[i];
        }
    }

    double calculateS() {
        // Вычисляем площадь многоугольника по координатам вершин
        double polygon = 0;
        for (int i = 0; i < size - 1; i++) {
            polygon += ((x[i] - x[i + 1]) * (y[i] + y[i + 1])) / 2.0;
        }
        polygon += ((x[size - 1] - x[0]) * (y[size - 1] + y[0])) / 2.0;
        polygon = abs(polygon);
        return polygon;
    }

    float calculateP() {
        // Вычисляем периметр многоугольника как сумму длин его сторон
        double perimeter = 0;
        for (int i = 0; i < size - 1; i++) {
            perimeter += sqrt(pow((x[i + 1] - x[i]), 2) + pow((y[i + 1] - y[i]), 2));
        }
        perimeter += sqrt(pow((x[size - 1] - x[0]), 2) + pow((y[size - 1] - y[0]), 2));
        return static_cast<float>(perimeter);
    }

    void print() {
        // Выводим координаты вершин, периметр и площадь многоугольника
        cout << "Abscissa: ";
        for (int i = 0; i < size; i++) {
            cout << x[i] << " ";
        }

        cout << "Ordinata: ";
        for (int i = 0; i < size; i++) {
            cout << y[i] << " ";
        }

        cout << "Perimeter = " << calculateP() << " Area = " << calculateS() << endl;
    }

    friend bool operator^(Poligon p1, Poligon p2) {
        bool A = false, B = false, C = false, D = false;
        bool intersection = false;

        // Проверяем пересечение двух многоугольников
        for (int i = 0; i < p1.size; i++) {
            for (int j = 0; j < p2.size; j++) {
                if (p1.x[i] < p2.x[j])
                    A = true;
                if (p1.x[i] > p2.x[j])
                    B = true;
                if (p1.y[i] > p2.y[j])
                    C = true;
                if (p1.y[i] < p2.y[j])
                    D = true;
            }
            if (A && B && D && C)
                intersection = true;
            A = false;
            B = false;
            C = false;
            D = false;
        }
        return intersection;
    }
};

int main() {
    Poligon p1;
    Poligon p2;

    cout << "Polygon 1: ";
    p1.print();

    cout << "Polygon 2: ";
    p2.print();

    bool fol = p1 ^ p2;
    if (fol == true) {
        cout << "Polygon 1 intersects Polygon 2" << endl;
    }
    else {
        cout << "Polygon 1 does not intersect Polygon 2" << endl;
    }

    return 0;
}
