Run on terminal:
```
#start at current directory:
mkdir build && cd build
export DISPLAY=:0
cmake ..
cmake --build . --config Debug # Debug mode
./ocv_sample 
```
So, we have used debug mode by exploiting the cmake.