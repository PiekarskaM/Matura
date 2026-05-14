#t = [line.split() for line in open('pary_przyklad.txt')]
t = [line.split() for line in open('pary.txt')]

def d(x, s):
    return s.count(x)

def W(x, s1, s2):
    return min(d(x, s1), d(x, s2))


alfabet = 'abcdefghijklmnopqrstuvwxyz'
max_sum = 0
best_pair = None
for s1, s2 in t:
    sum = 0
    for z in alfabet:
        sum += W(z, s1, s2)
    if sum > max_sum:
        max_sum = sum
        best_pair = (s1, s2)
print(f'3.2. najlepsza para: {best_pair}, suma: {max_sum}')   

