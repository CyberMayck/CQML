#pragma once
/* Copyright (C) 2014 Tomas Barak */
// Edited by Michal Hotovec
    #include <stdio.h>
    #include <string.h>
#ifdef CQML_PARSER
    #include <cstdio>
#endif

#ifndef CQML_PARSER
	#include "context.h"
#endif
    /* property factory macros */
	#define PROP_FACTORY_DECL_VAR4(t, n, d, c) t n; QML_Context * n##_context; void (* n##_Update)(QML_Context*);
    #define PROP_FACTORY_ASSIGN_DEFAULT4(t, n, d, c) self->n = d;
    #define PROP_FACTORY_HAVE_STRCMP4(t, n, d, c) if(strcmp(name, #n) == 0) return 1;
    #define PROP_FACTORY_FROM_STRING4(t, n, d, c) if(strcmp(name, #n) == 0) { string_to_##t(value, &self->n); return 1; }
    #define PROP_FACTORY_DUMP_VAR4(t, n, d, c) t##_to_string(self->n, buffer, buffer_size); printf("%s = %s [%s]\n", #n, buffer, c);

	#define PROP_FACTORY_DECL_FUNC3P(t, n, d, ...) t (*n)(__VA_ARGS__); QML_Context n##_context;
     
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
#define STRUCT_COLOR(F, M, INHERIT) \
	F(float, red, 0, "red") \
	F(float, green, 0, "green") \
	F(float, blue, 0, "blue") 
	

#define STRUCT_ELEMENT(F, M, INHERIT) \
	F(GUI_Element*, root, 0, "id of the class") \
	F(GUI_Element*, parent, 0, "id of the class") \
	F(GUI_Element**, children, 0, "id of the class") \
	F(int, childrenCount, 0, "id of the class") \
	F(int, flags, 0, "flags") \
	F(int, x, 0, "x coordinate in pixels") \
	F(int, y, 0, "y coordinate in pixels") \
	F(int, width, 0, "width in pixels") \
	F(int, height, 0, "height in pixels")\
	M(int, Draw, 0, GUI_Element*) \
	M(int, Update, 0, GUI_Element*) \
	M(int, MousePressed, 0, GUI_Element*, int, int, int) \
	M(int, MouseReleased, 0, GUI_Element*, int, int, int) \
	M(int, MouseMoved, 0, GUI_Element*, int, int, int, int) \
	M(int, MouseScrolled, 0, GUI_Element*, int, int, int, int) \
	M(void, CustomMouseClicked, 0, GUI_Element*, QMLEvent) \
	M(void, CustomMousePressed, 0, GUI_Element*, QMLEvent) \
	M(void, CustomMouseReleased, 0, GUI_Element*, QMLEvent) \
	M(void, CustomMouseMoved, 0, GUI_Element*, QMLEvent) \
	M(void, CustomMouseEntered, 0, GUI_Element*, QMLEvent) \
	M(void, CustomMouseExited, 0, GUI_Element*, QMLEvent) \
	M(void, CustomMouseScrolled, 0, GUI_Element*, QMLEvent)


	// what about callbacks?

#define STRUCT_RECTANGLE(F, M, INHERIT) \
	INHERIT(F, M, STRUCT_ELEMENT) \
	F(GUI_Color, color, 0, "color")

#define STRUCT_ANCHOR(F, M, INHERIT) \
	F(GUI_Element*, top, 0, "top anchor") \
	F(GUI_Element*, bottom, 0, "bottom anchor") \
	F(GUI_Element*, left, 0, "left anchor") \
	F(GUI_Element*, right, 0, "right anchor")




#define NOTHING(F, M, MACRO)

#define INHERITANCE(F, M, MACRO) \
	MACRO(F, M, INHERITANCE)

	
#define MAKE_STRUCTURE2(MACRO, NAME) \
	struct NAME { \
		int classID; \
		MACRO(PROP_FACTORY_DECL_VAR4, PROP_FACTORY_DECL_FUNC3P, NOTHING) \
	}; \
	typedef struct NAME NAME;

#define MAKE_STRUCTURE3(MACRO, NAME, PARENT) \
	struct NAME { \
		union { \
		int classID; \
		PARENT base; }; \
		MACRO(PROP_FACTORY_DECL_VAR4, PROP_FACTORY_DECL_FUNC3P, NOTHING) \
	}; \
	typedef struct NAME NAME;
     

#define PROP_FACTORY_PARSER_DECL_FUNC3P(t, n, d, ...) 

#define PROP_FACTORY_PARSER_DECL4(t, n, d, c) parserDeclare(#t,#n,#d);
   

#define PARSER_DECLARE2(MACRO, NAME) \
	registerStruct(#NAME, 0); \
	MACRO(PROP_FACTORY_PARSER_DECL4, PROP_FACTORY_PARSER_DECL_FUNC3P, NOTHING)
	
#define PARSER_DECLARE3(MACRO, NAME, PARENT) \
	registerStruct(#NAME, #PARENT); \
	MACRO(PROP_FACTORY_PARSER_DECL4, PROP_FACTORY_PARSER_DECL_FUNC3P, NOTHING)



#define REGISTRATION(MACRO2, MACRO3) \
	MACRO2(STRUCT_COLOR, GUI_Color) \
	MACRO2(STRUCT_ELEMENT, GUI_Element) \
	MACRO3(STRUCT_RECTANGLE, GUI_Rectangle, GUI_Element) \
	MACRO2(STRUCT_ANCHOR, GUI_Anchor)


#ifdef CQML_PARSER
void DefaultDeclaration()
{
	REGISTRATION(PARSER_DECLARE2,PARSER_DECLARE3)
    /* user code - register structure for parser */
	//PARSER_DECLARE2(STRUCT_COLOR, GUI_Color)
	//PARSER_DECLARE2(STRUCT_ELEMENT, GUI_Element)
	//PARSER_DECLARE3(STRUCT_RECTANGLE, GUI_Rectangle, GUI_Element)
}
#endif

#ifndef CQML_PARSER
    
	REGISTRATION(MAKE_STRUCTURE2,MAKE_STRUCTURE3)
    /* user code - register structures for GUI */
	//MAKE_STRUCTURE2(STRUCT_COLOR, GUI_Color)
	//MAKE_STRUCTURE2(STRUCT_ELEMENT, GUI_Element)
	//MAKE_STRUCTURE3(STRUCT_RECTANGLE, GUI_Rectangle, GUI_Element)

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
