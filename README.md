# cuda_fun

Current status:

1. From `./`, running

```
nvcc -O3 -I/usr/include/python3.8 -Xcompiler -fPIC -shared -o example.so add.cu host.cu -lpython3.8
```

compiles a shared object.  Running `export CUDA_VISIBLE_DEVICES=0` and then `python3 example.py` will run an example CUDA kernel, that adds two tensors together on GPU. If running correctly, the program will print to stdout:

```
Error is 0.0
```

2. Running

```
cd tensors/
g++ -O3 -Wall -shared -std=c++14 -fPIC `python3 -m pybind11 --includes` pybind.cpp -o Tensor1D`python3-config --extension-suffix`
```

will compile a shared object which allows you to run:

```python
from Tensor1D import Tensor1D
tensor = Tensor1D(5)
```

This `Tensor1D` object supports a few basic operations.
