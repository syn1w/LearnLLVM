#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

class HelloPass : public FunctionPass {
public:
  static char ID;
  HelloPass() : FunctionPass(ID) {}
  bool runOnFunction(Function &F) override {
    llvm::errs() << "Hello: " << F.getName() << '\n';
    return false;
  }

  // We don't modify the program, so we preserve all analyses.
  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesAll();
  }
};

} // namespace

char HelloPass::ID = 0;

static RegisterPass<HelloPass> X("hello", "Hello world pass", false, false);