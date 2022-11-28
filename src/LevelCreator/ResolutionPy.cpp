#include <pybind11/pybind11.h>

#include <string>

#include "LevelCreator/Resolution.h"

namespace py = pybind11;

PYBIND11_MODULE(ResolutionPy, m) {
  py::class_<Resolution>(m, "Resolution")
      .def(py::init<const uint, const uint>())
      .def("get", &Resolution::get<Resolution, uint>)
      .def("getMiddle", &Resolution::getMiddle<Resolution, uint>)
      .def_readwrite("width", &Resolution::width)
      .def_readwrite("height", &Resolution::height)
      .def("__repr__", [](const Resolution &res) {
        return "< Resolution : width = " + std::to_string(res.width) +
               ", height=" + std::to_string(res.height) + " >";
      });
}
