/** @file xapian_hunspell_stemmer.h
 *  @brief Implementation of Xapian::Stem API class which uses Hunspell
 *  instead of Snowball.
 */
/* Copyright (C) 2010 Eugene Sizikov
 * Copyright (C) 2005,2007 Olly Betts
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * Authors: Eugene Sizikov <esizikov@gmail.com>
 */
#ifndef _XAPIAN_HUNSPELL_STEMMER_H__
#define _XAPIAN_HUNSPELL_STEMMER_H__

#include <xapian/stem.h>
#include "InternalStemHunspell.h"

namespace Xapian {

/// Class representing a stemming algorithm.
class XAPIAN_VISIBILITY_DEFAULT HunspellStem : public Stem {
  public:

    /// Copy constructor.
    HunspellStem(const HunspellStem & o) {
        internal = o.internal;
    }

    /// Assignment.
    void operator=(const HunspellStem & o) {
        internal = o.internal;
    }

    /** Construct a Xapian::HunspellStem object for a particular language.
     */
    explicit HunspellStem(const std::string &affPath, const std::string &dicPath) : Stem() {
        internal = new InternalStemHunspell(affPath, dicPath);
        return;

    }

    /// Destructor.
    ~HunspellStem() {}

    /** Stem a word.
     *
     *  @param word		a word to stem.
     *  @return		the stem
     */
    std::string operator()(const std::string &word) const {
        return Stem::operator()(word);
    }
};

}

#endif // _XAPIAN_HUNSPELL_STEMMER_H__
