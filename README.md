# SystemC-Quickstart
> For a conan-only version please check the [conan-only](https://github.com/Minres/SystemC-Quickstart/tree/conan_only) branch.

A simple C++ CMake project to jump-start development of SystemC-based models and systems. It also shows the power of using a package manager:

```
git clone https://github.com/Minres/SystemC-Quickstart
cd SystemC-Quickstart/
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```
gets you to build a SystemC simulation uisng an unoptimized Debug build (for an optimized release build replace `Debug` with `Release`). To deploy other libraries just add them into the package list in [CMakeLists.txt](https://github.com/Minres/SystemC-Quickstart/blob/master/CMakeLists.txt#L27) e.g.:

```
	conan_cmake_configure(REQUIRES systemc/2.3.3 systemc-cci/1.0.0 systemc-scv/2.0.1 fmt/8.0.1
	                      OPTIONS systemc-cci:shared=False
	                      SETTINGS compiler.cppstd=${CMAKE_CXX_STANDARD}
	                      GENERATORS cmake_find_package)

```
is sufficient to be able to start using the FMT library in your models.

When using Eclipse CDT as developemnt environment it is highly recommended to install Martin Webers
[cmake4eclipse](https://marketplace.eclipse.org/content/cmake4eclipse) extension as it imports not only the
cmake configuration settings rather also those coming from the conan packages

# How to build (full story)
> Currently only Linux and MacOS are tested

## Using conan
Building the project from source is simple. First you need to install [conan.io](https://conan.io/) according to the [instructions](http://docs.conan.io/en/latest/installation.html) and setup the Minres remote:

```
pip install -r requirements.txt
conan profile new default --detect
```

Then clone the SystemC-Quickstart repo:

```
git clone https://github.com/Minres/SystemC-Quickstart.git
```

Now install needed packages (SystemC, CCI and SCV library), build the project and run it:

```
cd SystemC-Quickstart
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
build/TransactionExample
```

Et voila you completed your first SystemC simulation even with transaction recording!
If you would like to analyze the recording output further just download the latest release of 
[SCViewer](https://github.com/Minres/SCViewer/releases) to open the transaction_example.txlog.

## Without conan

Install needed packages (SystemC and SCV library) and set SYSTEMC_HOME and SCV_HOME accordingly (if you install
SCV in the same location than SystemC then SYSTEMC_HOME environment variable is sufficient).

Clone the SystemC-Quickstart repo:

```
git clone https://github.com/Minres/SystemC-Quickstart.git
cd SystemC-Quickstart
```

fix the CMakeLists.txt by removing the line

```
setup_conan()
```

Build the project and run it:

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
build/TransactionExample
```

## Notes

If you encounter issues using conan when linking wrt. c++11 symbols you might have run into GCC ABI incompatibility introduced from GCC 5.0 onwards. You can fix this by adding '-s compiler.libcxx=libstdc++11' to the conan call or changing compiler.libcxx to

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
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
build/TransactionExample
```
