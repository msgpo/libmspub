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

#ifndef __COLORREFERENCE_H__
#define __COLORREFERENCE_H__

#include "MSPUBTypes.h"

namespace libmspub
{
class ColorReference
{
  unsigned m_baseColor;
  unsigned m_modifiedColor;
//  static const unsigned char COLOR_PALETTE = 0x8;
  static const unsigned char CHANGE_INTENSITY = 0x10;
  static const unsigned char BLACK_BASE = 0x1;
  static const unsigned char WHITE_BASE  = 0x2;
  Color getRealColor(unsigned c, const std::vector<Color> &palette) const;
public:
  explicit ColorReference(unsigned color) : m_baseColor(color), m_modifiedColor(color) { }
  ColorReference(unsigned baseColor, unsigned modifiedColor) : m_baseColor(baseColor), m_modifiedColor(modifiedColor) { }
  Color getFinalColor(const std::vector<Color> &palette) const;
public:
  friend bool operator==(const libmspub::ColorReference &, const libmspub::ColorReference &);
};
}

#endif /* __COLORREFERENCE_H__ */
/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
