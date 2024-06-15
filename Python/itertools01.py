import itertools;
"""
itertools functions:
    : count
    : cycle
    : repeat

"""
# counter = itertools.count(1,1)
# print(type(counter))
# for i in counter:
#     print(i,end=' ')
#     if i>20:
#         break
l = [3,5,2]
permutation = itertools.permutations(l)
for perm in permutation:
    print(*perm)