add_llvm_library(HelloPass MODULE
  HelloPass.cpp

  PLUGIN_TOOL
  opt
)