#ifndef ISL_CXX_Mat_H
#define ISL_CXX_Mat_H


#include "isl/mat.h"
#include "isl/Ctx.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Val;
class Vec;

class Mat {
protected:
  Ctx ctx;
  void * This;
public:
  explicit Mat(Ctx ctx, isl_mat *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_mat *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_mat *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_mat *Get() const;


  /// \brief Constructor for isl_mat_alloc
  ///
  /// \param ctx
  /// \param n_row
  /// \param n_col
  static Mat alloc(const Ctx &ctx, unsigned int n_row, unsigned int n_col);


  /// \brief Constructor for isl_mat_from_row_vec
  ///
  /// \param vec
  static Mat fromRowVec(const Vec &vec);
public:
  virtual ~Mat();
  /// \brief Generated from  ::<isl_mat_add_rows>
  ///
  /// \param [in] n
  ///
  /// \returns A new Mat
  Mat addRows(unsigned int n) const;

  /// \brief Generated from  ::<isl_mat_add_zero_cols>
  ///
  /// \param [in] n
  ///
  /// \returns A new Mat
  Mat addZeroCols(unsigned int n) const;

  /// \brief Generated from  ::<isl_mat_add_zero_rows>
  ///
  /// \param [in] n
  ///
  /// \returns A new Mat
  Mat addZeroRows(unsigned int n) const;

  /// \brief Generated from  ::<isl_mat_cols>
  ///
  ///
  /// \returns A new int
  int cols() const;

  /// \brief Generated from  ::<isl_mat_concat>
  ///
  /// \param [in] bot
  ///
  /// \returns A new Mat
  Mat concat(const Mat &bot) const;

  /// \brief Generated from  ::<isl_mat_get_element_val>
  ///
  /// \param [in] row
  /// \param [in] col
  ///
  /// \returns A new Val
  Val getElementVal(int row, int col) const;

  /// \brief Generated from  ::<isl_mat_initial_non_zero_cols>
  ///
  ///
  /// \returns A new int
  int initialNonZeroCols() const;

  /// \brief Generated from  ::<isl_mat_insert_cols>
  ///
  /// \param [in] col
  /// \param [in] n
  ///
  /// \returns A new Mat
  Mat insertCols(unsigned int col, unsigned int n) const;

  /// \brief Generated from  ::<isl_mat_insert_rows>
  ///
  /// \param [in] row
  /// \param [in] n
  ///
  /// \returns A new Mat
  Mat insertRows(unsigned int row, unsigned int n) const;

  /// \brief Generated from  ::<isl_mat_insert_zero_cols>
  ///
  /// \param [in] first
  /// \param [in] n
  ///
  /// \returns A new Mat
  Mat insertZeroCols(unsigned int first, unsigned int n) const;

  /// \brief Generated from  ::<isl_mat_insert_zero_rows>
  ///
  /// \param [in] row
  /// \param [in] n
  ///
  /// \returns A new Mat
  Mat insertZeroRows(unsigned int row, unsigned int n) const;

  /// \brief Generated from  ::<isl_mat_is_equal>
  ///
  /// \param [in] mat2
  ///
  /// \returns A new int
  int isEqual(const Mat &mat2) const;

  /// \brief Generated from  ::<isl_mat_move_cols>
  ///
  /// \param [in] dst_col
  /// \param [in] src_col
  /// \param [in] n
  ///
  /// \returns A new Mat
  Mat moveCols(unsigned int dst_col, unsigned int src_col, unsigned int n) const;

  /// \brief Generated from  ::<isl_mat_normalize>
  ///
  ///
  /// \returns A new Mat
  Mat normalize() const;

  /// \brief Generated from  ::<isl_mat_normalize_row>
  ///
  /// \param [in] row
  ///
  /// \returns A new Mat
  Mat normalizeRow(int row) const;

  /// \brief Generated from  ::<isl_mat_right_inverse>
  ///
  ///
  /// \returns A new Mat
  Mat rightInverse() const;

  /// \brief Generated from  ::<isl_mat_right_kernel>
  ///
  ///
  /// \returns A new Mat
  Mat rightKernel() const;

  /// \brief Generated from  ::<isl_mat_rows>
  ///
  ///
  /// \returns A new int
  int rows() const;

  /// \brief Generated from  ::<isl_mat_set_element_val>
  ///
  /// \param [in] row
  /// \param [in] col
  /// \param [in] v
  ///
  /// \returns A new Mat
  Mat setElementVal(int row, int col, const Val &v) const;

  /// \brief Generated from  ::<isl_mat_vec_concat>
  ///
  /// \param [in] bot
  ///
  /// \returns A new Mat
  Mat vecConcat(const Vec &bot) const;

  Mat(const Mat &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  Mat &operator=(const Mat &Other);
  Mat (Mat && Other) : ctx(Other.Context()), This(Other.Give()) {}
  Mat &operator=(Mat && Other) {
    isl_mat *New = Other.Give();
    isl_mat_free((isl_mat *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const Mat &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_Mat_H
