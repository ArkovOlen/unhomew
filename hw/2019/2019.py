import math

def main():
    # Запрашиваем значения переменных
    e = float(input("Введите значение e: "))
    f = float(input("Введите значение f: "))
    g = float(input("Введите значение g: "))
    h = float(input("Введите значение h: "))

    # Вычисляем a, обрабатываем случай деления на 0
    if f == 0:
        print("Ошибка: деление на ноль при расчете 'a'.")
    else:
        a = math.sqrt(abs(e - (3 / f))**3 + g)
        print("a =", a)

    # Вычисляем b
    b = math.sin(e) + math.cos(h)**2
    print("b =", b)

    # Вычисляем c, обрабатываем случай деления на 0
    if e * f - 3 == 0:
        print("Ошибка: деление на ноль при расчете 'c'.")
    else:
        c = (33 * g) / (e * f - 3)
        print("c =", c)

if __name__ == "__main__":
    main()