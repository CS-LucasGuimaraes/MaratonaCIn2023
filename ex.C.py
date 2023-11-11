n = int(input())
tamanhos = input()
lista_str = tamanhos.split()
lista = []

for valores in lista_str:
    lista.append(int(valores))

lista.sort()
# print(lista)

max = (int(lista[0])+int(lista[-1]))
lista.pop(0)
lista.pop()

# print(lista)

min = (int(lista[0])+int(lista[-1]))

for c in range(0, int(len(lista)/2)):
    if int(lista[c]) + int(lista[-(1+c)]) > min:
        min = int(lista[c]) + int(lista[-(1+c)])

print(max-min)