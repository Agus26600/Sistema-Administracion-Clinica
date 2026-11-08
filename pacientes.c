#include <stdio.h>
#include <string.h>
#include "pacientes.h"

//funcion para registrar un paciente 
int pacientes_registrar(struct Paciente lista[], int *total) {
    if (*total >= MAX_PACIENTES) {
        printf("Error: Se ha alcanzado el limite maximo de pacientes registrados.\n");
        return 0;
    }

    struct Paciente nuevo;
    printf("\n--- REGISTRO DE PACIENTE ---\n");
    printf("Ingrese Identificador unico (entero): ");
    if (scanf("%d", &nuevo.id) != 1) {
        printf("Error: Entrada invalida.\n");
        while(getchar() != '\n'); //Limpia el bufer de entrada
        return 0;
    }

    // Validar que el ID no esté duplicado
    for (int i = 0; i < *total; i++) {
        if (lista[i].id == nuevo.id) {
            printf("Error: El ID de paciente ya existe.\n");
            return 0;
        }
    }

    printf("Ingrese Nombre completo: ");
    while(getchar() != '\n'); // Limpiar salto de línea pendiente
    fgets(nuevo.nombreCompleto, TAM_CADENA, stdin);
    nuevo.nombreCompleto[strcspn(nuevo.nombreCompleto, "\n")] = 0; // Eliminar el salto de línea capturado

    printf("Ingrese Edad: ");
    if (scanf("%d", &nuevo.edad) != 1 || nuevo.edad <= 0) {
        printf("Error: Edad invalida.\n");
        while(getchar() != '\n');
        return 0;
    }

    printf("Ingrese Telefono: ");
    scanf("%s", nuevo.telefono);

    // Agregar al arreglo en memoria
    lista[*total] = nuevo;
    (*total)++;

    printf("¡Paciente registrado exitosamente!\n");
    return 1;
}

// Función para consultar pacientes
void pacientes_consultar(const struct Paciente lista[], int total) {
    if (total == 0) {
        printf("No hay pacientes registrados en el sistema.\n");
        return;
    }

    printf("\n--- LISTA DE PACIENTES REGISTRADOS ---\n");
    printf("%-5s | %-30s | %-5s | %-15s\n", "ID", "Nombre Completo", "Edad", "Telefono");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-5d | %-30s | %-5d | %-15s\n", 
               lista[i].id, lista[i].nombreCompleto, lista[i].edad, lista[i].telefono);
    }
}

// Función auxiliar interna para buscar la posición de un paciente por ID
int pacientes_buscarPorId(const struct Paciente lista[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) {
            return i; // Retorna el índice en el arreglo
        }
    }
    return -1; // No encontrado
}

// Función para modificar un paciente
void pacientes_modificar(struct Paciente lista[], int total) {
    int idBuscado;
    printf("\n--- MODIFICAR PACIENTE ---\n");
    printf("Ingrese el ID del paciente a modificar: ");
    scanf("%d", &idBuscado);

    int index = pacientes_buscarPorId(lista, total, idBuscado);
    if (index == -1) {
        printf("Error: No existe ningun paciente con el ID proporcionado.\n");
        return;
    }

    printf("Modificando datos de: %s\n", lista[index].nombreCompleto);
    
    printf("Ingrese nuevo Nombre completo: ");
    while(getchar() != '\n');
    fgets(lista[index].nombreCompleto, TAM_CADENA, stdin);
    lista[index].nombreCompleto[strcspn(lista[index].nombreCompleto, "\n")] = 0;

    printf("Ingrese nueva Edad: ");
    scanf("%d", &lista[index].edad);

    printf("Ingrese nuevo Telefono: ");
    scanf("%s", lista[index].telefono);

    printf("¡Datos del paciente actualizados correctamente!\n");
}