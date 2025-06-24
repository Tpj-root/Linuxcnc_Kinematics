# Linuxcnc_Kinematics


CAD/CAM frameworks in C++:
1. Open CASCADE

    Type: Open-source CAD kernel.

    Use: 3D modeling, geometry, mesh, STEP/IGES support.

    Link: https://www.opencascade.com

2. BRL-CAD

    Type: Open-source solid modeling system.

    Use: CAD, geometry editing, ray tracing.

    Link: https://brlcad.org

3. FreeCAD (C++ Core)

    Type: Parametric 3D CAD.

    Use: Design, modeling, scripting (Python frontend).

    Link: https://www.freecad.org

4. LibIGL

    Type: C++ geometry processing library.

    Use: Mesh processing, not full CAD but useful for CAM-related tasks.

    Link: https://libigl.github.io






BRL-CAD is powerful for ray tracing and solid modeling, but it is not designed for CAM toolpath generation.
For CAM (toolpath) generation:

You’ll need a dedicated CAM library or integrate BRL-CAD with:

    Open CASCADE + custom CAM logic

    PyCAM / FreeCAD Path Workbench (has C++ backend)

    gcode generation tools (like bCNC or LinuxCNC)

Option:

    Model in BRL-CAD

    Export geometry (e.g., STL)

    Use other tools to generate toolpaths from that STL

