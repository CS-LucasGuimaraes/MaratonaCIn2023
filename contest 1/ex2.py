test_cases = int(input())


for i in range(0, test_cases):

    flag= False

    n = int(input())

    if n % 2 == 1:
        print("YES")
        continue
    
    for c in range(3, int(n/2), 2):
        if n%c == 0:
            print("YES")
            flag=True
            break
    if not flag:
        print("NO")
