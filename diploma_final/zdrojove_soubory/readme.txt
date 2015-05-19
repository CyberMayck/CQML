Dimplomová práce, Michal Hotovec

Soubory:

index.html obsahuje odkazy do rùzných souborù a složek
install.txt obsahuje postup instalace/spuštìní

Obsah složek:

text/ tištitelná forma diplomové práce v souboru DP.pdf
text/latex
	složka se zdrojovými soubory pro vygenerování tištitelné formy

src/Solution/CQML/bison_grammar
	zdrojové soubory pro vygenerování zdrojového kódu gramatiky pomocí FLEX a Bison
	(spustitelné soubory jsou pøiloženy, aby nebyla nutná instalace tìchto technologií)
src/Solution/CQML/parser
	zdrojové soubory pøekladaèe, který zpracovává na vstupu soubory v jazyce CQML a výstupem jsou zdrojové kódy v jazyce C++
src/Solution/CQML/CQML_lib_preprocessor
	zdrojové soubory preprocesoru vestavìných datových typù
src/Solution/CQML/CQML_DLL
	zdrojové soubory podpùrné knihovny pro správu vygenerovaného rozhraní za bìhu uživatelské aplikace
src/Solution/CQML/ParserLoader
	zdrojové soubory jednoduché aplikace jež slouží k automatické editaci projektù MSVC 2012, který do projektu vloží soubory outputX.cpp
src/Solution/CQML/CQML
	zdrojové soubory uživatelské aplikace zobrazující pøeložené rozhraní (jsou zde pøiloženy knihovny SDL2, ve složce lib)
src/cqml_includes
	složka s hlavièkovými soubory nutnými pro použití v uživatelské aplikaci
src/cqml_sources
	zdrojové CQML soubory z pøíkladu GUI ukázaného v diplomové práci
src/qml_sources
	zdrojové QML soubory z pøíkladu GUI ukázaného v diplomové práci (Vyžaduje QtCreator verze 5)
	

exe/translator
	spustitelná verze pøekladaèe a programu pro úpravu projektového souboru MSVC a batch soubor, obsahující pøíkazy makra pro spuštìní najednou
exe/CQML_run_app
	zdrojové soubory uživatelské aplikace, protože vygenerovaný kód pøekladaèem je nutné zkompilovat
exe/Excutable_test_app
	spustitelná verze ukázkové aplikace ukázané v diplomové práci


docs/
	návod k použití ve formátu .pdf
	složka doxygen s vygenerovanou doxygen dokumentací
