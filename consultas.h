#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "modelos.h"

// Registra la información clínica de una cita en estado PROGRAMADA 
int consultas_registrar(struct Consulta consultas[], int *totalConsultas, struct Cita citas[], int totalCitas);

// Consulta el historial de consultas y diagnósticos de un paciente específico 
void consultas_consultarHistorial(const struct Consulta consultas[], int totalConsultas, const struct Cita citas[], int totalCitas, int idPaciente);

#endif