# Empaquetador-C
Aplicación programada en lenguaje C, la cual tiene una función de unir todos los archivos en uno solo indicando el nombre de arhivo
de salida.

*Esta aplicación puede:*

    1. Crear un archivo empaquetado.
    2. Desempaquetar uno o más archivos de los que contiene un paquete.
    3. Listar los archivos ordenados por diferentes criterios (nombre, tamaño y fecha).
    4. Agregar un archivo al paquete.
    5. Ver los detalles de un archivo en particular dentro del paquete.
    
*Ejemplos de utilizacion:*

    1.Empaquetar archivos con --pack (es obligatorio indicar el nombre del paquete con --output), crea un
    paquete nuevo:
    emp --pack hola.txt chau.txt tres.bin --output file.emp

    2.Desempaquetar archivos con --unpack (si no se indica --outputdir los archivos se extraen en el
    directorio actual):
    emp --unpack hola.txt tres.bin --input file.emp [--outputdir /tmp]

    Desempaquetar todos los archivos con --unpack­all (--input es obligatorio y --outputdir opcional):
    emp --unpack­all --input file.emp [--outputdir /tmp]

    3.Listar archivos empaquetados con --list (--input es obligatorio). --list recibe un parámetro “name”, “date”
    o “size” indicando el criterio de ordenación de los archivos listados (notar que el valor indicado, para el 
    caso de date o size, debe mostrarse al lado del nombre de cada archivo listado):
    emp --list [name|date|size] --input file.emp

    4.Agregar un archivo a un paquete existente con --repack (también es obligatorio --output):
    emp --repack zuatro --output file.emp

    5.Listar con detalles con --detail (--input es obligatorio)
    emp --detail hola.txt --input file.emp
