arr = [3, -5, 8, 0, -2, 7, -4]

# Выводим неотрицательные элементы
print("Неотрицательные элементы:", end=' ')
for num in arr:
    if num >= 0:
        print(num, end=' ')

print()

# Выводим отрицательные элементы
print("Отрицательные элементы:", end=' ')
for num in arr:
    if num < 0:
        print(num, end=' ')
