/*******************************************************************************
addBest.cpp - Pharao

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



#include "addBest.h"



void
addBest(Result& res, const Options& uo, std::vector<Result*>& resList)
{
	// 1) if 'resList' is not full -> add it.
	// 2) if 'resList' is full but we have a result that is better than the worst
	//    one -> replace it.
	// 3) else -> do nothing
  
	if (resList.size() < uo.best)
	{
		Result* newRes = new Result(res);
		resList.push_back(newRes);
		sort(resList.begin(), resList.end(), CompScore());
		return;
	}
  
	Result* worst = *(resList.rbegin());    
	if (worst->rankbyScore < res.rankbyScore)
	{
		delete worst;
		resList.pop_back();
		Result* newRes =  new Result(res);
		resList.push_back(newRes);
		sort(resList.begin(), resList.end(), CompScore());
	}
}
