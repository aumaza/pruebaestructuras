#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;

}eEmpleado;



void mostrarEmpleado(eEmpleado* employee);
void cargaEmpleado(eEmpleado* employee, int cant);
void cargaEmpleado(eEmpleado* employee, int cant);

int main()
{
    eEmpleado unEmpleado, *employee;
    employee = &unEmpleado;


    /*unEmpleado.legajo=1234;
    strcpy(unEmpleado.nombre,"juan");
    unEmpleado.sexo='M';
    unEmpleado.sueldo=1500.00;
    unEmpleado.fechaIngreso.dia=17;
    unEmpleado.fechaIngreso.mes=9;
    unEmpleado.fechaIngreso.anio=2018;*/
    cargaEmpleado(employee, TAM);

    mostrarEmpleado(employee);

    return 0;
}


void mostrarEmpleado(eEmpleado* employee)
{

    printf("\nLegajo: %d", employee->legajo);
    printf("\nNombre: %s", employee->nombre);
    printf("\nSexo: %c", employee->sexo);
    printf("\nSueldo: %.2f", employee->sueldo);
    printf("\nFecha de Ingreso: %d/%d/%d\n", employee->fechaIngreso.dia, employee->fechaIngreso.mes, employee->fechaIngreso.anio);

}

void cargaEmpleado(eEmpleado* employee, int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {

    printf("\nIngrese legajo: ");
    scanf("%d", &employee->legajo);
    getchar();

    printf("\nIngrese nombre: ");
    fflush(stdin);
    fgets(employee->nombre, 20, stdin);

    printf("\nIngrese Sexo: ");
    scanf("%c", &employee->sexo);
    getchar();

    printf("\nIngrese Sueldo: ");
    scanf("%f", &employee->sueldo);
    getchar();

    printf("\nIngrese fecha ingreso (dia): ");
    scanf("%d", employee->fechaIngreso.dia);
    getchar();

    printf("\nIngrese fecha ingreso (mes): ");
    scanf("%d", employee->fechaIngreso.mes);
    getchar();

    printf("\nIngrese fecha ingreso (anio): ");
    scanf("%d", employee->fechaIngreso.anio);
    getchar();
    }

}

void ordenarEmpleados(eEmpleado* employee, int tam)
{

    eEmpleado auxEmpleado;
    int i;
    int j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if((employee+i)->sueldo < (employee+j)->sueldo)
            {
                auxEmpleado=*(employee+i);
                *(employee+i)=*(employee+j);
                *(employee+j)=auxEmpleado;
            }
        }
    }


}
