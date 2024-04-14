#!/bin/bash

# Función para imprimir el menú de ayuda
print_help() {
    echo "Uso: $0 [-h] [-m MODE] [-d DATE]"
    echo "  -h: Imprimir este menú de ayuda"
    echo "  -m MODE: Modo de funcionamiento del informe (opciones: servidor_web, base_de_datos, proceso_batch, aplicación, monitoreo)"
    echo "  -d DATE: Especifica la fecha en el formato año-mes-día (ejemplo: 2024-03-08)"
    exit 0
}

# Variables por defecto
MODE=""
DATE=""

# Parseo de las opciones utilizando getopts
while getopts "hm:d:" option; do
    case "${option}" in
        h) print_help;;
        m) MODE=${OPTARG};;
        d) DATE=${OPTARG};;
        *) echo "Opción no válida: ${OPTARG}. Use -h para obtener ayuda."; exit 1;;
    esac
done

# Validación de opciones
if [ -z "$MODE" ] && [ -z "$DATE" ]; then
    echo "Debe especificar al menos una opción. Use -h para obtener ayuda."
    exit 1
fi

# Construcción del comando de búsqueda 
grep_command="grep"
if [ -n "$MODE" ]; then
    grep_command+=" -e \"$MODE\""
fi
if [ -n "$DATE" ]; then
    grep_command+=" -e \"$DATE\""
fi

# Búsqueda de errores en archivos de registro
echo "Reporte de errores:"
echo "===================="
echo ""

# Bucle para procesar cada archivo de registro en la carpeta
for logfile in log_*.log; do
    echo "Archivo de registro: $logfile"
    echo "-----------------------------"
    # Ejecutar el comando grep para buscar errores 
    eval "$grep_command" "$logfile" | while read -r line; do
        # Imprimir los resultados formateados
        echo "Fecha: $(echo "$line" | cut -d ' ' -f 1)"
        echo "Hora del Error: $(echo "$line" | cut -d ' ' -f 2)"
        echo "Descripción del Error: $(echo "$line" | cut -d ' ' -f 5-)"
        echo ""
    done
done

exit 0
