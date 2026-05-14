t = [int(x) for x in open('korpo.txt')]
#t = [int(x) for x in open('korpo_przyklad.txt')]
n = len(t)
t = [0] + t
tab = [0 for i in range(0,n+1)]
for i in range(1,n+1):
    p = i
    counter = 0
    while p!=0:
        p = t[p]
        if p!=0:
            counter+=1
    #print(i, counter)
    tab[i] = counter
najwiecej = max(tab)
ilu = tab.count(najwiecej)
print(f'4.4. \nnajwiecej przelozonych to: {najwiecej} ma tylu przelozonych: {ilu} pracownikow')

