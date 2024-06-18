import numpy as np

# Определение прямой в пространстве с помощью точки и направляющего вектора
class Line:
    def __init__(self, point, direction):
        self.point = np.array(point)
        self.direction = np.array(direction)

# Функция для вычисления угла между двумя прямыми в радианах
def angle_between_lines(l1, l2):
    dot_product = np.dot(l1.direction, l2.direction)
    magnitude1 = np.linalg.norm(l1.direction)
    magnitude2 = np.linalg.norm(l2.direction)
    return np.arccos(dot_product / (magnitude1 * magnitude2))

# Функция для проверки параллельности двух прямых
def are_parallel(l1, l2):
    cross_product = np.cross(l1.direction, l2.direction)
    return np.allclose(cross_product, [0, 0, 0])

# Функция для вычисления расстояния между двумя параллельными прямыми
def distance_between_parallel_lines(l1, l2):
    diff = l2.point - l1.point
    cross_product = np.cross(diff, l1.direction)
    magnitude_dir = np.linalg.norm(l1.direction)
    return np.linalg.norm(cross_product) / magnitude_dir

# Функция для вычисления расстояния от точки до прямой
def distance_point_to_line(p, l):
    diff = np.array(p) - l.point
    cross_product = np.cross(diff, l.direction)
    magnitude_dir = np.linalg.norm(l.direction)
    return np.linalg.norm(cross_product) / magnitude_dir

# Функция для нахождения точки пересечения двух прямых
def intersection_point(l1, l2):
    A = np.array([l1.direction, -l2.direction]).T
    b = l2.point - l1.point
    try:
        t1, t2 = np.linalg.solve(A, b)
        intersection = l1.point + t1 * l1.direction
        return intersection
    except np.linalg.LinAlgError:
        print("Прямые параллельны или совпадают.")
        return None

# Генерация случайных параметров для прямых и точки
np.random.seed(0)
l1 = Line(point=np.random.randint(1, 11, size=3), direction=np.random.randint(1, 11, size=3))
l2 = Line(point=np.random.randint(1, 11, size=3), direction=np.random.randint(1, 11, size=3))
p = np.random.randint(1, 11, size=3)

# Вычисление угла между прямыми
angle = angle_between_lines(l1, l2)
print(f"Угол между прямыми: {np.degrees(angle)} градусов")

# Проверка параллельности
if are_parallel(l1, l2):
    print("Прямые параллельны.")
    # Вычисление расстояния между параллельными прямыми
    distance_parallel = distance_between_parallel_lines(l1, l2)
    print(f"Расстояние между параллельными прямыми: {distance_parallel}")
else:
    print("Прямые не параллельны.")
    # Нахождение точки пересечения прямых
    intersection = intersection_point(l1, l2)
    if intersection is not None:
        print(f"Точка пересечения прямых: {intersection}")
        # Вычисление расстояния от точки до точки пересечения прямых
        distance_to_intersection = np.linalg.norm(p - intersection)
        print(f"Расстояние от заданной точки до точки пересечения прямых: {distance_to_intersection}")

# Вычисление расстояния от точки до каждой прямой
distance_p_to_l1 = distance_point_to_line(p, l1)
distance_p_to_l2 = distance_point_to_line(p, l2)
print(f"Расстояние от точки до прямой 1: {distance_p_to_l1}")
print(f"Расстояние от точки до прямой 2: {distance_p_to_l2}")
