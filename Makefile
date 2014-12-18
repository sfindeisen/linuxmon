include Makefile.objects
include Makefile.programs

CPPOBJS__=$(addprefix out/obj/, $(OBJBASENAMES))
CPPOBJS=$(addsuffix .o, $(CPPOBJS__))

CPPPRGS__=$(addprefix out/obj/, $(PRGBASENAMES))
CPPPRGS=$(addsuffix .o, $(CPPPRGS__))

CPPDEPS__=$(addprefix out/obj/, $(OBJBASENAMES))
CPPDEPS__+=$(addprefix out/obj/, $(PRGBASENAMES))
CPPDEPS=$(addsuffix .depend, $(CPPDEPS__))

CPPDIRS__=$(dir $(OBJBASENAMES))
CPPDIRS__+=$(dir $(PRGBASENAMES))
CPPDIRS=$(sort $(CPPDIRS__))

OUTDIRS+=$(addprefix out/obj/, $(CPPDIRS))
OUTDIRS+=out/bin

.PHONY : default
default: help

CCPP=g++
CCPPDEPSCMD=g++ -MM -MG
CPPFLAGS+= -g -Wall -std=c++11

$(CPPPRGS): out/obj/%.o: src/%.cpp $(CPPOBJS)
	@echo "Compiling `basename $<`"
	@$(CCPP) -c $(CPPFLAGS) $< -o $@
	@$(CCPPDEPSCMD) -MT $@ $(CPPFLAGS) $< >> $(@:%.o=%.depend)
	@echo "Building  $*"
	@$(CCPP) $(LNFLAGS) -o out/bin/$* $@ $(CPPOBJS) -lpthread -lboost_regex

$(CPPOBJS): out/obj/%.o: src/%.cpp 
	@echo "Compiling: " `basename $<`
	@$(CCPP) -c $(CPPFLAGS) $< -o $@
	@$(CCPPDEPSCMD) -MT $@ $(CPPFLAGS) $< >> $(@:%.o=%.depend)

.PHONY : help
help:
	@echo "Available targets:"
	@echo "    build     - compiles and builds all"
	@echo "    all       - a synonim for build"
	@echo "    doc       - build + doxygen documentation generation"
	@echo "    clean"
	@echo "    showstats - source code statistics"

.PHONY : build
build : makedirs $(CPPOBJS) $(CPPPRGS)

.PHONY : all
all : build

.PHONY : doc
doc : build
	doxygen

.PHONY : makedirs
makedirs:
	-mkdir -p $(OUTDIRS)

.PHONY : clean
clean:
	rm -rf out/obj
	rm -rf out/bin/linuxmon-server
	rm -rf out/bin/proof-of-concept
	rm -rf doc/doxygen

.PHONY : showstats
showstats:
	@echo "====== Number of lines:"
	@wc --lines `find src \( -name "*.[ch]" -o -name "*.cpp" \) -print`

.PHONY : showfiles
showfiles:
#	@echo "OBJCPPSRCS == " $(OBJCPPSRCS)
#	@echo "PRGCPPSRCS == " $(PRGCPPSRCS)
	@echo "CPPDIRS    == " $(CPPDIRS)
	@echo "CPPOBJS    == " $(CPPOBJS)
	@echo "CPPPRGS    == " $(CPPPRGS)
	@echo "CPPDEPS    == " $(CPPDEPS)

-include $(CPPDEPS)
