#!/bin/bash

# Solicitar al usuario que ingrese el nombre de usuario
echo "Nombre de Usuario"
read NombreUsuario

# Solicitar al usuario que ingrese el nombre del grupo
echo "Nombre del grupo"
read NombreGrupo

# Verificar si el usuario ya existe
if id "$NombreUsuario" &>/dev/null; then
    # Si el usuario ya existe, mostrar un mensaje indicando su existencia
    echo "El usuario $NombreUsuario ya existe"

    # Verificar si el grupo especificado ya existe
    if getent group "$NombreGrupo" &>/dev/null; then
        # Si el grupo ya existe, mostrar un mensaje indicando su existencia
        echo "El grupo $NombreGrupo existe."
    else
        # Si el grupo no existe, crear el grupo utilizando 'groupadd' con privilegios de superusuario
        sudo groupadd "$NombreGrupo"
        echo "El grupo $NombreGrupo ha sido creado"
    fi

    # Agregar el usuario al grupo especificado utilizando 'adduser' con privilegios de superusuario
    sudo adduser "$NombreUsuario" "$NombreGrupo"
    echo "El usuario $NombreUsuario ha sido agregado a $NombreGrupo"

else
    # Si el usuario no existe, crear el usuario utilizando 'adduser' con privilegios de superusuario
    sudo adduser "$NombreUsuario"
    echo "El usuario $NombreUsuario ha sido creado"

    # Verificar si el grupo especificado ya existe
    if getent group "$NombreGrupo" &>/dev/null; then
        # Si el grupo ya existe, mostrar un mensaje indicando su existencia
        echo "El grupo $NombreGrupo existe."
    else
        # Si el grupo no existe, crear el grupo utilizando 'groupadd' con privilegios de superusuario
        sudo groupadd "$NombreGrupo"
        echo "El grupo $NombreGrupo ha sido creado"
    fi

    # Agregar el usuario al grupo especificado utilizando 'adduser' con privilegios de superusuario
    sudo adduser "$NombreUsuario" "$NombreGrupo"
    echo "El usuario $NombreUsuario ha sido agregado a $NombreGrupo"
fi
