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
(agregar boceto)
### Modelado 3D
El siguiente paso en nuestro objetivo fue realizar el modelado 3D.
Gracias al software OneShape y las librerías de GrabCad pudimos realizar nuestro modelado 3D, el cual después de pasar diversas revisiones por parte de los docentes, recibió el visto bueno y fue mandado a imprimir.
(agregar imágenes del modelado)
### Manufactura digital
Nuestro proyecto únicamente necesitaba de impresión 3D, ya que lo único necesario era una carcasa y soportes para los componentes.
Al recibir nuestra primera impresión, nos dimos cuenta de errores respecto a las dimensiones de los soportes y huecos para tornillos, los cuales se encontraban desfasados.
Tomando nota de estos errores, hicimos los cambios en el modelado y volvimos a imprimir una segunda versión de la carcasa, la cual finalmente pudo complementarse correctamente con los componentes.
### Diagrama de flujo
### Esquema electrónico
A diferencia de nuestro esquema electrónico del [Hito 1](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hitos/Hito_1.md), en este prototipo hemos eliminado el regulador de voltaje, ya que ninguno de nuestros componentes lo necesitaba.
También hemos agregado una segunda etapa de amplificación de la señal del sensor de presión haciendo uso de un segundo amplificador LM348.
![esquema](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hitos/Hito%202/Im%C3%A1genes%20Hito%202/esquema_electr%C3%B3nico.png?raw=true)