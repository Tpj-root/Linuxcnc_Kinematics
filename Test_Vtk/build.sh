g++ test_VTK.cpp -o test_vtk \
  -I/path/to/vtk/include \
  -L/path/to/vtk/lib -lvtkCommonCore-9.2 -lvtkRenderingCore-9.2 \
  -lvtkInteractionStyle-9.2 -lvtkRenderingOpenGL2-9.2
