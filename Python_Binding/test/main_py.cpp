#include <iostream>
#include <Python.h>
#include <boost/python.hpp>

int main(int argc, char* argv[]) {
    Py_Initialize();
    try {
        boost::python::object simplemath = boost::python::import("simplemath");
        int result_add = boost::python::extract<int>(simplemath.attr("add")(3, 4));
        int result_mul = boost::python::extract<int>(simplemath.attr("multiply")(3, 4));
        std::cout << "Python add(3,4) = " << result_add << "\n";
        std::cout << "Python multiply(3,4) = " << result_mul << "\n";
    } catch (boost::python::error_already_set const &) {
        PyErr_Print();
    }
    Py_Finalize();
    return 0;
}
