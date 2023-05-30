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
