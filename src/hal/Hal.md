# Hardware Abstraction Layer
You may notice that there are two .cpp files for every.h file.
This is because our HAL-Library can be compiled in several ways.
For example it can be compiled as the real HAL which works on the nao. 
It also can be compiled as a stub, which does nothing, just logs on the
commandline. Maybe in the future there is a third option, which works
as a HAL for a simulated virtual nao.

## Creating a new file
### Header
When a new Header is created it has to be registered in our CMakeLists.txt
For example i want to add a new file called `headeronly.h`.
Our CMakeLists.txt will look like this:
```cmake
set(HalHeaders
        # REGISTER HAL-HEADERS HERE
        hal/headeronly.h
        ...
        )
```
### C++-File
When creating a C++ file you have to ensure that you create on file for every suffix.
For example you have created `example.h`. Since there are currently two targets
"stub" and "nao" you have to create `example_stub.cpp` and `example_nao.cpp` and
implement them both. Make sure no .cpp files are being added to any target in the 
CMakeLists.txt.