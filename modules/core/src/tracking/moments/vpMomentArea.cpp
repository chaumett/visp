/****************************************************************************
 *
 * $Id: vpMomentArea.cpp 3530 2012-01-03 10:52:12Z fspindle $
 *
 * This file is part of the ViSP software.
 * Copyright (C) 2005 - 2014 by INRIA. All rights reserved.
 *
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * ("GPL") version 2 as published by the Free Software Foundation.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ViSP with software that can not be combined with the GNU
 * GPL, please contact INRIA about acquiring a ViSP Professional
 * Edition License.
 *
 * See http://www.irisa.fr/lagadic/visp/visp.html for more information.
 *
 * This software was developed at:
 * INRIA Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 * http://www.irisa.fr/lagadic
 *
 * If you have questions regarding the use of this file, please contact
 * INRIA at visp@inria.fr
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * Description:
 * 2D area of the object
 *
 * Authors:
 * Manikandan Bakthavatchalam
 *
 *****************************************************************************/
#include <visp3/core/vpMomentArea.h>
#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpMomentCentered.h>
#include <visp3/core/vpMomentDatabase.h>
#include <cmath>

/*!
  Has the area \f$ a = m_{00} = \mu_{00} \f$.
  Gets the value of m00 from vpMomentCentered.
*/
void vpMomentArea::compute(){
    /* getObject() returns a reference to a vpMomentObject. This is public member of vpMoment */
    if(getObject().getType()==vpMomentObject::DISCRETE) {
    	bool found_moment_centered;
		/*   getMoments() returns a reference to a vpMomentDatabase. It is a protected member of and is inherited from vpMoment
		 *  .get() is a member function of vpMomentDatabase that returns a specific moment which is linked to it
		 */
		const vpMomentCentered& momentCentered = static_cast<const vpMomentCentered&>(getMoments().get("vpMomentCentered",found_moment_centered));
		if(!found_moment_centered) throw vpException(vpException::notInitialized,"vpMomentCentered not found");
		values[0] = momentCentered.get(2,0) + momentCentered.get(0,2);
    }
    else {
    	values[0] = getObject().get(0,0);
    }
}

/*!
  Default constructor.
*/
vpMomentArea::vpMomentArea() : vpMoment(){
    values.resize(1);
}

/*!
  Outputs the moment's values to a stream.
*/
VISP_EXPORT std::ostream & operator<<(std::ostream & os, const vpMomentArea& m){
    os << (__FILE__) << std::endl;
    os << "a(m00) = " << m.values[0] << std::endl;
    return os;    
}

/*!
If the vpMomentObject type is
1. DISCRETE(set of discrete points), uses mu20+mu02
2. DENSE_FULL_OBJECT(from image) used mu00
*/
void vpMomentArea::printDependencies(std::ostream& os) const{
    os << (__FILE__) << std::endl;

    bool found_moment_centered;
    const vpMomentCentered& momentCentered = static_cast<const vpMomentCentered&>(getMoments().get("vpMomentCentered",found_moment_centered));
    if(!found_moment_centered) throw vpException(vpException::notInitialized,"vpMomentCentered not found");

    if(getObject().getType()==vpMomentObject::DISCRETE)
    {
        os << "mu20 = " << momentCentered.get(2, 0) << "\t";
        os << "mu02 = " << momentCentered.get(0, 2) << std::endl;
    }
    else
    {
        os << "mu00 = " << momentCentered.get(0, 0) << std::endl;
    }
}