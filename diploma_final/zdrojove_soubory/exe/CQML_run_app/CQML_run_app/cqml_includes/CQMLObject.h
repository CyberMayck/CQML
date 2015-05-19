#pragma once


#include "dll_export.h"

	struct VariantRef;
	struct CQMLObject
	{
	public:
		long classID;
		virtual CQML_API VariantRef Get(const char*);
		virtual CQML_API void Init();
		virtual CQML_API void DefaultUpdate();
		virtual CQML_API CQMLObject* Copy();
	};