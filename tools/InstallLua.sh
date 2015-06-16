curl -R -O http://www.lua.org/ftp/lua-5.2.3.tar.gz
tar zxf lua-5.2.3.tar.gz
cd lua-5.2.3
sudo make linux
sudo make install
cd ..
rm -rf lua-5.2.3
rm lua-5.2.3.tar.gz
