#include <pybind11/pybind11.h>

#include "gstart/gstart.h"

namespace py = pybind11;

PYBIND11_MODULE(GstartPy, m) {
  py::class_<Gstart>(m, "Gstart")
      .def(py::init([](const Resolution& resolution) {
        return Gstart::makeGstart(resolution);
      }))
      .def("run", &Gstart::run)
      .def("run", [](Gstart& g) { return g.run({}, {}); })
      .def("__repr__", [](const Gstart& res) { return "< Gstart >"; });
}
