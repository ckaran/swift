/*
 * util.h
 *
 *  Created on: 20-Oct-2009
 *      Author: arno
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <string>

namespace p2tp
{
	std::string gettmpdir(void);
	/**
	 * Return path of temporary directory.
	 *
	 * From http://msdn.microsoft.com/en-us/library/aa364992%28VS.85%29.aspx
	 *
	 * TODO: Unicode... (gets hairy with open() call on Linux. Win32 has _wopen)
	 */


};

#endif /* UTIL_H_ */
