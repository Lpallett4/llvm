// XFAIL: target-arm && linux-gnu
// clang-format off
// REQUIRES: lld

// RUN: %build --compiler=clang-cl --nodefaultlib -o %t.exe -- %s
// RUN: env LLDB_USE_NATIVE_PDB_READER=1 %lldb -f %t.exe -s \
// RUN:     %p/Inputs/ast-methods.lldbinit 2>&1 | FileCheck %s

struct Struct {
  void simple_method() {}

  virtual void virtual_method() {}

  static void static_method() {}

  int overloaded_method() {}
  int overloaded_method(char c) {}
  int overloaded_method(char c, int i, ...) {}
};

Struct s;

int main(int argc, char **argv) {
  return 0;
}

// CHECK: TranslationUnitDecl
// CHECK: |-CXXRecordDecl {{.*}} struct Struct definition
// CHECK: | |-CXXMethodDecl {{.*}} simple_method 'void (){{.*}}'
// CHECK: | |-CXXMethodDecl {{.*}} virtual_method 'void (){{.*}}' virtual
// CHECK: | |-CXXMethodDecl {{.*}} static_method 'void ()' static
// CHECK: | |-CXXMethodDecl {{.*}} overloaded_method 'int (){{.*}}'
// CHECK: | |-CXXMethodDecl {{.*}} overloaded_method 'int (char){{.*}}'
// CHECK: | | `-ParmVarDecl {{.*}} 'char'
// CHECK: | `-CXXMethodDecl {{.*}} overloaded_method 'int (char, int, ...)'
// CHECK: |   |-ParmVarDecl {{.*}} 'char'
// CHECK: |   `-ParmVarDecl {{.*}} 'int'
