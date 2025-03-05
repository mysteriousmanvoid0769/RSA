# RSA

Первая функция *_input* считывает строку и записывает цифры из строки в вектор. 

Изначально задаются два простых числа _p_,_q_. Их можно взять из файла `input.txt`.

Вычисляется открытый ключ _n_ при помощи функции *_multiply*:
    
  $$  n = p \cdot q $$

*_multiply* это функция умножения.

Также будет вычисляться _φ_:

  $$  φ = (p - 1) \cdot (q - 1) $$

Вычисляем открытую экспоненту _e_. Числа _e_ и _φ_ должны быть взаимно простыми. Для проверки используется функция _gcd.

Затем, вычисляем закрытую экспоненту _d_. 

   $$ d = \frac{(k \cdot φ + 1)} e $$

Для вычисления _d_ используется функция *calculate_d*.

Вводим строку _m_, которую хотим зашифровать. Записывается с помощью функции *input_char*.

**Важно! Объединение всех целочисленных кодов символов не должно превышать переменной** _n_.

Начинается этап шифрования, вызывается функция *encryption_char*.

  $$ c = m^e \pmod{n} $$


Далее полученный результат, расшифровываем, с помощью функции *decryption_char*.

$$ m = c^d \pmod{n} $$

_m_ должен быть равен введенному сообщению.


## Инструкция для пользователя
1. Введите _p_, _q_ (большие, простые числа). 
2. Введите message.