a = str(input("")).upper()
list = []
unique_list= []
impar = 0
meio = int()

for c in range(0, len(a)):
    list.append(a[c])

list.sort()
# print(list)
    
unique_dict = dict.fromkeys(list)

for key, value in unique_dict.items():
    unique_list.append(key)
    unique_list.append(list.count(key))

# print(unique_list)

for c in range(1, int(len(unique_list)), 2):
    if unique_list[c] % 2 != 0:
        impar += 1

if impar > 1:
    print('NO SOLUTION')
else:

    for c in range(1, int(len(unique_list)), 2):
        if unique_list[c] % 2 != 0:
            meio = unique_list[c-1]
        else:
            for i in range(int(unique_list[c]/2)):
                print('{}'.format(unique_list[c-1]),end='')
    if impar != 0:
        print(meio,end='')
    for c in range(int(len(unique_list)-1), 0, -2):
        if unique_list[c] % 2 != 0:
            meio = unique_list[c-1]
        else:
            for i in range(int(unique_list[c]/2)):
                print('{}'.format(unique_list[c-1]),end='')
