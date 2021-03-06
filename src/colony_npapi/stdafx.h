/*
 Hive Colony Framework
 Copyright (C) 2008-2012 Hive Solutions Lda.

 This file is part of Hive Colony Framework.

 Hive Colony Framework is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Hive Colony Framework is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Hive Colony Framework. If not, see <http://www.gnu.org/licenses/>.

 __author__    = João Magalhães <joamag@hive.pt>
 __version__   = 1.0.0
 __revision__  = $LastChangedRevision$
 __date__      = $LastChangedDate$
 __copyright__ = Copyright (c) 2008-2012 Hive Solutions Lda.
 __license__   = GNU General Public License (GPL), Version 3
*/

#pragma once

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef _MSC_VER
#include "_config_win32.h"
#endif

#ifdef HAVE_DEBUG
#define COLONY_DEBUG
#endif

#ifndef HAVE_LIBPTHREAD
#define COLONY_NO_THREADS
#endif

#ifdef HAVE_JNI_H
#define COLONY_JNI
#endif

#ifdef __MACH__
#define unix true
#include <TargetConditionals.h>
#endif

#ifdef _WIN32
#include "global/targetver.h"
#include "global/resource.h"

/* excludes rarely-used stuff from windows headers */
#define WIN32_LEAN_AND_MEAN

/* includes the extra math definitions */
#define _USE_MATH_DEFINES

/* defines the export prefix */
#define COLONY_EXPORT_PREFIX __declspec(dllexport)

/* defines the no export prefix */
#define COLONY_NO_EXPORT_PREFIX

/* defines the external prefix (careful usage) */
#define COLONY_EXTERNAL_PREFIX __declspec(dllexport)
#else
/* defines the export prefix */
#define COLONY_EXPORT_PREFIX __attribute__((visibility("default")))

/* defines the no export prefix */
#define COLONY_NO_EXPORT_PREFIX __attribute__((visibility("hidden")))

/* defines the external prefix (careful usage) */
#define COLONY_EXTERNAL_PREFIX extern
#endif

#include "global/definitions.h"

#ifdef COLONY_PLATFORM_WIN32
#define FD_SETSIZE 10000
#endif

#ifdef COLONY_PLATFORM_WIN32
#include <windows.h>
#include <windowsx.h>
#include <winspool.h>
#include <Commdlg.h>
#endif

#ifdef COLONY_PLATFORM_UNIX
#include <unistd.h>
#include <sys/types.h>
#include <cups/ppd.h>
#include <cups/cups.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "npapi/npapi.h"
#include "npapi/npfunctions.h"

#ifndef OSCALL
#define OSCALL
#endif

unsigned char *name_colony_npapi();
unsigned char *version_colony_npapi();
unsigned char *description_colony_npapi();

#ifndef HIBYTE
#define HIBYTE(x) ((((uint32_t)(x)) & 0xff00) >> 8)
#endif

#define NPCOLONY_NAME "Colony Gateway Plugin"
#define NPCOLONY_DESCRIPTION "<a href=\"http://getcolony.com/\">Colony Gateway</a> plugin."
#define NPCOLONY_VERSION "1.1.1"
#define NPCOLONY_MIME "application/x-colony-gateway:colony:gateway@getcolony.com";
#define NPCOLONY_BINIE "binie"
#define NPCOLONY_PDF "pdf"
#define NPCOLONY_TEMPLATE "/tmp/npcolony-XXXXXX"
#define NPCOLONY_PATH_SIZE 1024
