# Python-Module-Development
This repo helps you in develop a module using C/C++ to use it in any python scripts
## Pytohn-Extension Programming
Any code that you write using any compiled language like C, C++, or Java can be integrated or imported into another Python script. This code is considered as an "extension."

A Python extension module is nothing more than a normal C library. On Unix machines, these libraries usually end in .so (for shared object). On Windows machines, you typically see .dll (for dynamically linked library).

## Pre-Requisites
To start writing your extension, you are going to need the Python header files.

On Unix machines, this usually requires installing a developer-specific package such as python2.5-dev.

Windows users get these headers as part of the package when they use the binary Python installer.

Additionally, it is assumed that you have good knowledge of C or C++ to write any Python Extension using C programming.

## The 4 Parts of the Python Extension
1. The header file Python.h.

2. The C functions you want to expose as the interface from your module.

3. A table mapping the names of your functions as Python developers see them to C functions inside the extension module.

4. An initialization function.
