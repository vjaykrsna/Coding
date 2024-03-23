import heapq

def process_data(n, nums, x, y):
    pq = []
    for i in range(n):
        heapq.heappush(pq, (-y[i], x[i]))

    total = 0
    for _ in range(nums):
        priority, value = heapq.heappop(pq)
        total += value

    return total

if "__name__"=="__main__":
    n = int(input())
    x = []
    y = []
    for _ in range(n):
        x_val, y_val = map(int, input().split())
        x.append(x_val)
        y.append(y_val)
    nums = int(input())
    result = process_data(n, nums, x, y)
    print(result)