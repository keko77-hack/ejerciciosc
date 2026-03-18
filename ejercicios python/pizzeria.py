print("Bienvenido a la pizzeria Perales, ¿Que tipo de pizza desea ordenar?\n\t1- Vegetariana\n\t2- No vegetariana")
pizza = input("introduzca que tipo de pizza quiere: ")
if pizza == "1":
    print("ingredientes de pizza vegetariana\n\t1- pimiento\n\t2- tofu" )
    ingredientes = input("escoja el ingrediente: ")
    print("pizza vegetariana con mozzarella, tomate y ", end="")
    if ingredientes == "1":
        print("pimiento")
    else:
        print("tofu")
else:
    print("ingredietes de pizza no vegetariana\n\t1- pepperoni\n\t2- jamon\n\t3- pollo")
    ingredientes = input("escoja el ingrediente: ")
    print("pizza no vegetariana con mozzarella, tomate y ", end="")
    if ingredientes == "1":
        print("pepperoni")
    elif ingredientes == "2":
        print("jamon")
    else:
        print("pollo")
        
    
