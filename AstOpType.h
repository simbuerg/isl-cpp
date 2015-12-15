#ifndef ISL_CXX_AstOpType_H
#define ISL_CXX_AstOpType_H

namespace isl {
enum AstOpType {
  AOTOpAccess = 23,
  AOTOpAdd = 7,
  AOTOpAddressOf = 25,
  AOTOpAnd = 0,
  AOTOpAndThen = 1,
  AOTOpCall = 22,
  AOTOpCond = 15,
  AOTOpDiv = 10,
  AOTOpEq = 17,
  AOTOpError = -1,
  AOTOpFdivQ = 11,
  AOTOpGe = 20,
  AOTOpGt = 21,
  AOTOpLe = 18,
  AOTOpLt = 19,
  AOTOpMax = 4,
  AOTOpMember = 24,
  AOTOpMin = 5,
  AOTOpMinus = 6,
  AOTOpMul = 9,
  AOTOpOr = 2,
  AOTOpOrElse = 3,
  AOTOpPdivQ = 12,
  AOTOpPdivR = 13,
  AOTOpSelect = 16,
  AOTOpSub = 8,
  AOTOpZdivR = 14,
};
} // namespace isl
#endif //ISL_CXX_AstOpType_H
