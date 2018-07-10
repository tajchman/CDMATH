file(GLOB VALIDATION_FOLDERS_TO_INSTALL Poisson2DEF Poisson3DEF Poisson3DSphereEF Poisson2DVF Poisson3DVF WaveSystem2DFV)
file(GLOB VALIDATION_TESTS_TO_INSTALL 
  test_validation2DEF.py 
  test_validation3DEF.py
  test_validation3DSphereEF.py
  test_validation2DVF_s.py
  test_validation2DVF_ns.py
  test_validation2DVF_loc_ref.py
  test_validation3DVF_s.py
  test_validation3DVF_ns.py
  test_validation2DVF_checkerboard.py
  test_validation3DVF_checkerboard.py
  test_validation2DWaveSystemTrianglesFV.py
  test_validation2DWaveSystemSquaresFV.py)

install(FILES ${VALIDATION_TESTS_TO_INSTALL} DESTINATION share/validation)
install(DIRECTORY ${VALIDATION_FOLDERS_TO_INSTALL} DESTINATION share/validation)

if (CDMATH_WITH_PYTHON AND CDMATH_WITH_PETSC AND CDMATH_WITH_POSTPRO)
    ADD_TEST(test_validation2DEF ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation2DEF.py)
    SET_PROPERTY(TEST test_validation2DEF PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation2DEF APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson2DEF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation3DEF ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation3DEF.py)
    SET_PROPERTY(TEST test_validation3DEF PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation3DEF APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson3DEF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation3DSphereEF ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation3DSphereEF.py)
    SET_PROPERTY(TEST test_validation3DSphereEF PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation3DSphereEF APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson3DSphereEF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation2DVF_s ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation2DVF_s.py)
    SET_PROPERTY(TEST test_validation2DVF_s PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation2DVF_s APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson2DVF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation2DVF_ns ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation2DVF_ns.py)
    SET_PROPERTY(TEST test_validation2DVF_ns PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation2DVF_ns APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson2DVF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation2DVF_loc_ref ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation2DVF_ns_loc_ref.py)
    SET_PROPERTY(TEST test_validation2DVF_loc_ref PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation2DVF_loc_ref APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson2DVF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation3DVF_s ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation3DVF_s.py)
    SET_PROPERTY(TEST test_validation3DVF_s PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation3DVF_s APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson3DVF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation3DVF_ns ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation3DVF_ns.py)
    SET_PROPERTY(TEST test_validation3DVF_ns PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation3DVF_ns APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson3DVF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation2DVF_checkerboard ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation2DVF_checkerboard.py)
    SET_PROPERTY(TEST test_validation2DVF_checkerboard PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation2DVF_checkerboard APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson2DVF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation3DVF_checkerboard ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation3DVF_checkerboard.py)
    SET_PROPERTY(TEST test_validation3DVF_checkerboard PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation3DVF_checkerboard APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/Poisson3DVF:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation2DWaveSystemTrianglesFV ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation2DWaveSystemTrianglesFV.py)
    SET_PROPERTY(TEST test_validation2DWaveSystemTrianglesFV PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation2DWaveSystemTrianglesFV APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/WaveSystem2DFV:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

    ADD_TEST(test_validation2DWaveSystemSquaresFV ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test_validation2DWaveSystemSquaresFV.py)
    SET_PROPERTY(TEST test_validation2DWaveSystemSquaresFV PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_INSTALL_PREFIX}/lib/medcoupling:${CMAKE_INSTALL_PREFIX}/lib/med:${PETSC_DIR}/${PETSC_ARCH}/lib:${HDF5_ROOT_DIR}/lib")
    SET_PROPERTY(TEST test_validation2DWaveSystemSquaresFV APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/WaveSystem2DFV:${CMAKE_INSTALL_PREFIX}/lib/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath:${CMAKE_INSTALL_PREFIX}/bin/cdmath/postprocessing:${CMAKE_INSTALL_PREFIX}/${MEDCOUPLING_INSTALL_PYTHON}")

endif (CDMATH_WITH_PYTHON AND CDMATH_WITH_PETSC AND CDMATH_WITH_POSTPRO)

