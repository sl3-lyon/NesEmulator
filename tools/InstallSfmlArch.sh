#!/bin/bash
wget http://www.sfml-dev.org/files/SFML-2.3-linux-gcc-64-bit.tar.gz
tar -xf SFML-2.3-linux-gcc-64-bit.tar.gz
cd SFML-2.3
cd lib
sudo cp * /usr/lib
cd ../include
sudo cp -R SFML /usr/include
