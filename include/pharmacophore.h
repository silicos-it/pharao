/*******************************************************************************
pharmacophore.h - Pharao

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



#ifndef __SILICOSIT_PHARAO_PHARMACOPHORE_H__
#define __SILICOSIT_PHARAO_PHARMACOPHORE_H__



// General
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>

// OpenBabel

// Pharao
#include "coordinate.h"
#include "mainWar.h"
#include "siMath.h"
#include "stringTokenizer.h"
#include "defines.h"


enum FuncGroup
{
   AROM,  ///< Aromatic ringsystem, calculated by the AromFuncCalc class
   HDON,  ///< Hydrogen donor, calculated by the HDonFuncCalc class
   HACC,  ///< Hydrogen acceptor, calculated by the HAccFuncCalc class
   LIPO,  ///< Lipophilicity, calculated by the LipoFuncCalc class
   POSC,  ///< Positive charge, calculated by the ChargeFuncCalc class
   NEGC,  ///< Negative charge, calculated by the ChargeFuncCalc class
   HYBH,  ///< Hybrid Type: HDON + HACC
   HYBL,  ///< Hybrid Type: AROM + LIPO
   EXCL,  ///< Exclusion sphere
   UNDEF, ///< Undefined value (typically used for initialisation)
};



const std::string funcName[10] =
{
   "SILICOS-IT::PHARAO::AROM",
   "SILICOS-IT::PHARAO::HDON",
   "SILICOS-IT::PHARAO::HACC",
   "SILICOS-IT::PHARAO::LIPO",
   "SILICOS-IT::PHARAO::POSC",
   "SILICOS-IT::PHARAO::NEGC",
   "SILICOS-IT::PHARAO::HYBH",
   "SILICOS-IT::PHARAO::HYBL",
   "SILICOS-IT::PHARAO::EXCL",
   "SILICOS-IT::PHARAO::UNDEF"
};



const bool funcHasNormal[10] =
{
   true,
   true,
   true,
   false,
   false,
   false,
   true,
   true,
   false,
   false,
};



const double funcSigma[10] = 
{
   0.7, // AROM
   1.0, // HDON
   1.0, // HACC
   0.7, // LIPO
   1.0, // POSC
   1.0, // NEGC
   1.0, // HYBH
   0.7, // HYBL
   1.6, // EXCL
   1.0, // UNDEF
};



class PharmacophorePoint
{
   public:
   
      Coordinate     point;      ///< coordinates of the pharmacophore point
      FuncGroup      func;       ///< type of functional group
      Coordinate     normal;     ///< coordinates of the directionality of the pharmacophore
      double         alpha;      ///< spread of the gaussian is inverse proportional to radius squared
      bool           hasNormal;  ///< does the pharmacophore point has directionality
		
      PharmacophorePoint(void);
      PharmacophorePoint(const PharmacophorePoint&);
      PharmacophorePoint(const PharmacophorePoint*);
};



typedef std::vector<PharmacophorePoint> Pharmacophore;
typedef std::multimap<PharmacophorePoint*, PharmacophorePoint*> PharmacophoreMap;



class PharmacophoreReader
{
   private:

      void _skipPharmacophore(std::ifstream*);

   public:

      PharmacophoreReader(void);   
      ~PharmacophoreReader(void);
  
      Pharmacophore read(std::ifstream*, std::string&);
};



class PharmacophoreWriter
{
   public:
   
      PharmacophoreWriter(void);
      ~PharmacophoreWriter(void);
      
      void write(Pharmacophore&, std::ofstream*, const std::string&);
};
	


#endif