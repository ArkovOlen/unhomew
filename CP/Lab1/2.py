import math

# Определяем функцию f(x)
def f(x):
    return x * math.exp(x) - x - 1

# Производная функции f(x) для метода Ньютона
def df(x):
    return (x + 1) * math.exp(x) - 1

def bisection_method(f, a, b, epsilon):
    if f(a) * f(b) >= 0:
        print("Неправильный выбор интервала [a, b]")
        return None
    while (b - a) / 2.0 > epsilon:
        midpoint = (a + b) / 2.0
        if f(midpoint) == 0:
            return midpoint
        elif f(a) * f(midpoint) < 0:
            b = midpoint
        else:
            a = midpoint
    return (a + b) / 2.0

def simple_iteration_method(g, x0, epsilon):
    x1 = g(x0)
    while abs(x1 - x0) > epsilon:
        x0 = x1
        x1 = g(x0)
    return x1

def secant_method(f, x0, x1, epsilon):
    while abs(x1 - x0) > epsilon:
        f_x0 = f(x0)
        f_x1 = f(x1)
        x_temp = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0)
        x0 = x1
        x1 = x_temp
    return x1

def newton_method(f, df, x0, epsilon):
    x1 = x0 - f(x0) / df(x0)
    while abs(x1 - x0) > epsilon:
        x0 = x1
        x1 = x0 - f(x0) / df(x0)
    return x1

epsilon = 1e-6

# Дихотомия
root_bisection = bisection_method(f, 0, 1, epsilon)
print(f"Корень (метод дихотомии): {root_bisection}")

# Простая итерация (гарантируем, что выбрано правильное g(x))
g = lambda x: 1 / (math.exp(x) - 1)
root_simple_iteration = simple_iteration_method(g, 0.5, epsilon)
print(f"Корень (метод простой итерации): {root_simple_iteration}")

# Метод хорд
root_secant = secant_method(f, 0, 1, epsilon)
print(f"Корень (метод хорд): {root_secant}")

# Метод Ньютона
root_newton = newton_method(f, df, 0.5, epsilon)
print(f"Корень (метод Ньютона): {root_newton}")
