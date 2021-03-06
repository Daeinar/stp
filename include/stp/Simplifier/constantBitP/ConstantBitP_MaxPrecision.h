// -*- c++ -*-
/********************************************************************
 * AUTHORS: Trevor Hansen
 *
 * BEGIN DATE: Februrary, 2010
 *
 * LICENSE: Please view LICENSE file in the home dir of this Program
 ********************************************************************/

#ifndef CONSTANTBITPROPAGATION_MAXPRECISION_H_
#define CONSTANTBITPROPAGATION_MAXPRECISION_H_

#include "stp/Simplifier/constantBitP/ConstantBitPropagation.h"
#include <vector>
#include "stp/Simplifier/constantBitP/FixedBits.h"
#include "stp/AST/ASTKind.h"



namespace simplifier
{
namespace constantBitP
{

   enum Direction
   {
     UPWARDS_ONLY, BOTH_WAYS
   };

   // This is used for very specific purposes.
   enum Type
   {
     BOOL_TYPE, VALUE_TYPE
   };

struct Signature
{
	BEEV::Kind kind;
	Type resultType;
	Type inputType;
	int maxInputWidth;
	int numberOfInputs;
	Direction direction;
	bool imprecise;
	Signature()
	{
		imprecise=false;
	}
};

bool maxPrecision(std::vector<FixedBits*> children, FixedBits& output, BEEV::Kind kind, BEEV::STPMgr* beev);
}
}

#endif /* CONSTANTBITPROPAGATION_MAXPRECISION_H_ */
