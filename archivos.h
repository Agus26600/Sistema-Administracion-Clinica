
#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "modelos.h"

//carga la informacion de todos los archivos al iniciar el programa
int archivos_cargarTodo(
    struct Paciente pacientes[], int *totalPac,
    struct Medico medicos[], int *totalMed,
    struct Cita citas[], int *totalCit,
    struct Consulta consultas[], int *totalCon
);

//guarda la informacion de todos los modulos
int archivos_guardarTodo(
    const struct Paciente pacientes[], int totalPac,
    const struct Medico medicos[], int totalMed,
    const struct Cita citas[], int totalCit,
    const struct Consulta consultas[], int totalCon
);

#endif
