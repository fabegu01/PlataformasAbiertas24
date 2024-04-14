#!/bin/bash

# Directorio a monitorear
DIRECTORIO=/home/fabian/PlataformasAbiertas24


# Archivo de log
LOG_FILE=/home/fabian/PlataformasAbiertas24/Lab2


# Función para escribir mensaje de log con fecha y hora
escribir_log() {
    echo "$(date +"%Y-%m-%d %H:%M:%S"): $1" >> "$LOG_FILE"
}

# Función para monitorear el directorio
monitorear_directorio() {
    # Utiliza inotifywait para monitorear el directorio en busca de eventos de creación, modificación y eliminación
    # -m: modo monitor continuo
    # -r: recorre el directorio de forma recursiva
    # -e: especifica los eventos a los que se debe prestar atención (creación, modificación, eliminación)
    inotifywait -m -r -e create,modify,delete "$DIRECTORIO" |
    # Lee la salida de inotifywait línea por línea
    while read -r directory event file; do
        # Llama a la función escribir_log para registrar el evento en el archivo de log
        escribir_log "Evento detectado: $event en $file"
    done
}

# Llamada a la función para monitorear el directorio
monitorear_directorio