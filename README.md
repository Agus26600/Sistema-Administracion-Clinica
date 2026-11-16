## Sistema Modular de Administración Clínica

##  Antecedentes de la Propuesta

La administración de una clínica implica organizar y mantener actualizada una cantidad considerable de información relacionada con sus actividades diarias. Entre los datos más importantes se encuentran los registros de los pacientes, la información del personal médico, la programación de citas y el historial de las consultas realizadas. La correcta organización de estos elementos es fundamental para facilitar la atención de los pacientes y mantener un control adecuado de los servicios que ofrece el establecimiento.

En algunas clínicas, especialmente aquellas que no cuentan con sistemas informáticos especializados, parte de esta información puede administrarse mediante documentos físicos, hojas de cálculo o registros independientes. Aunque estos métodos permiten almacenar datos, también pueden ocasionar dificultades al momento de consultar información, actualizar registros o relacionar los datos de diferentes áreas. Entre los problemas que pueden presentarse se encuentran la duplicación de información, la pérdida de registros, los errores en la programación de citas y la dificultad para dar seguimiento a las consultas anteriores de un paciente.

Ante esta situación, se propone desarrollar un sistema que permita administrar la información básica de una clínica de manera estructurada. El programa facilitará el registro, consulta, búsqueda, modificación y eliminación de información de pacientes y médicos, así como administrar las citas y mantener un historial de las consultas realizadas.

### ¿Qué tiene de diferente este proyecto?
Si se compara con el caso de los sistemas comerciales web, es claro que brindan soluciones robustas con interfaces gráficas avanzadas. No obstante, requieren infraestructura de servidores remotos, conexión permanente a internet, licencias de costo elevado y escapan del alcance didáctico y técnico del paradigma de programación estructurada. En el caso de los cálculos, se podría usar fácilmente hojas de cálculo de otras apps, pero estas carecen de integridad referencial estricta (pueden romperse fórmulas o relaciones entre pacientes y médicos fácilmente) y no implementan lógica de negocio automatizada (como validación de choques de horario en tiempo real).

El sistema que se desarrolla en este proyecto se posiciona como una **aplicación de consola modular, eficiente, ligera y autónoma**. Su contribución radica en aplicar estrictamente los principios de modularidad, estructuras de datos estáticas/dinámicas y persistencia en archivos locales, ofreciendo un control transaccional estructurado sin dependencias externas, ideal para entornos de recursos limitados o propósitos académicos de alto rigor técnico.

El proyecto se desarrollará en lenguaje C mediante una aplicación de consola, aplicando los principios de programación estructurada y modular. Para ello, se utilizarán estructuras de datos que permitan representar los diferentes registros del sistema, funciones para separar las operaciones según su responsabilidad y archivos para almacenar la información de manera permanente. La información se almacenará en archivos locales para que los registros permanezcan disponibles después de cerrar el programa. De esta manera, se busca construir una aplicación funcional que permita aplicar los conocimientos de programación estructurada y modular a un problema práctico.

---

##  Descripción del Producto de Software

El producto consiste en un **Sistema de Administración de una Clínica**, desarrollado como una aplicación de consola en lenguaje C, cuyo objetivo es facilitar la organización y el control de la información relacionada con los pacientes, médicos, citas y consultas médicas.

El sistema contará con un menú principal desde el cual los usuarios podrán acceder a las diferentes funcionalidades disponibles. Cada una de estas estará organizada mediante módulos independientes, permitiendo realizar operaciones específicas sin concentrar toda la lógica del programa en un único archivo fuente.

La gestión de pacientes permitirá registrar nuevos usuarios de los servicios médicos, consultar los registros existentes, buscar información mediante identificadores, modificar datos personales y eliminar registros cuando corresponda. De manera similar, el módulo de médicos permitirá administrar la información del personal médico, incluyendo sus datos personales y especialidades, además de facilitar la consulta de los médicos disponibles.

Por otra parte, el módulo de citas permitirá relacionar a los pacientes con los médicos mediante la programación de fechas y horarios de atención. También permitirá consultar la agenda, modificar los datos de una cita, cancelar registros y actualizar su estado de acuerdo con la situación correspondiente. Para mantener una organización adecuada, se incorporarán validaciones que permitan verificar la existencia de los pacientes y médicos involucrados, así como evitar la asignación de citas simultáneas.

El desarrollo se organizará mediante archivos de encabezado `.h`, encargados de contener las declaraciones de estructuras y funciones, y archivos fuente `.c`, donde se implementará la lógica correspondiente a cada módulo. Esta organización permitirá mantener una separación clara de responsabilidades, facilitar la comprensión del código y simplificar futuras modificaciones.

### Características Principales

* **Gestión de pacientes:** Permitirá registrar, consultar, buscar, modificar y eliminar información de los pacientes, manteniendo sus datos organizados y disponibles para las operaciones del sistema.
* **Gestión de médicos:** Permitirá administrar los registros del personal médico, incluyendo sus datos personales, especialidades y disponibilidad para la asignación de citas.
* **Gestión de citas:** Permitirá programar, consultar, modificar y cancelar citas médicas, así como actualizar sus estados y verificar que no existan conflictos de horarios.
* **Historial de consultas:** Permitirá almacenar y consultar información de las atenciones médicas realizadas, relacionando cada consulta con el paciente y el médico correspondiente.
* **Reportes:** Permitirá generar resúmenes estadísticos sobre los pacientes, médicos, citas y consultas, utilizando la información registrada en los diferentes módulos.
* **Validaciones:** Incorporará mecanismos para evitar identificadores duplicados, registros incompletos, referencias a pacientes o médicos inexistentes y programación de citas simultáneas.
* **Almacenamiento de información:** Utilizará archivos locales para conservar los registros y permitir su recuperación cuando el programa vuelva a ejecutarse.

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

##  Requerimientos Funcionales

| ID | Requerimiento | Descripción |
| :--- | :--- | :--- |
| **RF1** | Registrar pacientes | El sistema permitirá dar de alta pacientes con un identificador único y sus datos personales básicos. |
| **RF2** | Consultar pacientes | Permitirá mostrar todos los pacientes o buscar uno por identificador o nombre. |
| **RF3** | Modificar y eliminar pacientes | Permitirá actualizar registros y eliminar aquellos que no tengan citas activas asociadas. |
| **RF4** | Gestionar médicos | Permitirá registrar, consultar, modificar y eliminar médicos, respetando las restricciones de citas pendientes. |
| **RF5** | Programar citas | Permitirá relacionar un paciente con un médico, una fecha y una hora. |
| **RF6** | Validar disponibilidad | Impedirá programar dos citas activas simultáneas para el mismo médico o paciente. |
| **RF7** | Gestionar estados de citas | Permitirá marcar las citas como programadas, atendidas o canceladas. |
| **RF8** | Consultar historiales | Permitirá consultar las citas y las consultas registradas para cada paciente. |
| **RF9** | Generar reportes | Calculará estadísticas de pacientes, médicos, citas y consultas. |
| **RF10** | Guardar información | Almacenará los registros en archivos locales. |
| **RF11** | Recuperar información | Cargará los datos guardados cuando se inicie el programa. |
| **RF12** | Validar entradas | Detectará opciones inválidas, identificadores inexistentes y datos fuera de los límites permitidos. |

---

##  Requerimientos No Funcionales

| ID | Categoría | Descripción |
| :--- | :--- | :--- |
| **RNF1** | Modularidad | El programa deberá estar dividido en módulos `.c` y `.h` con responsabilidades claramente definidas. |
| **RNF2** | Mantenibilidad | El código deberá seguir convenciones uniformes de nombres, comentarios y organización. |
| **RNF3** | Integridad de datos | Las operaciones deberán evitar referencias a pacientes, médicos o citas inexistentes. |
| **RNF4** | Persistencia | Los registros deberán conservarse entre ejecuciones del programa. |
| **RNF5** | Portabilidad | El programa deberá utilizar C estándar en la medida de lo posible y evitar dependencias innecesarias del sistema operativo. |
| **RNF6** | Usabilidad | Los menús y mensajes deberán ser claros y facilitar el uso desde la consola. |
| **RNF7** | Robustez | El sistema deberá detectar errores de entrada y de acceso a archivos sin terminar inesperadamente. |
| **RNF8** | Eficiencia | Las búsquedas y los reportes deberán utilizar procedimientos adecuados al volumen de información esperado para una clínica pequeña. |
| **RNF9** | Seguridad | Si se implementan perfiles de usuario, las operaciones deberán restringirse de acuerdo con los permisos asignados. |
| **RNF10** | Verificabilidad | Las funcionalidades deberán poder probarse mediante casos de prueba documentados y resultados esperados. |
