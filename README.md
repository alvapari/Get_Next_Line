## Get Next Line

*Get Next Line* es el tercer proyecto de la escuela de programación 42 School. 

El proyecto consiste en implementar una función que **acceda a un archivo externo y vaya imprimiendo por pantalla**, cada vez que se llama a la función,
**una línea de texto de ese archivo**. Por tanto, si se llama a Get_Next_Line en bucle, se acabará imprimiento el archivo completo, línea a línea.

<br> 

**Conceptos clave del proyecto:**
<br> 
- El usuario que ejecute el programa podrá introducir, a la hora de compilar, **un BUFFER_SIZE=xx que determinará el tamaño del buffer de las lecturas
  de la función Get_Next_Line**, por tanto, sea ese tamaño 01 (lectura de 1 carácter) o sea de 1.000 (lectura de 1.000 caracteres) la función deberá imprimir
  solo una línea. En el primer caso (1 caracter) la función deberá realizar varias lecturas para devolver 1 línea,  **en el segundo caso** (1000 caracteres) **la
  función deberá realizar solo una lectura**, devolver una línea, y **gestionar bien el resto de memoria que ha leído y no ha impreso**.
- **Variable estática:** primera vez que el estudiante de 42 trabaja con ellas.
- **File descriptor:** constante acceso y lectura a un archivo externo.

<br> 



Si quieres ver la **documentación completa** del proyecto, puedes ver estos apuntes: <br> 
https://42guideprojects.notion.site/Get-Next-Line-f8513f536df1483c93c8c058af938f1e

<br> 
Si quieres leer los requerimientos del proyecto, puedes encontrarlos aquí: <br> 
https://github.com/user-attachments/files/17881957/es.subject.pdf
