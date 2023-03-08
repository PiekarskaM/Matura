res=0
dlugosci =[]
rodziny = [[] for _ in range(200)]

for _ in range(2000):
    s = input().rstrip()
    if s==s[::-1]:
        res+=1
        dlugosci.append(len(s))
        rodziny[len(s)].append(s)
print(res)
print(len(set(dlugosci)))
for element in rodziny:
    if len(element)>0:
        t = sorted(element)
        for s in t:
            print(s,end=' ')
        print()
