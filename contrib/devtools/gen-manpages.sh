#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

DCLRD=${DCLRD:-$SRCDIR/dclrd}
DCLRCLI=${DCLRCLI:-$SRCDIR/dclr-cli}
DCLRTX=${DCLRTX:-$SRCDIR/dclr-tx}
DCLRQT=${DCLRQT:-$SRCDIR/qt/dclr-qt}

[ ! -x $DCLRD ] && echo "$DCLRD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
DCLRVER=($($DCLRCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for dclrd if --version-string is not set,
# but has different outcomes for dclr-qt and dclr-cli.
echo "[COPYRIGHT]" > footer.h2m
$DCLRD --version | sed -n '1!p' >> footer.h2m

for cmd in $DCLRD $DCLRCLI $DCLRTX $DCLRQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${DCLRVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${DCLRVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
