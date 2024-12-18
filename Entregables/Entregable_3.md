# Problemática
## Contexto
En la actualidad, Perú enfrenta una serie de problemas relacionados con el servicio sanitario del país. Entre los factores que originan la situación mencionada, destacan deficiencias como la escasez de centros de salud, falta de personal calificado, equipos obsoletos y hospitales saturados.
Los factores mencionados dificultan y limitan el diagnóstico de enfermedades, especialmente en los sectores con más carencias en el país. Las enfermedades respiratorias obstructivas, como el asma, EPOC y enfisema; son algunas de las cuales causan más problemas en la población debido a la dificultad de diagnóstico frente a su alta prevalencia. En Latinoamérica, el asma alcanza una prevalencia de 17%, con fluctuaciones que oscilan entre 5 y 30%. En 2023, en Perú se registraron 1253 casos de asma [1]. Por otro lado, a nivel global, la EPOC es la tercera causa de muerte y la séptima causa de mala salud.

Para diagnosticar enfermedades respiratorias es necesaria la espirometría, pero se utiliza con poca frecuencia. A pesar del progreso en la disponibilidad de espirómetros en nuestro país y de la constante formación de especialistas en Neumología en los últimos años, aún continúa siendo insuficiente accesibilidad a estos recursos, especialmente en el ámbito público [2]. Esto ha llevado a una alarmante cifra de diagnósticos erróneos (64% de los casos), lo que es una prueba de la urgencia de mejora en este aspecto.

![asma_estadística](https://github.com/leomachiavello/FundBio2024-2/blob/main/Im%C3%A1genes/asma_estad.png?raw=true)

## Definición de problema
El problema que se abordará es el de la deficiencia en el diagnóstico de enfermedades respiratorias obstructivas en las zonas de escasos recursos en Perú.

## Impacto 
Este problema afecta a los usuarios en diversos aspectos. La falta de diagnóstico oportuno impide iniciar un tratamiento adecuado a tiempo, lo que puede agravar la enfermedad y aumentar el riesgo de complicaciones. Además, los síntomas de las enfermedades respiratorias, como dificultad para respirar, tos crónica y fatiga, pueden afectar significativamente la calidad de vida de los pacientes, limitando sus actividades diarias y su participación social.

# Propuesta de solución
## Descripción de la solución
Espirómetro portable de bajo costo que contribuya a la detección de exámenes correctamente realizados haciendo uso de sensores de presión, un dispositivo buzzer (para ser usado de alerta por el uso correcto o incorrecto por el uso del usuario) y un microcontrolador para la gestión de datos. Nuestro dispositivo busca directamente solucionar el problema de la deficiencia en el diagnóstico, la precisión y diferenciación de enfermedades respiratorias en zonas de bajos recursos, entregándonos un equipo (espirómetro) accesible para un uso frecuente en zonas de bajos recursos y que cumpla efectivamente con el rol de identificar la patología pulmonar.
## Características del dispositivo
- Sensor de presión diferencial que mide el aire que emite la persona al momento de exhalar.
- Dispositivo buzzer integrado para advertir al paciente cuando esté cometiendo un error en el examen.
- Case impreso en 3D para costos reducidos.
- Portabilidad para una mayor accesibilidad en zonas rurales.
- Bajo consumo de energía.
## Beneficios 
El principal problema que encontramos en la espirometría de bajo costo, es la precisión y la exactitud de los exámenes, debido a que los usuarios no realizan el examen de manera óptima, por lo que la implementación del dispositivo buzzer contribuye en esta situación, generando un sonido luego de realizada la prueba para notificar si es que el usuario a relizado el examen de manera óptima (analizando el tiempo, el flujo de aire y el volumen total del aire inhalado y exhalado del examen realizado por el usuario); dando como consecuencia, un análisis diferenciado.
- Implementación de buzzer (SFM-20B), el cual emitirá distintos tipos de sonido dependiendo de los datos analizados.
- El hardware usado para el ensamble del dispositivo tiene un coste accesible, tomando en cuenta las posibilidades de las zonas de bajos recursos del Perú.
- Su tamaño ayuda a su portabilidad y distribución.
Su bajo consumo energético busca no crear un inconveniente económico a sus usuarios.
El prototipo podrá ser fácilmente replicable al contar con información necesaria para poder ser considerado open hardware.
## Viabilidad técnica
- Uso de dispositivos accesibles como el sensor de presión, microcontrolador, buzzer y una pantalla LCD (MPX210DP, SFM-20B, LCD1622-BMDWH6)
- Conocimiento en softwares de modelado e impresiones en 3D.
- Utilizando el sensor de presión podremos medir el tiempo para el uso correcto del dispositivo.
- Conocimiento en Git.
- Conocimiento en el uso de Arduino.
# Coherencia
## Objetivo general
Desarrollar un espirómetro portátil de bajo costo que permita detectar de manera eficiente un examen realizado correctamente respecto a enfermedades respiratorias como el asma, EPOC y neumonía en zonas de bajos recursos en Perú.
## Objetivos específicos
- Implementar sensores de presión en el espirómetro para medir el flujo de aire del paciente.
- Integrar un microcontrolador para la gestión de los datos obtenidos.
- Diseñar un sistema portátil, accesible y de fácil uso para su implementación en áreas de bajos recursos.
- Validar el prototipo mediante pruebas comparativas con dispositivos comerciales de espirometría.
## Justificación del prototipo
El espirómetro portátil propuesto es la mejor solución debido a su enfoque en reducir costos sin perder su funcionalidad inicial. El dispositivo presenta un sensor de presión diferencial (MPX210DP) con una exactitud del 1%, que mide hasta 10 kPa de presión de trabajo, y tiene un tiempo de respuesta de 1 ms (3). A diferencia de otros dispositivos de mayor precio, este espirómetro utiliza componentes que cumplen con los estándares de diagnóstico a un costo reducido. Mientras que los espirómetros comerciales cuestan aproximadamente 900 soles (4), el costo mínimo estimado de nuestro prototipo es de 200 soles (sensor de presión MPX210DP: 145 soles (5), buzzer SFM-20B: 5 soles (6), pantalla LCD1622-BMDWH6 (7):50  soles sin incluir la carcasa impresa en 3D), lo que lo hace accesible para comunidades vulnerables.

Este espirómetro permite ofrecer un diagnóstico pulmonar preciso a un precio accesible. En las zonas rurales del Perú, donde el acceso a los servicios de salud no es el esperado, un porcentaje significativo de la población no recibe un diagnóstico adecuado. Además, la propuesta mejoraría el acceso al diagnóstico en estas áreas, con componentes que pueden impactar positivamente a las personas en situación de pobreza o vulnerabilidad, quienes actualmente enfrentan graves deficiencias en el diagnóstico temprano de enfermedades respiratorias. Se estima que el dispositivo podría impactar significativamente a esta población, mejorando así la capacidad de diagnóstico en estas zonas.
## Alineación con el problema
Este espirómetro portátil de bajo costo responde a la necesidad de mejorar el diagnóstico de enfermedades respiratorias (asma, EPOC, neumonía) en zonas de bajos recursos en Perú, donde el acceso a equipos médicos avanzados es limitado. Actualmente, los espirómetros comerciales son costosos y requieren infraestructura y personal especializado, lo que los hace poco accesibles para estas comunidades.

El 20% de la población peruana vive en zonas rurales, donde el acceso a servicios de salud es deficiente. Dentro de este grupo, el 40% es pobre y otro 40% es vulnerable, enfrentando dificultades en el acceso a diagnósticos tempranos de enfermedades respiratorias como el asma, la EPOC y la neumonía (8). En las áreas rurales, solo el 3,1% de la población adulta mayor ha sido diagnosticada con asma, en comparación con el 4,9% en áreas urbanas. Además, la neumonía ha causado 248 defunciones en menores de 5 años, siendo Loreto, Cusco y Junín los departamentos con mayor número de casos (9). 

La solución propuesta, basada en un sensor de presión diferencial y un microcontrolador, ofrece una alternativa accesible y fácil de usar, que puede implementarse en áreas rurales. Esto permitirá realizar diagnósticos tempranos y mejorar el manejo de enfermedades respiratorias, reduciendo la brecha de atención médica en poblaciones vulnerables.


# Resumen
La accesibilidad al diagnóstico y seguimiento de enfermedades pulmonares ha sido y sigue siendo una problemática en las zonas alejadas del mundo donde los servicios de salud son precarios. Pruebas como la espirometría han tenido avances en su accesibilidad a este tipo de poblaciones, pero siguen habiendo retos que deben ser enfrentados, como la baja precisión y exactitud, necesidad de especialistas, el cansancio que genera debido a la repetición, etc. Es por esto que nuestra solución se enfoca en la accesibilidad en costo y portabilidad, y en generar avisos al paciente para notificarle sobre un proceso de expiración erróneo que pueda afectar a los resultados de la prueba.

Nuestra visión para el dispositivo es que con este se puedan realizar campañas y visitas a hogares de poblaciones vulnerables que vivan en zonas alejadas para que no se den casos de enfermedades pulmonares no diagnosticadas, las cuales en casos graves, pueden llevar al paciente a la muerte.

Nuestro siguiente paso para hacer realidad el proyecto a partir de lo que tenemos, es especificar aquellas características que queremos implementar, buscar componentes que se puedan integrar unos con otros y que sean de un buen costo para nuestro propósito de brindar accesibilidad. 

# Fuentes 

[1]	Centro Nacional de Epidemiología, Prevención y Control de Enfermedades, “BOLETÍN EPIDEMIOLÓGICO DEL PERÚ”, 2023.

[2]	S. P. de Neumología, “Guía Peruana de EPOC - 2016”, 2016.

[3] Mouser.pe. [En línea]. Disponible en: https://www.mouser.pe/ProductDetail/NXP-Semiconductors/MPX2010DP?qs=N2XN0KY4UWUZAyVjnqwQiQ%3D%3D. 

[4] “Espirómetro digital”, Medifay |, 16-feb-2021. [En línea]. Disponible en: https://www.medifay.pe/producto/espirometro-digital/.

[5] “Sensor de Presión MPX2010DP”, Electromanía Perú. [En línea]. Disponible en: https://www.electromania.pe/producto/sensor-de-presion-mpx2010dp/. 

[6] Naylampmechatronics.com. [En línea]. Disponible en: https://naylampmechatronics.com/interfaz-de-usuario/367-piezo-buzzer-activo-sfm-20b-dc3-24v-2312.html.

[7] Naylampmechatronics.com. [En línea]. Disponible en: https://naylampmechatronics.com/lcd-alfanumerico/653-display-alfanumerico-lcd-lc1622-verde.html.

[8] “La deficiente atención de salud en área rural”, ArchivoRevista Ideele. [En línea]. Disponible en: https://revistaideele.com/ideele/content/la-deficiente-atenci%C3%B3n-de-salud-en-%C3%A1rea-rural.

[9] Gob.pe. [En línea]. Disponible en: https://www.inei.gob.pe/media/MenuRecursivo/publicaciones_digitales/Est/Lib1146/cap04.pdf. 

