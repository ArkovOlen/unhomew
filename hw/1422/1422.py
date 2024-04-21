import math

# Функция для проверки числа на простоту
def is_prime(num):
    if num <= 1:
        return False
    
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    
    return True

n = int(input("Введите количество чисел: "))
count = 0

for i in range(n):
    num = int(input(f"Введите число {i+1}: "))
    
    # Проверяем, является ли число степенью пятерки
    if num > 0 and math.log(num, 5).is_integer():
        count += 1

print(f"Количество чисел, являющихся степенями пятерки: {count}")
