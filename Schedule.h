#ifndef ISL_CXX_Schedule_H
#define ISL_CXX_Schedule_H


#include "isl/schedule.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/band.h"
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {
class UnionMap;

class Schedule {
protected:
  struct ptr {
    isl_schedule *p;
    explicit ptr(isl_schedule *p) : p(p) {}
    ~ptr() {
      isl_schedule_free(p);
    }
    ptr(const ptr &other) = delete;
    ptr &operator=(const ptr &other) = delete;
    ptr(ptr && other) = delete;
    ptr &operator=(ptr && other) = delete;
  };

public:
  Ctx ctx;
  std::shared_ptr<ptr> This;
  explicit Schedule(Ctx ctx, isl_schedule *That) : ctx(ctx), This(std::make_shared<ptr>(That)) {}
  const Ctx &Context() const { return ctx; }
  std::shared_ptr<isl::Schedule::ptr> GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_schedule *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_schedule *Get() const;

  virtual ~Schedule() = default;

  virtual Schedule asSchedule() const;

  /// \brief Generated from  ::<isl_schedule_foreach_band>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new int
  int foreachBand(const std::function<int(isl_band *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_schedule_get_map>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getMap() const;
  Schedule(const Schedule &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Schedule &operator=(const Schedule &Other) = delete;
  Schedule (Schedule && Other) : ctx(Other.Context()), This(Other.This) {}
  Schedule &operator=(Schedule && Other) {
    std::swap(This, Other.This);
    return *this;
  }
};
} // namespace isl
#endif //ISL_CXX_Schedule_H