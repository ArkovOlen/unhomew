import math

def calculate_a(e, f):
    return (e + f / 2) / 3

def calculate_b(h, g):
    return abs(h**2 - g)

def calculate_c(g, h, e):
    return math.sqrt((g - h)**2 - 3 * math.sin(e))

# Пользовательский ввод данных
e = float(input("Введите значение переменной e: "))
f = float(input("Введите значение переменной f: "))
g = float(input("Введите значение переменной g: "))
h = float(input("Введите значение переменной h: "))

# Вычисление значений функций
a = calculate_a(e, f)
b = calculate_b(h, g)
c = calculate_c(g, h, e)

# Вывод результатов
print(f"Значение функции a: {a}")
print(f"Значение функции b: {b}")
print(f"Значение функции c: {c}")
