#include <Python.h>

// Function definition
static PyObject* mymodule_hello(PyObject* self, PyObject* args)
{
    const char* name;

    // Parse the arguments
    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    // Create the return value
    return PyUnicode_FromFormat("Hello, %s!", name);
}

// Method table
static PyMethodDef mymodule_methods[] = {
    {"hello", mymodule_hello, METH_VARARGS, "Print a greeting."},
    {NULL, NULL, 0, NULL} // Sentinel
};

// Module definition
static struct PyModuleDef mymodule_definition = {
    PyModuleDef_HEAD_INIT,
    "mymodule", // Module name
    "A sample module", // Module documentation
    -1,
    mymodule_methods // Method table
};

// Module initialization function
PyMODINIT_FUNC PyInit_mymodule(void)
{
    return PyModule_Create(&mymodule_definition);
}
