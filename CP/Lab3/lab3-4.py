import math

def series_sum(x, epsilon=1e-6):
    sum_value = 0.0
    k = 1
    term = 1.0  # начальное значение для входа в цикл
    
    while abs(term) > epsilon:
        term = (-1)**k / (math.sin(k*x) + 4 + k**2)
        sum_value += term
        k += 1
    
    return sum_value

# Пример использования:
x = 1.0
result = series_sum(x)
print(f"Сумма ряда для x = {x}: {result}")
