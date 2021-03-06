/*******************************************************************************
printHeader.cpp - Pharao

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



#include "printHeader.h"



void
printHeader()
{
	std::cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cerr << "  Pharao v" << ALIGNIT_VERSION << "." << ALIGNIT_RELEASE << "." << ALIGNIT_SUBRELEASE << " | ";
	std::cerr << __DATE__ " " << __TIME__ << std::endl;
	std::cerr << std::endl;
	std::cerr << "  -> GCC:         " << __VERSION__ << std::endl;
	std::cerr << "  -> Open Babel:  " << BABEL_VERSION << std::endl;
	std::cerr << std::endl;
	std::cerr << "  Copyright 2012-2022 by Silicos-it" << std::endl;
	std::cerr << std::endl;
	std::cerr << "  Pharao is free software: you can redistribute it and/or modify" << std::endl;
	std::cerr << "  it under the terms of the GNU Lesser General Public License as published" << std::endl;
	std::cerr << "  by the Free Software Foundation, either version 3 of the License, or" << std::endl;
	std::cerr << "  (at your option) any later version." << std::endl;
	std::cerr << std::endl;
	std::cerr << "  Pharao is distributed in the hope that it will be useful," << std::endl;
	std::cerr << "  but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl;
	std::cerr << "  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" << std::endl;
	std::cerr << "  GNU Lesser General Public License for more details." << std::endl;
	std::cerr << std::endl;
	std::cerr << "  Pharao is linked against OpenBabel version 2." << std::endl;
	std::cerr << "  OpenBabel is free software; you can redistribute it and/or modify" << std::endl;
	std::cerr << "  it under the terms of the GNU General Public License as published by" << std::endl;
	std::cerr << "  the Free Software Foundation version 2 of the License." << std::endl;
	std::cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cerr << std::endl;
}
