if(EXISTS "/Users/CHESS101/CLionProjects/Project3JoySticks/build/Tests-b12d07c_tests.cmake")
  include("/Users/CHESS101/CLionProjects/Project3JoySticks/build/Tests-b12d07c_tests.cmake")
else()
  add_test(Tests_NOT_BUILT-b12d07c Tests_NOT_BUILT-b12d07c)
endif()
