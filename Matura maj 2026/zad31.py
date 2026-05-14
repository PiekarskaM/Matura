#t = [line.split() for line in open('pary_przyklad.txt')]
t = [line.split() for line in open('pary.txt')]

def ascii(slowo):
    s = 0
    for c in slowo:
        s += ord(c)
    return s

def f(s1,s2):
    n = ascii(s1) - ascii(s2)
    if n<0: 
        n = -n
    return (n, s1, s2)

tab = []
for s1, s2 in t:
    tab.append(f(s1,s2))

print(f'3.1. {max(tab)}')