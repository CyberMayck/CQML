#include "dll_export.h"

#include "variant.h"
#include "CQMLObject.h"
#include "attribControl.h"

/**
 * Attempts to get attribute reference
 * 
 *
 * @param attribute name
 *
 * @return invalid reference
 */
VariantRef CQMLObject::Get(const char*)
{
	return VariantRef();
}

/**
 * Shallow copy of CQML object.
 * used for value types
 *
 * @return pointer to copy.
 */
CQMLObject* CQMLObject::Copy()
{
	return new CQMLObject(*this);
}

/**
 * Init function.
 * does nothing
 */
void CQMLObject::Init()
{
	
}

/**
 * Default update function.
 *  does nothing
 */
void CQMLObject::DefaultUpdate()
{

}