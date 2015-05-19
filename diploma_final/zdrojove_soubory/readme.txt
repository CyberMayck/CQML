Dimplomov� pr�ce, Michal Hotovec

Soubory:

index.html obsahuje odkazy do r�zn�ch soubor� a slo�ek
install.txt obsahuje postup instalace/spu�t�n�

Obsah slo�ek:

text/ ti�titeln� forma diplomov� pr�ce v souboru DP.pdf
text/latex
	slo�ka se zdrojov�mi soubory pro vygenerov�n� ti�titeln� formy

src/Solution/CQML/bison_grammar
	zdrojov� soubory pro vygenerov�n� zdrojov�ho k�du gramatiky pomoc� FLEX a Bison
	(spustiteln� soubory jsou p�ilo�eny, aby nebyla nutn� instalace t�chto technologi�)
src/Solution/CQML/parser
	zdrojov� soubory p�eklada�e, kter� zpracov�v� na vstupu soubory v jazyce CQML a v�stupem jsou zdrojov� k�dy v jazyce C++
src/Solution/CQML/CQML_lib_preprocessor
	zdrojov� soubory preprocesoru vestav�n�ch datov�ch typ�
src/Solution/CQML/CQML_DLL
	zdrojov� soubory podp�rn� knihovny pro spr�vu vygenerovan�ho rozhran� za b�hu u�ivatelsk� aplikace
src/Solution/CQML/ParserLoader
	zdrojov� soubory jednoduch� aplikace je� slou�� k automatick� editaci projekt� MSVC 2012, kter� do projektu vlo�� soubory outputX.cpp
src/Solution/CQML/CQML
	zdrojov� soubory u�ivatelsk� aplikace zobrazuj�c� p�elo�en� rozhran� (jsou zde p�ilo�eny knihovny SDL2, ve slo�ce lib)
src/cqml_includes
	slo�ka s hlavi�kov�mi soubory nutn�mi pro pou�it� v u�ivatelsk� aplikaci
src/cqml_sources
	zdrojov� CQML soubory z p��kladu GUI uk�zan�ho v diplomov� pr�ci
src/qml_sources
	zdrojov� QML soubory z p��kladu GUI uk�zan�ho v diplomov� pr�ci (Vy�aduje QtCreator verze 5)
	

exe/translator
	spustiteln� verze p�eklada�e a programu pro �pravu projektov�ho souboru MSVC a batch soubor, obsahuj�c� p��kazy makra pro spu�t�n� najednou
exe/CQML_run_app
	zdrojov� soubory u�ivatelsk� aplikace, proto�e vygenerovan� k�d p�eklada�em je nutn� zkompilovat
exe/Excutable_test_app
	spustiteln� verze uk�zkov� aplikace uk�zan� v diplomov� pr�ci


docs/
	n�vod k pou�it� ve form�tu .pdf
	slo�ka doxygen s vygenerovanou doxygen dokumentac�
