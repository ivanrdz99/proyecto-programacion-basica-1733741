#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

struct tienda {
    int Nart;
    std::string descripcion, Nomart, genero, clasif, consola;
    float costo;
};

const int CAPACIDAD_MAXIMA = 20;
tienda prod[CAPACIDAD_MAXIMA];
int numArticulos = 0;

void guardarRegistro() {
    FILE* archivo;
    fopen_s(&archivo, "registro.txt", "w");

    if (archivo != NULL) {
        for (int i = 0; i < numArticulos; i++) {
            fprintf(archivo, "%d\n", prod[i].Nart);
            fprintf(archivo, "%s\n", prod[i].Nomart.c_str());
            fprintf(archivo, "%s\n", prod[i].genero.c_str());
            fprintf(archivo, "%s\n", prod[i].clasif.c_str());
            fprintf(archivo, "%s\n", prod[i].consola.c_str());
            fprintf(archivo, "%s\n", prod[i].descripcion.c_str());
            fprintf(archivo, "%f\n", prod[i].costo);
        }

        fclose(archivo);
        printf("Registro guardado correctamente.\n");
    }
    else {
        printf("Error al abrir el archivo.\n");
    }
}

void cargarRegistro() {
    FILE* archivo;
    fopen_s(&archivo, "registro.txt", "r");

    if (archivo != NULL) {
        numArticulos = 0;
        char linea[255];
        int contador = 0;

        while (fgets(linea, sizeof(linea), archivo) != NULL) {
            if (contador % 7 == 0) {
                sscanf_s(linea, "%d", &prod[numArticulos].Nart);
            }
            else if (contador % 7 == 1) {
                prod[numArticulos].Nomart = linea;
            }
            else if (contador % 7 == 2) {
                prod[numArticulos].genero = linea;
            }
            else if (contador % 7 == 3) {
                prod[numArticulos].clasif = linea;
            }
            else if (contador % 7 == 4) {
                prod[numArticulos].consola = linea;
            }
            else if (contador % 7 == 5) {
                prod[numArticulos].descripcion = linea;
            }
            else if (contador % 7 == 6) {
                sscanf_s(linea, "%f", &prod[numArticulos].costo);
                numArticulos++;
            }

            contador++;
        }

        fclose(archivo);
        printf("Registro cargado correctamente.\n");
    }
    else {
        printf("El archivo no existe. Se creará uno nuevo al guardar el registro.\n");
    }
}

void altaArticulo() {
    if (numArticulos >= CAPACIDAD_MAXIMA) {
        printf("La capacidad máxima ha sido alcanzada. No se pueden agregar más artículos.\n");
        return;
    }

    tienda nuevoProducto;

    printf("Numero de articulo: ");
    scanf_s("%d", &nuevoProducto.Nart);

    printf("Nombre del articulo: ");
    scanf_s(" %[^\n]s", nuevoProducto.Nomart, sizeof(nuevoProducto.Nomart));

    printf("Genero: ");
    scanf_s(" %[^\n]s", nuevoProducto.genero, sizeof(nuevoProducto.genero));

    printf("Clasificacion: ");
    scanf_s(" %[^\n]s", nuevoProducto.clasif, sizeof(nuevoProducto.clasif));

    printf("Consola: ");
    scanf_s(" %[^\n]s", nuevoProducto.consola, sizeof(nuevoProducto.consola));

    printf("Descripcion: ");
    scanf_s(" %[^\n]s", nuevoProducto.descripcion, sizeof(nuevoProducto.descripcion));

    printf("Costo: ");
    scanf_s("%f", &nuevoProducto.costo);

    prod[numArticulos] = nuevoProducto;
    numArticulos++;
    guardarRegistro();
}

void modificarArticulo() {
    if (numArticulos == 0) {
        printf("No hay articulos registrados.\n");
        return;
    }

    int numArticulo;
    printf("Ingrese el numero del articulo que desea modificar: ");
    scanf_s("%d", &numArticulo);

    int indice = -1;
    for (int i = 0; i < numArticulos; i++) {
        if (prod[i].Nart == numArticulo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("El articulo no fue encontrado.\n");
    }
    else {
        tienda articuloModificado;

        printf("Numero de articulo: ");
        scanf_s("%d", &articuloModificado.Nart);

        printf("Nuevo nombre del articulo: ");
        scanf_s(" %[^\n]s", articuloModificado.Nomart, sizeof(articuloModificado.Nomart));

        printf("Nuevo genero: ");
        scanf_s(" %[^\n]s", articuloModificado.genero, sizeof(articuloModificado.genero));

        printf("Nueva clasificacion: ");
        scanf_s(" %[^\n]s", articuloModificado.clasif, sizeof(articuloModificado.clasif));

        printf("Nueva consola: ");
        scanf_s(" %[^\n]s", articuloModificado.consola, sizeof(articuloModificado.consola));

        printf("Nueva descripcion: ");
        scanf_s(" %[^\n]s", articuloModificado.descripcion, sizeof(articuloModificado.descripcion));

        printf("Nuevo costo: ");
        scanf_s("%f", &articuloModificado.costo);

        prod[indice] = articuloModificado;
        guardarRegistro();

        printf("El articulo ha sido modificado correctamente.\n");
    }
}

void bajaArticulo() {
    if (numArticulos == 0) {
        printf("No hay articulos registrados.\n");
        return;
    }

    int numArticulo;
    printf("Ingrese el numero del articulo que desea eliminar: ");
    scanf_s("%d", &numArticulo);

    int indice = -1;
    for (int i = 0; i < numArticulos; i++) {
        if (prod[i].Nart == numArticulo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("El articulo no fue encontrado.\n");
    }
    else {
        for (int i = indice; i < numArticulos - 1; i++) {
            prod[i] = prod[i + 1];
        }

        numArticulos--;
        guardarRegistro();

        printf("El articulo ha sido eliminado correctamente.\n");
    }
}

void mostrarArticulos() {
    if (numArticulos == 0) {
        printf("No hay articulos registrados.\n");
        return;
    }

    printf("Lista de articulos:\n");

    for (int i = 0; i < numArticulos; i++) {
        printf("Numero de articulo: %d\n", prod[i].Nart);
        printf("Nombre del articulo: %s\n", prod[i].Nomart.c_str());
        printf("Genero: %s\n", prod[i].genero.c_str());
        printf("Clasificacion: %s\n", prod[i].clasif.c_str());
        printf("Consola: %s\n", prod[i].consola.c_str());
        printf("Descripcion: %s\n", prod[i].descripcion.c_str());
        printf("Costo: %f\n\n", prod[i].costo);
    }
}

int main() {
    cargarRegistro();

    int opcion;
    do {
        printf("MENU\n");
        printf("1. Alta de articulo\n");
        printf("2. Modificar articulo\n");
        printf("3. Baja de articulo\n");
        printf("4. Mostrar articulos\n");
        printf("5. limpiar pantalla\n");
        printf("6. Salir\n");
        printf("Que deseas hacer? ");
        scanf_s("%d", &opcion);

        switch (opcion) 
        {
        case 1:
            altaArticulo();
            break;
        case 2:
            modificarArticulo();
            break;
        case 3:
            bajaArticulo();
            break;
        case 4:
            mostrarArticulos();
            break;
        case 5:
            system("cls");
            break;
        case 6:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
        }

        printf("\n");
    } while (opcion != 6);

    return 0;
}


