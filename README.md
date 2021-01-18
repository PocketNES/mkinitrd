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

# pls-install

pls-install es un script que va a tomar el lugar de dpkg en PortaLinux por ahora.
Se esta trabajando en una version escrita en C++. Aqui estan los comandos que se le
puede dar al script:

instalar	Instala los paquetes dados
remover		Remueve los paquetes dados
