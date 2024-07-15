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
make -j8
```

## How to Run
In `build` folder, run the executable as below to run the main code (which is essentially doing nothing.)
```
./RosaSimulator
```
and the following to run the tests
```
./hello_test
```
