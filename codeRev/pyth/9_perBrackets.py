count = 0
def per(no, nc, out):
    global count
    if no == 0 and nc == 0:
        count += 1
        print(out)

    if no:
        per(no-1, nc, out+"{")

    if nc - no > 0:
        per(no, nc-1, out+"}")

per(2,2,"")
print(count)
