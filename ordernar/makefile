# Variables
CXX = g++
CXXFLAGS = -Wall  #opción -Wall es una bandera del compilador g++ que habilita una serie de advertencias (warnings) útiles
OBJ = paso1.o persona.o nodo.o listaligada.o archivo.o
TARGET = programa

# Regla para compilar el programa
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar paso1.cpp
paso1.o: paso1.cpp persona.h nodo.h listaligada.h archivo.h
	$(CXX) $(CXXFLAGS) -c paso1.cpp

# Regla para compilar persona.cpp
persona.o: persona.cpp persona.h
	$(CXX) $(CXXFLAGS) -c persona.cpp

# Regla para compilar nodo.cpp
nodo.o: nodo.cpp nodo.h persona.h
	$(CXX) $(CXXFLAGS) -c nodo.cpp

# Regla para compilar listaligada.cpp
listaligada.o: listaligada.cpp listaligada.h nodo.h persona.h
	$(CXX) $(CXXFLAGS) -c listaligada.cpp

# Regla para compilar archivo.cpp
archivo.o: archivo.cpp archivo.h
	$(CXX) $(CXXFLAGS) -c archivo.cpp

# Limpiar archivos objeto y el ejecutable
clean:
	rm -f $(OBJ) $(TARGET)
