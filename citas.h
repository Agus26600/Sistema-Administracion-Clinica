#ifndef CITAS_H
#define CITAS_H

#include "modelos.h"

// Registra una nueva cita validando existencia y disponibilidad 
int citas_registrar(struct Cita citas[], int *totalCitas, const struct Paciente pacientes[], int totalPacientes, const struct Medico medicos[], int totalMedicos);

// Muestra las citas registradas en el sistema 
void citas_consultarAgenda(const struct Cita citas[], int totalCitas);

// Cambia el estado de una cita a ATENDIDA o CANCELADA 
int citas_cambiarEstado(struct Cita citas[], int totalCitas);

#endif