def is_prime(num):
    if num <= 1:
        return False
    
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            return False
    
    return True

print("Трехзначные простые числа:")
for i in range(100, 1000):
    if is_prime(i):
        print(i)
