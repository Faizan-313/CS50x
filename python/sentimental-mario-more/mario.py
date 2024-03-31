while True:
    try:
        height = int(input("Height: "))
        if height > 8 or height < 1:
            continue
        else:
            break
    except ValueError:
        continue
c = 0
r = 0
for c in range(height):
    for r in range(height - (c + 1)):
        print(" ", end="")
        r += 1
    for i in range(c + 1):
        print("#", end="")
        i += 1
    c += 1
    print("  ", end="")
    for r in range(c):
        print("#", end="")
        r += 1
    c += 1
    print()
