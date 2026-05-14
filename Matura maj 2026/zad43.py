from collections import Counter

t = [int(x) for x in open('korpo.txt')]
#t = [int(x) for x in open('korpo_przyklad.txt')]
n = len(t)

licznik = Counter(t)
najczestszy = licznik.most_common(1)
print(f"4.3. Najczęstszy: {najczestszy}") 

