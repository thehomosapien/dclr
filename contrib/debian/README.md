
Debian
====================
This directory contains files used to package dclrd/dclr-qt
for Debian-based Linux systems. If you compile dclrd/dclr-qt yourself, there are some useful files here.

## dclr: URI support ##


dclr-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install dclr-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your dclr-qt binary to `/usr/bin`
and the `../../share/pixmaps/dclr128.png` to `/usr/share/pixmaps`

dclr-qt.protocol (KDE)

