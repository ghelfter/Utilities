#!/bin/bash

# Galen Helfter
# cch.sh
# Generates a stub C++ class in a .h file.
MINPAR=1


if [ $# -lt "$MINPAR" ]; then
    echo "Must specify a filename."
else
    FILE="$1.h"
    if [ -f ./$FILE ]; then
        echo "File already exists!"
    else
        UPP=$(echo $1 | awk '{print toupper($0)}')
        echo "Writing to file $FILE."
        echo "/*  ---------------  Galen Helfter  --------------- */" >> ./$FILE
        echo "/*  ---------------  $FILE  --------------- */" >> ./$FILE
        echo >> ./$FILE

        echo "#ifndef _${UPP}_H_" >> ./$FILE
        echo "#define _${UPP}_H_" >> ./$FILE

        echo >> ./$FILE

        echo "#include <iostream>" >> ./$FILE
        echo ./$FILE
        echo "class $1" >> ./$FILE
        echo "{" >> ./$FILE
        echo "  public:" >> ./$FILE
        echo "    $1();" >> ./$FILE
        echo "    ~$1();" >> ./$FILE
        echo "  protected:" >> ./$FILE
        echo "  private:" >> ./$FILE
        echo "    $1(const $1&);" >> ./$FILE
        echo "    $1& operator=(const $1&);" >> ./$FILE
        echo "};" >> ./$FILE

        echo >> ./$FILE

        echo "#endif" >> ./$FILE
    fi
fi  
