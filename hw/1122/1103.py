arr = [0, -5, 30, 80, -2, 120, 50, 0, 90, 145, -9]

print("Все неотрицательные элементы:")
for num in arr:
    if num >= 0:
        print(num, end=" ")

print("\nВсе элементы, не превышающие 100:")
for num in arr:
    if num <= 100:
        print(num, end=" ")
