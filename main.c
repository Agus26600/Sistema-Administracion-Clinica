
#include <stdio.h>
#include "modelos.h"
#include "pacientes.h"
#include "medicos.h"
#include "citas.h"
#include "consultas.h"
#include "reportes.h"
#include "archivos.h"

int main(void) {
    int opcion, subopcion;

    // Arreglos y contadores
    struct Paciente listaPacientes[MAX_PACIENTES];
    int totalPacientes = 0;

    struct Medico listaMedicos[MAX_MEDICOS];
    int totalMedicos = 0;

    struct Cita listaCitas[MAX_CITAS];
    int totalCitas = 0;

    struct Consulta listaConsultas[MAX_CONSULTAS];
    int totalConsultas = 0;

    // Cargar información al iniciar
    archivos_cargarTodo(
        listaPacientes, &totalPacientes,
        listaMedicos, &totalMedicos,
        listaCitas, &totalCitas,
        listaConsultas, &totalConsultas
    );

    do {
        printf("\n=========================================\n");
        printf("   SISTEMA DE ADMINISTRACION CLINICA\n");
        printf("=========================================\n");
        printf("1. Gestion de pacientes\n");
        printf("2. Gestion de medicos\n");
        printf("3. Administracion de citas\n");
        printf("4. Historial de consultas\n");
        printf("5. Reportes y estadisticas\n");
        printf("6. Guardar informacion\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {

            // PACIENTES
            case 1:
                do {
                    printf("\n--- GESTION DE PACIENTES ---\n");
                    printf("1. Registrar paciente\n");
                    printf("2. Consultar pacientes\n");
                    printf("3. Modificar paciente\n");
                    printf("4. Regresar\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &subopcion);

                    switch (subopcion) {
                        case 1:
                            pacientes_registrar(listaPacientes, &totalPacientes);
                            break;

                        case 2:
                            pacientes_consultar(listaPacientes, totalPacientes);
                            break;

                        case 3:
                            pacientes_modificar(listaPacientes, totalPacientes);
                            break;

                        case 4:
                            break;

                        default:
                            printf("Opcion invalida.\n");
                    }
                } while (subopcion != 4);
                break;

            // MEDICOS
            case 2:
                do {
                    printf("\n--- GESTION DE MEDICOS ---\n");
                    printf("1. Registrar medico\n");
                    printf("2. Consultar medicos\n");
                    printf("3. Buscar medico\n");
                    printf("4. Modificar medico\n");
                    printf("5. Eliminar medico\n");
                    printf("6. Regresar\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &subopcion);

                    switch (subopcion) {
                        case 1:
                            medicos_registrar(listaMedicos, &totalMedicos);
                            break;

                        case 2:
                            medicos_consultar(listaMedicos, totalMedicos);
                            break;

                        case 3:
                            medicos_buscar(listaMedicos, totalMedicos);
                            break;

                        case 4:
                            medicos_modificar(listaMedicos, totalMedicos);
                            break;

                        case 5:
                            medicos_eliminar(listaMedicos, &totalMedicos,
                                            listaCitas, totalCitas);
                            break;

                        case 6:
                            break;

                        default:
                            printf("Opcion invalida.\n");
                    }
                } while (subopcion != 6);
                break;

            // CITAS
            case 3:
                do {
                    printf("\n--- ADMINISTRACION DE CITAS ---\n");
                    printf("1. Registrar cita\n");
                    printf("2. Consultar agenda\n");
                    printf("3. Cambiar estado de cita\n");
                    printf("4. Regresar\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &subopcion);

                    switch (subopcion) {
                        case 1:
                            citas_registrar(listaCitas, &totalCitas,
                                            listaPacientes, totalPacientes,
                                            listaMedicos, totalMedicos);
                            break;

                        case 2:
                            citas_consultarAgenda(listaCitas, totalCitas);
                            break;

                        case 3:
                            citas_cambiarEstado(listaCitas, totalCitas);
                            break;

                        case 4:
                            break;

                        default:
                            printf("Opcion invalida.\n");
                    }
                } while (subopcion != 4);
                break;

            // CONSULTAS
            case 4:
                do {
                    printf("\n--- HISTORIAL DE CONSULTAS ---\n");
                    printf("1. Registrar consulta\n");
                    printf("2. Consultar historial de paciente\n");
                    printf("3. Regresar\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &subopcion);

                    switch (subopcion) {
                        case 1:
                            consultas_registrar(listaConsultas, &totalConsultas,
                                                listaCitas, totalCitas);
                            break;

                        case 2: {
                            int idPaciente;
                            printf("Ingrese el ID del paciente: ");
                            scanf("%d", &idPaciente);

                            consultas_consultarHistorial(
                                listaConsultas, totalConsultas,
                                listaCitas, totalCitas,
                                idPaciente
                            );
                            break;
                        }

                        case 3:
                            break;

                        default:
                            printf("Opcion invalida.\n");
                    }
                } while (subopcion != 3);
                break;

            // REPORTES (***PENDIENTE***)
            case 5:
                printf("\n");
                break;

            // GUARDAR (***PENDIENTE***)
            case 6:
                if (archivos_guardarTodo(
                    listaPacientes, totalPacientes,
                    listaMedicos, totalMedicos,
                    listaCitas, totalCitas,
                    listaConsultas, totalConsultas
                )) {
                    printf("pendiente\n");
                } else {
                    printf("error\n");
                }
                break;

            case 7:
                printf("Saliendo del sistema.\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 7);

    return 0;
}
