SHELL := /bin/bash

SRC_FILE := main.cpp
HEADER_FILES := Cards.h Standard52CardDeckEnum.h

all: a.out

clean:
	rm -rf a.out out.cpp

.PHONY: all clean

out.cpp: $(SRC_FILE) $(HEADER_FILES)
	bash -x build_out_cpp.sh $^ > $@

eval_comp_cmd = perl -ne 'print if s/\/\/\s?(g\+\+ .*)/$$1/' $<
a.out: out.cpp
#	print the evaluated compilation command
	@$(eval_comp_cmd)
#	execute the actual command
	@$$($(eval_comp_cmd))
