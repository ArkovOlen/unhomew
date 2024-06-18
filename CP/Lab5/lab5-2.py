import numpy as np

# Заданные точки x_i
p = np.pi
x = np.array([0.1 * p, 0.2 * p, 0.3 * p, 0.4 * p])
# Вычисление соответствующих значений y_i = sin(x_i)
y = np.sin(x)

# Функция для вычисления интерполяционного многочлена Лагранжа
def lagrange_interpolation(x, y, x_interp):
    n = len(x)
    p_interp = 0.0
    
    for i in range(n):
        # Вычисляем базисный полином Лагранжа
        l = np.prod([(x_interp - x[j]) / (x[i] - x[j]) for j in range(n) if j != i])
        # Суммируем члены многочлена Лагранжа
        p_interp += y[i] * l
    
    return p_interp

# Точка, в которой мы хотим вычислить погрешность интерполяции
x_star = 0.25 * p

# Вычисляем значение интерполяционного многочлена Лагранжа в точке x_star
p_x_star = lagrange_interpolation(x, y, x_star)

# Вычисляем значение функции sin(x_star)
sin_x_star = np.sin(x_star)

# Вычисляем погрешность интерполяции в точке x_star
error = np.abs(sin_x_star - p_x_star)

print(f"Значение интерполяционного многочлена в точке x* = {x_star}: {p_x_star}")
print(f"Значение sin(x*) = {sin_x_star}")
print(f"Погрешность интерполяции в точке x* = {x_star}: {error}")
