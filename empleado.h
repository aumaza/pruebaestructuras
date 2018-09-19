#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;

}eEmpleado;



void mostrarEmpleado(eEmpleado* employee);
void cargaEmpleado(eEmpleado* employee, int cant);
void ordenarEmpleados(eEmpleado* employee, int tam);
void mostrarEmpleados(eEmpleado* employee, int tam);
int menuGeneral();
int subMenuInformes(eEmpleado* employee, int TAM);

#endif // EMPLEADO_H_INCLUDED
