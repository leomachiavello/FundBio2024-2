# Estado de arte
## Contexto comercial

## Patentes de Invención
### Sistema de diagnóstico de espirometría portátil personal
- **Número de patente:** [KR1020220167645](https://patentscope.wipo.int/search/es/detail.jsf?docId=KR383841388&_cid=P12-M14AZK-98835-1)
- **Año:** 2022
- **País:** Corea del Sur

<div style="display: flex; align-items: center;">
  <img src="https://github.com/leomachiavello/FundBio2024-2/blob/main/Im%C3%A1genes/espirometr%C3%ADa_celular.png?raw=true" alt="description" style="width: 135px; margin-left: 25px; margin-right: 50px">
  <p>La patente describe un "Sistema de Diagnóstico de Espirometría Personal y Portátil". Este dispositivo está diseñado para ofrecer pruebas de espirometría de manera compacta y portátil, permitiendo a los usuarios evaluar su función pulmonar en cualquier lugar. Sus características incluyen un diseño ergonómico para facilitar el uso en el hogar o en movimiento, sensores precisos para medir el flujo y volumen de aire, y la capacidad de almacenar y analizar datos para el diagnóstico de afecciones respiratorias como el asma o la enfermedad pulmonar obstructiva crónica (EPOC). La importancia de esta patente radica en su capacidad para proporcionar una herramienta de diagnóstico accesible y conveniente, lo que puede mejorar la gestión de enfermedades respiratorias y permitir un monitoreo más frecuente y personalizado de la salud pulmonar.</p>
</div>

### Métodos de espirometría para diagnosticar la destrucción leve y temprana del flujo aéreo
- **Número de patente:** [WO2022036172](https://patentscope.wipo.int/search/es/detail.jsf?docId=WO2022036172&_cid=P12-M14B1X-01074-1)
- **Año:** 2022
- **País:** Estados Unidos


<div style="display: flex; align-items: center;">
  <img src="https://github.com/leomachiavello/FundBio2024-2/blob/main/Im%C3%A1genes/metodos_espirometr%C3%ADa.png?raw=true" alt="description" style="width: 155px; margin-left: 25px; margin-right: 35px">
  <p>Esta patente se enfoca en métodos avanzados para diagnosticar obstrucción leve y temprana del flujo aéreo mediante espirometría. Las especificaciones incluyen técnicas mejoradas para medir parámetros como la velocidad máxima de flujo espiratorio (PEF) y el flujo expiratorio forzado en 1 segundo (FEV1). Utiliza algoritmos avanzados para analizar estos datos y detectar patrones sutiles que indican obstrucción antes de que sea evidente con métodos convencionales. Además, incorpora sensores de alta precisión y dispositivos de espirometría que permiten una recolección de datos más detallada y fiable, facilitando una intervención temprana en enfermedades respiratorias como el asma y la EPOC.</p>
</div>

## Patente de Modelo de Utilidad
### Método y dispositivo para mediciones respiratorias utilizando muestras de gas de respiración
- **Número de patente:** [ES2843105T3](https://patents.google.com/patent/ES2843105T3/es?oq=ES2843105T3)
- **Año:** 2021
- **País:** España

La patente describe un dispositivo y método para medir la eficacia del intercambio de gases en los pulmones de manera no invasiva, utilizando muestras de gas respiratorio. El sistema mide la presión parcial de oxígeno (O2) y dióxido de carbono (CO2) durante la respiración y calcula indicadores como la saturación de oxígeno en sangre y el cociente respiratorio.

**Características relevantes:**
- Medición no invasiva: Evalúa la función respiratoria sin necesidad de extraer sangre.
- Detección y monitoreo: Puede detectar condiciones respiratorias anómalas, como hipoxemia y EPOC.
- Multifuncionalidad: Integra sensores para monitorear varios parámetros respiratorios, permitiendo su uso en diferentes pruebas respiratorias.
- Visualización y Alarma: Incluye una pantalla para mostrar los resultados y un sistema de alarmas para alertar sobre problemas respiratorios.
<div style="text-align: center;">
  <img src="https://github.com/leomachiavello/FundBio2024-2/blob/main/Im%C3%A1genes/patente_3.png?raw=true" alt="description" style="width:400px;">
</div>
<br>

# Requerimientos del proyecto
<div style="text-align: center;">
  <table border="1" style="width:100%; margin-left:auto; margin-right:auto;">
    <tr>
      <th style="width:50%">No funcionales</th>
      <th style="width:50%">Funcionales</th>
    </tr>
    <tr>
      <td>Portabilidad. Característica necesaria para el uso en zonas de difícil acceso, una buena portabilidad hará posible el uso del dispositivo en más lugares.</td>
      <td>Medir el flujo y volumen de aire del paciente haciendo uso de sensores.</td>
    </tr>
     <tr>
      <td>Interfaz amigable. Al momento de crear de herramienta de salud accesible, el entorno con el que interactúa el usuario debe ser familiar para él.</td>
      <td>Gestionar los datos de los sensores haciendo uso de un microcontrolador.</td>
    </tr>
    <tr>
      <td>Replicabilidad. Propiedad indispensable para cualquier proyecto open hardware.</td>
      <td>Diferenciación de patologías según las gráficas de resultados.</td>
    </tr>
    <tr>
      <td>No invasivo. A miras de crear un dispositivo simple, un enfoque no invasivo es el más ideal nos permite desarrollar un dispositivo con menor riesgo.</td>
      <td>Evaluación del paciente para determinar su capacidad pulmonar y riesgo a enfermedades pulmonares.</td>
    </tr>
    <tr>
      <td>Bajo costo. Nuestro enfoque en zonas de bajos ingresos requiere de un dispositivo accesible económicamente.</td>
      <td> </td>
    </tr>
   
  </table>
</div>

# Propuesta de solución
<h3>Espirómetro portable de bajo costo que facilite la diferenciación de las principales enfermedades pulmonares (asma, EPOC, neumonía) haciendo uso de sensores de presión y un microcontrolador para la gestión de datos.