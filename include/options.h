/*******************************************************************************
options.h - Pharao

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



#ifndef __SILICOSIT_PHARAO_OPTIONS_H__
#define __SILICOSIT_PHARAO_OPTIONS_H__



// General
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// OpenBabel
#include "openbabel/obconversion.h"

// Pharao
#include "fileType.h"
#include "rankType.h"
#include "pharmacophore.h"



class Options
{
	public:
   
		std::string					refInpFile;			//  -r  --reference
		std::string					refInpType;			//      --refType
		std::ifstream*				refInpStream;
      
		std::string					dbInpFile;			//  -d  --dbase
		std::string					dbInpType;			//      --dbType
		std::ifstream*				dbInpStream;
	
		std::string					pharmOutFile;		//  -p  --pharmacophore
		std::ofstream*				pharmOutStream;
		PharmacophoreWriter*		pharmOutWriter;
      
		std::string					molOutFile;			//  -o  --out
		std::string					molOutType;		  	//      --outType
		std::ofstream*				molOutStream;
		OpenBabel::OBConversion*	molOutWriter;
      
		std::string					scoreOutFile;		//  -s  --scores
		std::ofstream*				scoreOutStream;
      
		double						cutOff;				//      --cutOff
		int							best;				//      --best
		RankType					rankby;				//      --rankby
  
		std::vector<bool>			funcGroupVec;		//  -f  --funcGroup
		bool						noHybrid;         	//      --noHybrid
		double						epsilon;			//  -e  --epsilon
		bool						withExclusion;    	//      --withExclusion
		bool						merge;            	//  -m  --merge
		bool						noNormal;			//  -n  --noNormal
		bool						scoreOnly;       	//      --scoreOnly
  
		bool						isQuiet;			//  -q  --quiet
		bool						version;			//  -v  --version
		bool						help;				//  -h  --help
   
		Options(void);
		~Options(void);
      
		std::string					print(void) const;
};



#endif
