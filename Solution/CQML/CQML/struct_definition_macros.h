#pragma once
/* Copyright (C) 2014 Tomas Barak */
// Edited by Michal Hotovec
   // #include <stdio.h>
   // #include <string.h>
#ifdef CQML_PARSER
    #include <cstdio>
#endif

#ifndef CQML_PARSER
#include <iostream>
using namespace std;

#endif
    /* property factory macros */
	#define PROP_FACTORY_DECL_MVAR4(t, n, d, c) t n;
	#define PROP_FACTORY_DECL_VAR4(t, n, d, c) t n; QML_Context * n##_context; void (* n##_Update)(QML_Context*);
    #define PROP_FACTORY_ASSIGN_DEFAULT4(t, n, d, c) self->n = d;
    #define PROP_FACTORY_HAVE_STRCMP4(t, n, d, c) if(strcmp(name, #n) == 0) return 1;
    #define PROP_FACTORY_FROM_STRING4(t, n, d, c) if(strcmp(name, #n) == 0) { string_to_##t(value, &self->n); return 1; }
    #define PROP_FACTORY_DUMP_VAR4(t, n, d, c) t##_to_string(self->n, buffer, buffer_size); printf("%s = %s [%s]\n", #n, buffer, c);

	#define PROP_FACTORY_DECL_FUNC3P(t, n, d, ...) t (*n)(__VA_ARGS__); QML_Context n##_context;
	#define PROP_FACTORY_DECL_METH3P(t, n, d, ...) virtual t n(__VA_ARGS__);
	#define PROP_FACTORY_DECL_METHV3P(t, n, d, ...) virtual t n(__VA_ARGS__);
     
    /* helper functions */
   /* int string_to_int(const char * str, int * outInt) {
            return sscanf(str, "%d", outInt) == 1 ? 1 : 0;
    }
     
    int string_to_float(const char * str, float * outFloat) {
            return sscanf(str, "%f", outFloat) == 1 ? 1 : 0;
    }
     
    void int_to_string(int val, char * buffer, size_t buffer_size) {
            //snprintf(buffer, buffer_size, "%d", val);
            sprintf(buffer, "%d", val);
    }
     
    void float_to_string(float val, char * buffer, size_t buffer_size) {
            //snprintf(buffer, buffer_size, "%f", val);
            sprintf(buffer, "%f", val);
    }*/
	
// user declared structs
#define STRUCT_COLOR(MF, F, M, ME, MEV, INHERIT) \
	F(float, red, 0, "red") \
	F(float, green, 0, "green") \
	F(float, blue, 0, "blue") 

#define STRUCT_FONT(MF, F, M, ME, MEV, INHERIT) \
	F(int, capital, 0, "capital") \
	F(int, italic, 0, "italic") \
	F(int, bold, 0, "bold") \
	F(int, size, 0, "size") \
	F(string, family, 0, "family")
	

#define STRUCT_ELEMENT(MF, F, M, ME, MEV, INHERIT) \
	MF(Element*, root, 0, "id of the class") \
	MF(Element*, parent, 0, "id of the class") \
	MF(Element**, children, 0, "id of the class") \
	MF(int, childrenCount, 0, "id of the class") \
	MF(int, flags, 0, "flags") \
	F(int, x, 0, "x coordinate in pixels") \
	F(int, y, 0, "y coordinate in pixels") \
	F(int, width, 0, "width in pixels") \
	F(int, height, 0, "height in pixels")\
	ME(int, Top, 0)\
	ME(int, Left, 0)\
	MEV(void, Draw, 0) \
	MEV(void, Update, 0) \
	MEV(int, MousePressed, 0, int, int, int) \
	MEV(int, MouseReleased, 0, int, int, int) \
	MEV(int, MouseClicked, 0, int, int, int) \
	MEV(int, MouseMoved, 0, int, int, int, int) \
	ME(int, MouseScrolled, 0, int, int, int, int) \
	M(void, CustomMouseClicked, 0, QML_Context*, QMLEvent) \
	M(void, CustomMousePressed, 0, QML_Context*, QMLEvent) \
	M(void, CustomMouseReleased, 0, QML_Context*, QMLEvent) \
	M(void, CustomMouseMoved, 0, QML_Context*, QMLEvent) \
	M(void, CustomMouseEntered, 0, QML_Context*, QMLEvent) \
	M(void, CustomMouseExited, 0, QML_Context*, QMLEvent) \
	M(void, CustomMouseScrolled, 0, QML_Context*, QMLEvent)



	// what about callbacks?

#define STRUCT_RECTANGLE(MF, F, M, ME, MEV, INHERIT) \
	INHERIT(F, M, STRUCT_ELEMENT) \
	MEV(void, Draw, 0) \
	MEV(void, Update, 0) \
	MEV(int, MousePressed, 0, int, int, int) \
	MEV(int, MouseReleased, 0, int, int, int) \
	MEV(int, MouseClicked, 0, int, int, int) \
	MEV(int, MouseMoved, 0, int, int, int, int) \
	MEV(int, MouseScrolled, 0, int, int, int, int) \
	F(Color, color, 0, "color")


#define STRUCT_TEXT(MF, F, M, ME, MEV, INHERIT)\
	INHERIT(F, M, STRUCT_RECTANGLE)\
	MEV(void, Draw, 0) \
	MEV(void, Update, 0) \
	F(Color, text_color, 0, "text color")\
	F(string, text, 0, "text color")\
	F(Font, font, 0, "font style")

#define STRUCT_TEXT_INPUT(MF, F, M, ME, MEV, INHERIT)\
	INHERIT(F, M, STRUCT_RECTANGLE)\
	MEV(void, Update, 0) \
	MEV(void, Draw, 0) 


#define STRUCT_ANCHOR(MF, F, M, ME, MEV, INHERIT) \
	F(Element*, top, 0, "top anchor") \
	F(Element*, bottom, 0, "bottom anchor") \
	F(Element*, left, 0, "left anchor") \
	F(Element*, right, 0, "right anchor")


#ifdef CQML_PARSER
#define REGPRIMITIVE(x)		registerPrimitive(#x);

#else
#define REGPRIMITIVE(x)

#endif


#define NOTHING(F, M, MACRO)

#define INHERITANCE(F, M, MACRO) \
	MACRO(F, M, INHERITANCE)

	
#define MAKE_STRUCTURE2(MACRO, NAME) \
	struct NAME : public CQMLObject { \
		NAME();\
		MACRO(PROP_FACTORY_DECL_MVAR4, PROP_FACTORY_DECL_VAR4, PROP_FACTORY_DECL_FUNC3P, PROP_FACTORY_DECL_METH3P, PROP_FACTORY_DECL_METHV3P, NOTHING) \
	}; \


#define MAKE_STRUCTURE3(MACRO, NAME, PARENT) \
	struct NAME : public PARENT { \
		NAME();\
		MACRO(PROP_FACTORY_DECL_MVAR4, PROP_FACTORY_DECL_VAR4, PROP_FACTORY_DECL_FUNC3P, PROP_FACTORY_DECL_METH3P, PROP_FACTORY_DECL_METHV3P, NOTHING) \
	}; \
     

#define PROP_FACTORY_PARSER_DECL_FUNC3P(t, n, d, ...) parserDeclareFunc(#t, #n, #d, #__VA_ARGS__);

#define PROP_FACTORY_PARSER_DECL4(t, n, d, c) parserDeclare(#t,#n,#d);
#define PROP_FACTORY_PARSER_DECL_METH3P(t, n, d, ...)
   
#define PARSER_DECLARE2_REF(MACRO, NAME) \
	registerStructRef(#NAME, 0); \
	MACRO(PROP_FACTORY_PARSER_DECL4, PROP_FACTORY_PARSER_DECL4, PROP_FACTORY_PARSER_DECL_FUNC3P, PROP_FACTORY_PARSER_DECL_METH3P, PROP_FACTORY_PARSER_DECL_METH3P, NOTHING)

#define PARSER_DECLARE2(MACRO, NAME) \
	registerStruct(#NAME, 0); \
	MACRO(PROP_FACTORY_PARSER_DECL4, PROP_FACTORY_PARSER_DECL4, PROP_FACTORY_PARSER_DECL_FUNC3P, PROP_FACTORY_PARSER_DECL_METH3P, PROP_FACTORY_PARSER_DECL_METH3P, NOTHING)
	
#define PARSER_DECLARE3(MACRO, NAME, PARENT) \
	registerStruct(#NAME, #PARENT); \
	MACRO(PROP_FACTORY_PARSER_DECL4, PROP_FACTORY_PARSER_DECL4, PROP_FACTORY_PARSER_DECL_FUNC3P, PROP_FACTORY_PARSER_DECL_METH3P, PROP_FACTORY_PARSER_DECL_METH3P, NOTHING)


#define REGISTRATION(MACRO2, MACRO2REF, MACRO3) \
	REGPRIMITIVE(char)\
	REGPRIMITIVE(short)\
	REGPRIMITIVE(int)\
	REGPRIMITIVE(long)\
	REGPRIMITIVE(float)\
	REGPRIMITIVE(double)\
	REGPRIMITIVE(string)\
	MACRO2(STRUCT_COLOR, Color) \
	MACRO2(STRUCT_FONT, Font) \
	MACRO2REF(STRUCT_ELEMENT, Element) \
	MACRO3(STRUCT_RECTANGLE, Rectangle, Element) \
	MACRO2(STRUCT_ANCHOR, Anchor) \
	MACRO3(STRUCT_TEXT, Text, Rectangle) \
	MACRO3(STRUCT_TEXT_INPUT, TextInput, Text)


#ifdef CQML_PARSER
void DefaultDeclaration()
{
	REGISTRATION(PARSER_DECLARE2,PARSER_DECLARE2_REF,PARSER_DECLARE3)
    /* user code - register structure for parser */
	//PARSER_DECLARE2(STRUCT_COLOR, GUI_Color)
	//PARSER_DECLARE2(STRUCT_ELEMENT, GUI_Element)
	//PARSER_DECLARE3(STRUCT_RECTANGLE, GUI_Rectangle, GUI_Element)
}
#endif

#ifndef CQML_PARSER
	
namespace CQMLGUI
{
#include "context.h"
	//struct Element : public CQMLObject { 
	//	Element();
	//	PROP_FACTORY_DECL_VAR4(Element*, root, 0, "id of the class");
	/////	PROP_FACTORY_DECL_VAR4(Element*, parent, 0, "id of the class");
	//PROP_FACTORY_DECL_VAR4(Element**, children, 0, "id of the class");
	//PROP_FACTORY_DECL_VAR4(int, childrenCount, 0, "id of the class");

	
	//PROP_FACTORY_DECL_METH3P(int, Left, 0)
	//PROP_FACTORY_DECL_METHV3P(void, Draw, 0)

	//	STRUCT_ELEMENT(PROP_FACTORY_DECL_VAR4, PROP_FACTORY_DECL_FUNC3P, PROP_FACTORY_DECL_METH3P, PROP_FACTORY_DECL_METHV3P, NOTHING) \
	//};
	//MAKE_STRUCTURE2(STRUCT_COLOR, Color)
	//MAKE_STRUCTURE2(STRUCT_ELEMENT, Element)
	REGISTRATION(MAKE_STRUCTURE2, MAKE_STRUCTURE2, MAKE_STRUCTURE3)


    /* user code - register structures for GUI */
	//MAKE_STRUCTURE2(STRUCT_COLOR, GUI_Color)
	//MAKE_STRUCTURE2(STRUCT_ELEMENT, GUI_Element)
	//MAKE_STRUCTURE3(STRUCT_RECTANGLE, GUI_Rectangle, GUI_Element)

// end namspace 
};
#endif

#ifdef MEH


     
    /* following test_* functions should be hidden into another macros for later reuse
     * for example you will have a _init function for all structs like this one
     */
     
    /* initializes to default values */
    void test_init(Rectangle * self) {
            STRUCT_RECTANGLE(PROP_FACTORY_ASSIGN_DEFAULT4, INHERITANCE)
    }
     
    /* dumps all properties and their help */
    void test_dump(const Rectangle * self) {
            static const size_t buffer_size = 64;
            char buffer[buffer_size];
            STRUCT_RECTANGLE(PROP_FACTORY_DUMP_VAR4, INHERITANCE)
    }
     
    /* returns nonzero if property is there */
    int test_have_property(const char * name) {
            STRUCT_RECTANGLE(PROP_FACTORY_HAVE_STRCMP4, INHERITANCE)
            return 0;
    }
     
    /* returns nonzero if property was set */
    int test_set_property(Rectangle* self, const char * name, const char * value) {
            STRUCT_RECTANGLE(PROP_FACTORY_FROM_STRING4, INHERITANCE)
            return 0;
    }
     
    /*int main(int argc, char * argv[]) {
            //const char * pname = 0;
            //const char * pvalue = 0;
            Rectangle test;
            if(argc < 3) {
                    printf("usage: %s PROP_NAME VALUE\n", argv[0]);
                   // return 1;
            }
			//pname = argv[1];
            //pvalue = argv[2];
			char * pname="width";
			char * pvalue="20";
			int meh;
     
            test_init(&test);
            printf("== defaults ==\n");
            test_dump(&test);
            if(!test_have_property(pname)) {
                    printf("property %s is unknown\n", pname);
				scanf("%d",&meh);
                    return 1;
            }
            if(!test_set_property(&test, pname, pvalue)) {
                    printf("cannot set property %s to %s\n", pname, pvalue);
            } else {
                    printf("changed %s property\n", pname);
            }
            printf("== changed from console ==\n");
            test_dump(&test);

			scanf("%d",&meh);
            return 0;
    }*/

#endif
