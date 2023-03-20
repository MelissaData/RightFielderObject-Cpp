# Melissa Right Fielder Object Windows C++

CXX=cl
CXXFLAGS=-Zi -EHsc
LDLIBS=mdRightFielder.lib
RM=del /q /f

all: MelissaRightFielderObjectWindowsCpp.exe clean

MelissaRightFielderObjectWindowsCpp.exe:	Main.cpp mdRightFielder.h mdRightFielderEnums.h
	$(CXX) $(CXXFLAGS) Main.cpp RightFielderObject.cpp $(LDLIBS) /Fe:.\Build\MelissaRightFielderObjectWindowsCpp.exe

clean:
	$(RM) *.obj *.ilk *.pdb *.h.hash *.lib.hash 

