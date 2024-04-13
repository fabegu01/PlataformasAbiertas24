#!/bin/bash

# Comprobar si el proceso existe.
recibirProceso() {
    local NombreProceso="$1"
    ps -e | grep "$NombreProceso"
}

# Función principal
main() {
    local NombreProceso="$1"

    if recibirProceso "$NombreProceso"; then
        # obetner el pid con pgrep para luego usar ps.

        local pid=$(pgrep "$NombreProceso")

        # utilizar el ps para filtrar los datos.  
        local usodecpu=$(ps -p "$pid" -o %cpu --no-headers)
        local usuario=$(ps -p "$pid" -o user --no-headers)
        local estado=$(ps -p "$pid" -o stat --no-headers)
        local memoriausada=$(ps -p "$pid" -o %mem --no-headers)
        #implementacion de readlink para encontrar el path ejecutable del proceso.
        local pathEjecutable=$(readlink "/proc/$pid/exe")

        echo "Proceso $NombreProceso"
        echo "PID: $pid"
        echo "Usuario: $usuario"
        echo "Estado: $estado"
        echo "Uso de CPU: $usodecpu%"
        echo "Uso de memoria: $memoriausada%"
        echo "path ejecutable: $pathEjecutable"
    else 
        echo "El proceso $NombreProceso no está en ejecución."
    
    fi
}

# Verificar que se haya proporcionado un argumento
if [ $# -eq 0 ]; then
    echo "Por favor, proporcione el nombre del proceso como argumento."
    exit 1
fi

# Llamar a la función principal con el argumento proporcionado
main "$1"
