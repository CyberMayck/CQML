#pragma once


#include "dll_export.h"

	struct Variant;
	struct CQMLObject
	{
	public:
		long classID;
		virtual CQML_API  Variant Get(char*);
		virtual CQML_API  void Init();
		virtual CQML_API  void DefaultUpdate();
	};