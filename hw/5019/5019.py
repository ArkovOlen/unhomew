while True:
    print("Меню:")
    print("1. Найти среднее арифметическое всех целых чисел от 1 до 750")
    print("2. Найти среднее арифметическое всех целых чисел от 150 до b (b >= 150)")
    print("3. Найти среднее арифметическое всех целых чисел от a до 200 (a <= 200)")
    print("4. Найти среднее арифметическое всех целых чисел от a до b (b >= a)")
    print("5. Выход")

    choice = input("Введите ваш выбор: ")

    if choice == "1":
        sum = 0
        for i in range(1, 751):
            sum += i
        average = sum / 750.0
        print("Среднее значение:", average)
        
    elif choice == "2":
        b = int(input("Введите значение b (b >= 150): "))
        if b < 150:
            print("Недопустимое значение b, попробуйте снова.")
        else:
            sum = 0
            for i in range(150, b + 1):
                sum += i
            average = sum / (b - 150 + 1.0)
            print("Среднее значение:", average)
            
    elif choice == "3":
        a = int(input("Введите значение a (a <= 200): "))
        if a > 200:
            print("Недопустимое значение a, попробуйте снова.")
        else:
            sum = 0
            for i in range(a, 201):
                sum += i
            average = sum / (200 - a + 1.0)
            print("Среднее значение:", average)
            
    elif choice == "4":
        a = int(input("Введите значение a: "))
        b = int(input("Введите значение b (b >= a): "))
        if b < a:
            print("Недопустимые значения a и b, попробуйте снова.")
        else:
            sum = 0
            for i in range(a, b + 1):
                sum += i
            average = sum / (b - a + 1.0)
            print("Среднее значение:", average)
            
    elif choice == "5":
        print("Выход из программы...")
        break
        
    else:
        print("Недопустимый выбор, попробуйте снова.")
