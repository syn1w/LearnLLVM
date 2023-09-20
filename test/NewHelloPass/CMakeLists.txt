function(add_new_hello_pass_test)
  set(PARAMS NAME EXT)
  cmake_parse_arguments("ARG" "" "${PARAMS}" "" "${ARGN}")
  add_test_case(
    NEW
    NAME ${ARG_NAME}
    GROUP NewHelloPass
    EXT ${ARG_EXT}
    LIB_NAME NewHelloPass
    PASS_NAME new-hello
  )
endfunction()

add_new_hello_pass_test(NAME test1 EXT c)