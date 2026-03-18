def lectura():
    gluco = float(input("nivel de glucosa: "))
    edad = int(input("ingrese la edad: "))
    genero = input("0 masculino, 1 femenino: ")
    return[gluco, edad, genero]

def analisis (datos):
    if datos[1] > 19:
        if datos[2] == "0":
            if datos[0] >= 70 and datos[0] < 150:
                resultado = "nivel normal"
            else:
                if datos[0] > 150:
                    resultado = "Positivo (nivel sobre rango)"
                else:
                    if datos[0] < 70:
                        resultado = "Negativo (nivel bajo rango)"
    if datos[1] > 19:
        if datos[2] == "1":
            if datos[0] >= 70 and datos[0] < 140:
                resultado = "nivel normal"
            else:
                if datos[0] > 140:
                    resultado = "Positivo (nivel sobre rango)"
                else:
                    if datos[0] < 70:
                        resultado = "Negativo (nivel bajo rango)"
    if datos[1] > 12 and datos[1] <= 19:
        if datos[0] >= 70 and datos[0] < 120:
                resultado = "nivel normal"
        else:
                if datos[0] > 120:
                    resultado = "Positivo (nivel sobre rango)"
                else:
                        if datos[0] < 70:
                           resultado = "Negativo (nivel bajo rango)"
    if datos[1] > 5 and datos[1] <= 12:
        if datos[0] >= 70 and datos[0] < 130:
                resultado = "nivel normal"
        else:
                if datos[0] > 130:
                    resultado = "Positivo (nivel sobre rango)"
                else:
                    if datos[0] < 70:
                        resultado = "Negativo (nivel bajo rango)"
    if datos[1] > 1 and datos[1] <= 5:
        if datos[0] >= 80 and datos[0] < 110:
                resultado = "nivel normal"
        else:
                if datos[0] > 110:
                    resultado = "Positivo (nivel sobre rango)"
                else:
                    if datos[0] < 80:
                        resultado = "Negativo (nivel bajo rango)"
    if datos[1] >= 0 and datos[1] <= 1:
        if datos[0] >= 70 and datos[0] < 100:
                resultado = "nivel normal"
        else:
                if datos[0] > 100:
                    resultado = "Positivo (nivel sobre rango)"
                else:
                    if datos[0] < 70:
                        resultado = "Negativo (nivel bajo rango)"
    return resultado


def muestra_resultado(resultado):
     print(resultado)

if __name__ == "__main__":
    datos = lectura()
    resultados = analisis(datos)
    muestra_resultado (resultados)


