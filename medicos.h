#ifndef MEDICOS_H
#define MEDICOS_H

#include "modelos.h"

// Registra un nuevo médico validando ID único 
int medicos_registrar(struct Medico lista[], int *total);

// Muestra la lista general de médicos registrados
void medicos_consultar(const struct Medico lista[], int total);

// Busca un médico por ID o nombre 
void medicos_buscar(const struct Medico lista[], int total);

// Modifica los datos de un médico existente 
void medicos_modificar(struct Medico lista[], int total);

// Elimina un médico validando que no tenga citas pendientes 
int medicos_eliminar(struct Medico lista[], int *totalMedicos, const struct Cita citas[], int totalCitas);

#endif