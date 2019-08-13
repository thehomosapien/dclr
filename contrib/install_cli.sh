 #!/usr/bin/env bash

 # Execute this file to install the dclr cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%DCLR-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/DCLR-Qt.app/Contents/MacOS/dclrd /usr/local/bin/dclrd
 sudo ln -s ${LOCATION}/DCLR-Qt.app/Contents/MacOS/dclr-cli /usr/local/bin/dclr-cli
