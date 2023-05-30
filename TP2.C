#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct venta_cliente {
    char producto[20];
    char marca[20];
    char tipo[20];
    float talle;
    char datos_del_cliente[100];
    char modo_de_pago[100];
} VentaCliente;

void menu(VentaCliente* ventas, int* contador);
void cargar_venta(VentaCliente* ventas, int* contador);
void mostrar_ventas(VentaCliente* ventas, int contador);
void modificar_venta(VentaCliente* ventas, int contador);
void eliminar_venta(VentaCliente* ventas, int* contador);

int main() {
    VentaCliente ventas[SIZE];
    int contador = 0;
    menu(ventas, &contador);
    return 0;
}
void menu(VentaCliente* ventas, int* contador) {
    int opcion;
    printf("1. Cargar venta\n");
    printf("2. Mostrar ventas\n");
    printf("3. Modificar venta\n");
    printf("4. Eliminar venta\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            cargar_venta(ventas, contador);
            break;
        case 2:
            mostrar_ventas(ventas, *contador);
            break;
        case 3:
            modificar_venta(ventas, *contador);
            break;
        case 4:
            eliminar_venta(ventas, contador);
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
    }
}

void cargar_venta(VentaCliente* ventas, int* contador) {
    if (*contador == SIZE) {
        printf("La lista de ventas está llena.\n");
        return;
    }

    VentaCliente venta;
    printf("Producto: ");
    scanf("%s", venta.producto);
    printf("Marca: ");
    scanf("%s", venta.marca);
    printf("Tipo: ");
    scanf("%s", venta.tipo);
    printf("Talle: ");
    scanf("%f", &venta.talle);
    printf("Datos del cliente: ");
    scanf(" %[^\n]", venta.datos_del_cliente);
    printf("Modo de pago: ");
    scanf(" %[^\n]", venta.modo_de_pago);

    ventas[*contador] = venta;
    (*contador)++;

    printf("Venta cargada exitosamente.\n");
    menu(ventas, contador);
}