
set(SampleNb 10)
set(SampleName sample${SampleNb})


# add_library(${SampleName} ${SampleName}.cc)

# target_include_directories(${SampleName} PUBLIC include)


add_executable(${SampleName}_test ${SampleName}_unittest.cc)

target_link_libraries(${SampleName}_test
 PRIVATE
  GTest::GTest
)

add_test(${SampleName}_gtests ${SampleName}_test)
