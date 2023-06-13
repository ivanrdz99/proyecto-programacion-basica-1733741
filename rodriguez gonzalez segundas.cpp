#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct videojuegos
{
	int Nprod = 0;
	string Nomprod, anio, categoria, clasif, consola, descripcion;
	float precio = 0, iva = 0, PT = 0;
	string estado = "dado de baja";
};

videojuegos* productos;

int registros = -1;

void alta();
void modif();
void baja();
void listadeproductos();
void guardar();
void cargar();

int main()
{
	int opc;
	do
	{
		cout << "\t" << "MENU PRINCIPAL" << endl;
		cout << "1-Alta de Producto" << endl;
		cout << "2-Modificar Producto" << endl;
		cout << "3-Baja de Producto" << endl;
		cout << "4-Lista de Producto" << endl;
		cout << "5-limpiar pantalla" << endl;
		cout << "6-Salir" << endl;
		cout << "Seleccione lo que desea hacer" << endl;
		cin >> opc;

		switch (opc)
		{
		case 1:
			alta();
			return main();
			break;
		case 2:
			modif();
			return main();
			break;
		case 3:
			baja();
			return main();
			break;
		case 4:
			listadeproductos();
			return main();
			break;
		case 5:
			system("cls");
			return main();
			break;
		case 6:
			guardar();
			exit(1);
			break;
		default:
			cout << "seleccion no permitida" << endl;
			system("pause");
			break;
		}
	} while (opc != 6);
	return 0;
}
void alta()
{
	cout << "\t" << "Alta de Productos" << endl;
	cout << "cuantos Productos quiere dar de alta:";
	cin >> registros;

	productos = new videojuegos[registros];

	for (int i = 0; i < registros; i++)
	{
		productos[i].Nprod = i + 1;
		productos[i].estado = "de alta";
		cin.ignore();

		cout << "\nRegistros " << productos[i].Nprod << endl;

		cout << "Nombre del Producto:";
		getline(cin, productos[i].Nomprod);

		cout << "Descripcion:";
		getline(cin, productos[i].descripcion);

		cout << "Categoria:";
		getline(cin, productos[i].categoria);

		cout << "fecha de lazamiento:";
		getline(cin, productos[i].anio);

		cout << "Clasificacion:";
		getline(cin, productos[i].clasif);

		cout << "Consola:";
		getline(cin, productos[i].consola);

		cout << "precio:";
		cin >> productos[i].precio;

		cout << "cantidad de iva agregado:";
		cin >> productos[i].iva;

		productos[i].PT = productos[i].precio + (productos[i].precio * productos[i].iva); //precio total

		cin.ignore();
	}
	cout << "\nProductos Dados de alta" << endl;
	system("pause");
}

void modif()
{
	int NR; // NUMERO DE REGISTRO
	bool encontrado = false;

	cout << "\t" << "Modificacion de Productos" << endl;
	cout << "Numero del producto que deseas modificar:";
	cin >> NR;

	for (int i = 0; i < registros; i++)
	{
		if (productos[i].Nprod == NR)
		{
			encontrado = true;

			cout << "\nRegistros " << productos[i].Nprod << endl;

			cout << "Nombre del Poducto:";
			cin.ignore();
			getline(cin, productos[i].Nomprod);

			cout << "Descripcion:";
			getline(cin, productos[i].descripcion);

			cout << "Categoria:";
			getline(cin, productos[i].categoria);

			cout << "fecha de lazamiento:";
			getline(cin, productos[i].anio);

			cout << "Clasificacion:";
			getline(cin, productos[i].clasif);

			cout << "Consola:";
			getline(cin, productos[i].consola);

			cout << "costo:";
			cin >> productos[i].precio;

			cout << "cantidad de iva agregado:";
			cin >> productos[i].iva;

			productos[i].PT = productos[i].precio + (productos[i].precio * productos[i].iva); //precio total

			cin.ignore();

			cout << "\nProducto Modificado" << endl;
			system("pause");
			break;
		}
	}

	if (!encontrado)
	{
		cout << "\nNo se encunetra en la base de datos" << endl;
		system("pause");
	}
}

void baja()
{
	int NR;
	bool encontrado = false;

	cout << "\t" << "Baja de Producto" << endl;
	cout << "Numero del producto que deseas modificar:";
	cin >> NR;

	for (int i = 0; i < registros; i++)
	{
		if (productos[i].Nprod == NR)
		{
			encontrado = true;
			productos[i].estado = "dado de baja";
			cout << "\nProducto dado de baja" << endl;
			system("pause");
			break;
		}
	}
	if (!encontrado)
	{
		cout << "\nNo se encuntra en la base de datos" << endl;
		system("pause");
	}
}

void consulta()
{
	int NR;
	bool encontrado = false;

	cout << "\t" << "Consulta de Producto" << endl;
	cout << "Numero del producto que deseas modificar:";
	cin >> NR;

	for (int i = 0; i < registros; i++)
	{
		if (productos[i].Nprod == NR)
		{
			encontrado = true;

			cout << "\tProductos" << productos[i].Nprod << endl;
			cout << "Estado" << productos[i].estado << endl;
			cout << "Nombre del Producto" << productos[i].Nomprod << endl;
			cout << "Descripcion" << productos[i].descripcion << endl;
			cout << "Categoria" << productos[i].categoria << endl;
			cout << "Fecha de lanzamiento" << productos[i].anio << endl;
			cout << "Clasificacion" << productos[i].clasif << endl;
			cout << "Consola" << productos[i].consola << endl;
			cout << "costo" << productos[i].precio << endl;
			cout << "Iva" << productos[i].iva << endl;
			cout << "Precio Total" << productos[i].PT << endl;

			break;
		}
	}
	if (!encontrado)
	{
		cout << "\nRegistro No Existe" << endl;
	}
	system("pause");
}

void listadeproductos()
{
	if (registros == -1)
	{
		cout << "No hay articulos registrados." << endl;
		return;
	}

	int opcion;
	cout << "1. Mostrar todos los productos." << endl;
	cout << "2. Filtrar por clasificacion." << endl;
	cout << "3. Filtrar por genero." << endl;
	cout << "4. Filtrar por consola." << endl;
	cout << "Ingrese el numero de opcion: ";
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		for (int i = 0; i < registros; i++)
		{
			cout << "numero del producto:" << productos[i].Nprod << endl;
			cout << "Nombre del Producto:" << productos[i].Nomprod << endl;
			cout << "Descripcion:" << productos[i].descripcion << endl;
			cout << "Categoria:" << productos[i].categoria << endl;
			cout << "Fecha de lanzamiento:" << productos[i].anio << endl;
			cout << "Clasificacion:" << productos[i].clasif << endl;
			cout << "Consola:" << productos[i].consola << endl;
			cout << "costo:" << productos[i].precio << endl;
			cout << "Iva:" << productos[i].iva << endl;
			cout << "Precio Total:" << productos[i].PT << endl;
		}
		break;
	case 2:
	{
		cin.ignore();
		string clasificacion;
		cout << "Ingrese la clasificacion: ";
		getline(cin, clasificacion);

		for (int i = 0; i < registros; i++)
		{
			if (productos[i].clasif == clasificacion)
			{
				cout << "numero del producto:" << productos[i].Nprod << endl;
				cout << "Nombre del Producto:" << productos[i].Nomprod << endl;
				cout << "Descripcion:" << productos[i].descripcion << endl;
				cout << "Categoria:" << productos[i].categoria << endl;
				cout << "Fecha de lanzamiento:" << productos[i].anio << endl;
				cout << "Clasificacion:" << productos[i].clasif << endl;
				cout << "Consola:" << productos[i].consola << endl;
				cout << "costo:" << productos[i].precio << endl;
				cout << "Iva:" << productos[i].iva << endl;
				cout << "Precio Total:" << productos[i].PT << endl;
			}

		}
		break;
	}
	case 3:
	{
		cin.ignore();
		string gen;
		cout << "Ingrese el genero: ";
		getline(cin, gen);

		for (int i = 0; i < registros; i++)
		{
			if (productos[i].categoria == gen)
			{
				cout << "numero del producto:" << productos[i].Nprod << endl;
				cout << "Nombre del Producto:" << productos[i].Nomprod << endl;
				cout << "Descripcion:" << productos[i].descripcion << endl;
				cout << "Categoria:" << productos[i].categoria << endl;
				cout << "Fecha de lanzamiento:" << productos[i].anio << endl;
				cout << "Clasificacion:" << productos[i].clasif << endl;
				cout << "Consola:" << productos[i].consola << endl;
				cout << "costo:" << productos[i].precio << endl;
				cout << "Iva:" << productos[i].iva << endl;
				cout << "Precio Total:" << productos[i].PT << endl;
			}

		}
		break;
	}
	case 4:
	{
		cin.ignore();
		string consola;
		cout << "Ingrese la consola: ";
		getline(cin, consola);

		for (int i = 0; i < registros; i++)
		{
			if (productos[i].consola == consola)
			{
				cout << "numero del producto:" << productos[i].Nprod << endl;
				cout << "Nombre del Producto:" << productos[i].Nomprod << endl;
				cout << "Descripcion:" << productos[i].descripcion << endl;
				cout << "Categoria:" << productos[i].categoria << endl;
				cout << "Fecha de lanzamiento:" << productos[i].anio << endl;
				cout << "Clasificacion:" << productos[i].clasif << endl;
				cout << "Consola:" << productos[i].consola << endl;
				cout << "costo:" << productos[i].precio << endl;
				cout << "Iva:" << productos[i].iva << endl;
				cout << "Precio Total:" << productos[i].PT << endl;
			}


		}
		break;
	}
	default:
		cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
		break;
	}
}
void guardar()
{
	ofstream archivo("productos.txt");

	if (archivo.is_open())
	{
		for (int i = 0; i < registros; i++)
		{
			archivo << productos[i].Nprod << "\n";
			archivo << productos[i].estado << "\n";
			archivo << productos[i].Nomprod << "\n";
			archivo << productos[i].descripcion << "\n";
			archivo << productos[i].categoria << "\n";
			archivo << productos[i].anio << "\n";
			archivo << productos[i].clasif << "\n";
			archivo << productos[i].consola << "\n";
			archivo << productos[i].precio << "\n";
			archivo << productos[i].iva << "\n";
			archivo << productos[i].PT << "\n";
		}
		archivo.close();
		cout << "\nLos datos fueron Guardados correctamente en el archivo: productos.txt" << endl;
	}
	else
	{
		cout << "\nNo se puede abrir el archivo para poder guardar los datos" << endl;
	}
	system("pause");
}

void cargar()
{
	ifstream archivo("productos.txt");

	if (archivo.is_open())
	{
		registros = 0;
		string line;
		int i = 0;

		while (getline(archivo, line))
		{
			if (i % 11 == 0)
			{
				productos[i].Nprod = stoi(line);
			}
			else if (i % 11 == 1)
			{
				productos[i].estado = line;
			}
			else if (i % 11 == 2)
			{
				productos[i].Nomprod = line;
			}
			else if (i % 11 == 3)
			{
				productos[i].descripcion = line;
			}
			else if (i % 11 == 4)
			{
				productos[i].categoria = line;
			}
			else if (i % 11 == 5)
			{
				productos[i].anio = line;
			}
			else if (i % 11 == 6)
			{
				productos[i].clasif = line;
			}
			else if (i % 11 == 7)
			{
				productos[i].consola = line;
			}
			else if (i % 11 == 8)
			{
				productos[i].precio = stof(line);
			}
			else if (i % 11 == 9)
			{
				productos[i].iva = stof(line);
			}
			else if (i % 11 == 10)
			{
				productos[i].PT = stof(line);
				registros++;
			}
			i++;
		}
		archivo.close();
		cout << "\nLos datos fueron Guardados correctamente desde el archivo: productos.txt" << endl;
	}
	else
	{
		cout << "\nNo se pudo abrir el archvivo para guardar los datos" << endl;
	}
	system("pause");
}
