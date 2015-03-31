#pragma once
	struct Variant;
	struct CQMLObject
	{
	public:
		long classID;
		Variant Get(char*);
		virtual void Init();
		virtual void DefaultUpdate();
	};