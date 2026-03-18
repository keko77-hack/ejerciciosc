nombre = input("ingresa tu nombre: ")
genero = input("ingresa tu genero (F O M): ")

if genero == "M":
    if nombre.lower() < "m":
        grupo = "A"
    else:
        grupo = "B"
else:
    if nombre.lower() > "n":
        grupo = "A"
    else:
        grupo = "B"
print("tu grupo es", (grupo))
