#include <iostream>
#include <string>
#include "opencamlib/stlreader.hpp"
#include "opencamlib/stlsurf.hpp"
#include "opencamlib/pointdropcutter.hpp"
#include "opencamlib/ballcutter.hpp"
#include "opencamlib/point.hpp"


int main() {
    std::string stlPath = "test.stl";  // your STL path
    ocl::STLReader reader(stlPath);

    if (!reader.isValid()) {
        std::cerr << "Failed to load STL: " << stlPath << std::endl;
        return 1;
    }

    ocl::STLSurf surface;
    reader.fillSurface(&surface);
    surface.buildAccel();  // build acceleration structure (kdtree)

    // Create BallCutter (diameter=2.0, length=5.0)
    ocl::BallCutter cutter(2.0, 5.0);

    // Create PointDropCutter (no constructor args)
    ocl::PointDropCutter pdc;
    pdc.setCutter(&cutter);
    pdc.setSurface(&surface);

    // Sample grid over XY, drop cutter from Z=10
    for (double x = 0; x <= 5; x += 1) {
        for (double y = 0; y <= 5; y += 1) {
            ocl::Point p(x, y, 10.0);
            pdc.dropPoint(p);
            if (pdc.isValid()) {
                double z = pdc.getHeight();
                std::cout << "DropCutter height at (" << x << "," << y << ") = " << z << std::endl;
            } else {
                std::cout << "No contact at (" << x << "," << y << ")\n";
            }
        }
    }

    return 0;
}
