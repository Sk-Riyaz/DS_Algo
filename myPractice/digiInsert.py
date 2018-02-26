T = int(input().strip())
for i in range(0, T):
    n = int(input().strip())
    lst = list(map(int, input().strip().split()))

    valToInsert = lst[n//2]
    if n % 2 == 0:
        valToInsert += lst[n//2-1]
    dupArr = []
    firstNeg = None
    secPos = None
    for index, ele in enumerate(lst):
        if ele == 0:
            dupArr.append(ele)
            if secPos is None:
                secPos = -1
            elif secPos == -1:
                secPos = ele
                continue
            dupArr.append(valToInsert)
        elif ele < 0:
            if firstNeg is None:
                firstNeg = ele
                continue
            dupArr.append(ele)
        elif ele > 0:
            if secPos is None:
                secPos = -1
            elif secPos == -1:
                secPos = ele
                continue
            dupArr.append(ele)

    print(" ".join(map(str, dupArr)))
