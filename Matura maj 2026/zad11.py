licznik = 0
def A(m,n):
    
    global licznik
    licznik += 1
    print(f'{m},{n}')

    if n == 1:
        return m
    elif n > 1 and n%2==0:
        return A(2*m,n//2)
    elif n > 1 and n%2==1:
        return A(m,(n-1)//2)

licznik = 0
A(2**5,2**5)
print(f'liczba wywolan: {licznik-1}\n')

licznik = 0
A(10,15)
print(f'liczba wywolan: {licznik-1}\n')

licznik = 0
A(1,2**100+1)
print(f'liczba wywolan: {licznik-1}\n')

