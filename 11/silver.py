stones = input().split()
iterations =  int(input("how many iterations"))

for x in range(iterations):
    next_iter=[]
    for stone in stones:
        if int(stone) == 0:
            next_iter.append("1")
        elif len(stone) % 2 == 0:
            left_stone = int(stone[:len(stone)//2])
            right_stone = int(stone[len(stone)//2:])
            next_iter.append(str(left_stone))
            next_iter.append(str(right_stone))
        else:
            next_iter.append(str(int(stone)*2024))
    stones = next_iter
    print("AFTER " + str(x+1)  + " ITERATIONS")
    print(len(stones))
    print()


print(len(stones))

