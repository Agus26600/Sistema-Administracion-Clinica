#include <stdio.h>
#include <string.h>
#include "consultas.h"

#ifndef MAX_CONSULTAS
#define MAX_CONSULTAS 100
#endif

// Función para registrar una consulta clínica
int consultas_registrar(struct Consulta consultas[], int *totalConsultas, struct Cita citas[], int totalCitas) {
    if (*totalConsultas >= MAX_CONSULTAS) {
        printf("Error: Se ha alcanzado el límite máximo de consultas registradas.\n");
        return 0;
    }
    
    int idCitaBuscada;
    printf("\n--- REGISTRO DE CONSULTA MEDICA ---\n");
    printf("Ingrese el ID de la cita a atender: ");
    if (scanf("%d", &idCitaBuscada) != 1) {
        printf("Error: Entrada inválida.\n");
        while(getchar() != '\n'); // Limpia el bufer de entrada
        return 0;
    }

    // Buscar la cita en el arreglo
    int indexCita = -1;
    for (int i = 0; i < totalCitas; i++) {
        if (citas[i].id == idCitaBuscada) {
            indexCita = i;
            break;
        }
    }

    // Validar existencia de la cita (Cita no valida o cancelada)
    if (indexCita == -1) {
        printf("Error: La cita especificada no existe en el sistema.\n");
        return 0;
    }

    // Validar que la cita este activa (no cancelada ni ya atendida)
    if (citas[indexCita].estado == CANCELADA || citas[indexCita].estado == ATENDIDA) {
        printf("Error: No se puede registrar consulta. La cita está cancelada o ya fue atendida.\n");
        return 0;
    }

    struct Consulta nueva;
    nueva.idCita = idCitaBuscada;

    printf("Ingrese Motivo de consulta: ");
    while(getchar() != '\n'); // Limpiar salto de linea pendiente
    fgets(nueva.motivo, TAM_CADENA, stdin);
    nueva.motivo[strcspn(nueva.motivo, "\n")] = 0;

    printf("Ingrese Observaciones médicas: ");
    fgets(nueva.observaciones, TAM_CADENA, stdin);
    nueva.observaciones[strcspn(nueva.observaciones, "\n")] = 0;

    printf("Ingrese Diagnostico ficticio: ");
    fgets(nueva.diagnostico, TAM_CADENA, stdin);
    nueva.diagnostico[strcspn(nueva.diagnostico, "\n")] = 0;

    // Almacenar la consulta
    consultas[*totalConsultas] = nueva;
    (*totalConsultas)++;

    // Actualizar el estado de la cita a ATENDIDA automáticamente
    citas[indexCita].estado = ATENDIDA;

    printf("¡Consulta registrada exitosamente y cita actualizada a ATENDIDA!\n");
    return 1;
}

// Función para consultar el historial de un paciente
void consultas_consultarHistorial(const struct Consulta consultas[], int totalConsultas, const struct Cita citas[], int totalCitas, int idPaciente) {
    printf("\n--- HISTORIAL CLINICO DEL PACIENTE (ID: %d) ---\n", idPaciente);
    int encontradas = 0;

    // Recorremos las citas para filtrar las que pertenecen al paciente
    for (int i = 0; i < totalCitas; i++) {
        if (citas[i].idPaciente == idPaciente) {
            // Buscamos si hay un registro de consulta vinculado a esta cita
            for (int j = 0; j < totalConsultas; j++) {
                if (consultas[j].idCita == citas[i].id) {
                    encontradas++;
                    printf("\n[Cita ID: %d] Fecha: %s | Hora: %s\n", citas[i].id, citas[i].fecha, citas[i].hora);
                    printf("  -> Motivo:        %s\n", consultas[j].motivo);
                    printf("  -> Observaciones: %s\n", consultas[j].observaciones);
                    printf("  -> Diagnostico:   %s\n", consultas[j].diagnostico);
                    printf("--------------------------------------------------\n");
                }
            }
        }
    }

    if (encontradas == 0) {
        printf("No se encontraron consultas registradas para este paciente.\n");
    }
}