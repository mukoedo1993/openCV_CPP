Run on terminal:
```
#start at current directory:
mkdir build && cd build
export DISPLAY=:0
cmake ..
cmake --build . --config Release # release mode
./ocv_sample 
```