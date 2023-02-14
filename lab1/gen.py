import random

with open('input.txt', 'w') as f:
    n = random.randint(1e5, 1e6)
    f.write(str(n) + '\n')
    for i in range(n):
        f.write(str(random.randint(0, 1e9 + 1)) + "\n")
    f.write(str(random.randint(1, n)))