
#ifndef MODELOS_H
#define MODELOS_H

#define MAX_PACIENTES 100
#define MAX_MEDICOS 50
#define MAX_CITAS 200
#define MAX_CONSULTAS 100

#define TAM_CADENA 80
#define TAM_FECHA 11
#define TAM_HORA 6

enum EstadoCita {
    PROGRAMADA,
    ATENDIDA,
    CANCELADA
};

struct Paciente {
    int id;
    char nombreCompleto[TAM_CADENA];
    int edad;
    char telefono[20];
};

struct Medico {
    int id;
    char nombreCompleto[TAM_CADENA];
    char especialidad[TAM_CADENA];
};

struct Cita {
    int id;
    int idPaciente;
    int idMedico;
    char fecha[TAM_FECHA];
    char hora[TAM_HORA];
    enum EstadoCita estado;
};

struct Consulta {
    int idCita;
    char motivo[TAM_CADENA];
    char observaciones[TAM_CADENA];
    char diagnostico[TAM_CADENA];
};

#endif
