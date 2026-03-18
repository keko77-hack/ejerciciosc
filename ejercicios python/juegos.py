edad = int(input("ingrese su edad: "))
if edad < 4:
    precio = "entrada gratis"
else:
    if edad >= 4 and edad <= 18:
        precio = "debera pagar 5$"
    else:
        if edad > 18:
            precio = "debra pagar 10$"
print(precio)
