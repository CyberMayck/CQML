#pragma once


	struct Variant;
	struct CQMLObject
	{
	public:
		long classID;
		virtual Variant Get(char*);
		virtual void Init();
		virtual void DefaultUpdate();
	};