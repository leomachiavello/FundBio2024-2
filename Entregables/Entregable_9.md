# Verificación de diseño (Software)

<table border="1">
  <tr>
    <th rowspan="2">Funcionalidad</th>
    <th colspan="2">Cumplimiento</th>
  </tr>
  <tr>
    <th>Sí</th>
    <th>No</th>
  </tr>
  <tr>
    <td>Recibe señales del sensor de presión</td>
    <td>X</td>
    <td></td>
  </tr>
  <tr>
    <td>Convierte las señales del sensor a presión</td>
    <td></td>
    <td>X</td>
  </tr>
  <tr>
    <td>Mide el tiempo de la prueba</td>
    <td>X</td>
    <td></td>
  </tr>
  <tr>
    <td>Genera un reporte rápido en la pantalla</td>
    <td>X</td>
    <td></td>
  </tr>
  <tr>
    <td>Genera un tabla con los datos en la tarjeta microSD</td>
    <td></td>
    <td>X</td>
  </tr>
</table>

# Verificación de diseño (Hardware)
| **Requerimiento de Diseño**                                        | **Resultado del Test**                                                                                           |
|--------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|
| El dispositivo sumado al sistema de ajuste debe pesar máximo 300 gramos. | En suma de todos los componentes electrónicos el dispositivo cuenta con un peso de 260 gramos.                  |
| Debe tener una autonomía de 2 horas aproximadamente.               | Con una batería de 9 voltios, se estima una duración aproximada de 5 horas tomando en cuenta el consumo de los elementos utilizados. |
| Debe ser simple de usar para el usuario                            | El dispositivo cuenta con solo un switch de encendido y apagado.                                                |
| Se debe seleccionar un sistema con boquilla desechable para que evitar contaminación en el dispositivo. | El sistema cuenta con una serie de boquillas desechables que permiten evitar cualquier tipo de contaminación.    |
| El dispositivo de sonido buzzer proyecta un sonido a una frecuencia mayor o menor rango al señalizado por el Arduino Uno. | El dispositivo buzzer se activa a señal del Arduino Uno.                                                        |
| Mide la presión dada por la espiración del usuario.                | El sensor de presión MPX2010DP mide la presión del usuario gracias a los amplificadores implementados |
| La interacción entre componentes se acciona mediante el protoboard y el Arduino Uno. | La interfaz entre los componentes otorga un resultado satisfactorio a través de la conexión con el protoboard señalizado al Arduino Uno. |
| El dispositivo es compacto y permite fácil transporte.             | El dispositivo tiene unas dimensiones 157x147x49 mm que permiten su fácil transporte y un diseño compacto.          |
| El dispositivo permite almacenar y transmitir datos.               | El dispositivo permite almacenar datos gracias a la micro SD, transmitirlos gracias a la pantalla OLED y procesarlos gracias al Arduino Uno. |
