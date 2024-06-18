#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

namespace HyperbolaUtils {
    // Структура для точки
    struct Point {
        double x, y;
    };

    // Функция для проверки принадлежности точки гиперболе
    bool isPointOnHyperbola(const Point& p, double a, double b) {
        return std::abs((p.x * p.x) / (a * a) - (p.y * p.y) / (b * b) - 1) < 1e-6;
    }

    // Функция для вычисления эксцентриситета гиперболы
    double eccentricity(double a, double b) {
        return std::sqrt(1 + (b * b) / (a * a));
    }

    // Функция для нахождения координат фокусов гиперболы
    void fociCoordinates(double a, double b, Point& f1, Point& f2) {
        double c = std::sqrt(a * a + b * b);
        f1 = { c, 0 };
        f2 = { -c, 0 };
    }

    // Функция для вычисления расстояния между директрисами гиперболы
    double distanceBetweenDirectrices(double a, double b) {
        double e = eccentricity(a, b);
        return 2 * a / e;
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Явное приведение типа для std::time(0)

    // Генерация случайных параметров гиперболы
    double a = static_cast<double>(std::rand() % 10 + 1); // Явное приведение типа для std::rand()
    double b = static_cast<double>(std::rand() % 10 + 1); // Явное приведение типа для std::rand()

    // Генерация случайной точки
    HyperbolaUtils::Point p = { static_cast<double>(std::rand() % 21 - 10), static_cast<double>(std::rand() % 21 - 10) }; // Явное приведение типа для std::rand()

    // Проверка принадлежности точки гиперболе
    if (HyperbolaUtils::isPointOnHyperbola(p, a, b)) {
        std::cout << "Точка (" << p.x << ", " << p.y << ") принадлежит гиперболе.\n";
    } else {
        std::cout << "Точка (" << p.x << ", " << p.y << ") не принадлежит гиперболе.\n";
    }

    // Вычисление координат фокусов гиперболы
    HyperbolaUtils::Point f1, f2;
    HyperbolaUtils::fociCoordinates(a, b, f1, f2);
    std::cout << "Координаты фокусов гиперболы: (" << f1.x << ", " << f1.y << ") и (" << f2.x << ", " << f2.y << ")\n";

    // Длины действительной и мнимой полуосей
    std::cout << "Длина действительной полуоси: " << a << "\n";
    std::cout << "Длина мнимой полуоси: " << b << "\n";

    // Вычисление эксцентриситета гиперболы
    double e = HyperbolaUtils::eccentricity(a, b);
    std::cout << "Эксцентриситет гиперболы: " << e << "\n";

    // Вычисление расстояния между директрисами гиперболы
    double distanceDirectrices = HyperbolaUtils::distanceBetweenDirectrices(a, b);
    std::cout << "Расстояние между директрисами гиперболы: " << distanceDirectrices << "\n";

    return 0;
}

