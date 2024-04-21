import random

size = 15
arr1 = [random.uniform(22, 23) for _ in range(size)]
arr2 = [random.uniform(0, 10) for _ in range(size)]
arr3 = [random.uniform(-50, 50) for _ in range(size)]
arr4 = [random.randint(0, 10) for _ in range(size)]

print("Массив 1:", arr1)
print("Массив 2:", arr2)
print("Массив 3:", arr3)
print("Массив 4:", arr4)


