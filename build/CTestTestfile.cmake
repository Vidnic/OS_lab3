# CMake generated Testfile for 
# Source directory: C:/Users/USER/source/repos/os_lab3
# Build directory: C:/Users/USER/source/repos/os_lab3/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(MyTests "C:/Users/USER/source/repos/os_lab3/build/Debug/tests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/USER/source/repos/os_lab3/CMakeLists.txt;29;add_test;C:/Users/USER/source/repos/os_lab3/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(MyTests "C:/Users/USER/source/repos/os_lab3/build/Release/tests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/USER/source/repos/os_lab3/CMakeLists.txt;29;add_test;C:/Users/USER/source/repos/os_lab3/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(MyTests "C:/Users/USER/source/repos/os_lab3/build/MinSizeRel/tests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/USER/source/repos/os_lab3/CMakeLists.txt;29;add_test;C:/Users/USER/source/repos/os_lab3/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(MyTests "C:/Users/USER/source/repos/os_lab3/build/RelWithDebInfo/tests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/USER/source/repos/os_lab3/CMakeLists.txt;29;add_test;C:/Users/USER/source/repos/os_lab3/CMakeLists.txt;0;")
else()
  add_test(MyTests NOT_AVAILABLE)
endif()
subdirs("_deps/googletest-build")
