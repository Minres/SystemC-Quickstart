# SystemC-Quickstart
A simple C++ CMake project to jump-start development of SystemC-based models and systems

# How to build
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
Now install needed packages (SystemC and SCV library), build the project and run it:
```
cd SystemC-Quickstart
mkdir build
cd build
conan install .. --build=missing
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
