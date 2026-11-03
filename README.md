# scrutator.me code samples #

### What's this repository about? ###

This repository contains code samples used in the articles published on my blog ([scrutator.me](http://scrutator.me)) and will hardly be interesting to anyone besides its readers.

### Prerequisites ###

* MSVS 2026 or Ninja with working C++23 compiler.
* [CMake](https://cmake.org) 4.0 or higher.
* [Vcpkg](https://vcpkg.io/en/) installed and [VCPKG_ROOT](https://learn.microsoft.com/en-us/vcpkg/users/config-environment#vcpkg_root) env variable set

### How to setup? ###
Install the prerequisites and setup required env variables, then copy `assets/LocalConfig.json.template` to `./LocalConfig.json`.

### How to build? ###

To build the application follow the steps:

* Generate either MSVS2026 or Ninja output with `cmake --preset vs` or `cmake --preset nj`
* Then either go to the `.\bin` folder to work with the generated files or 
* Build it with `cmake --build --preset [vs|nj]-[debug|release]`. E.g. `cmake --build --preset vs-debug`  