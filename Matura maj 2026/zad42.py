t = [int(x) for x in open('korpo.txt')]
#t = [int(x) for x in open('korpo_przyklad.txt')]
n = len(t)

counter = 0
for p in range(1, n+1):
    if p not in t:
        counter+=1
print(f'4.2. ilosc pracownikow, ktorzy nie sa przelozonymi: {counter}')

