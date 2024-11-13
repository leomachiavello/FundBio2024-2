# Software
## [Códigos de prueba](https://github.com/leomachiavello/FundBio2024-2/tree/main/Software/c%C3%B3digos_prueba)
Agregamos códigos de prueba para cada componente electrónico (excluyendo el lector de tarjetas SD) con los cuales podemos realizar testeos. Estos se mostraron útiles sobre todo en la implementación de la pantalla de OLED y pruebas con la ganancia del amplificador INA126.
## [Borrador 1](https://github.com/leomachiavello/FundBio2024-2/tree/main/Software/borradores/borrador1)
Nuestra intención con este primer borrador fue la de integrar los principales componentes del proyecto. Hasta este punto todavía no teníamos la pantalla OLED, por lo que está excluída del código. Básicamente el código toma valores digitales del sensor y los pasa a voltaje haciendo uso de la ecuación $V=\frac{5.0}{1023.0}$ donde 5.0 representa el voltaje de la fuente y 1023.0 el número de bits máximo de la señal digital del Arduino. 
## [Borrador 2](https://github.com/leomachiavello/FundBio2024-2/tree/main/Software/borradores/borrador2)
En este segundo borrador implementamos la pantalla OLED junto a los demás componentes haciendo uso de librerías externas como Adafruit_GFX y Adafruit_SSD1306. En la pantalla OLED se muestran los valores de voltaje.
## [Borrador 3](https://github.com/leomachiavello/FundBio2024-2/tree/main/Software/borradores/borrador3)
En el tercer borrador implementamos un módulo en el código cuya función es la de promediar 10 valores en el lapso de un segundo de las señales amplificadas del sensor. Esto se hizo con el objetivo de reducir la variación de valores que se crea por el amplificador. 
## [Borrador 4](https://github.com/leomachiavello/FundBio2024-2/tree/main/Software/borradores/borrador4)
Finalmente en este borrador hemos juntado todo lo previamente mencionado e implementado un cronómetro que se activa al momento que el voltaje sobrepasa cierto límite. También en este código podemos generar un reporte del voltaje máximo y un promedio de los voltajes obtenidos para obtener información sobre la prueba.
## Parámetros de la espirometría
![parámetros](https://github.com/leomachiavello/FundBio2024-2/blob/main/Im%C3%A1genes/par%C3%A1metros_espirometr%C3%ADa.jpeg?raw=true)

Existen una serie de parámetros relacionados con la espirometría como el FVC, FEV6, FEV1 y PEF que sirven para detectar y clasificar enfermedades respiratorias. Entre los mencionados destacan el FVC y FEV1, ya que con estos se obtiene un índice con el que se clasifica una enfermedad respiratoria como obstructiva o restrictiva, lo que se ajusta a los objetivos de este proyecto.
# Hardware
## [Amplificador INA126](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/Datasheets/INA126_datasheet.pdf)
La fórmula de la ganancia de este amplificador en específico es la siguiente: 
$G=5+\frac{80k\Omega}{R_G}$. Actualmente la resistencia que estamos empleando para la ganancia es de $1k\Omega$ por lo que nuestra ganancia resultante es de 85. Aunque esta ganancia no es tan pequeña, tampoco es ideal para nuestro caso ya que el rango de voltajes del sensor se encuentra entre los 0 a 25mV, por lo que lo ideal será emplear una ganancia de 1000 que sea estable. Nuestras opciones de solución son las siguientes:
### Usar una resistencia menor 
Esta solución implicaría una mayor inestabilidad en la señal brindada por el amplificador, por lo que también se tendrían que implementar filtros de ruido usando capacitores y pequeños circuitos RC.
### Usar un amplificador extra
Esta solución sería un poco más costosa que la anterior, pero sería más simple. El amplificador que planeamos implementar es el **LM358**, el cual es económico y simple de usar. Para ajustar la ganancia se hace uso de dos resistencias, siguiendo la siguiente fórmula: $G=1+\frac{R_f}{R_{in}}$.
## Modelado 3D
Para este semana hemos logrado culminar al 100% nuestro modelo 3D, arreglamos las correciones indicadas por el profesor Andoni Molina y enviamos nuestras 5 piezas a imprimir, estamos a la espera que nos avisen para poder recogerlas. Acá tenemos algunas imagenes de nuestro modelo ensamblado, tenemos los [planos](https://github.com/leomachiavello/FundBio2024-2/tree/main/Hardware/Planos%20finales) de las 5 piezas corregidos y actualizados al igual que los [archivos stl](https://github.com/leomachiavello/FundBio2024-2/tree/main/Hardware/Archivos%20STL).
### Vistas isométricas del ensamblado
![1](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/Dise%C3%B1o%20mec%C3%A1nico/Renders/Ensamblado/1.jpeg?raw=true)
![2](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/Dise%C3%B1o%20mec%C3%A1nico/Renders/Ensamblado/2.jpeg?raw=true)
![4](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/Dise%C3%B1o%20mec%C3%A1nico/Renders/Ensamblado/4.jpeg?raw=true)
### Vista superior
![3](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/Dise%C3%B1o%20mec%C3%A1nico/Renders/Ensamblado/3.jpeg?raw=true)
### Vista inferior
![5](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/Dise%C3%B1o%20mec%C3%A1nico/Renders/Ensamblado/5.jpeg?raw=true)
## [Esquema electrónico](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/Dise%C3%B1o%20electr%C3%B3nico/Esquema_electr%C3%B3nico.pdf)
Actualizamos el esquema electrónico previo, eliminando el regulador de voltaje que no fue necesario para el proyecto e incluyendo el segundo amplificador LM358.