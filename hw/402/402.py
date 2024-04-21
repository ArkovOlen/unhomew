import math

def calculate_y(x):
    if x > 0:
        return math.sin(x) ** 2  # y = sin^2(x)
    elif x < 0:
        return 1 - 2 * math.sin(x ** 2)  # y = 1 - 2*sin(x^2)
    else:
        return "Значение y не определено для x = 0"

def main():
    try:
        x = float(input("Введите значение переменной x: "))
        y = calculate_y(x)
        if isinstance(y, str):
            print(y)
        else:
            print(f"Значение функции y при x = {x} равно {y}")
    except ValueError:
        print("Ошибка: введите числовое значение для x.")

if __name__ == "__main__":
    main()
