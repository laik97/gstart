import os
import sys


sys.path.append(str(os.path.join(os.getcwd(), "build", "lib")))

import ResolutionPy
import GstartPy
import WorkerPy


def main():
    r = ResolutionPy.Resolution(800, 600)

    print(r.getMiddle())

    g = GstartPy.Gstart(r)

    print(g)

    workers = WorkerPy.VectorWorker(
        [
            WorkerPy.Worker(
                WorkerPy.WorkerShape(r.getMiddle().width, r.getMiddle().height, 0)
            )
        ]
    )
    world_items = WorkerPy.VectorRectangleShape([])

    g.run(workers, world_items)

    print("\n\nend\n\n")


if __name__ == "__main__":
    main()
