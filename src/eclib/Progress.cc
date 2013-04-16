/*
 * (C) Copyright 1996-2012 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */


#include "eckit/runtime/Monitor.h"
#include "eclib/Progress.h"


//-----------------------------------------------------------------------------

namespace eckit {

//-----------------------------------------------------------------------------

Progress::Progress(const string& name, unsigned long long min, unsigned long long  max )
{
	Monitor::progress(name,min,max);
}

Progress::~Progress()
{
	Monitor::progress();
}

void Progress::operator()(unsigned long long value)
{
	Monitor::progress(value);
}

//-----------------------------------------------------------------------------

} // namespace eckit

