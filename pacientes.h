#ifndef PACIENTES_H
#define PACIENTES_H

#include "modelos.h"

// Declaraciones de funciones del módulo de pacientes
int pacientes_registrar(struct Paciente lista[], int *total);
void pacientes_consultar(const struct Paciente lista[], int total);
int pacientes_buscarPorId(const struct Paciente lista[], int total, int id);
void pacientes_modificar(struct Paciente lista[], int total);

#endif