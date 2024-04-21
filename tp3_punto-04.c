#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura del producto.

struct 
{

    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;

}typedef producto;

//Estructura del cliente.

struct
{

    int clienteID;
    char *nombreCliente;
    int ProductosPedidos;
    producto *productos;

}typedef clientes;

//Funcion para cargar clientes.

clientes cargarClientes(int aux);

//Funcion para cargar productos.

producto cargarProducto(int aux2);

//Funcion para cargar productos.

void mostrarProductos(clientes cliente);

//Funcion para calcular el precio.

float calcularPrecio(producto producto);

//Funcion principal.

int main(void){

    int aux;

    clientes *cliente = malloc(5 * sizeof(clientes));

    do
    {

        printf("\nIngrese la cantidad de clientes (maximo cinco personas):\n");
        scanf("%d", &aux);

    } while (aux > 5);
    
    //Cargo los clientes.

    for (int i = 0; i < aux; i++)
    {
        cliente[i] = cargarClientes(i);
    }

    //Mostrar datos.

    for (int i = 0; i < aux; i++)
    {
        mostrarProductos(cliente[i]);
    }
    
    //Libero la memoria.

    for (int i = 0; i < aux; i++)
    {
        free(cliente[i].nombreCliente);
        free(cliente[i].productos);
    }
    free(cliente);
    
    

}

//FUNCION PARA CARGAR CLIENTES.

clientes cargarClientes(int aux){

        clientes cliente;

        cliente.clienteID = aux + 1;

        //Reserva dinamica de memoria para el nombre del cliente.

        cliente.nombreCliente = malloc(100 * sizeof(char));

        printf("Ingrese el nombre del cliente: \n");
        scanf("%s", cliente.nombreCliente);

        cliente.ProductosPedidos = 1 + rand() % 5;

        //Reserva dinamica de memoria para los productos.

        cliente.productos = malloc(cliente.ProductosPedidos * sizeof(producto));

        //Cargo productos.

        for (int j = 0; j < cliente.ProductosPedidos; j++) {

            cliente.productos[j] = cargarProducto(j);

        }

        return cliente;

}

//FUNCION PARA CARGAR PRODUCTOS.

producto cargarProducto(int aux2){

    int k = 0;
    char *tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    producto productos;

    productos.productoID = aux2 + 1;

    productos.cantidad = 1 + rand() % 10;

    //Genero un valor aleatorio para algun producto.

    k = rand() % 5;

    //Reservo memoria.

    //productos.tipoProducto = malloc(100 * sizeof(char));

    productos.tipoProducto = tiposProductos[k];

    productos.precioUnitario = 10 + rand() % 91;

    return productos;
}

//FUNCION PARA CALCULAR EL PRECIO.

float calcularPrecio(producto producto){

    float total = producto.cantidad * producto.precioUnitario;

    return total;

}

//FUNCION PARA MOSTRAR LOS PRODUCTOS.

void mostrarProductos(clientes cliente){

    float suma = 0;

    printf("\nNumero de cliente: %d \n Nombre del cliente: %s \n Cantidad de productos que pidio: %d \n Productos que pidio: \n", cliente.clienteID, cliente.nombreCliente, cliente.ProductosPedidos);

    for (int i = 0; i < cliente.ProductosPedidos; i++)
    {
        float total = 0;

        printf("Producto %d:\n", i+1);

        printf("ID del producto: %d \n Cantidad: %d \n Tipo de producto: %s \n Precio: %f\n", cliente.productos[i].productoID, cliente.productos[i].cantidad, cliente.productos[i].tipoProducto, cliente.productos[i].precioUnitario);

        total = calcularPrecio(*cliente.productos);

        suma = suma + total;
    }

    printf("\nEl total a pagar es: %f\n\n", suma);
}