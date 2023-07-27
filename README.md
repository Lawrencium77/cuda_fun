## Overview

**Status**: In progress.

`csrc/` contains source code for tensor processing library, written in C++.
`python_neural_net` contains a super basic neural network written in Python, using only NumPy. The aim is to replace NumPy with the C++ library once it is complete.

##  Dependencies

Has been tested only with Python 3.11.1.
Run `pip install -r requirements.txt` to install Python dependencies.

### Build Process

Simply run `make all`. This will compile a shared object file and put it into `build/`.
