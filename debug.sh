set -euxo pipefail

# Memory leak check when running on MacOS with arm64

CMAKE_BUILD_PROGRAM="$(which ninja)"

mkdir -p cmake-build-leaks

cmake -G Ninja -S . -B cmake-build-leaks/ -D CMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-leaks/

cd ./cmake-build-leaks
leaks -quiet -atExit -- ./lab1