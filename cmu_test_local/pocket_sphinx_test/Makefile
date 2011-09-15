CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		pocket_sphinx_test.o

LIBS =

TARGET =	pocket_sphinx_test

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
