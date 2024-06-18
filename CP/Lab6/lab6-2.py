import numpy as np
from scipy.optimize import minimize_scalar

# Определение функции f(x)
def func(x):
    x1, x2 = x
    return x1**2 + np.exp(x1**2 + x2**2) + 4*x1 + 3*x2

# Определение градиента функции f(x)
def grad_func(x):
    x1, x2 = x
    grad_x1 = 2*x1 + 2*x1*np.exp(x1**2 + x2**2) + 4
    grad_x2 = 2*x2*np.exp(x1**2 + x2**2) + 3
    return np.array([grad_x1, grad_x2])

# Метод наискорейшего спуска
def steepest_descent(x0, epsilon=1e-6, max_iterations=1000):
    x = np.array(x0, dtype=float)
    iter_count = 0
    
    while iter_count < max_iterations:
        grad = grad_func(x)
        direction = -grad  # Направление наискорейшего спуска
        
        # Оптимизация по направлению спуска
        def objective(alpha):
            return func(x + alpha * direction)
        
        # Поиск оптимального шага
        result = minimize_scalar(objective)
        alpha_opt = result.x
        
        # Обновление текущей точки
        x = x + alpha_opt * direction
        
        # Проверка критерия остановки
        if np.linalg.norm(grad) < epsilon:
            break
        
        iter_count += 1
    
    return x, func(x)

# Начальная точка и запуск метода наискорейшего спуска
x0 = [0, 0]
optimum, min_value = steepest_descent(x0)

print(f"Минимум функции f(x) достигается в точке: {optimum}")
print(f"Значение f(x) в этой точке: {min_value}")
