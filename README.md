# scrutator.me code samples #

### What's this repository about? ###

This repository contains code samples used in the articles published in my blog([scrutator.me](http://scrutator.me)) and will hardly be interesting to anyone besides my readers.

### Prerequisites ###

* [CMake](https://cmake.org)
* C++17 compatible compiler

The code has been tested on: *gcc version 7.1.0* 

### How to build? ###

To build the application follow the steps:

* Create `bin` folder
* `cd bin`
* `cmake -G "Generator" ..` where `Generator` should be one of the list CMake supports. Consult the CMake help(`cmake --help`) to find the one which suits you.   