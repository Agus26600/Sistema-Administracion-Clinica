#include <stdio.h>
#include <string.h>
#include "citas.h"

// Funciones auxiliares internas de validación
static int existePaciente(const struct Paciente pacientes[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (pacientes[i].id == id) return 1;
    }
    return 0;
}

static int existeMedico(const struct Medico medicos[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (medicos[i].id == id) return 1;
    }
    return 0;
}

// Función para registrar una cita 
int citas_registrar(struct Cita citas[], int *totalCitas, const struct Paciente pacientes[], int totalPacientes, const struct Medico medicos[], int totalMedicos) {
    if (*totalCitas >= MAX_CITAS) {
        printf("Error: Se ha alcanzado el limite maximo de citas registradas.\n");
        return 0;
    }

    struct Cita nueva;
    printf("\n--- PROGRAMACION DE CITA ---\n");
    printf("Ingrese ID de la cita: ");
    if (scanf("%d", &nueva.id) != 1) {
        printf("Error: Entrada invalida.\n");
        while(getchar() != '\n');
        return 0;
    }

    //Validar ID único de cita
    for (int i = 0; i < *totalCitas; i++) {
        if (citas[i].id == nueva.id) {
            printf("Error: Ya existe una cita registrada con ese ID.\n");
            return 0;
        }
    }

    printf("Ingrese ID del paciente: ");
    scanf("%d", &nueva.idPaciente);
    if (!existePaciente(pacientes, totalPacientes, nueva.idPaciente)) {
        printf("Error: El paciente especificado no existe en el sistema.\n");
        return 0;
    }

    printf("Ingrese ID del medico: ");
    scanf("%d", &nueva.idMedico);
    if (!existeMedico(medicos, totalMedicos, nueva.idMedico)) {
        printf("Error: El médico especificado no existe en el sistema.\n");
        return 0;
    }

    //*** ERROR PENDIENTE, FECHA NO APARECE***/
    printf("Ingrese Fecha (DD/MM/AAAA): ");
    scanf("%s", nueva.fecha);
    printf("Ingrese Hora (HH:MM): ");
    scanf("%s", nueva.hora);

    // Validar disponibilidad / choques de agenda
    for (int i = 0; i < *totalCitas; i++) {
        // Solo evaluamos citas activas (PROGRAMADA) para bloquear horarios
        if (citas[i].estado == PROGRAMADA &&
            strcmp(citas[i].fecha, nueva.fecha) == 0 &&
            strcmp(citas[i].hora, nueva.hora) == 0) {
            
            if (citas[i].idMedico == nueva.idMedico) {
                printf("Error: El medico ya cuenta con una cita en esa fecha y hora.\n");
                return 0;
            }
            if (citas[i].idPaciente == nueva.idPaciente) {
                printf("Error: El paciente ya tiene una cita agendada en ese horario.\n");
                return 0;
            }
        }
    }

    // Asignar estado inicial por defecto
    nueva.estado = PROGRAMADA;
    citas[*totalCitas] = nueva;
    (*totalCitas)++;

    printf("¡Cita programada exitosamente!\n");
    return 1;
}

// Función para consultar la agenda de citas
void citas_consultarAgenda(const struct Cita citas[], int totalCitas) {
    if (totalCitas == 0) {
        printf("No hay citas registradas en el sistema.\n");
        return;
    }
    // **** PENDIENTE AJUSTAR EL FORMATO****
    printf("\n--- AGENDA DE CITAS MEDICAS ---\n");
    printf("%-5s | %-10s | %-10s | %-12s | %-7s | %-12s\n", "ID", "ID Pac.", "ID Med.", "Hora", "Mes", "Estado");
    printf("------------------------------------------------------------------\n");
    
    const char *estadosStr[] = {"PROGRAMADA", "ATENDIDA", "CANCELADA"};

    for (int i = 0; i < totalCitas; i++) {
        printf("%-5d | %-10d | %-10d | %-12s | %-7s | %-12s\n",
               citas[i].id,
               citas[i].idPaciente,
               citas[i].idMedico,
               citas[i].fecha,
               citas[i].hora,
               estadosStr[citas[i].estado]);
    }
}

// Función para cambiar el estado de una cita (****PENDIENTE ***)
int citas_cambiarEstado(struct Cita citas[], int totalCitas) {

}