#Marc Giannandrea | AC21008 
#Makefile
#Used to build,run and clean the relevant source files


CFLAGS = -Wall -Wextra –pedantic  @#Set compiler to alert at any warnings.

build:
	cc -o stacktest frame_manager.c stack.c stack_tester.c 
	@#Build all c files and output as executable stacktest

clean:
	rm -f stacktest
	@#Delete stacktest file

run:
	@([ -f ./stacktest ] && ./stacktest) || (make build && ./stacktest)
	@#If stacktest file exists then run. If not then call make build and then run stacktest
	
help:
	@echo "make build = build source files"
	@echo "make clean = clean up the built executable"
	@echo "make run = runs the executable. It will also rebuild if file doesn't exist"
	@echo "make help = prints this help section
	@#Echo all the commands possible in the make file.
