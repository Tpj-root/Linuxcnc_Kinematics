


To match Boost libraries with your Python version, follow these steps:

    Check your Python version (e.g., python3 --version).

    Use a Boost version that supports your Python version. For example:

        Python 3.11 → Boost 1.81+

        Python 3.10 → Boost 1.78+

        Python 3.9 → Boost 1.75+

    When building Boost:

        Use --with-python and --with-python-version=3.x flags in bootstrap.sh.

        Set the Python path using:

./bootstrap.sh --with-python=/usr/bin/python3.x
./b2 install




For Python 3.11.2, use Boost 1.81.0 or newer.

✅ Recommended:

    Boost 1.81.0

    Boost 1.82.0

    Boost 1.83.0 (or latest)



If installed via package manager:

grep "BOOST_LIB_VERSION" /usr/include/boost/version.hpp




If built from source:
cat /path/to/boost/boost/version.hpp | grep "BOOST_LIB_VERSION"

#define BOOST_LIB_VERSION "1_81"




```
https://github.com/boostorg/boost/releases?page=2

boost-1.83.0.tar.xz 
```





Build Boost from Source

sudo apt install build-essential g++ python3.11-dev wget unzip


wget https://boostorg.jfrog.io/artifactory/main/release/1.83.0/source/boost_1_83_0.tar.gz
tar -xzf boost_1_83_0.tar.gz
cd boost_1_83_0




./bootstrap.sh --with-libraries=python --with-python=/usr/bin/python3.11


/opt/boost_1_83_0/lib
sudo mkdir -p /opt/boost_1_83_0/lib
sudo chown $USER:$USER /opt/boost_1_83_0/lib





./b2 --prefix=/opt/boost_1_83_0 install

or

sudo apt install python3-numpy
./b2 --with-python --with-numpy install --prefix=/opt/boost_1_83_0



Run this inside Boost source directory to clean build files:

./b2 --clean





Set environment variables:

export BOOST_ROOT=/opt/boost_1_83_0
export LD_LIBRARY_PATH=$BOOST_ROOT/lib:$LD_LIBRARY_PATH
export CPLUS_INCLUDE_PATH=$BOOST_ROOT/include

