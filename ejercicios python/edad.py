def lectura():
    edad = float(input("Ingrese su edad: "))
    return[edad]

def analisis(datos),:
    if datos[0] >= 18:
        resultado = "Usted es mayor de edad"
    else:
        if datos[0] < 18:
            resultado = "Usted es menor de edad"
    return resultado
    
def resultados(resultado):
    print(resultado)

if __name__ == "__main__":
    datos = lectura()
    resultado = analisis(datos)
    resultados(resultado)
