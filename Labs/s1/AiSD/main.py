def count(str):
    arr = []
    for i in range(26):
        arr.append( [chr(i+ord('a')),len([c for c in str if c==chr(i+ord('a'))])] )
    arr = [i for i in arr if i[1]!=0]
    arr.sort(key=lambda x:x[1],reverse=1)
    return arr

def fanoShannon(freq):
    srg1 = []
    srg2 = []
    tr=[ [''.join([i[0] for i in freq]) , sum([i[1] for i in freq]) ]]

    if(len(freq)>2):
        min=[9999,-1]
        for i in range(len(freq)//2 +1):
            if( abs(sum([val[1] for idx,val in enumerate(freq) if idx<=i]) - sum([val[1] for idx,val in enumerate(freq) if idx>i])) < min[0]  ):
                min=[abs(sum([val[1] for idx,val in enumerate(freq) if idx<=i]) - sum([val[1] for idx,val in enumerate(freq) if idx>i])),i]

        rg1 = freq[0:min[1]+1]
        rg2 = freq[min[1] + 1:]
        if(sum([i[1] for i in rg1])>sum([i[1] for i in rg2])):
            srg = rg2
            rg2 = rg1
            rg1 = srg
        srg1=fanoShannon(rg1)
        srg2 = fanoShannon(rg2)

        tr.append(srg1)
        tr.append(srg2)
    elif len(freq)==2:
        srg1=freq[0]
        srg2 = freq[1]
        if srg1[1]>srg2[1]:
            srg=srg2
            srg2=srg1
            srg1=srg
        tr.append(srg1)
        tr.append(srg2)
    elif len(freq) ==1:
       tr=tr[0]

    return tr
text = '''we are the champions my friends
and we ll keep on fighting til the end
we are the champions
we are the champions'''

'''   srg=srg2
   srg2=srg1
   srg1=srg
'''

freq = count(text)

tree = fanoShannon(freq)

print(tree)

#print(count(text))


