# Compilateur utilisé
CLANG=clang++
# Fichiers objets (.o) -> 1 par dossier / module
SFMLOBJ=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# Différents fichiers selon les modules
CORE=core/core.cc core/RomReader.cc
CPU=cpu/cpu.cc
GRAPHICS=graphics/graphics.cc
TOOLS=tools/tools.cc
EXEC=emulator
# Flags clang++
CXXFLAGS=-std=c++1y -pedantic-errors -Wall -Wdeprecated-writable-strings -Werror \
         -Wextra -Wsign-conversion -Wswitch-enum -Wtype-limits -Wundef -Wunused-variable -pthread
SOURCES=$(CORE) $(CPU) $(GRAPHICS) $(TOOLS) main.cc
LIBS=lib/lua5.2.3.a

# Flags:
# @> -std=c++1y > activation de C++14
# @> -Wall > active davantage de warnings (-Wunused-function, -Wswitch, -Wunused-local-typedef, -Wmaybe-uninitialized entre autres)
# @> -Wdeprecated-writable-strings > utilisation de char* au lieu de std::string char* const
# @> -Werror > transforme les warnings en erreurs
# @> -Wextra > active davantage de warnings (-Wuninitialized, -Wunused-parameter, -Wunused-but-set-parameter, -Wsign-compare entre autres)
# @> -Wsign-conversion > conversions implicites signé / non signé
# @> -Wswitch-enum > tous les cas d'une enum doivent être testés dans un switch
# @> -Wtype-limits > comparaison signé / non signé
# @> -Wundef > si on teste dans un #if une macro non définie
# @> -Wunused-variable > variables non utilisées

$(EXEC): clean $(SFMLOBJ)
	@echo "Making emulator (NO LUA)"
	@$(CLANG) $(CXXFLAGS) $(SFMLOBJ) $(SOURCES) -o $(EXEC) $(LIBS)
	@echo "Done"
	
debug: clean $(SFMLOBJ)
	@echo "Making emulator (DEBUG, NO LUA)"
	@$(CLANG) $(CXXFLAGS) -DDEBUG $(SFMLOBJ) $(SOURCES) -o $(EXEC) $(LIBS)
	@echo "Done"
	
release: clean $(SFMLOBJ)
	@echo "Making emulator (RELEASE)"
	@$(CLANG) $(CXXFLAGS) -DRELEASE -O2 $(SFMLOBJ) $(SOURCES) -o $(EXEC) -lm -ldl -DLUA_OK $(LIBS)
	@echo "Done"

run:
	@./$(EXEC)

clean:
	@echo "Deleting files"
	@rm -rf *.o *.cc~ Makefile~ *.h.gch a.out $(EXEC)
	@echo "Done"

