# Advent of Code

Assuming that AoC is a nail, lets try the heaviest hammer I can find (C++).

## HOWTOs
Build with:
```bash
mkdir build && cd build
cmake -G "Ninja" ..
cmake --build
```

Choose compiler by:
```bash
# GCC
CC=gcc CXX=g++ cmake -G "Ninja" -DCMAKE_BUILD_TYPE=RelWithDebInfo path/to/source
# clang
CC=clang CXX=clang++ cmake -G "Ninja" -DCMAKE_BUILD_TYPE=RelWithDebInfo path/to/source
```

Build with sanitizers:
```bash
mkdir build_address && cd build_address
CC=clang CXX=clang++ cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=address -fsanitize=undefined" path/to/source
cd .. && mkdir build_cmemory && cd build_memory
CC=clang CXX=clang++ make -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=memory" path/to/source
cd .. && mkdir build_thread && cd build_thread
CC=clang CXX=clang++ cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=thread" path/to/source
```

Test with:
```bash
ctest --output-on-failure
```

### Clang-format
- Use clang-format as pre-commit hook
- Formatting style based on google
- Just for consistency, no strong feelings about the style whatsoever

### Run Code Coverage Test
- Requires `gcov`, `lcov` and `genhtml` to be available
```bash
cmake -G "Ninja" -DCOMPILE_WITH_COVERAGE=On -DCMAKE_BUILD_TYPE=Debug ../AdventOfCode
cmake --build .
ninja cov
firefox coverage/index.html
# or independent
ctest -T covearge
```


### VS Code/Codium dev setup
- Install clang, clang-tidy, cmake, CodeChecker, lizard
- Install CodeChecker, CMake, C++ extension
- Set compile_command path to `${workspaceFolder}/build/compile_commands.json`
- Set argument to: `--ignore ${workspaceFolder}/.skipfile --analyzer-config clangsa:mode=shallow --ctu --tidy-config ${workspaceFolder}/.clang-tidy`
