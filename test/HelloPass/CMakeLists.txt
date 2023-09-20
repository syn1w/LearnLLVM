function(add_hello_pass_test)
  set(PARAMS NAME EXT)
  cmake_parse_arguments("ARG" "" "${PARAMS}" "" "${ARGN}")
  add_test_case(
    NAME ${ARG_NAME}
    GROUP HelloPass
    EXT ${ARG_EXT}
    LIB_NAME HelloPass
    PASS_NAME hello
  )
endfunction()

add_hello_pass_test(NAME test1 EXT c)