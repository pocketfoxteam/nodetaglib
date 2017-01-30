Welcome to NodeTagLib
===================

###Build in linux
```bash
g++ main.cpp -std=c++11 -Ltaglib -Ilinuxlibs -ltag -o NodeTagLib
```
or with system packages

You need TagLib installed on your system
```bash
Ubuntu:
sudo apt-get install libtag1-dev
```
Get cflags and libs path, for example
```bash
taglib-config --cflags
```
and returns "-I/usr/include/taglib" in mi case

Get libs path
```bash
taglib-config --libs
```
and returns "-L/usr/lib/x86_64-linux-gnu -ltag" in my case

When you have both paths you can use to build NodeTagLib
```bash
g++ main.cpp -std=c++11 -I/usr/include/taglib -L/usr/lib/x86_64-linux-gnu -ltag -o NodeTagLib
```

###Build in windows

You need use mingw-w64 to build (mingw have few bugs with c++11)

```bash
g++ -static main.cpp -std=c++11 -Ltaglib -Iwinlibs -ltag -o NodeTagLib.exe
```
or you can build your own TagLib static library

###Building TagLib static library for windows
You need cmake for windows and mingw-w64

Download and extract Taglib 1.9.1 from [taglib.org](http://taglib.org/)

Enter in taglib-1.9.1 directory and:
```bash
cmake -G "MinGW Makefiles" -DENABLE_STATIC=ON -DHAVE_ZLIB=0 -DMAKE_TAGLIB_LIB=1
cmake --build ./
```

After this you should have libtag.a in taglib-1.9.1/libtag and you can use this to build NodeTagLib

PD: TagLib header files is provided for building easely
