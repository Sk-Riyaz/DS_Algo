count = 0
def per(na, nb, nc, out):
    global count
    if na == 0 and nb ==0 and nc == 0:
        count += 1
        print(out)
    
    if na:
        per(na-1, nb, nc, out+"a")
    if nb:
        per(na, nb-1, nc, out+"b")
    if nc:
        per(na, nb, nc-1, out+"c")

per(2,2,2,"")
print(count)
