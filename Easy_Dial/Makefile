OPCIONS = -O0 -g -Wall -Wextra -Werror -std=c++14 -Wno-deprecated 

program.exe: driver_easydial.o phone.o easy_dial.o dialog.o call_registry.o
	g++ -o program.exe driver_easydial.o dialog.o easy_dial.o call_registry.o phone.o
	
driver_easydial.o: driver_easydial.cpp phone.hpp easy_dial.hpp dialog.hpp call_registry.hpp
	g++ -c driver_easydial.cpp $(OPCIONS);

easy_dial.o: easy_dial.cpp easy_dial.hpp easy_dial.rep
	g++ -c easy_dial.cpp $(OPCIONS);

dialog.o: dialog.cpp dialog.hpp
	g++ -c dialog.cpp $(OPCIONS);

call_registry.o: call_registry.cpp call_registry.hpp call_registry.rep 
	g++ -c call_registry.cpp $(OPCIONS);

phone.o: phone.cpp phone.hpp phone.rep
	g++ -c phone.cpp $(OPCIONS) -ansi;


clean:
	rm *.o
	rm *.exe
	rm *.gch
