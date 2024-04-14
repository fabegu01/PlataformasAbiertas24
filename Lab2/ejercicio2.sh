#!/bin/bash  

# Verificar si la cantidad de argumentos fue la correcta y sino enseñarle al usuario el uso adecuado
if [ $# -ne 2 ]; then
    echo "Uso: $0 <nombre_del_proceso> <comando_para_ejecutar>"
    exit 1
fi

NombreProceso=$1
CodigoProceso=$2
#uso del pgrep para buscar e inspeccionar el proceso. 
procejoejecutandose() {
    local nombre_proceso="$1"
    pgrep -x "$nombre_proceso" > /dev/null
}

while true; do
    if ! procejoejecutandose "$NombreProceso"; then 
        echo "El proceso $NombreProceso no está en ejecución, se ejecutará a continuación"
         #encontramos la ruta del archivo y la guardamos en una variable para despues ver si esta vacia, con head -n 1, encontramos solo la primera coincidencia
        
        $CodigoProceso &

        
    

            # Ejecutar el archivo usando su ruta
            $RutaArchivo &

            sleep 5 
        
    else 
        echo "El proceso $NombreProceso está en ejecución"
        sleep 5
    

    fi
done
