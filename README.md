# mkinitrd
`mkinitrd` es un script de shell hecho para crear un initrd o un initramfs personalizado mientras siendo compatible con el estándar de POSIX.
# Instalar
Para instalar `mkinitrd`, solo muevalo a unos de las carpetas declaradas por el variable `$PATH`, como `/usr/bin` o `/bin` y eso es todo lo que se tiene que hacer para instalarlo.
# Opciones/Parametros
`-v | --verbosa`: Activa esta opcion para recivir mensajes mas detallados
`-a | --ayuda`: Muestra la ayuda
`--estatico`: Activa esta opcion si Busybox fue compilado estaticamente
`--busybox`: Ruta del binario de Busybox (Requerido, ruta absoluta)
`--biblioteca`: Ruta de la biblioteca de C (Requerido si Busybox no es estatico, ruta absoluta)
`--carpeta`: Cambiar carpeta temporaria (Pred. /tmp/mkinitrd, ruta absoluta)
`--tipord`: Especificar el tipo de ramdisk (initrd o initramfs)
`--archivocp`: Ruta de un archivo conteniendo una lista de rutas absolutas a los otros archivos (ruta absoluta)
`--init`: Ruta del init script (ruta absoluta)
`-disp`: Ruta de un tar o un cpio conteniendo nodos de dispositivos (ruta absoluta)
