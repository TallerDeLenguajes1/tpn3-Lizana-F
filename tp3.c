#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
    int ProductoID;//Numerado en ciclo iterativo
    int cantidad; //entre 1 -10
    char *Tipoproducto;//algun valor del arreglo Tipo productos
    float PrecioUnitario;// entre 10-100
}Producto;

typedef struct{
    int ClienteID;
    char* NombreCliente; //ingresado por usuario
    int CantidadProductosAPedir;//random 1-5
    Producto *Productos; //el tamaño depende de la variable CantidadProductosAPedir
}Clientes;


void Cargar_datos(Clientes* cliente, int cantidad_Clientes);
void mostrar_datos(Clientes* cliente, int cant_clientes);
void calcularPrecio(int cantidad_productos,float precioUnitario);

int main(){
    srand(time(NULL));
    int cantClientes;
    printf("cant clientes: ");
    scanf("%d",&cantClientes);

    Clientes *Client=(Clientes*) malloc(sizeof(Clientes)*cantClientes);
    Cargar_datos(Client,cantClientes);
    mostrar_datos(Client,cantClientes);

    free(Client);
    return 0;
}

void Cargar_datos(Clientes* cliente, int cantidad_Clientes){
    int i,j;
    for(i=0;i<cantidad_Clientes;i++){
        (cliente+i)->ClienteID=i+1;
        (cliente+i)->NombreCliente=(char *) malloc(sizeof(char)*40);
        printf("nombre Cliente %d : ",i+1);
        scanf("%s",(cliente+i)->NombreCliente);
        (cliente+i)->CantidadProductosAPedir=rand()%5+1;
        (cliente+i)->Productos=(Producto *) malloc(sizeof(Producto)*(cliente+i)->CantidadProductosAPedir);
        for(j=0;j<(cliente+i)->CantidadProductosAPedir;j++){
            int random_tipoproducto=rand()%5;
            ((cliente+i) -> Productos+j)->ProductoID=j+1;
            ((cliente+i) -> Productos+j)->cantidad=rand()%10 +1;
            ((cliente+i) -> Productos+j)->Tipoproducto=TiposProductos[random_tipoproducto];
            ((cliente+i) -> Productos+j)->PrecioUnitario=rand()%101+10;
        }
    }
}
void mostrar_datos(Clientes* cliente, int cant_clientes){
int i,j;
    for (i=0;i<cant_clientes;i++){
        printf("ID: %d \n Nombre dle Cliente %d : %s \n Productos pedidos : %d \n {",(cliente+i)->ClienteID,i+1,(cliente+i)->NombreCliente,(cliente+i)->CantidadProductosAPedir);
        for(j=0;j<(cliente+i)->CantidadProductosAPedir;j++){
            printf(" \n Producto: %s \n ID : %d \n Cantidad : %d \n Precio unitario : %2.f \n",((cliente+i)->Productos+j)->Tipoproducto,((cliente+i)->Productos+j)->ProductoID,((cliente+i)->Productos+j)->cantidad,((cliente+i)->Productos+j)->PrecioUnitario);
            calcularPrecio((cliente+i)->CantidadProductosAPedir,((cliente+i)->Productos+j)->PrecioUnitario);
        }
        
        printf("\n}\n");
    }
}

void calcularPrecio(int cantidad_productos,float precioUnitario){

    float total=(float)cantidad_productos*precioUnitario;
    printf("total a pagar: %.2f",total);

}


