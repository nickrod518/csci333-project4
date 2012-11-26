CPP = g++
CFLAGS = -Wall -Werror -Wextra

htest: hash_test.cpp Hash.o Entry.o
	$(CPP) $(CFLAGS) -o htest $^

Hash.o: Hash.h Hash.cpp
	$(CPP) $(CFLAGS) -c Hash.cpp

etest: entry_test.cpp Entry.o
	$(CPP) $(CFLAGS) -o etest entry_test.cpp Entry.o

Entry.o: Entry.h Entry.cpp
	$(CPP) $(CFLAGS) -c Entry.cpp

clean:
	rm -f *.o;
	rm -f *~;
	rm -f htest;
	rm -f etest;
