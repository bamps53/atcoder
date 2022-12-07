#!/bin/bash

if [ ! -e agc ]; then
  echo "Error: directory 'agc' not exists." 1>&2
  exit 1
fi

mkdir -p agc/agc$1

cp -n template.cpp agc/agc$1/a.cpp
cp -n template.cpp agc/agc$1/b.cpp
cp -n template.cpp agc/agc$1/c.cpp
cp -n template.cpp agc/agc$1/d.cpp
cp -n template.cpp agc/agc$1/e.cpp
cp -n template.cpp agc/agc$1/f.cpp
cp -n template.cpp agc/agc$1/g.cpp
cp -n template.cpp agc/agc$1/h.cpp

exit 0