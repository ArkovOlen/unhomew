arr = [13, 20, 6, 8, 15, 40, 7, 50, 62, 70]

# Все четные элементы
print("Все четные элементы:", end=" ")
for num in arr:
    if num % 2 == 0:
        print(num, end=" ")

# Все элементы, оканчивающиеся на 0
print("\nВсе элементы, оканчивающиеся на 0:", end=" ")
for num in arr:
    if num % 10 == 0:
        print(num, end=" ")
