/*******************************************************************************
calcPharm.cpp - Pharao

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



#include "calcPharm.h"



void
calcPharm(OpenBabel::OBMol* m, Pharmacophore* p, const Options& uo)
{
	if (uo.funcGroupVec[AROM]) { aromFuncCalc(m, p); }
	if (uo.funcGroupVec[HDON]) { hDonFuncCalc(m, p); }
	if (uo.funcGroupVec[HACC]) { hAccFuncCalc(m, p); }
	if (uo.funcGroupVec[LIPO]) { lipoFuncCalc(m, p); }
    
	if (uo.funcGroupVec[NEGC] || uo.funcGroupVec[POSC])
	{
		chargeFuncCalc(m, p); 
	}
	if (uo.funcGroupVec[HYBH] || uo.funcGroupVec[HYBL])
   	{
      	hybridCalc(m, p); 
   	}
   	return;
}
