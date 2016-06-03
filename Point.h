#ifndef ISL_CXX_Point_H
#define ISL_CXX_Point_H


#include "isl/point.h"
#include "isl/BasicSet.h"
#include "isl/Bool.h"
#include "isl/DimType.h"
#include "isl/Format.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Space;
class Val;

class Point {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Point(Ctx ctx, isl_point *That) : ctx(ctx), This(That) {}
  Point() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_point *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_point *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_point *Get() const;


  /// \brief Constructor for isl_point_void
  ///
  /// \param dim
  static Point void_(const Space &dim);


  /// \brief Constructor for isl_point_zero
  ///
  /// \param dim
  static Point zero(const Space &dim);
public:
  virtual ~Point();
  /// \brief Generated from  ::<isl_point_add_ui>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] val
  ///
  /// \returns A new Point
  Point addUi(DimType type, int pos, unsigned int val) const;

  /// \brief Generated from  ::<isl_point_dump>
  ///
  ///
  /// \returns A new void
  void dump() const;

  /// \brief Generated from  ::<isl_point_get_coordinate_val>
  ///
  /// \param [in] type
  /// \param [in] pos
  ///
  /// \returns A new Val
  Val getCoordinateVal(DimType type, int pos) const;

  /// \brief Generated from  ::<isl_point_get_space>
  ///
  ///
  /// \returns A new Space
  Space getSpace() const;

  /// \brief Generated from  ::<isl_point_is_void>
  ///
  ///
  /// \returns A new Bool
  Bool isVoid() const;

  /// \brief Generated from  ::<isl_point_set_coordinate_val>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] v
  ///
  /// \returns A new Point
  Point setCoordinateVal(DimType type, int pos, const Val &v) const;

  /// \brief Generated from  ::<isl_point_sub_ui>
  ///
  /// \param [in] type
  /// \param [in] pos
  /// \param [in] val
  ///
  /// \returns A new Point
  Point subUi(DimType type, int pos, unsigned int val) const;

  Point(const Point &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Point &operator=(const Point &Other);
  Point (Point && Other) : ctx(Other.Context()), This(Other.Give()) {}
  Point &operator=(Point && Other) {
    isl_point *New = Other.Give();
    isl_point_free((isl_point *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Point &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Point_H
