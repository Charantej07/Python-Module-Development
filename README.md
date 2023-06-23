# Python-Module-Development
This repo helps you in develop a module using C/C++ to use it in any python scripts
## Python-Extension Programming
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

## The header file Python.h
You should inlcud Python.h header file in your C/C++ program which gives you access to the internal API
Note: Make sure to include Python.h before any other headers you might need. You need to follow the includes with the functions you want to call from Python.

## The C\C++ functions
The signatures of the C implementation of your functions always takes one of the following three forms:
```
static PyObject *MyFunction( PyObject *self, PyObject *args );

static PyObject *MyFunctionWithKeywords(PyObject *self,
                                 PyObject *args,
                                 PyObject *kw);

static PyObject *MyFunctionWithNoArgs( PyObject *self );
```

Each one of the preceding declarations returns a Python object. There is no such thing as a void function in Python as there is in C. If you do not want your functions to return a value, return the C equivalent of Python's None value. The Python headers define a macro, Py_RETURN_NONE, that does this for us.

The names of your C functions can be whatever you like as they are never seen outside of the extension module. They are defined as static function.

The convention we use for naming the functions is Python module and the function name
```
static PyObject *module_func(PyObject *self, PyObject *args) {
   /* Do your stuff here. */
   Py_RETURN_NONE;
}
```

## The Method mapping table
This method table is a simple array of PyMethodDef structures. That structure looks something like this:
```
struct PyMethodDef {
   char *ml_name;
   PyCFunction ml_meth;
   int ml_flags;
   char *ml_doc;
};
```

Here is the description of the members of this structure:

* ml_name − This is the name of the function as the Python interpreter presents when it is used in Python programs.

* ml_meth − This must be the address to a function that has any one of the signatures described in previous seection.

* ml_flags − This tells the interpreter which of the three signatures ml_meth is using.

&emsp; This flag usually has a value of METH_VARARGS.

&emsp; This flag can be bitwise OR'ed with METH_KEYWORDS if you want to allow keyword arguments into your function.

&emsp; This can also have a value of METH_NOARGS that indicates you do not want to accept any arguments.

* ml_doc − This is the docstring for the function, which could be NULL if you do not feel like writing one.

This table needs to be terminated with a sentinel that consists of NULL and 0 values for the appropriate members.

## Example
For the above-defined function, we have following method mapping table :
```
static PyMethodDef module_methods[] = {
   { "func", (PyCFunction)module_func, METH_NOARGS, NULL },
   { NULL, NULL, 0, NULL }
};
```
