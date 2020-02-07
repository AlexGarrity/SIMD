# agSIMD
Small library for more easily performing vector maths, using AVX or SSE extensions.

### Building
The easiest way to build is to just run:
```bash
cmake .
make -j4
make install
```

The extensions available to you should be detected automatically, and the library will build whichever one is going to perform best.
Alternatively, you can use my *preferred* method for CMake projects...
```bash
mkdir build
cd build
cmake-gui -S .. -B .
make -j4
make install
```
This allows you to graphically tweak the CMake configuration, provided that you have `cmake-gui` installed.  `ccmake` will also allow you to do this, but with a terminal-based UI.

### Features
The library is built around the `Quad<T>` templated type, which behaves as a vector of 4 values.  Currently the library has three of these defined as typedefs - `BQuad`, `FQuad`, and `DQuad` for `BYTE`s, `float`s, and `double`s respectively.
There are then a set of basic maths functions, `Add`, `Sub`, `Div`, and `Mul` which will take the Quad types and efficiently perform their respective operations on them.  Additionally, there are also packed maths functions, which perform on types such as `BQuad8` - this will allow you to operate on 32 `BYTE` types at once.

### Future Additions
At some point in the future I'll likely add more Quad types for 16, 32, and 64 bit values.  The library was originally extracted from my Pixel library, so only the necessary types for that are currently implemented.
If I do end up doing that, I may well separate the Quad types out into their own files and implement the maths functions as operator overloads.