#!/bin/bash
archivosBibliotecaCompartida=$(cd ../../SharedLibrary; ls $PWD/*.c)
referencias="-lcommons -lpthread"

echo "Compilando proyecto FileSystem";
gcc *.c ${archivosBibliotecaCompartida} -o FileSystem.o ${referencias};
