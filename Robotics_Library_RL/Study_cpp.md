# Linuxcnc_Kinematics



### If glxinfo is not installed, install it with:

```
sudo apt-get install mesa-utils

```



###  Build own



```
https://github.com/GammaUNC/PQP
https://github.com/dtecta/solid3

```




### Qt5 development packages are installed


```
sudo apt install qtbase5-dev


dependencies

sudo apt install libeigen3-dev
sudo apt install libdc1394-dev
sudo apt install libcomedi-dev 
sudo apt install gnuplot

```







### ATIDAQ – vendor SDK from ATI

https://www.ati-ia.com/


### cifX – vendor SDK from Hilscher

https://www.hilscher.com/







```
https://github.com/roboticslibrary/rl
```

The Robotics Library (RL) is a self-contained C++ library for rigid body kinematics and dynamics, motion planning, and control. 




# Build RL on Ubuntu

```
https://www.roboticslibrary.org/tutorials/build-ubuntu/
```



make (static library)  ON --> OFF 




```
https://github.com/roboticslibrary/rl/blob/master/CMakeLists.txt


if(MSVC)
	option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
else()
	option(BUILD_SHARED_LIBS "Build shared libraries" ON)
endif()

```



#  third-party dependencies required

```
sudo apt-get install libboost-all-dev libbullet-dev libdc1394-22-dev libeigen3-dev libnlopt-dev libode-dev libsimage-dev libsolid3d-dev libsoqt-dev libxml2-dev libxslt1-dev

```





Run time fix errors

```
lcnc@debian:~$ alias fixbug
alias fixbug='LIBGL_ALWAYS_SOFTWARE=1 MESA_GL_VERSION_OVERRIDE=3.3 MESA_GLSL_VERSION_OVERRIDE=330 '



That means your program only works when forcing software rendering, likely due to a problem with the GPU driver (Nouveau) or OpenGL compatibility.


Nouveau (open-source driver) has poor 3D support. Replace it:


Install Proprietary NVIDIA Driver

sudo apt install nvidia-driver


```


# Check 

```
glxinfo | grep "renderer"




cnc@debian:~$ glxinfo | grep "renderer"
    GLX_MESA_copy_sub_buffer, GLX_MESA_query_renderer, GLX_MESA_swap_control, 
    GLX_MESA_copy_sub_buffer, GLX_MESA_query_renderer, GLX_MESA_swap_control, 
Extended renderer info (GLX_MESA_query_renderer):
OpenGL renderer string: NVD9



...
OpenGL renderer string: NVIDIA ...



```



if GPU fix isn’t possible.


run this command
```
LIBGL_ALWAYS_SOFTWARE=1 ./rlPlanDemo ...


that mean

With LIBGL_ALWAYS_SOFTWARE=1 → CPU used (llvmpipe)



cnc@debian:~$ LIBGL_ALWAYS_SOFTWARE=1 glxinfo | grep "renderer"
    GLX_MESA_copy_sub_buffer, GLX_MESA_query_renderer, GLX_MESA_swap_control, 
    GLX_MESA_query_renderer, GLX_OML_swap_method, GLX_SGIS_multisample, 
Extended renderer info (GLX_MESA_query_renderer):
OpenGL renderer string: llvmpipe (LLVM 15.0.6, 256 bits)
cnc@debian:~$ 



```




```
cnc@debian:~$ glxinfo | grep "version"
server glx version string: 1.4
client glx version string: 1.4
GLX version: 1.4
    Max core profile version: 4.3
    Max compat profile version: 4.3
    Max GLES1 profile version: 1.1
    Max GLES[23] profile version: 3.1
OpenGL core profile version string: 4.3 (Core Profile) Mesa 22.3.6
OpenGL core profile shading language version string: 4.30
OpenGL version string: 4.3 (Compatibility Profile) Mesa 22.3.6
OpenGL shading language version string: 4.30
OpenGL ES profile version string: OpenGL ES 3.1 Mesa 22.3.6
OpenGL ES profile shading language version string: OpenGL ES GLSL ES 3.10
    GL_EXT_shader_implicit_conversions, GL_EXT_shader_integer_mix, 
cnc@debian:~$ 


```




Yes — if you have an old CPU or GPU that only supports lower OpenGL/GLSL versions, and a program requires newer versions, then you can try:


```
MESA_GL_VERSION_OVERRIDE=3.3 MESA_GLSL_VERSION_OVERRIDE=330


```


testing only

faking GPU support using the CPU via software rendering (llvmpipe). It lets apps run even if the real GPU is missing or unsupported.

```

LIBGL_ALWAYS_SOFTWARE=1 MESA_GL_VERSION_OVERRIDE=3.3 MESA_GLSL_VERSION_OVERRIDE=330

```


```
/lib64/ld-linux-x86-64.so.2
libbrotlicommon.so.1
libbrotlidec.so.1
libbsd.so.0
libBulletCollision-float64.so.3.24
libccd.so.2
libCoin.so.80c
libcom_err.so.2
libc.so.6
libdc1394.so.25

libdouble-conversion.so.3
libexpat.so.1
libfcl.so.0.7
libfreetype.so.6
libgcc_s.so.1
libGLdispatch.so.0
libglib-2.0.so.0
libGL.so.1
libGLX.so.0
libgraphite2.so.3

libgssapi_krb5.so.2
libharfbuzz.so.0
libicudata.so.72
libicui18n.so.72
libicuuc.so.72
libk5crypto.so.3
libkeyutils.so.1
libkrb5.so.3
libkrb5support.so.0
libLinearMath-float64.so.3.24

liblzma.so.5
libmd4c.so.0
libmd.so.0
libm.so.6
libnlopt.so.0
liboctomap.so.1.9
liboctomath.so.1.9
libode.so.8
libOpenGL.so.0
libpcre2-16.so.0

libpcre2-8.so.0
libpng16.so.16
libpthread.so.0
libQt5Core.so.5
libQt5Gui.so.5
libQt5Network.so.5
libQt5OpenGL.so.5
libQt5PrintSupport.so.5
libQt5Widgets.so.5
libraw1394.so.11

libresolv.so.2
libsolid3.so.3.5.8
libSoQt.so.520
libstdc++.so.6
libudev.so.1
libusb-1.0.so.0
libX11.so.6
libXau.so.6
libxcb.so.1
libXdmcp.so.6

libXext.so.6
libXi.so.6
libxml2.so.2
libxslt.so.1
libz.so.1
libzstd.so.1
linux-vdso.so.1
```




The file /lib64/ld-linux-x86-64.so.2 is the dynamic linker/loader for 64-bit ELF binaries on Linux.


```

sudo apt install libc6

sudo apt install \
  libbrotli1 \
  libbsd0 \
  libbullet-dev \
  libccd2 \
  libcoin80c \
  libcom-err2 \
  libc6 \
  libdc1394-25

sudo apt install libdouble-conversion3 \
                 libexpat1 \
                 libfcl0.7 \
                 libfreetype6 \
                 libgcc-s1 \
                 libgl1 \
                 libglib2.0-0 \
                 libglx0 \
                 libgraphite2-3

sudo apt install libgssapi-krb5-2 \
                 libharfbuzz0b \
                 libicu72 \
                 libk5crypto3 \
                 libkeyutils1 \
                 libkrb5-3 \
                 libkrb5support0

sudo apt install liblzma5 \
                 libmd4c0 \
                 libmd0 \
                 libc6 \
                 libnlopt0 \
                 liboctomap1.9 \
                 libode8 \
                 libopengl0 \
                 libpcre2-16-0

sudo apt install libpcre2-8-0 \
                 libpng16-16 \
                 libc6 \
                 qtbase5-dev \
                 libraw1394-11

sudo apt install libc6 \
                 libkf5solid5 \
                 libsoqt520 \
                 libstdc++6 \
                 libudev1 \
                 libusb-1.0-0 \
                 libx11-6 \
                 libxau6 \
                 libxcb1 \
                 libxdmcp6

sudo apt install libxext6 libxi6 libxml2 libxslt1.1 zlib1g libzstd1



https://github.com/OctoMap/octomap
sudo apt install liboctomath1.9
```



















### Run time test


```
./rlViewDemo /home/cnc/Desktop/BUILD3/rl/examples/rlsg/unimation-puma560_boxes.xml
./rlCollisionDemo /home/cnc/Desktop/BUILD3/rl/examples/rlsg/scene.xml



math fun
./rlRotationConverterDemo



### not work bug in GPU

fixbug ./rlPlanDemo /home/cnc/Desktop/BUILD3/rl/examples/rlplan/unimation-puma560_boxes_rrtConCon.xml
fixbug ./rlCoachKin /home/cnc/Desktop/BUILD3/rl/examples/rlsg/unimation-puma560_boxes.xml /home/cnc/Desktop/BUILD3/rl/examples/rlkin/unimation-puma560.xml
fixbug ./wrlview





#### SCENEFILE MODELFILE
             
rlCoachMdl

fixbug ./rlCoachMdl /home/cnc/Desktop/BUILD3/rl/examples/rlsg/unimation-puma560/unimation-puma560.xml /home/cnc/Desktop/BUILD3/rl/examples/rlmdl/unimation-puma560.xml



fixbug ./rlSimulator /home/cnc/Desktop/BUILD3/rl/examples/rlsg/unimation-puma560/unimation-puma560.xml /home/cnc/Desktop/BUILD3/rl/examples/rlmdl/unimation-puma560.xml


fixbug ./rlSimulator /home/cnc/Desktop/BUILD3/rl/examples/rlsg/planar3.xml /home/cnc/Desktop/BUILD3/rl/examples/rlmdl/planar3.xml
fixbug ./rlSimulator /home/cnc/Desktop/BUILD3/rl/examples/rlsg/planar2.xml /home/cnc/Desktop/BUILD3/rl/examples/rlmdl/planar2.xml




not work
fixbug ./rlSimulator /home/cnc/Desktop/BUILD3/rl/examples/rlsg/box-6d-300505_maze.xml /home/cnc/Desktop/BUILD3/rl/examples/rlmdl/box-6d-300505.sixDof.xml














byu2wrl                   rlDynamics1Planar2Demo       rlLaserDemo                        rlPumaDemo                           rlSpatialDotProductTest
csv2wrl                   rlDynamics2Demo              rlLoadXmlDemo                      rlQuarticLinearQuarticTest           rlSpatialForceVectorTest
rlAxisControllerDemo      rlDynamicsTest               rlLowPassDemo                      rlQuaternionDemo                     rlSpatialMotionVectorTest
rlCameraDemo              rlEetTest                    rlMathDeltaTest                    rlRangeSensorDemo                    rlSpatialPlueckerTransformTest
rlCircularTest            rlEuclideanCrossProductTest  rlNearestNeighborsTest             rlRobotiqModelCDemo                  rlSpatialRigidBodyInertiaTest
rlCoachKin                rlEulerAnglesDemo            rlPcaDemo                          rlRotationConverterDemo              rlSplineScaleTest
rlCoachKin-0.7.0          rlGripperDemo                rlPlanDemo                         rlRotationConverterDemo-0.7.0        rlSplineTest
rlCoachMdl                rlHalEndianTest              rlPlanDemo-0.7.0                   rlRrtDemo                            rlSplineTranslationTest
rlCoachMdl-0.7.0          rlInterpolatorDemo           rlPlanDemo-20250521-134552027.pdf  rlSceneCollisionTest                 rlThreadsDemo
rlCollisionDemo           rlInverseKinematicsKinTest   rlPlanDemo-20250521-134556611.png  rlSexticLinearSexticTest             rlTimerDemo
rlCollisionDemo-0.7.0     rlInverseKinematicsMdlTest   rlPlanDemo-20250521-134559562.png  rlSimulator                          rlTrapezoidalAccelerationTest
rlCollisionTest           rlInversePositionDemo        rlPolynomialAtRestTest             rlSimulator-0.7.0                    rlTrapezoidalVelocityDemo
rlCompositeFunctionTest   rlJacobianDemo               rlPolynomialExtremaTest            rlSixAxisForceTorqueSensorDemo       rlViewDemo
rlCoordinatesPolarTest    rlJacobianKinTest            rlPolynomialRootsDemo              rlSocketDemoClient                   rlViewDemo-0.7.0
rlCoordinatesSpatialTest  rlJacobianMdlTest            rlPolynomialTest                   rlSocketDemoServer                   tris2wrl
rlDenavitHartenbergDemo   rlKalmanDemo                 rlPrmDemo                          rlSpatialArticulatedBodyInertiaTest  wrlview
rlDynamics1Demo           rlKalmanDemo2                rlPrmTest                          rlSpatialCrossProductTest            wrlview-0.2.2





./byu2wrl 
Usage: byu2wrl [input.g] [output.wrl]


./csv2wrl 
Usage: csv2wrl [input.csv] [output.wrl]


./rlAxisControllerDemo 
Connection refused


./rlCameraDemo 
Segmentation fault


./rlCircularTest 
Circular: testing with y0: 0.0000000000 0.0000000000 yi: 0.0000000000 1.0000000000 y1: -1.0000000000  0.0000000000
Circular: testing with y0: 2.0000000000 0.0000000000 yi:  3.0000000000 -1.0000000000 y1:  2.0000000000 -1.0000000000
Circular: testing with y0: 0.0000000000 5.0000000000 yi: 0.0000000000 8.0000000000 y1: -3.0000000000  5.0000000000
Circular: testing with y0: 0.0000000000 5.0000000000 2.0000000000 yi: 0.0000000000 8.0000000000 2.0000000000 y1: -3.0000000000  5.0000000000  2.0000000000
Circular: testing with y0: 0.0000000000 5.0000000000 2.0000000000 yi: 0.0000000000 8.0000000000 2.0000000000 y1: 0.1000000000 5.0000000000 3.0000000000



./rlCollisionTest 
Usage: rlCollisionTest SCENEFILE KINEMATICSFILE JOINT1 ... JOINTn (in degrees)




./rlCollisionTest /home/cnc/Desktop/BUILD3/rl/tests/rlCollisionTest/twotori.xml /home/cnc/Desktop/BUILD3/rl/tests/rlCollisionTest/twotori.wrl 0 0 0 0 0 0




./rlCompositeFunctionTest
rlCompositeFunctionTest: /home/cnc/Desktop/BUILD3/rl/src/rl/math/Polynomial.h:590: T rl::math::Polynomial<T>::operator()(const rl::math::Real&, const std::size_t&) const [with T = double; rl::math::Real = double; std::size_t = long unsigned int]: Assertion `x < this->upper() + this->functionBoundary' failed.
Aborted



./rlCoordinatesPolarTest
success: 100005 failure: 0




./rlCoordinatesSpatialTest
success: 100007 failure: 0





./rlDenavitHartenbergDemo 
T_d = 
  1   0   0   0
  0   1   0   0
  0   0   1 101
  0   0   0   1
T_theta = 
 -0.999848  0.0174524          0          0
-0.0174524  -0.999848          0          0
         0          0          1          0
         0          0          0          1
T_a = 
 1  0  0 31
 0  1  0  0
 0  0  1  0
 0  0  0  1
T_alpha = 
        1         0         0         0
        0 0.0174524  0.999848         0
        0 -0.999848 0.0174524         0
        0         0         0         1
A = 
  -0.999848 0.000304586   0.0174497    -30.9953
 -0.0174524  -0.0174497   -0.999695   -0.541025
          0   -0.999848   0.0174524         101
          0           0           0           1
A = 
  -0.999848 0.000304586   0.0174497    -30.9953
 -0.0174524  -0.0174497   -0.999695   -0.541025
          0   -0.999848   0.0174524         101
          0           0           0           1
a = 31
alpha = -89
d = 101
theta = -179





./rlDynamics1Demo 
Usage: rlDynamics1Demo MODELFILE Q1 ... Qn QD1 ... QDn QDD1 ... QDDn



./rlDynamics1Planar2Demo
Usage: rlDynamics1Planar2Demo Q1 Q2 QD1 QD2 QDD1 QDD2



./rlDynamics2Demo
Usage: rlDynamics2Demo MODELFILE Q1 ... Qn QD1 ... QDn QDD1 ... QDDn



./rlDynamicsTest
Usage: rlDynamicsTest MODELFILE LOOP






./rlEuclideanCrossProductTest
./rlEulerAnglesDemo
Usage: rlEulerAnglesDemo AXIS0 AXIS1 AXIS2 DEG0 DEG1 DEG2
./rlEulerAnglesDemo 10 10 10 12 12 12
angle0: 0.20944 rad - axis0: 0 0 0
angle1: 0.20944 rad - axis1: 0 0 0
angle2: 0.20944 rad - axis2: 0 0 0

quaternion.w: 0.975653 - quaternion.vec: 0 0 0
angle: 0 rad - axis: 1 0 0
x: 0 deg - y: -0 deg - z: 0 deg




./rlGripperDemo
No route to host




./rlHalEndianTest
host   42ec
host   42ec
little 42ec
big    42ec

                word   42ec
        reverse(word)  ec42
reverse(reverse(word)) 42ec

host   42ec7654
host   42ec7654
little 42ec7654
big    42ec7654

                doubleWord   42ec7654
        reverse(doubleWord)  5476ec42
reverse(reverse(doubleWord)) 42ec7654

                float   1.41421
        reverse(float)  -1.05142e+31
reverse(reverse(float)) 1.41421

host   42ec7654c5bd91e0
host   42ec7654c5bd91e0
little 42ec7654c5bd91e0
big    42ec7654c5bd91e0

                quadWord   42ec76546d8b43ac
        reverse(quadWord)  ac438b6d5476ec42
reverse(reverse(quadWord)) 42ec76546d8b43ac

                double   1.41421
        reverse(double)  -1.13119e+64
reverse(reverse(double)) 1.41421







./rlInterpolatorDemo


./rlInverseKinematicsKinTest
Usage: rlInverseKinematicsTest KINEMATICSFILE



./rlInverseKinematicsMdlTest 
Usage: rlInverseKinematicsMdlTest KINEMATICSFILE




./rlInversePositionDemo 
Usage: rlInversePositionDemo MODELFILE Q1 ... Qn


./rlJacobianDemo 
Usage: rlJacobianDemo KINEMATICSFILE Q1 ... Qn QD1 ... QDn


./rlJacobianKinTest 
Usage: rlKinJacobianTest KINEMATICSFILE



./rlJacobianMdlTest 
Usage: rlJacobianTest KINEMATICFILE



./rlKalmanDemo
rlKalmanDemo: /home/cnc/Desktop/BUILD3/rl/src/rl/math/Kalman.h:101: rl::math::Kalman<Scalar>::VectorType rl::math::Kalman<Scalar>::correct(const VectorType&) [with Scalar = double; VectorType = Eigen::Matrix<double, -1, 1>]: Assertion `z.size() == xPriori.size()' failed.
Aborted



./rlKalmanDemo2
Usage: rlKalmanDemo2 DATA FILTERED




./rlLaserDemo 
terminate called after throwing an instance of 'rl::hal::ComException'
  what():  Input/output error
Aborted
sh: 1: gnuplot: not found








./rlLoadXmlDemo
Usage: rlLoadXmlDemo XMLFILE [PARAM1 VALUE1 ... PARAMN VALUEN]



./rlLowPassDemo
Usage: rlLowPassDemo DATA FILTERED





./rlMathDeltaTest
T1: 
  1   0   0 0.1
  0   1   0   0
  0   0   1   0
  0   0   0   1
T2: 
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
delta: -0.1    0    0    0    0    0
T1: 
  0.995004          0  0.0998334        0.1
         0          1          0          0
-0.0998334          0   0.995004          0
         0          0          0          1
T2: 
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
delta: -0.1    0    0    0 -0.1    0
T1: 
6.12323e-17           0           1         0.1
          0           1           0           0
         -1           0 6.12323e-17           0
          0           0           0           1
T2: 
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
delta:    -0.1       0       0       0 -1.5708       0
T1: 
          -1            0  1.22465e-16          0.1
           0            1            0            0
-1.22465e-16            0           -1            0
           0            0            0            1
T2: 
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
delta:     -0.1        0        0       -0 -3.14159       -0
T1: 
           1            0 -2.44929e-16          0.1
           0            1            0            0
 2.44929e-16            0            1            0
           0            0            0            1
T2: 
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
delta:        -0.1           0           0           0 2.44929e-16           0







./rlNearestNeighborsTest
===============================================================================

** LinearNearestNeighbors<Metric> *********************************************
build time 0.002892 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.009398 ms
** LinearNearestNeighbors<MetricSquared> **************************************
build time 0.001031 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.006522 ms
** GnatNearestNeighbors<Metric> ***********************************************
build time 0.001032 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.007784 ms
** KdtreeBoundingBoxNearestNeighbors<MetricSquared> ***************************
build time 0.00782 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.008335 ms
** KdtreeNearestNeighbors<MetricSquared> **************************************
build time 0.022962 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.011526 ms

-------------------------------------------------------------------------------

** LinearNearestNeighbors<Metric> *********************************************
build time 0.002756 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.008629 ms
** LinearNearestNeighbors<MetricSquared> **************************************
build time 0.001621 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.007417 ms
** GnatNearestNeighbors<Metric> ***********************************************
build time 0.000784 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.009059 ms
** KdtreeBoundingBoxNearestNeighbors<MetricSquared> ***************************
build time 0.005025 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.009666 ms
** KdtreeNearestNeighbors<MetricSquared> **************************************
build time 0.009397 ms
searching for 9 2
found 8 1 dist 1.41421
search time 0.011434 ms

===============================================================================

** LinearNearestNeighbors<Metric> *********************************************
build time 0.345426 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 49.1582 ms


average search time (100) 46.9351 ms
** LinearNearestNeighbors<MetricSquared> **************************************
build time 0.313847 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 46.1996 ms



average search time (100) 45.5649 ms
** GnatNearestNeighbors<Metric> ***********************************************
build time 1656.27 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 3.47051 ms
average search time (100) 3.02148 ms
** KdtreeBoundingBoxNearestNeighbors<MetricSquared> ***************************
build time 349.224 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 1.05223 ms
average search time (100) 0.716583 ms
** KdtreeNearestNeighbors<MetricSquared> **************************************
build time 297.057 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 0.724899 ms
average search time (100) 0.625953 ms

-------------------------------------------------------------------------------

** LinearNearestNeighbors<Metric> *********************************************
build time 2.26811 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 47.8327 ms
average search time (100) 46.7283 ms
** LinearNearestNeighbors<MetricSquared> **************************************
build time 2.23988 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 47.2322 ms
average search time (100) 46.0836 ms
** GnatNearestNeighbors<Metric> ***********************************************
build time 1579.01 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 3.96632 ms
average search time (100) 3.29706 ms
** KdtreeBoundingBoxNearestNeighbors<MetricSquared> ***************************
build time 256.497 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 0.878392 ms
average search time (100) 0.739539 ms
** KdtreeNearestNeighbors<MetricSquared> **************************************
build time 276.087 ms
searching for   0.559834  -0.623382 -0.0325239   0.513115   0.172075   0.598115
found   0.60905 -0.624743 0.0747089  0.473941  0.321456  0.498267 dist 0.218499
search time 0.885935 ms
average search time (100) 0.715049 ms





./rlPcaDemo
Usage: rlPcaDemo FILE



./rlPolynomialAtRestTest


./rlPolynomialExtremaTest
rlPolynomialExtremaTest: Polynomial::getAbsoluteMaximum() is ok.



./rlPolynomialRootsDemo
Usage: rlPolynomialRootsDemo C0 ... CN



./rlPolynomialTest
rlPolynomialTest is ok.



./rlPrmDemo
Usage: rlPrmDemo SCENEFILE KINEMATICSFILE START1 ... STARTn GOAL1 ... GOALn



./rlPrmTest
Usage: rlPrmTest ENGINE SCENEFILE KINEMATICSFILE EXPECTED_NUM_VERTICES_MAX EXPECTED_NUM_EDGES_MAX X Y Z A B C START1 ... STARTn GOAL1 ... GOALn




./rlPumaDemo
Usage: rlPumaDemo PUMAFILE Q1 Q2 Q3 Q4 Q5 Q6










./rlQuarticLinearQuarticTest
rlQuarticLinearQuarticTest(Real): Ok, done.
rlQuarticLinearQuarticTest(ArrayX): Ok, done.
rlQuarticLinearQuarticTest: Done.




./rlQuaternionDemo
r1 = 
2.22045e-16          -1           0
          1 2.22045e-16           0
          0           0           1
q1 =        0        0 0.707107 0.707107
r1 = 
2.22045e-16          -1           0
          1 2.22045e-16           0
          0           0           1
r2 = 
2.22045e-16           1           0
         -1 2.22045e-16          -0
         -0           0           1
q2 =         0         0 -0.707107  0.707107
q = 0 0 0 1
r = 
1 0 0
0 1 0
0 0 1
q1 -> q2 = 3.14159
q1 -> q  = 1.5708
q  -> q2 = 1.5708
log(q1) =        0        0 0.785398        0
exp(q1) =        0        0 0.649637 0.760245
exp(log(q1)) =        0        0 0.707107 0.707107
q1^1 =        0        0 0.707107 0.707107
q1^2 =            0            0            1 -1.60812e-16
(q1^2)^0.5 =        0        0 0.707107 0.707107
omega =  45  90 135
qd =  0.833041   0.27768  0.833041 -0.833041
omega =  45  90 135
omegad =  450  900 1350
qdd =  8.33041   2.7768  6.80378 -9.85703
omegad =  450  900 1350
rlQuaternionDemo: /home/cnc/Desktop/BUILD3/rl/src/rl/math/QuaternionBaseAddons.h:53: static Eigen::Quaternion<typename Eigen::internal::traits<T>::Scalar> Eigen::QuaternionBase<Derived>::Random(const Eigen::MatrixBase<OtherDerived>&, const Eigen::QuaternionBase<OtherDerived2>&, const Eigen::MatrixBase<OtherDerived3>&) [with OtherDerived1 = Eigen::Matrix<double, 3, 1>; OtherDerived2 = Eigen::Quaternion<double>; OtherDerived3 = Eigen::Matrix<double, 3, 1>; Derived = Eigen::Quaternion<double>; typename Eigen::internal::traits<T>::Scalar = double]: Assertion `gauss(2) <= Scalar(1)' failed.
Aborted





./rlRangeSensorDemo
terminate called after throwing an instance of 'rl::hal::ComException'
  what():  Input/output error
Aborted


./rlRobotiqModelCDemo
No such file or directory




./rlRrtDemo
Usage: rlRrtDemo SCENEFILE KINEMATICSFILE START1 ... STARTn GOAL1 ... GOALn



./rlSceneCollisionTest
Usage: rlSceneCollisionTest SCENEFILE [shouldCollide]



./rlSexticLinearSexticTest
rlSexticLinearSexticTest(Real): Ok, done.
rlSexticLinearSexticTest(ArrayX): Ok, done.
rlSexticLinearSexticTest: Done.



./rlSixAxisForceTorqueSensorDemo
Usage: rlSixAxisForceTorqueSensorDemo FILE


./rlSocketDemoClient
Usage: rlSocketDemoClient ADDRESS PORT MESSAGE BUFFERSIZE


./rlSocketDemoServer
Usage: rlSocketDemoServer PORT BUFFERSIZE



./rlSpatialArticulatedBodyInertiaTest



./rlSpatialCrossProductTest

                    
./rlSpatialForceVectorTest 





./rlSpatialMotionVectorTest
./rlSpatialPlueckerTransformTest

./rlSpatialRigidBodyInertiaTest
./rlSplineScaleTest
rlSplineTest2: Verify Spline::scaledX done.
./rlSplineTest
rlSplineTest: Done.
./rlSplineTranslationTest
0: p(x) = 6.80375
0: q(x) = 6.80375
0: p(x) = q(x - 2.11234)

1: p(x) = 5.9688 x^1 + 5.66198
1: q(x) = 5.9688 x^1 + 54.8028
1: p(x) = q(x + 8.23295)

2: p(x) = 5.36459 x^2 - 3.29554 x^1 - 6.04897
2: q(x) = 5.36459 x^2 - 50.9815 x^1 + 114.568
2: p(x) = q(x - 4.44451)

3: p(x) = -2.70431 x^3 + 2.57742 x^2 - 0.452059 x^1 + 1.0794
3: q(x) = -2.70431 x^3 + 0.403005 x^2 + 0.346749 x^1 + 1.09132
3: p(x) = q(x + 0.268018)

4: p(x) = -7.16795 x^4 + 4.34594 x^3 + 2.71423 x^2 + 8.3239 x^1 + 9.04459
4: q(x) = -7.16795 x^4 - 56.9939 x^3 - 166.236 x^2 - 201.138 x^1 - 68.3267
4: p(x) = q(x + 2.13938)

5: p(x) = -1.98111 x^5 - 6.86642 x^4 + 6.08354 x^3 - 7.25537 x^2 - 5.14226 x^1 - 9.67399
5: q(x) = -1.98111 x^5 + 66.4762 x^4 - 876.642 x^3 + 5640.62 x^2 - 17519.2 x^1 + 20610.2
5: p(x) = q(x - 7.40419)

6: p(x) = -4.07937 x^6 + 2.2528 x^5 + 6.78224 x^4 + 0.258648 x^3 - 5.63486 x^2 + 9.97849 x^1 - 7.82382
6: q(x) = -4.07937 x^6 - 65.0824 x^5 - 425.335 x^4 - 1453.31 x^3 - 2731.37 x^2 - 2661.98 x^1 - 1042.57
6: p(x) = q(x + 2.75105)

7: p(x) = -1.99543 x^7 + 5.39828 x^6 + 0.5349 x^5 + 5.42715 x^4 - 4.14966 x^3 + 9.4555 x^2 - 0.12834 x^1 + 0.485744
7: q(x) = -1.99543 x^7 - 103.979 x^6 - 2315.31 x^5 - 28542.6 x^4 - 210258 x^3 - 924818 x^2 - 2.24684e+06 x^1 - 2.32312e+06
7: p(x) = q(x + 7.83059)

8: p(x) = -6.15572 x^8 - 8.27888 x^7 + 0.519907 x^6 + 8.98654 x^5 - 8.60489 x^4 + 8.38053 x^3 + 6.15449 x^2 - 2.95083 x^1 - 4.33371
8: q(x) = -6.15572 x^8 - 169.044 x^7 - 2025.55 x^6 - 13826.8 x^5 - 58799.9 x^4 - 159508 x^3 - 269537 x^2 - 259369 x^1 - 108792
8: p(x) = q(x + 3.26454)

9: p(x) = 7.0184 x^9 + 8.04416 x^8 + 9.41268 x^7 - 5.2344 x^6 - 8.73808 x^5 - 0.845965 x^4 - 9.59954 x^3 - 8.71657 x^2 - 3.02214 x^1 + 7.80465
9: q(x) = 7.0184 x^9 - 286.73 x^8 + 5211.56 x^7 - 55323.5 x^6 + 378074 x^5 - 1.7252e+06 x^4 + 5.25726e+06 x^3 - 1.03181e+07 x^2 + 1.18357e+07 x^1 - 6.04596e+06
9: p(x) = q(x - 4.66669)



./rlThreadsDemo
Thread[0]
Thread[1]
Thread[2]
Thread[3]
Thread[4]
before join()
Thread[2] - 0 - 0.117016 seconds
Thread[3] - 0 - 0.186466 seconds
Thread[0] - 0 - 0.67079 seconds
Thread[1] - 0 - 1.07074 seconds
Thread[0] - 1 - 0.592615 seconds
Thread[4] - 0 - 1.27255 seconds
Thread[2] - 1 - 1.36947 seconds
Thread[4] - 1 - 0.37905 seconds
Thread[1] - 1 - 0.630391 seconds
Thread[3] - 1 - 1.85506 seconds
Thread[2] - 2 - 0.55637 seconds
Thread[4] - 2 - 0.426074 seconds
Thread[4] - 3 - 0.346115 seconds
Thread[3] - 2 - 0.411249 seconds
Thread[0] - 2 - 1.49468 seconds
Thread[0] - 3 - 0.162717 seconds
Thread[2] - 3 - 1.01157 seconds
Thread[3] - 3 - 1.15027 seconds
Thread[0] - 4 - 0.704301 seconds
Thread[1] - 2 - 1.96336 seconds
Thread[4] - 4 - 1.80756 seconds
Thread[2] - 4 - 1.3276 seconds
Thread[1] - 3 - 1.64042 seconds
Thread[3] - 4 - 1.73168 seconds
Thread[1] - 4 - 0.205943 seconds
after join()





./rlTimerDemo
0.514026 seconds... 0.51415
0.690622 seconds... 0.690685
0.921167 seconds... 0.921308
0.704391 seconds... 0.70446
0.766444 seconds... 0.766576
0.635402 seconds... 0.63553
0.958615 seconds... 0.958777



./rlTrapezoidalAccelerationTest
rlTrapeziodalAccelerationTest(ArrayX): Ok, done.
rlTrapeziodalAccelerationTest: Done.





./rlTrapezoidalVelocityDemo >outv






ls *.dat
cubic.dat                 cubicSecondDerivative.dat  normalQuaternions.dat  slerpFirstDerivative.dat  squadFirstDerivative.dat
cubicFirstDerivative.dat  interpolation.dat          slerp.dat              squad.dat                 uniformQuaternions.dat




./tris2wrl
Usage: tris2wrl [input.tris] [output.wrl]





```











