# scrutator.me code samples #

### What's this repository about? ###

This repository contains code samples used in the articles published in my blog ([scrutator.me](http://scrutator.me)) and will hardly be interesting to anyone besides my readers.

### Prerequisites ###

* MSVS 2022 or Ninja with working C++23 compiler.
* [CMake](https://cmake.org) 23.8
* [Google Benchmark](https://github.com/google/benchmark)

### How to setup? ###
Download and build all the required libs listed in the Prerequisites section, copy `assets/LocalConfig.json.template` to `./LocalConfig.json` and set all the required paths there.

### How to build? ###

To build the application follow the steps:

* Generate either MSVS2022 or Ninja output with `cmake --preset vs` or `cmake --preset nj`
* Then either go to the `.\bin` folder to work with the generated files or 
* Build it with `cmake --build --preset [vs|nj]-[debug|release]`. E.g. `cmake --build --preset vs-debug`  