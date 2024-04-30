# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/aisd6/out/build/x64-Debug/_deps/googletest-src"
  "D:/aisd6/out/build/x64-Debug/_deps/googletest-build"
  "D:/aisd6/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "D:/aisd6/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "D:/aisd6/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "D:/aisd6/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "D:/aisd6/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/aisd6/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
