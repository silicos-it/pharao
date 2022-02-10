/*******************************************************************************
lipoFuncCalc.h - Pharao

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



#ifndef __SILICOSIT_PHARAO_LIPOFUNCCALC_H__
#define __SILICOSIT_PHARAO_LIPOFUNCCALC_H__



// General
#include <set>
#include <list>

// OpenBabel
#include "openbabel/mol.h"
#include "openbabel/atom.h"
#include "openbabel/bond.h"
#include "openbabel/ring.h"

// Pharao
#include "pharmacophore.h"
#include "defines.h"



void                          lipoFuncCalc(OpenBabel::OBMol*, Pharmacophore*);
void                          _lipoLabelAtoms(OpenBabel::OBMol*);
double                        _lipoCalcAccSurf(OpenBabel::OBAtom*);
void                          _lipoGroupAtoms(OpenBabel::OBMol*, Pharmacophore*);
std::list<OpenBabel::OBAtom*> _lipoGetNeighbors(OpenBabel::OBAtom*);
void                          _lipoLabelNeighbors(OpenBabel::OBAtom*, double);


#endif
