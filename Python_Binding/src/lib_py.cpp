// lib_py.cpp
#include <boost/python.hpp>
#include "lib.hpp"

BOOST_PYTHON_MODULE(simplemath)
{
    using namespace boost::python;
    def("add", add);
    def("multiply", multiply);
}
