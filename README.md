# SystemC-Quickstart
A simple C++ CMake project to jump-start development SystemC of SystemC models and systems

# How to build
Building the project from source is simple. First you need to install conan and setup the Minres remote:
```
pip install conan
conan remote add minres https://dl.bintray.com/minres/conan-repo
```
The clone the repo:
```
git clone https://github.com/Minres/SystemC-Quickstart.git
```
Now install needed packages (SystemC and SCV library) and build:
```
cd SystemC-Quickstart
mkdir build
cd build
conan install ..
cmake ..
cmake --build .
bin/TransactionExample
```
et voila you completed your first SystemC simulation even with transaction recording!
If you would like to see the recording output just download the latest release of 
SCViewer [https://github.com/Minres/SCViewer/releases] to open the transaction_example.txlog.
