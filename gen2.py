import random, string
import sys

def randomname(n):
   randlst = [random.choice(string.ascii_letters + string.digits) for i in range(n)]
   return ''.join(randlst)

k = int(sys.argv[1])
keys = []
for i in range(k) :
    keys.append(randomname(5))
    print(keys[i])
    print(i)
print("")

for key in keys:
    print(key)