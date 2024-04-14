#!/bin/bash

# Verifica que se haya proporcionado un ejecutable como argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 <ejecutable>"
    exit 1
fi
NombreProceso=$1

procesoEjecutandose() {
    local nombre_proceso="$1"
    pgrep -x "$nombre_proceso" > /dev/null
}

archivo_log="registro.txt"

if ! procesoEjecutandose "$NombreProceso"; then 
    echo "El proceso $NombreProceso no está en ejecución, se ejecutará a continuación"
    $NombreProceso &
fi

# Función para monitorear el proceso
monitorear() {
    # Encabezado del archivo de registro
    echo "Tiempo CPU Memoria" > "$archivo_log"

    # Inicia el monitoreo
    while true; do
        # Obtener el PID del proceso con pgrep
        local pid=$(pgrep "$NombreProceso") 
        # Obtener el tiempo con date
        local tiempo=$(date +"%Y-%m-%d %H:%M:%S")
        # Obtener el uso de CPU y memoria
        local uso_cpu=$(ps -p "$pid" -o %cpu --no-headers)
        local uso_memoria=$(ps -p "$pid" -o %mem --no-headers)
        # Registrar los datos en el archivo de registro
        echo "$tiempo $uso_cpu $uso_memoria" >> "$archivo_log"
        sleep 5
    done
}

# Llama a la función para monitorear en segundo plano
monitorear &

# Genera el gráfico utilizando gnuplot
gnuplot << EOF
set terminal png
set output 'grafico.png'
set title 'Consumo de CPU y Memoria'
set xlabel 'Tiempo'
set ylabel 'Porcentaje de uso'
plot '$archivo_log' using 1:2 with lines title 'CPU', \
     '$archivo_log' using 1:3 with lines title 'Memoria'
EOF

echo "Proceso finalizado. Gráfico generado en grafico.png"
