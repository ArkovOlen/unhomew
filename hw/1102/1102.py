arr = []

print("Введите 10 значений: ")
for i in range(10):
    arr.append(int(input()))

print("Итоговый массив: ", end="")
for i in range(10):
    print(arr[i], end=" ")
