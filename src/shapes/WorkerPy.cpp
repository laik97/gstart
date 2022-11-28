#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <vector>

#include "shapes/workerShape.h"

PYBIND11_MAKE_OPAQUE(std::vector<Worker>)
PYBIND11_MAKE_OPAQUE(std::vector<sf::RectangleShape>)

namespace py = pybind11;

PYBIND11_MODULE(WorkerPy, m) {
  py::class_<WorkerShape>(m, "WorkerShape")
      .def(py::init(
          [](const float pos_x, const float pos_y, const float orientation) {
            return WorkerShape{ { pos_x, pos_y }, orientation };
          }));

  py::class_<Worker>(m, "Worker").def(py::init<const WorkerShape&>());

  py::bind_vector<std::vector<Worker>>(m, "VectorWorker");
  py::bind_vector<std::vector<sf::RectangleShape>>(m, "VectorRectangleShape");
}
