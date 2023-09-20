# LearnLLVM
Learn llvm snippet code

# Deps
```sh
sudo apt install llvm-15-dev
sudo apt install clang-15
```

# Build
```sh
mkdir build && cd build
make -j8
```

# Test
```sh
make TestHelloPass_test1
make TestNewHelloPass_test1
```

# Passes
- `HelloPass` is written by legacy pass manager
- `NewHelloPass` is written by new pass manager