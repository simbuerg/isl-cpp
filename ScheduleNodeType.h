#ifndef ISL_CXX_ScheduleNodeType_H
#define ISL_CXX_ScheduleNodeType_H

namespace isl {
enum ScheduleNodeType {
  SNTNodeBand = 0,
  SNTNodeContext = 1,
  SNTNodeDomain = 2,
  SNTNodeError = -1,
  SNTNodeExpansion = 3,
  SNTNodeExtension = 4,
  SNTNodeFilter = 5,
  SNTNodeGuard = 7,
  SNTNodeLeaf = 6,
  SNTNodeMark = 8,
  SNTNodeSequence = 9,
  SNTNodeSet = 10,
};
} // namespace isl
#endif //ISL_CXX_ScheduleNodeType_H
