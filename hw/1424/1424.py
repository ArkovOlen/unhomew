def is_prime(num):
    if num <= 1:
        return False
    
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            return False
    
    return True

print("Пары чисел-близнецов:")
for i in range(2, 200):
    if is_prime(i) and is_prime(i+2):
        print(i, "и", i+2)
