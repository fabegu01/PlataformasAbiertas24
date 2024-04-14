#!/bin/bash

# Se muestra un mensaje para solicitar al usuario que ingrese el nombre del archivo
echo "Escriba el nombre del archivo"
read NombreArchivo

# Verificar si el archivo existe
if [ -e "$NombreArchivo" ]; then
    # Obtener los permisos del archivo utilizando el comando 'stat'
    Permisos=$(stat -c "%A" "$NombreArchivo")
    
    # Definición de una función para obtener los permisos de forma más detallada
    get_permission_verbose() {
        # Extraer y mostrar los permisos para el usuario propietario del archivo
        permisosUsuario=$(echo "$Permisos" | cut -c 2-4)
        echo "Permisos de usuarios: $permisosUsuario"
        
        # Extraer y mostrar los permisos para los grupos a los que pertenece el archivo
        permisosGrupos=$(echo "$Permisos" | cut -c 5-7)
        echo "Permisos de Grupos: $permisosGrupos"
        
        # Extraer y mostrar los permisos para otros usuarios
        permisoOtros=$(echo "$Permisos" | cut -c 8-10)
        echo "Permiso de otros usuarios: $permisoOtros"
    }
    
    # Llamar a la función para mostrar los permisos de forma detallada
    get_permission_verbose
else 
    # Mostrar un mensaje si el archivo no existe
    echo "El archivo no existe"
fi
