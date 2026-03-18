edad = int(input("ingrese su edad: "))
ingresos = int(input("ingrese sus ingresos mensuales: "))
if edad > 16 and ingresos >= 1000:
    print("Usted debe tributar")
else:
    print("Usted no debe tributar")
    