def lectura():
    operacion = float(input("Ingrese la operacion: 1 = suma / 0 = producto "))
    x1 = float(input("Ingrese coordenada punto x1: "))
    x2 = float(input("Ingrese coordenada punto x2: "))
    y1 = float(input("Ingrese coordenada punto y1: "))
    y2 = float(input("Ingrese coordenada punto y2: "))
    z1 = float(input("Ingrese coordenada punto z1: "))
    z2 = float(input("Ingrese coordenada punto z2: "))
    return[x1, y1, z1, x2, y2, z2, operacion]
    

def suma_producto():
    if datos[6] == "0":
        escalarx = datos[0]*datos[3]
        escalary = datos[1]*datos[4]
        escalarz = datos[2]*datos[5]
        return escalarx, escalary, escalarz
    else:
        sumax = datos[0]+datos[3]
        sumay = datos[1]+datos[4]
        sumaz = datos[2]+datos[5]
        return sumax, sumay, sumaz

def muestra_resultados(suma_producto):
    print(suma_producto)



if __name__ == "__main__":
    datos = lectura()
    muestra_resultados(datos)


    








