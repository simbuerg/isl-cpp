#ifndef ISL_CXX_UnionAccessInfo_H
#define ISL_CXX_UnionAccessInfo_H


#include "isl/union_access_info.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Schedule;
class UnionFlow;
class UnionMap;

class UnionAccessInfo {
protected:
  Ctx ctx;
  void * This;
public:
  explicit UnionAccessInfo(Ctx ctx, isl_union_access_info *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_union_access_info *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_union_access_info *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_union_access_info *Get() const;


  /// \brief Constructor for isl_union_access_info_from_sink
  ///
  /// \param sink
  static UnionAccessInfo fromSink(const UnionMap &sink);
public:
  virtual ~UnionAccessInfo();
  /// \brief Generated from  ::<isl_union_access_info_compute_flow>
  ///
  ///
  /// \returns A new UnionFlow
  UnionFlow computeFlow() const;

  /// \brief Generated from  ::<isl_union_access_info_set_may_source>
  ///
  /// \param [in] may_source
  ///
  /// \returns A new UnionAccessInfo
  UnionAccessInfo setMaySource(const UnionMap &may_source) const;

  /// \brief Generated from  ::<isl_union_access_info_set_must_source>
  ///
  /// \param [in] must_source
  ///
  /// \returns A new UnionAccessInfo
  UnionAccessInfo setMustSource(const UnionMap &must_source) const;

  /// \brief Generated from  ::<isl_union_access_info_set_schedule>
  ///
  /// \param [in] schedule
  ///
  /// \returns A new UnionAccessInfo
  UnionAccessInfo setSchedule(const Schedule &schedule) const;

  /// \brief Generated from  ::<isl_union_access_info_set_schedule_map>
  ///
  /// \param [in] schedule_map
  ///
  /// \returns A new UnionAccessInfo
  UnionAccessInfo setScheduleMap(const UnionMap &schedule_map) const;

  UnionAccessInfo(const UnionAccessInfo &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionAccessInfo &operator=(const UnionAccessInfo &Other);
  UnionAccessInfo (UnionAccessInfo && Other) : ctx(Other.Context()), This(Other.This) {}
  UnionAccessInfo &operator=(UnionAccessInfo && Other) {
    isl_union_access_info *New = Other.Give();
    isl_union_access_info_free((isl_union_access_info *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionAccessInfo &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionAccessInfo_H
