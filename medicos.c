#include <stdio.h>
#include <string.h>
#include "medicos.h"

// Función para registrar un médico
int medicos_registrar(struct Medico lista[], int *total) {
    if (*total >= MAX_MEDICOS) {
        printf("Error: Se ha alcanzado el limite maximo de medicos registrados.\n");
        return 0;
    }

    struct Medico nuevo;
    printf("\n--- REGISTRO DE MÉDICO ---\n");
    printf("Ingrese Identificador unico (entero): ");
    if (scanf("%d", &nuevo.id) != 1) {
        printf("Error: Entrada invalida.\n");
        while(getchar() != '\n'); // Limpia el bufer de entrada
        return 0;
    }

    // Validar que el ID no esté duplicado
    for (int i = 0; i < *total; i++) {
        if (lista[i].id == nuevo.id) {
            printf("Error: El ID del medico ya se encuentra registrado.\n");
            return 0;
        }
    }

    printf("Ingrese Nombre completo: ");
    while(getchar() != '\n'); //Limpia salto de línea pendiente
    fgets(nuevo.nombreCompleto, TAM_CADENA, stdin);
    nuevo.nombreCompleto[strcspn(nuevo.nombreCompleto, "\n")] = 0;

    printf("Ingrese Especialidad medica: ");
    fgets(nuevo.especialidad, TAM_CADENA, stdin);
    nuevo.especialidad[strcspn(nuevo.especialidad, "\n")] = 0;

    // Guardar en el arreglo en memoria
    lista[*total] = nuevo;
    (*total)++;

    printf("¡Medico registrado exitosamente!\n");
    return 1;
}

// Función para consultar la lista de médicos 
void medicos_consultar(const struct Medico lista[], int total) {
    if (total == 0) {
        printf("No hay medicos registrados en el sistema.\n");
        return;
    }

    printf("\n--- LISTA DE MÉDICOS REGISTRADOS ---\n");
    printf("%-5s | %-30s | %-25s\n", "ID", "Nombre Completo", "Especialidad");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-5d | %-30s | %-25s\n", 
               lista[i].id, lista[i].nombreCompleto, lista[i].especialidad);
    }
}

// Función para buscar un médico por ID o nombre
void medicos_buscar(const struct Medico lista[], int total) {
    if (total == 0) {
        printf("No hay medicos registrados.\n");
        return;
    }

    int opcion;
    printf("\n--- BUSCAR MEDICO ---\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por Nombre\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        int idBuscado;
        printf("Ingrese el ID: ");
        scanf("%d", &idBuscado);
        for (int i = 0; i < total; i++) {
            if (lista[i].id == idBuscado) {
                printf("\n[Encontrado] ID: %d | Nombre: %s | Especialidad: %s\n", 
                       lista[i].id, lista[i].nombreCompleto, lista[i].especialidad);
                return;
            }
        }
        printf("No se encontro ningun medico con ese ID.\n");
    } else if (opcion == 2) {
        char nombreBuscado[TAM_CADENA];
        printf("Ingrese el nombre (o parte de él): ");
        while(getchar() != '\n');
        fgets(nombreBuscado, TAM_CADENA, stdin);
        nombreBuscado[strcspn(nombreBuscado, "\n")] = 0;

        int encontrados = 0;
        for (int i = 0; i < total; i++) {
            if (strstr(lista[i].nombreCompleto, nombreBuscado) != NULL) {
                printf("\n[Encontrado] ID: %d | Nombre: %s | Especialidad: %s\n", 
                       lista[i].id, lista[i].nombreCompleto, lista[i].especialidad);
                encontrados++;
            }
        }
        if (encontrados == 0) {
            printf("No se encontraron coincidencias con ese nombre.\n");
        }
    } else {
        printf("Opcion invalida.\n");
    }
}

// Función para modificar los datos de un médico
void medicos_modificar(struct Medico lista[], int total) {
    int idBuscado;
    printf("\n--- MODIFICAR MEDICO ---\n");
    printf("Ingrese el ID del medico a modificar: ");
    scanf("%d", &idBuscado);

    int index = -1;
    for (int i = 0; i < total; i++) {
        if (lista[i].id == idBuscado) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: No existe ningun medico con el ID proporcionado.\n");
        return;
    }

    printf("Modificando datos de: %s\n", lista[index].nombreCompleto);
    
    printf("Ingrese nuevo Nombre completo: ");
    while(getchar() != '\n');
    fgets(lista[index].nombreCompleto, TAM_CADENA, stdin);
    lista[index].nombreCompleto[strcspn(lista[index].nombreCompleto, "\n")] = 0;

    printf("Ingrese nueva Especialidad: ");
    fgets(lista[index].especialidad, TAM_CADENA, stdin);
    lista[index].especialidad[strcspn(lista[index].especialidad, "\n")] = 0;

    printf("¡Datos del médico actualizados correctamente!\n");
}

// Función para eliminar un médico validando citas pendientes
int medicos_eliminar(struct Medico lista[], int *totalMedicos, const struct Cita citas[], int totalCitas) {
    int idBuscado;
    printf("\n--- ELIMINAR MÉDICO ---\n");
    printf("Ingrese el ID del médico a eliminar: ");
    scanf("%d", &idBuscado);

    int index = -1;
    for (int i = 0; i < *totalMedicos; i++) {
        if (lista[i].id == idBuscado) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: No se encontro ningun medico con ese ID.\n");
        return 0;
    }

    //Validar si el médico tiene citas en estado PROGRAMADA
    for (int i = 0; i < totalCitas; i++) {
        if (citas[i].idMedico == idBuscado && citas[i].estado == PROGRAMADA) {
            printf("Error: El medico posee citas pendientes. No se puede eliminar.\n");
            return 0;
        }
    }

    // Reorganizar el arreglo desplazando elementos hacia la izquierda
    for (int i = index; i < *totalMedicos - 1; i++) {
        lista[i] = lista[i + 1];
    }
    (*totalMedicos)--;

    printf("¡Médico eliminado correctamente del sistema!\n");
    return 1;
}