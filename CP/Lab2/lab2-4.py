import numpy as np

class SecondOrderConic:
    def __init__(self, A, B, C, D, E, F, G, H, I, J):
        self.coefficients = np.array([[A, D/2, E/2],
                                      [D/2, B, F/2],
                                      [E/2, F/2, C]])

    def contains_point(self, point):
        x, y, z = point
        coords = np.array([x, y, z])
        result = np.dot(coords, np.dot(self.coefficients, coords))
        return abs(result) < 1e-6

    def intersects_plane(self, plane_coeffs):
        A, B, C, D = plane_coeffs
        plane_vector = np.array([A, B, C, -D])  # Поправили порядок коэффициентов плоскости
        result = np.dot(plane_vector, np.dot(self.coefficients, plane_vector[:3]))
        return abs(result) < 1e-6

    def intersects_line(self, line_coeffs):
        a, b, c, d, e, f = line_coeffs
        line_vector = np.array([a, b, c])
        result = np.dot(line_vector, np.dot(self.coefficients, line_vector)) + d * a + e * b + f * c
        return abs(result) < 1e-6

# Генерация случайных параметров конуса второго порядка, плоскости и прямой
A, B, C, D, E, F, G, H, I, J = np.random.rand(10) * 10  # случайные параметры от 0 до 10

# Создание объекта конуса второго порядка
conic = SecondOrderConic(A, B, C, D, E, F, G, H, I, J)

# Генерация случайной точки
point = np.random.rand(3) * 20 - 10  # случайные координаты от -10 до 10

# Генерация случайных параметров плоскости
plane_coeffs = np.random.rand(4) * 10  # случайные коэффициенты от 0 до 10

# Генерация случайных параметров прямой
line_coeffs = np.random.rand(6) * 20 - 10  # случайные коэффициенты от -10 до 10

# Проверка принадлежности точки конусу второго порядка
if conic.contains_point(point):
    print(f"Точка {point} принадлежит конусу второго порядка.")
else:
    print(f"Точка {point} не принадлежит конусу второго порядка.")

# Проверка пересечения плоскости с конусом второго порядка
if conic.intersects_plane(plane_coeffs):
    print("Плоскость пересекает конус второго порядка.")
else:
    print("Плоскость не пересекает конус второго порядка.")

# Проверка пересечения прямой с конусом второго порядка
if conic.intersects_line(line_coeffs):
    print("Прямая пересекает конус второго порядка.")
else:
    print("Прямая не пересекает конус второго порядка.")
