import math

# Функция для вычисления подынтегральной функции
def f(x):
    return math.exp(-2*x) * math.sin(4*x)

# Метод прямоугольников
def rectangle_method(a, b, n):
    h = (b - a) / n
    integral = 0.0
    for i in range(n):
        x = a + (i + 0.5) * h  # середина интервала
        integral += f(x)
    integral *= h
    return integral

# Метод трапеций
def trapezoid_method(a, b, n):
    h = (b - a) / n
    integral = 0.5 * (f(a) + f(b))  # сумма в крайних точках
    for i in range(1, n):
        x = a + i * h
        integral += f(x)
    integral *= h
    return integral

# Метод Симпсона (парабол)
def simpson_method(a, b, n):
    h = (b - a) / n
    integral = f(a) + f(b)  # сумма в крайних точках
    for i in range(1, n):
        x = a + i * h
        if i % 2 == 0:
            integral += 2 * f(x)
        else:
            integral += 4 * f(x)
    integral *= h / 3.0
    return integral

# Точность до которой нужно найти значение интеграла
epsilon = 1e-6

# Пределы интегрирования
a = 0.0
b = 1.0

# Начальное количество интервалов
n = 1

# Вычисление интеграла методом прямоугольников
prev_rect = rectangle_method(a, b, n)
curr_rect = rectangle_method(a, b, 2 * n)
while abs(curr_rect - prev_rect) > epsilon:
    prev_rect = curr_rect
    n *= 2
    curr_rect = rectangle_method(a, b, 2 * n)

# Вычисление интеграла методом трапеций
n = 1
prev_trap = trapezoid_method(a, b, n)
curr_trap = trapezoid_method(a, b, 2 * n)
while abs(curr_trap - prev_trap) > epsilon:
    prev_trap = curr_trap
    n *= 2
    curr_trap = trapezoid_method(a, b, 2 * n)

# Вычисление интеграла методом Симпсона
n = 1
prev_simpson = simpson_method(a, b, n)
curr_simpson = simpson_method(a, b, 2 * n)
while abs(curr_simpson - prev_simpson) > epsilon:
    prev_simpson = curr_simpson
    n *= 2
    curr_simpson = simpson_method(a, b, 2 * n)

# Вывод результатов
print(f"Метод прямоугольников: {curr_rect}")
print(f"Метод трапеций: {curr_trap}")
print(f"Метод Симпсона: {curr_simpson}")

