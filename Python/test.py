def get_sort_key(item):
    return -item[1], item[0]

from collections import Counter

# arr = list(map(int, input().split(',')))

arr = [4,2,4,4,2,1,1]

freq = Counter(arr).items()
freq2 = Counter(arr)

print(freq)
print(freq2)

# ans = [num for num, _ in sorted(freq.items(), key=get_sort_key)]

# print(ans)