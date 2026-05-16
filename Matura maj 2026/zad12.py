
def A(m,n):
    if n == 1:
        return m
    elif n > 1 and n%2==0:
        return A(2*m,n//2)
    elif n > 1 and n%2==1:
        return 2*A(m,(n-1)//2)+m




print(A(1,777))
print(A(2*(10**6),256*(10**6)))
print()



