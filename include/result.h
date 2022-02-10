/*******************************************************************************
result.h - Pharao

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



#ifndef __SILICOSIT_PHARAO_RESULT_H__
#define __SILICOSIT_PHARAO_RESULT_H__



// General
#include <string>
#include <vector>

// OpenBabel
#include <openbabel/mol.h>

// Pharao
#include "pharmacophore.h"
#include "solutionInfo.h"



class Result
{
   public:
   
      std::string             refId;         // id of the reference pharmacophore
      double                  refVolume;     // volume of the reference pharmacophore
      std::string             dbId;          // id of the database pharmacophore
      double                  dbVolume;      // volume of the database pharmacophore
      double                  overlapVolume; // volume overlap between reference and database pharmacophore
      double                  exclVolume;    // volume overlap between database pharmacophore and exclusion spheres
      int                     resPharSize;   // number of points in the resulting pharmacophore
	
      double                  tanimoto;      // resulting score = info.volume/(refVolume+resVolume-info.volume)
      double                  tversky_ref;   // info.volume/refVolume
      double                  tversky_db;    // info.volume/dbVolume
      double                  rankbyScore;   // one of the three scores...
  
      SolutionInfo            info;          // information about the alignment
      OpenBabel::OBMol        resMol;        // resulting molecule
      Pharmacophore           resPhar;       // overlapping pharmacophore
      
      Result(void);
};



#endif
