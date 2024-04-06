#!/bin/bash

# Función para imprimir el menú de ayuda
imprimir_menu() {
    echo "Uso: [-m] Mode  [-d] DATE"
    echo " -h : imprimir menú de ayuda"
    echo " -m : modo de funcionamiento del informe. Las opciones disponibles son: servidor_web, base_de_datos, proceso_batch, aplicación, monitoreo."
    echo " -d : Especifica la fecha en el formato año-mes-día (ejemplo: 2024-03-08)."
}

# Variables para almacenar el modo y la fecha
mode=""
date=""

# Función para procesar las opciones de línea de comandos
procesar() {
    # Utilizando el comando getopts para procesar las opciones de línea de comandos
    while getopts ":hm:d:" option; do
        case $option in
            h)
                # Si se especifica la opción "-h", imprimir el menú de ayuda
                imprimir_menu
                ;;
            m)
                # Si se especifica la opción "-m", almacenar el valor del modo en la variable $mode
                mode=$OPTARG
                ;;
            d)
                # Si se especifica la opción "-d", almacenar el valor de la fecha en la variable $date
                date=$OPTARG
                ;;
            \?)
                # Si se especifica una opción inválida, mostrar un mensaje de error
                echo "Opción inválida: $OPTARG"
                echo "Ingrese una opción válida: [h] [m] [d]"
                ;;
        esac
    done
}

generarInforme() {
    # Definir patrón de búsqueda inicial
    local grep_pattern="ERROR"

    # Agregar modo al patrón de búsqueda si está definido
    if [ -n "$mode" ]; then
        grep_pattern="ERROR\[$mode\]"
    fi

    # Agregar fecha al patrón de búsqueda si está definida
    if [ -n "$date" ]; then
        grep_pattern="^\[$date.*\] $grep_pattern"
    fi

    # Filtrar mensajes de error y formatear el informe
    grep -E "$grep_pattern" *.log | \
    sed -E 's/^\[([^ ]*) ([^ ]*).*ERROR \[([^]]*)\] (.*)/Fecha: \1\nHora del Error: \2\nModo: \3\nDescripción del Error: \4\n/'
}

# Llamar a la función para procesar las opciones de línea de comandos
procesar

# Llamar a la función para generar el informe
generarInforme