#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct tienda
{
    int Nart;
    string descripcion,Nomart,genero,clasif,consola;
    float costo;
};

tienda prod[1];

int main()
{
  
    int opcion;
    do
    {
        printf("\t menu de opciones \n");// \t es tabulador
        printf("1-alta \n");
        printf("2-modificacion \n");
        printf("3-baja \n");
        printf("4-lista \n");
        printf("5-limpiar pantalla \n");
        printf("6-salir \n");
        printf("que deseas hacer \n");
        scanf_s("%d", &opcion);
    switch (opcion)
    {
     case 1://alta de articulo
        for (int i = 0; i < 1; i++)
        {
            printf("numero de articulo \n");
            scanf_s("%d", &prod[i].Nart);

            cin.ignore();
            printf("ingrese nombre del articulo \n");
            getline(cin, prod[i].Nomart);
            printf("genero \n");
            getline(cin, prod[i].genero);
            printf("ingrese clasificacion del juego \n");
            getline(cin, prod[i].clasif);
            printf("ingrese la consola del juego \n");
            getline(cin, prod[i].consola);
            printf("dedcripcion del articulo \n");
            getline(cin, prod[i].descripcion);
            printf("ingrese costo del articulo\n");
            scanf_s("%f", &prod[i].costo);
        }
        
        break;
     case 2:
        break;
     case 3:
        break;
     case 4:
         cout << "Ingrese el numero del producto que desea buscar:\n ";
         
         for (int i = 0; i < 1; i++) 
         {
             printf("numero del articulo %d \n", prod[i].Nart);
             printf("Nombre del articulo: %s \n", prod[i].Nomart.c_str());
             printf("Genero: %s \n", prod[i].genero.c_str());
             printf("Clasificacion: %s \n", prod[i].clasif.c_str());
             printf("consola: %s \n", prod[i].consola.c_str());
             printf("Descripcion: %s \n", prod[i].descripcion.c_str());
             printf("Costo: %f \n", prod[i].costo);
                 
         }
         
         break;
     case 5:
        system("cls"); // limpiar pantalla
        
        break;
     case 6:
        exit(1); // cierra la pantalla
        break;
    }
} 
while (opcion != 6);
}
