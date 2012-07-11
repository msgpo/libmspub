/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* libmspub
 * Version: MPL 1.1 / GPLv2+ / LGPLv2+
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License or as specified alternatively below. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * Major Contributor(s):
 * Copyright (C) 2012 Brennan Vincent <brennanv@email.arizona.edu>
 *
 * All Rights Reserved.
 *
 * For minor contributions see the git repository.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPLv2+"), or
 * the GNU Lesser General Public License Version 2 or later (the "LGPLv2+"),
 * in which case the provisions of the GPLv2+ or the LGPLv2+ are applicable
 * instead of those above.
 */

#ifndef __VECTORTRANSFORMATION2D_H__
#define __VECTORTRANSFORMATION2D_H__

namespace libmspub
{
struct Vector2D
{
  double m_x;
  double m_y;
  Vector2D(double x, double y) : m_x(x), m_y(y)
  {
  }
};
Vector2D operator+(const Vector2D &l, const Vector2D &r);
Vector2D operator-(const Vector2D &l, const Vector2D &r);
class VectorTransformation2D
{
  double m_m11, m_m12, m_m21, m_m22;
  double m_x, m_y;
public:
  VectorTransformation2D();
  Vector2D transform(Vector2D original) const;
  Vector2D transformWithOrigin(Vector2D v, Vector2D origin) const;
  double getRotation() const;
  double getHorizontalScaling() const;
  double getVerticalScaling() const;
  friend VectorTransformation2D operator*(const VectorTransformation2D &l, const VectorTransformation2D &r);
  static VectorTransformation2D fromFlips(bool flipH, bool flipV);
  static VectorTransformation2D fromTranslate(double x, double y);
  static VectorTransformation2D fromCounterRadians(double theta);
};
VectorTransformation2D operator*(const VectorTransformation2D &l, const VectorTransformation2D &r);
} // namespace libmspub

#endif /* __VECTORTRANSFORMATION2D_H__ */
/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
