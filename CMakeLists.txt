cmake_minimum_required(VERSION 3.6)
project(DesignPatternDemos)

set(CMAKE_CXX_STANDARD 14)
#find_package(Boost REQUIRED COMPONENTS serialization)

set(SOURCE_FILES main.cpp SOLID/OpenClose.cpp SOLID/OpenClose.h common.h SOLID/Lisokov.h SOLID/InterfaceSegregation.h SOLID/DependencyInversion.h "Design Patterns/Builder/Builder.h" SOLID/Single.h "Design Patterns/Builder/GroovyStyleBuilder.h" "Design Patterns/Builder/builderFacets.h" "Design Patterns/Builder/builderFacets.cpp" "Design Patterns/Builder/PersonBuilder.cpp" "Design Patterns/Builder/PersonBuilder.h")
add_executable(DesignPatternDemos ${SOURCE_FILES})
target_link_libraries(DesignPatternDemos boost_serialization)
target_link_libraries(DesignPatternDemos boost_wserialization)