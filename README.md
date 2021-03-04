# PortaUtils
PortaUtils es una coleccion de herramientas hechas para Proyecto PortaLinux

# mkinitrd

mkinitrd es un script que crea ramdisks iniciales. Aqui estan las opciones qe se le
puede dar al script:

--busybox       La ruta de BusyBox
--init          La ruta del script de init
--type          Define el tipo de initrd (rd, ramfs)
--compression   Define el tipo de compresion (gzip, bzip2, xz)
--help          Mostrar esta ayuda

# decompress-all

decompress-all es un script que decomprime y desempaca archivos. Soporta xz, bzip2,
gzip, tar y cpio

# pls-install y pls-pkg

pls-pkg es un administrador de paquetes escrito en Python. Es us buscador de paquetes y
un front-end para pls-install, el instalador de paquetes (escrito en C). Aqui estan las
opciones:

pls-pkg:

install		Instala un paquete
search		Busca un paquete
remove		Remueve un paquete

pls-install:

i		Instala los paquetes dados
r		Remueve los paquetes dados
