/*******************************************************************************
alignment.h - Pharao

Copyright 2012-2022 by Silicos-it
 
This file is part of Pharao.

	Pharao is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published 
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Pharao is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with Pharao.  If not, see <http://www.gnu.org/licenses/>.

Pharao is linked against OpenBabel version 2.

	OpenBabel is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation version 2 of the License.

***********************************************************************/



#ifndef __SILICOSIT_PHARAO_ALIGNMENT_H__
#define __SILICOSIT_PHARAO_ALIGNMENT_H__



// General
#include <cmath>

// OpenBabel

// Pharao
#include "siMath.h"
#include "solutionInfo.h"
#include "coordinate.h"
#include "pharmacophore.h"
#include "utilities.h"



class Alignment
{
   public:

      Alignment(PharmacophoreMap&);
      ~Alignment(void);
			
      SolutionInfo align(bool n);

   private:
      
      std::vector<PharmacophorePoint> _refMap;   // holds translated points of the original reference points
      std::vector<PharmacophorePoint> _dbMap;    // holds translated points of the original database points
		
			// coordinates of translation centers
      Coordinate _refCenter;
      Coordinate _dbCenter;
			// initial axes of rotation
      SiMath::Matrix _refRotMat;
      SiMath::Matrix _dbRotMat;
			
      // local storage of reusable computational objects
      std::vector<SiMath::Matrix *> _AkA;
      SiMath::Vector _dCdq;                // holds gradient update of normal computation
      SiMath::Matrix _d2Cdq2;              // holds hessian update of normal computation
      SiMath::Vector _grad;
		
      unsigned int _nbrPoints;         ///< counts the number of pharmacophore points
      unsigned int _nbrExcl;           ///< counts the number of exclusion sphere overlaps

      void _normalGradientMatrix(Coordinate& n1, Coordinate& n2, SiMath::Matrix & A);
      double _quatVolumeOverlap(double alpha1, double alpha2, const SiMath::Vector& q, const SiMath::Matrix& A);
      double _normalContribution(Coordinate& n1, Coordinate& n2, SiMath::Vector& q); 
};



#endif
