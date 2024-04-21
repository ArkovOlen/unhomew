arr = [12, 45, 100, 78, 952, 6, 333, 777, 222, 1010, 1, 7]

# Двузначные числа
print("Двузначные числа:", end=" ")
for num in arr:
    if 10 <= num < 100:
        print(num, end=" ")
print()

# Трехзначные числа
print("Трехзначные числа:", end=" ")
for num in arr:
    if 100 <= num < 1000:
        print(num, end=" ")
print()
