cmake_minimum_required(VERSION 3.2.2)
project(xapian-hunspell-stemmer)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(Xapian REQUIRED)
find_package(HunSpell REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES src/example/hunspell_stemmer.cc src/include/xapian-hunspell-stemmer/InternalStemHunspell.h)
add_executable(hunspell_stem_example ${SOURCE_FILES})

target_include_directories(hunspell_stem_example PUBLIC ${HUNSPELL_INCLUDE_DIR})
target_link_libraries(hunspell_stem_example ${XAPIAN_LIBRARIES})
target_link_libraries(hunspell_stem_example ${HUNSPELL_LIBRARY})