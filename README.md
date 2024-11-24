# SystemC-Quickstart
A simple C++ CMake project to jump-start development of SystemC-based models and systems. It also shows the power of using a package manager:
```
git clone https://github.com/Minres/SystemC-Quickstart
cd SystemC-Quickstart/
mkdir build
cd build/
cmake ..
make
``` 
gets you to build a SystemC simulation. E.g. to deploy SystemC CCI to your project, changing conanfile.txt in the project root to
```
[requires]
SystemC/2.3.3@minres/stable
SystemCVerification/2.0.1@minres/stable
SystemC-CCI/1.0.0@minres/stable

[generators]
cmake

[options]
SystemC:stdcxx=14
SystemCVerification:stdcxx=14
SystemC-CCI:stdcxx=14
```
is sufficient to be able to start using CCI in your models.

When using Eclipse CDT as developemnt environment it is highly recommended to install Martin Webers
[cmake4eclipse](https://marketplace.eclipse.org/content/cmake4eclipse) extension as it imports not only the
cmake configuration settings rather also those coming from the conan packages

# How to build (full story)
> Currently only Linux and MacOS are tested

Building the project from source is simple. First you need to install [conan.io](https://conan.io/) according to the [instructions](http://docs.conan.io/en/latest/installation.html) and setup the Minres remote:
```
pip install conan
conan remote add minres https://api.bintray.com/conan/minres/conan-repo
```
Then clone the SystemC-Quickstart repo:
```
git clone https://github.com/Minres/SystemC-Quickstart.git
```
Build the project (it will download the needed libraries) and run it:
```
cd SystemC-Quickstart
mkdir build
cd build
cmake ..
cmake --build .
bin/TransactionExample
```
Et voila you completed your first SystemC simulation even with transaction recording!
If you would like to analyze the recording output further just download the latest release of 
[SCViewer](https://github.com/Minres/SCViewer/releases) to open the transaction_example.txlog.

## Notes

If you encounter issues when linking wrt. c++11 symbols you might have run into GCC ABI incompatibility introduced from GCC 5.0 onwards. You can fix this by adding '-s compiler.libcxx=libstdc++11' to the conan call or changing compiler.libcxx to
```
compiler.libcxx=libstdc++11
```
in $HOME/.conan/profiles/default

### Detailed preparation steps

#### Ubuntu

```
#prepare system
sudo apt-get install -y git python-pip build-essential cmake libloki-dev zlib1g-dev libncurses5-dev \	
    libboost-dev libboost-program-options-dev libboost-system-dev libboost-thread-dev llvm-dev llvm-doc
#install conan
pip install --user conan
export PATH=${PATH}:$HOME/.local/bin
```

#### Fedora

```
#prepare system
dnf install @development-tools gcc-c++ boost-devel zlib-devel loki-lib-devel cmake python2 python3 llvm-devel llvm-static
#install conan
pip3 install --user conan
export PATH=${PATH}:$HOME/.local/bin
```
 
### Build the project

```
# configure conan
conan remote add minres https://git.minres.com/api/packages/Tooling/conan
conan profile new default --detect
# clone the project
git clone https://github.com/Minres/SystemC-Quickstart.git
cd SystemC-Quickstart
mkdir build; cd build
cmake ..
cmake --build .
bin/TransactionExample
```
