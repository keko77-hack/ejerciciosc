renta = int((input("ingrese su renta mensual: ")))
if renta < 10000:
    impuesto = 5
else:
    if renta >= 10000 and renta <= 20000:
        impuesto = 15
    else:
        if renta >= 20000 and renta <= 35000:
            impuesto = 20
        else:
            if renta >= 35000 and renta <= 60000:
                impuesto = 30
            else:
                if renta > 60000:
                    impuesto = 45
print("tiene que pagar", renta * impuesto / 100,"$")


