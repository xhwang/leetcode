import random


for s in range(20):

    num = random.randint(1, 10)

    rel = []
    for i in range(num):
        rel.append(random.randint(2, 1000))

    print(rel)
