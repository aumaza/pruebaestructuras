#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleado.h"

#define TAM 3


void mostrarEmpleado(eEmpleado* employee)
{
system("cls");
system("clear");

    printf("\n==============================================");
    printf("\nID: %d", employee->id);
    printf("\nLegajo: %d", employee->legajo);
    printf("\nNombre: %s", employee->nombre);
    printf("\nSexo: %c", employee->sexo);
    printf("\nSueldo: %.2f", employee->sueldo);
    printf("\nFecha de Ingreso: %d/%d/%d\n", employee->fechaIngreso.dia, employee->fechaIngreso.mes, employee->fechaIngreso.anio);
    printf("\n==============================================");

    getchar();

}

void cargaEmpleado(eEmpleado* employee, int cant)
{
system("cls");
system("clear");
    //int i;
    char resp='s';
    //int flag=0;


    do
    {

    /*if(employee->id >=0 && employee->id <=cant && employee != NULL)
    {
        employee->id=1;
        employee->legajo=1;
        flag=1;

    }

    if(flag==1)
    {

        employee->id++;
        employee->legajo++;

    }*/

    printf("\nIngrese ID: ");
    scanf("%d", &employee->id);
    getchar();

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
    scanf("%d", &employee->fechaIngreso.dia);
    getchar();

    printf("\nIngrese fecha ingreso (mes): ");
    scanf("%d", &employee->fechaIngreso.mes);
    getchar();

    printf("\nIngrese fecha ingreso (anio): ");
    scanf("%d", &employee->fechaIngreso.anio);
    getchar();

    printf("\nDesea continuar: ");
    scanf("%c", &resp);
    getchar();


}while(resp != 'n');

}

void ordenarEmpleados(eEmpleado* employee, int tam)
{
system("cls");
system("clear");

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

    getchar();
}

void mostrarEmpleados(eEmpleado* employee, int tam)
{
system("cls");
system("clear");

int i;

printf("\n==============================================");

for(i=0; i<tam; i++)
{

    printf("\nID: %d", employee->id);
    printf("\nLegajo: %d", employee->legajo);
    printf("\nNombre: %s", employee->nombre);
    printf("\nSexo: %c", employee->sexo);
    printf("\nSueldo: %.2f", employee->sueldo);
    printf("\nFecha de Ingreso: %d/%d/%d\n", employee->fechaIngreso.dia, employee->fechaIngreso.mes, employee->fechaIngreso.anio);

}

//system("pause");
getchar();

}

int menuGeneral()
{
system("cls");
system("clear");

eEmpleado unEmpleado, *employee;
employee = &unEmpleado;

int opc;

do{
system("cls");
system("clear");


int ok;
int ch;

printf("\n======================================");
printf("\nSeleccione la Operacion a Realizar");
printf("\n======================================\n");
printf("\n1. Altas");
printf("\n2. Modificar");
printf("\n3. Baja");
printf("\n4. Informes");
printf("\n5. Salir");
printf("\n\n======================================\n");

do
    {
      printf("\nOpcion: ");
      fflush(stdout);
      if ((ok = scanf("%d", &opc)) == EOF)
         return 1;


      if ((ch = getchar()) != '\n')
      {
         ok = 0;

         while ((ch = getchar()) != EOF && ch != '\n');
      }
   }while(!ok);
printf("\n======================================\n");

switch(opc)
{

case 1:  cargaEmpleado(employee, TAM); break;
case 2:  break;
case 3:  break;
case 4:  subMenuInformes(employee,TAM); break;

}
}while(opc != 5);

return 0;

}


int subMenuInformes(eEmpleado* employee, int cant)
{
system("cls");
system("clear");

//eEmpleado unEmpleado, *employee;
//employee = &unEmpleado;

int opc;

do{
system("cls");
system("clear");


int ok;
int ch;

printf("\n======================================");
printf("\nSeleccione la Operacion a Realizar");
printf("\n======================================\n");
printf("\n1. Mostrar un Empleado");
printf("\n2. Listar Empleados");
printf("\n3. Lista Empleados Ordenada");
//printf("\n4. Informes");
printf("\n4. Salir");
printf("\n\n======================================\n");

do
    {
      printf("\nOpcion: ");
      fflush(stdout);
      if ((ok = scanf("%d", &opc)) == EOF)
         return 1;


      if ((ch = getchar()) != '\n')
      {
         ok = 0;

         while ((ch = getchar()) != EOF && ch != '\n');
      }
   }while(!ok);
printf("\n======================================\n");

switch(opc)
{

case 1:  mostrarEmpleado(employee); break;
case 2:  mostrarEmpleados(employee, cant); break;
case 3:  ordenarEmpleados(employee, cant); break;
//case 4:  mostrarEmpleados(employee,TAM); break;

}
}while(opc != 4);

return 0;

}




