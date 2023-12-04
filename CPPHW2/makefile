OBJECTS = approximations.o pi_approx.o
CXX = g++
CXXflags = -std=c++17

HW2main : $(OBJECTS)
	$(CXX) $(CXXflags) -o HW2main HW2main.cpp $(OBJECTS) 


# Windows specific TODO check that this is okay
# Or should we have rm?????
clean : 
	@echo "Removing the executable"
	del *.o
	del HW2main.exe