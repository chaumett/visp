/****************************************************************************
 *
 * $Id$
 *
 * This file is part of the ViSP software.
 * Copyright (C) 2005 - 2012 by INRIA. All rights reserved.
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
 * Interface for the Biclops robot.
 *
 * Authors:
 * Fabien Spindler
 *
 *****************************************************************************/

#ifndef __vpBiclops_H
#define __vpBiclops_H

/* ----------------------------------------------------------------------- */
/* --- INCLUDES -------------------------------------------------------- */
/* --------------------------------------------------------------------- */

/* --- ViSP --- */
#include <visp/vpMatrix.h>
#include <visp/vpHomogeneousMatrix.h>
#include <visp/vpPoseVector.h>
#include <visp/vpMath.h>
#include <visp/vpRxyzVector.h>
#include <visp/vpTranslationVector.h>
#include <visp/vpVelocityTwistMatrix.h>

/* --- GENERAL --- */
#include <iostream>

/*!

  \class vpBiclops

  \ingroup Biclops

  \brief Jacobian, geometric model functionnalities... for biclops, pan, tilt
  head.

  See http://www.traclabs.com/tracbiclops.htm for more details.

*/

class VISP_EXPORT vpBiclops
{

public: /* Constants */

  static const unsigned int ndof;  /*!< Number of dof */


  /* Geometric model */
  static const float h;

  static const float panJointLimit;
  static const float tiltJointLimit;
  static const float speedLimit;


public:

  vpBiclops (void);
  void init (void);

  void computeMGD (const vpColVector &q, vpHomogeneousMatrix & fMc);

  vpHomogeneousMatrix computeMGD (const vpColVector & q);
  void computeMGD (const vpColVector & q,  vpPoseVector & r);

  void get_cMe(vpHomogeneousMatrix &_cMe) ;
  void get_cVe(vpVelocityTwistMatrix &_cVe) ;
  void get_eJe(const vpColVector &q, vpMatrix &eJe);
  void get_fJe(const vpColVector &q, vpMatrix &fJe);

  friend std::ostream & operator << (std::ostream & os,
				     const vpBiclops & constant);
};




/*
 * Local variables:
 * c-basic-offset: 2
 * End:
 */

#endif