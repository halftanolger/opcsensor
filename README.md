# opcsensor

Hensikten med opcsensor er å se litt på OPC UA

## Kokebok mht det å bygge Open62541 for Windows

* Last ned Qt open source for Windows, MinGW 7.3.0 32-bit
  (Da får man også et fiks-ferdig-byggemiljø for MinGW)
  (www.qt.io)

* Last ned open62541
  (open62541.org)

* Bygg open6241 open62541 (MinGW 7.3.0.32-bit bulid) for windows, som følger:

```
     mkdir build
     cd build
     cmake .. -G"MinGW Makefiles" -DUA_ENABLE_AMALGAMATION=ON -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Debug -DUA_ENABLE_DISCOVERY=ON -DUA_ENABLE_METHODCALLS=ON -DUA_ENABLE_NODEMANAGEMENT=ON -DUA_ENABLE_SUBSCRIPTIONS=ON -DUA_LOGLEVEL=300
     mingw32-make
```

Ut fra dette får vi to filer; open62541.c og open62541.h Disse representerer vårt open62541-bibliotek.


## Kokebok mht å bygge opcsensor for Windows

```
mkdir build
cd build
gcc -std=c99 -I../lib/open62541 ../lib/open62541/open62541.c -lws2_32  ../src/server.c -o server
```


Nå har du ei kjørbar fil kalt 'server.exe' som representerer OPC -serveren vår.

Sjekk data fra serven vha f.eks UaExpert sin OPC UA klient, som du kanskje finner her: https://www.unified-automation.com/

Nå har du også et tipp-topp utviklingsmiljø for å teste ut de andre tutorial-eksemplene du finner på open62541.org -siden.


## Mer info    

https://open62541.org/doc/current/toc.html#  
https://medium.com/gradiant-talks/implementing-an-opc-ua-server-using-open62541-77aeddd99370




