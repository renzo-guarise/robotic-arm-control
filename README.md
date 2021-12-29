# Robot control arm
## Description
In this project my partner Lucas Trubiano and I implemented an Graphical Interface and Client-Server Connection for the control of an ABB IRB 460 robot arm. Also we used the library robotics toolbox by Peter Corke which we were able to simulate the robot and visualize how the robot did the instrutions from the client

##Objectives
- Implementar OOP.
- Utilizar modelos de capas (al menos 2), de manera que la solución
pueda usarse independientemente de que haya interfaz gráfica o de consola.
- Los módulos del lado servidor deben estar desarrollados en Python
- Los módulos del lado cliente deben estar desarrollados en C++.
- El desarrollo debe ser operativo bajo plataforma Linux para los módulos del lado
servidor y cliente.
###Servicios del lado servidor:
- Panel de control del robot, mediante consola (CLI) que permita realizar:
  - Conexión/desconexión al Robot usando comunicación serial.
  - Activación/Desactivación del robot.
  - Listado de los comandos de control
  - Ayuda con ejemplificación de la sintaxis requerida3 para los comandos que lo requieran.
  - Servidor XML-RPC, capaz de ejecutar las mismas operaciones anteriores solicitadas en forma remota.
  - La aplicación de consola debe implementar herencia desde la clase Cmd

### Servicios del lado Cliente. La interfaz principal debe ofrecer:
  - Panel de control del robot, con funcionalidades similares a las de la interfaz de consola.
  - Reporte mostrando la conexión, el estado de actividad del Robot, el instante de tiempo (acumulado) desde el inicio de actividad, el instante de inicio de cada orden, las coordenadas de cada articulación del robot y, de estar disponible, la velocidad del efector final.
  - GUI de control y monitoreo de parámetros.
  - Despliegue visual del robot, usando vista 3D o proyecciones.
  - Tabla o curvas que muestren la velocidad de cada uno de los vínculos.
  - Aprendizaje de trayectoria con almacenamiento de las órdenes correspondientes en un archivo de texto (legible) que permita reproducir la misma.
