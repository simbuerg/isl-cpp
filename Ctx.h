#ifndef ISL_CXX_Ctx_H
#define ISL_CXX_Ctx_H


#include "isl/options.h"
#include "isl/band.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/Stat.h"
#include <mutex>
#include <string>
#include <ostream>

#include "isl/IslFnPtr.h"

namespace isl {

class Ctx {
protected:
  struct ptr {
    isl_ctx *p;
    explicit ptr(isl_ctx *p) : p(p) {}
    ~ptr() {
      isl_ctx_free(p);
    }
    ptr(const ptr &other) = delete;
    ptr &operator=(const ptr &other) = delete;
    ptr(ptr && other) = delete;
    ptr &operator=(ptr && other) = delete;
  };

public:
  std::shared_ptr<ptr> This;
  explicit Ctx(std::shared_ptr<ptr> That) : This(That) {}
  const Ctx &Context() const { return *this; }
  /// \brief Wrap an existing isl object.
  ///
  /// This serves as an entry point into the C++ API.
  /// We take ownership of the isl object.
  ///
  /// \param That the isl_ctx we want to wrap.
  explicit Ctx(isl_ctx *That) : This(std::make_shared<isl::Ctx::ptr>(That)) {}
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  isl_ctx *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  isl_ctx *Get() const;

  /// \brief Constructor for isl_ctx_alloc
  ///
  static Ctx alloc();
  virtual ~Ctx() = default;
private:
  mutable std::recursive_mutex M;
public:
  void lock() const {
    M.lock();
  }

  void unlock() const {
    M.unlock();
  }

  bool hasError() const {
    isl_ctx *ctx = Get();
    enum isl_error err = isl_ctx_last_error(ctx);
    int goe = isl_options_get_on_error(ctx);
    return (err != isl_error_none) && goe != ISL_ON_ERROR_CONTINUE;
  }

  virtual Ctx asCtx() const;

  /// \brief Generated from  ::<isl_options_get_tile_scale_tile_loops>
  ///
  ///
  /// \returns A new int
  int getTileScaleTileLoops() const;

  /// \brief Generated from  ::<isl_options_get_tile_shift_point_loops>
  ///
  ///
  /// \returns A new int
  int getTileShiftPointLoops() const;

  /// \brief Generated from  ::<isl_options_set_tile_scale_tile_loops>
  ///
  /// \param [in] val
  ///
  /// \returns A new Stat
  Stat setTileScaleTileLoops(int val) const;

  /// \brief Generated from  ::<isl_options_set_tile_shift_point_loops>
  ///
  /// \param [in] val
  ///
  /// \returns A new Stat
  Stat setTileShiftPointLoops(int val) const;
  Ctx(const Ctx &Other) : Ctx(Other.This) {}};
} // namespace isl
#endif //ISL_CXX_Ctx_H
