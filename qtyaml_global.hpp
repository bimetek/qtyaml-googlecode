/*
 * Copyright (C) 2011 BARBOTIN Nicolas
 *
 * This file is part of QtYaml.
 *
 * QtYaml is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * QtYaml is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with QtYaml.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef QTYAML_GLOBAL_HPP
#define QTYAML_GLOBAL_HPP

#include <QtCore/qglobal.h>

#if defined(QTYAML_LIBRARY)
#  define QTYAMLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTYAMLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTYAML_GLOBAL_HPP
