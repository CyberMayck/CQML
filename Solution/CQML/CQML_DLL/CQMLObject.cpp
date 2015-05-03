#include "dll_export.h"

#include "variant.h"
#include "CQMLObject.h"
#include "attribControl.h"

VariantRef CQMLObject::Get(const char*)
{
	return VariantRef();
}

CQMLObject* CQMLObject::Copy()
{
	return new CQMLObject(*this);
}

void CQMLObject::Init()
{
	
}

void CQMLObject::DefaultUpdate()
{

}