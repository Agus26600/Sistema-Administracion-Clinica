## Objetivos del Sistema

###  Objetivo General
Desarrollar un sistema modular de administración clínica mediante el lenguaje **ANSI C**, aplicando los fundamentos de la programación estructurada, modularización por archivos `.c` y `.h`, manejo de estructuras de datos y persistencia en archivos de texto; con el fin de optimizar el control de pacientes, personal médico, programación de citas y expedientes de consultas de un establecimiento médico, garantizando la integridad de la información y facilitando la generación de reportes estadísticos para la toma de decisiones.

###  Objetivos Específicos

1. **Gestión de Pacientes:** Diseñar e implementar un módulo que permita registrar, consultar, buscar, modificar y eliminar información, incorporando validaciones para mantener la integridad de los registros.
2. **Administración de Médicos:** Desarrollar un módulo que permita gestionar datos personales y especialidades, así como consultar su información y disponibilidad para la programación de citas.
3. **Gestión de Citas:** Implementar un sistema de programación y administración que relacione pacientes y médicos mediante identificadores únicos, facilitando la organización de fechas y horarios.
4. **Validaciones del Sistema:** Incorporar validaciones para verificar la existencia de registros relacionados, evitar identificadores duplicados y prevenir la asignación de citas simultáneas para un mismo paciente o médico.
5. **Historial de Consultas:** Desarrollar un módulo que permita registrar y consultar las atenciones médicas realizadas, manteniendo la relación entre consultas, pacientes y médicos.
6. **Persistencia de Datos:** Implementar mecanismos de lectura y escritura de archivos para almacenar la información permanentemente y recuperarla en nuevas ejecuciones.
7. **Reportes Estadísticos:** Diseñar un módulo de generación de reportes para obtener estadísticas de pacientes registrados, médicos disponibles, citas programadas y consultas atendidas.
8. **Arquitectura y Modularidad:** Organizar el código fuente mediante archivos `.c` y `.h`, separando las responsabilidades de cada módulo para facilitar el mantenimiento e integración.
9. **Pruebas Funcionales:** Realizar pruebas para verificar el correcto funcionamiento de las operaciones, comprobar las validaciones y asegurar la consistencia de la información entre módulos.
