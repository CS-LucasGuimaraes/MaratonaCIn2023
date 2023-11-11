input_1 = input()

valores = input_1.split(" ")

soma = int()

for c in range(int(valores[0]), int(valores[1])+1):
    soma += c**2

print(soma)