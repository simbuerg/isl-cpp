#ifndef ISL_CXX_AstNodeType_H
#define ISL_CXX_AstNodeType_H

namespace isl {
enum class AstNodeType {
  NodeBlock = 3,
  NodeError = -1,
  NodeFor = 1,
  NodeIf = 2,
  NodeMark = 4,
  NodeUser = 5,
};
} // namespace isl
#endif //ISL_CXX_AstNodeType_H
