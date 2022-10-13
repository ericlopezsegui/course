rmsf: rmsf.o
	gcc -o rmsf rmsf.o
rmsf.o: rmsf.c
	gcc -c rmsf.c

test.sh:
	@touch
	@touch
	@touch
	@mkdir
	@ls
	@./rmsf test test1
	@./rmsf dir1
	@echo ls post rmsf;
	@ls
	@cd \.trash
	@echo cd \.trash
	@ls .trash
	@cd \..

install:
	@su root
	@cp rmsf usr/bin/
	@su els8