#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Line {
    double a, b, c; // параметры прямой в виде ax + by + c = 0
};

struct Point {
    double x, y;
};

// Функция для нахождения расстояния от точки до прямой
double distancePointToLine(const Point& p, const Line& l) {
    return std::abs(l.a * p.x + l.b * p.y + l.c) / std::sqrt(l.a * l.a + l.b * l.b);
}

// Функция для нахождения точки пересечения двух прямых
Point intersectionPoint(const Line& l1, const Line& l2) {
    double det = l1.a * l2.b - l2.a * l1.b;
    if (det == 0) {
        std::cerr << "Прямые параллельны или совпадают.\n";
        return { NAN, NAN };
    } else {
        double x = (l2.b * (-l1.c) - l1.b * (-l2.c)) / det;
        double y = (l1.a * (-l2.c) - l2.a * (-l1.c)) / det;
        return { x, y };
    }
}

// Функция для нахождения расстояния между двумя точками
double distanceBetweenPoints(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Функция для нахождения угла между двумя прямыми
double angleBetweenLines(const Line& l1, const Line& l2) {
    double dotProduct = l1.a * l2.a + l1.b * l2.b;
    double magnitude1 = std::sqrt(l1.a * l1.a + l1.b * l1.b);
    double magnitude2 = std::sqrt(l2.a * l2.a + l2.b * l2.b);
    return std::acos(dotProduct / (magnitude1 * magnitude2));
}

int main() {
    std::srand(std::time(0));

    // Определяем случайные параметры для прямых
    Line l1 = { std::rand() % 10 + 1, std::rand() % 10 + 1, std::rand() % 10 + 1 };
    Line l2 = { std::rand() % 10 + 1, std::rand() % 10 + 1, std::rand() % 10 + 1 };

    // Определяем случайные координаты для точки
    Point p = { std::rand() % 10 + 1, std::rand() % 10 + 1 };

    // Вычисление расстояния от точки до каждой прямой
    double distPToL1 = distancePointToLine(p, l1);
    double distPToL2 = distancePointToLine(p, l2);

    // Нахождение точки пересечения прямых
    Point intersection = intersectionPoint(l1, l2);

    // Вычисление расстояния от точки до точки пересечения прямых
    double distPToIntersection = distanceBetweenPoints(p, intersection);

    // Вычисление угла между прямыми
    double angle = angleBetweenLines(l1, l2);

    // Вывод результатов
    std::cout << "Прямая 1: " << l1.a << "x + " << l1.b << "y + " << l1.c << " = 0\n";
    std::cout << "Прямая 2: " << l2.a << "x + " << l2.b << "y + " << l2.c << " = 0\n";
    std::cout << "Точка: (" << p.x << ", " << p.y << ")\n";
    std::cout << "Расстояние от точки до прямой 1: " << distPToL1 << "\n";
    std::cout << "Расстояние от точки до прямой 2: " << distPToL2 << "\n";
    std::cout << "Точка пересечения прямых: (" << intersection.x << ", " << intersection.y << ")\n";
    std::cout << "Расстояние от точки до точки пересечения прямых: " << distPToIntersection << "\n";
    std::cout << "Угол между прямыми: " << angle * 180.0 / M_PI << " градусов\n";

    return 0;
}

