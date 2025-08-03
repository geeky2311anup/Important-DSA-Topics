for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print('Yes' if sum(a)%2 == 0 and sum(x for x in a if x%2 == 1) else 'No'