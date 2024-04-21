import math

def calculate_y(x):
    if x > 0:
        return math.sin(x ** 2)  # y = sin(x^2)
    elif x < 0:
        return 1 + 2 * (math.sin(x) ** 2)  # y = 1 + 2*sin^2(x)
    else:
        # Так как для x = 0 явное условие не задано, можно выбрать любое, например, используя вторую формулу:
        return 1 + 2 * (math.sin(x) ** 2)

def main():
    try:
        x = float(input("Введите значение переменной x: "))
        y = calculate_y(x)
        print(f"Значение функции y при x = {x} равно {y}")
    except ValueError:
        print("Ошибка: введите числовое значение для x.")

if __name__ == "__main__":
    main()
    
