/**
 * Seashell's C Runtime Library (C bindings)
 * Copyright (C) 2013-2015 The Seashell Maintainers.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * See also 'ADDITIONAL TERMS' at the end of the included LICENSE file.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "seashell-runtime.h"
#include <sys/unistd.h>
#include <errno.h>
#undef errno
extern int errno;

void *_sbrk(ptrdiff_t incr) {
  static char* current = NULL;
  if (!current) current = (char*)_seashell_RT_brk_base();

  int result = _seashell_RT_brk(current + incr);

  if (result < 0) {
    errno = -result;
    return (void*)-1;
  } else {
    return current;
  }
}
