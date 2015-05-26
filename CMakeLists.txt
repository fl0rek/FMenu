cmake_minimum_required(VERSION 3.1)
project(FMenu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(FMenu ${SOURCE_FILES} MenuElement.cpp MenuElement.h MenuMultiSelect.cpp MenuMultiSelect.h FVisitor.cpp FVisitor.h MenuNameVisitor.cpp MenuNameVisitor.h MenuSingleSelect.cpp MenuSingleSelect.h RemoveElementVisitor.cpp RemoveElementVisitor.h InsertElementVisitor.cpp InsertElementVisitor.h)