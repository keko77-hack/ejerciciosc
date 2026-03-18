puntuacion = float(input("ingrese la puntuacion: "))
if puntuacion == 0.0:
    a = "su rendimiento fue inaceptable"
else:
    if puntuacion == 0.4:
        a = puntuacion * 2400
        b = "su rendimiento fue aceptable"
    else:
        if puntuacion >= 0.6:
            a = puntuacion * 2400
            b = "su rendimiento fue meritorio"
print(b, ", ademas recibira", a, "$")

