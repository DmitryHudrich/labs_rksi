add_test([=[SquareMatrixTest.AddMatrices]=]  [==[/home/hudrich/Документы/projects/cpp/labs_rksi/build/binaries/danil_kostin_work_8/matrix_test]==] [==[--gtest_filter=SquareMatrixTest.AddMatrices]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SquareMatrixTest.AddMatrices]=]  PROPERTIES WORKING_DIRECTORY [==[/home/hudrich/Документы/projects/cpp/labs_rksi/build/cmake_stuff/work_8]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[SquareMatrixTest.MultiplyMatrices]=]  [==[/home/hudrich/Документы/projects/cpp/labs_rksi/build/binaries/danil_kostin_work_8/matrix_test]==] [==[--gtest_filter=SquareMatrixTest.MultiplyMatrices]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SquareMatrixTest.MultiplyMatrices]=]  PROPERTIES WORKING_DIRECTORY [==[/home/hudrich/Документы/projects/cpp/labs_rksi/build/cmake_stuff/work_8]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  matrix_test_TESTS SquareMatrixTest.AddMatrices SquareMatrixTest.MultiplyMatrices)