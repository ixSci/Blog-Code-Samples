# scrutator.me code samples #

### What's this repository about? ###

This repository contains code samples used in the articles published in my blog([scrutator.me](http://scrutator.me)) and will hardly be interesting to anyone besides my readers.

### Prerequisites ###

* [CMake](https://cmake.org)
* C++14 compatible compiler.
* [Boost.TTI](http://www.boost.org/doc/libs/1_63_0/libs/tti/doc/html/index.html)

The code has been tested on: *MSVC 2015 Update 3* & *gcc version 6.2.0*

### How to build? ###

To build the application follow the steps:

* Create `bin` folder
* `cd bin`
* `cmake -G "Generator" ..` where `Generator` should be one of the list CMake supports. Consult the CMake help(`cmake --help`) to find the one which suits you.   
