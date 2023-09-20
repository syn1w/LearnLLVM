#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

using namespace llvm;

namespace {

struct NewHelloPass : public PassInfoMixin<NewHelloPass> {
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
    llvm::errs() << "Hello: " << F.getName() << '\n';

    // Assuming you did not change anything of the IR code
    return PreservedAnalyses::all();
  }

  static bool isRequired() { return true; }
};

} // namespace

extern "C" PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK llvmGetPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "NewHelloPass", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef PassName, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (PassName == "new-hello") {
                    FPM.addPass(NewHelloPass());
                    return true;
                  }
                  return false;
                });
          }};
}