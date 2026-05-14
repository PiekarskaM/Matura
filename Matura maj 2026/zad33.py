t = [line.split() for line in open('pary.txt')]
#t = [line.split() for line in open('pary_przyklad.txt')]
print('3.3. pary z prefiksem/sufiksem o dlugosci co najmniej 5:')
for s1, s2 in t:
    pref = min(len(s1),len(s2))
    while pref>0:
        if s1[:pref]==s2[-pref:]:
            break
        pref-=1
    if pref>=5:
        print(s1,s2,pref)
        continue
    pref = min(len(s1),len(s2))
    while pref>0:
        if s2[:pref]==s1[-pref:]:
            break
        pref-=1
    if pref>=5:
        print(s1,s2,pref)
  
