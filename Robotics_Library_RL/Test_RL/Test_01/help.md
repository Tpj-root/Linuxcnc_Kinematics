g++ myMdlDemo.cpp \
-I/home/where/Desktop/BUILD_FILES/rl/src \
-I/usr/include/eigen3 \
-L/home/where/Desktop/BUILD_FILES/rl/build/lib \
-lrlkin -lrlmdl -lrlplan -lrlsg -lrlhal \
-o rl_test



where@slave:~$ find /home/where/Desktop/BUILD_FILES/rl -name "export.h"
/home/where/Desktop/BUILD_FILES/rl/build/src/rl/mdl/export.h
/home/where/Desktop/BUILD_FILES/rl/build/src/rl/sg/export.h
/home/where/Desktop/BUILD_FILES/rl/build/src/rl/plan/export.h
/home/where/Desktop/BUILD_FILES/rl/build/src/rl/hal/export.h
/home/where/Desktop/BUILD_FILES/rl/build/src/rl/kin/export.h



