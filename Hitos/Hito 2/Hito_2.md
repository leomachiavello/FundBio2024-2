# Lungie
## Problemática
La falta de servicios de salud competentes en el Perú ha causado problemas en todo el país, pero las zonas que más afectadas se han visto han sido aquellas con menos recursos.
Esta deficiencia en el servicio de salud se debe a varios motivos, entre ellos la falta de dispositivos de diagnóstico eficientes y de bajo costo lo que ocasiona que veamos cifras tan alarmantes como llegar a ver aproximadamente un 64% de diagnósticos erróneos en el país.
## Solución
Es por esto que hemos desarrollado un espirómetro de bajo costo accesible para estas zonas de bajos recursos del país.
La espirometría es una técnica de detección de enfermedades respiratorias obstructivas la cual permite el diagnóstico de las mismas. 

Nuestro proyecto busca ser principalmente un dispositivo portable, de bajo costo, y con una interfaz amigable.
Funciona en tres simples pasos:
1. El paciente exhala a través de la boquilla del espirómetro.
2. Los datos son registrados y procesados por el dispositivo.
3. Se obtienen los resultados y valores buscados.
## Desarrollo del proyecto
### Boceto inicial
Al inicio del proyecto planteamos un boceto que nos sirvió de guía durante el resto del desarrollo.
Como podrán ver a continuación, este borrador inicial se asemeja mucho a como terminó nuestro prototipo actual.
![boceto](https://github.com/leomachiavello/FundBio2024-2/blob/main/Im%C3%A1genes/prototipo_caja.jpeg?raw=true)
### Modelado 3D
El siguiente paso en nuestro objetivo fue realizar el modelado 3D.
Gracias al software OneShape y las librerías de GrabCad pudimos realizar nuestro modelado 3D, el cual después de pasar diversas revisiones por parte de los docentes, recibió el visto bueno y fue mandado a imprimir.
- Vista isométrica sin la tapa:
![sin_tapa](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/Dise%C3%B1o%20mec%C3%A1nico/Renders/Ensamblado/1.jpeg?raw=true)
- Vista isométrica con la tapa:
![con_tapa](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/Dise%C3%B1o%20mec%C3%A1nico/Renders/Ensamblado/2.jpeg?raw=true)
### Manufactura digital
Nuestro proyecto únicamente necesitaba de impresión 3D, ya que lo único necesario era una carcasa y soportes para los componentes.
Al recibir nuestra primera impresión, nos dimos cuenta de errores respecto a las dimensiones de los soportes y huecos para tornillos, los cuales se encontraban desfasados.
Tomando nota de estos errores, hicimos los cambios en el modelado y volvimos a imprimir una segunda versión de la carcasa, la cual finalmente pudo complementarse correctamente con los componentes.
### Diagrama de flujo
Haciendo uso de las librerías correspondientes y las ecuaciones físicas para el cambio de voltaje a flujo hicimos nuestro diagrama de flujo final a partir del cual escribimos nuestro [borrador final del código](https://github.com/leomachiavello/FundBio2024-2/blob/main/Software/borradores/borrador6/borrador6.ino).
![diagrama](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hitos/Hito%202/Im%C3%A1genes%20Hito%202/diagrama_de_flujo_final.jpg?raw=true)
### Esquema electrónico
A diferencia de nuestro esquema electrónico del [Hito 1](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hitos/Hito_1.md), en este prototipo hemos eliminado el regulador de voltaje, ya que ninguno de nuestros componentes lo necesitaba.
También hemos agregado una segunda etapa de amplificación de la señal del sensor de presión haciendo uso de un segundo amplificador LM348.
![esquema](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hitos/Hito%202/Im%C3%A1genes%20Hito%202/esquema_electr%C3%B3nico.png?raw=true)
### Limitaciones
A lo largo de nuestro desarrollo del proyecto nos encontramos con varios percances que limitaron el óptimo funcionamiento del prototipo según nuestro planteamiento. Entre los principales podemos encontrar:
- **Mala compatibilidad entre las librerías de la pantalla OLED (Adafruit) y del lector SD (SD.h):** Cuando usábamos ambas librerías en el mismo programa ninguno de los componentes funcionaba, por lo que tuvimos que recurrir a cambiar de biblioteca de la pantalla OLED a SSD1306 Ascii que es más ligera, por lo que permite el uso de ambas a la vez. Esta librería tiene la desventaja de tener menos opciones, pero aún así se pudo usar para nuestro propósito, ya que solo nos interesa mostrar texto en nuestra pantalla.
- **Amplificadores:** Ambos amplificadores, el de instrumentación (INA126) y el secundario (LM348) nos han dado bastantes problemas durante el desarrollo del proyecto. El INA126 presentaba una gran cantidad de ruido de señal que no permitía una correcta toma de datos del espirómetro, mientras que el LM348 necesitaba de más voltaje del que es capaz nuestro microcontrolador. 
- **Espirómetro de referencia:** El método de espirometría que empleamos para nuestro proyecto fue la neumatacografía, la cual se basa en el uso de un tubo con una resistencia por el cual va a fluir el aire del paciente y donde se va a generar un cambio de presión. Este tiene diferentes variables que pueden afectar a los datos (geometría del tubo, resistencia, posicionamiento de los tubos, etc.). Todas estas variables se juntan para darnos una constante $K$ que se usa en el cálculo del flujo de aire ($Flujo=K\sqrt{\Delta{P}}$). La falta de un espirómetro de referencia hace imposible el cálculo preciso del flujo de aire.