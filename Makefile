pa17a: pa17a.o simple_list.o
	$(CXX) $(CXXFLAGS) simple_list.o pa17a.o -o pa17a

simple_list.o: simple_list.h simple_list.cpp
	$(CXX) $(CXXFLAGS) simple_list.cpp -c

pa17a.o: pa17a.cpp simple_list.h
	$(CXX) $(CXXFLAGS) pa17a.cpp -c

clean:
	rm -f pa17a.o pa17a

turnin:
	turnin -c cs202 -p pa17a -v \
		simple_list.h simple_list.cpp pa17a.cpp Makefile
