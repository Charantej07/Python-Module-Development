from distutils.core import setup, Extension

module = Extension("mymodule", sources=["mymodule.cpp"])

setup(
    name="mymodule",
    version="1.0",
    description="A sample module",
    ext_modules=[module]
)
