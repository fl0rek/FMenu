cmake_minimum_required(VERSION 3.0)
project(FMenu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(FMenu ${SOURCE_FILES} MenuElement.cpp MenuElement.h MenuMultiSelect.cpp MenuMultiSelect.h FVisitor.cpp FVisitor.h MenuNameVisitor.cpp MenuNameVisitor.h InsertVisitor.cpp InsertVisitor.h MenuSingleSelect.cpp MenuSingleSelect.h FMenuFacade.cpp FMenuFacade.h)
