# NEW
# NAME
# GROUP
# EXT
# LIB_NAME
# PASS_NAME
function(add_test_case)
  set(PARAMS NAME GROUP EXT LIB_NAME PASS_NAME)
  cmake_parse_arguments("ARG" "NEW" "${PARAMS}" "" ${ARGN})
  set(SRC "${CMAKE_SOURCE_DIR}/test/${ARG_GROUP}/${ARG_NAME}.${ARG_EXT}")
  set(LL "${CMAKE_BINARY_DIR}/test/${ARG_GROUP}/${ARG_NAME}.ll")
  set(LIB "${CMAKE_BINARY_DIR}/lib/${ARG_LIB_NAME}.so")
  set(OUT "${CMAKE_BINARY_DIR}/test/${ARG_GROUP}/${ARG_NAME}_${ARG_PASS_NAME}.ll")
  set(TARGET "Test${ARG_GROUP}_${ARG_NAME}")
  if (ARG_NEW)
    add_custom_target(${TARGET}
      COMMAND clang-15 -emit-llvm -S -fno-discard-value-names -c
              -o ${LL} ${SRC}
      COMMAND opt -load-pass-plugin ${LIB} -passes="${ARG_PASS_NAME}" -S ${LL} -o ${OUT}
    )
  else ()
    add_custom_target(${TARGET}
      COMMAND clang-15 -emit-llvm -S -fno-discard-value-names -c
              -o ${LL} ${SRC}
      COMMAND opt -load ${LIB} -${ARG_PASS_NAME} -enable-new-pm=0 -S ${LL} -o ${OUT}
    )
  endif ()
  add_dependencies(${TARGET} ${ARG_LIB_NAME})
endfunction()

add_subdirectory(HelloPass)
add_subdirectory(NewHelloPass)