# ROSA, temporary GoogleTest exercise
This repo will be removed later.

## Requirements
1. Build tool:
   * CMake version 3.10

## How to clone
Since the repository contains GoogleTest as a submodule, use the following git command for convenience.
```
git clone --recurse-submodules <URL> <desired dir name>
```
where you could use the HTTPS or SSH URL of the repository as you prefer.


## How to Build
### 1. Build the project:
```
mkdir build
cd build
cmake ../
```
#### MacOS:
```
make -j8
```
#### Windows:

Add the following line to the CMakeLists.txt before "add_subdirectory" line:
```
# make gtest link the runtimes dynamically
SET(gtest_force_shared_crt on CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib.")
```
Then Continue the build process :
```
cd ..
cmake --build build
```
## How to Run

```
cd build
```
#### Windows :
For multi-config generators (e.g. Visual Studio), first navigate to the appropriate subdirectory
```
cd debug
```
#### Run .exe :
Run the executable as below to run the main code (which is essentially doing nothing.) 
```
./RosaSimulator
 ```
and the following to run the tests
``` 
./hello_test
```
