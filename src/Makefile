# object files that will compose the executable file
OBJS= uimain.o tokenizer.o history.o


# -g means debug and -03 mean optimization 
CFLAGS = -g -O3

# building target file that is called tokenize
all: tokenize

# complie the target file with these specific .o files and dependencies with the specified "rules"
tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)


$(OBJS): tokenizer.h history.h
#clean up previous tokenize file if it exists
clean:
	rm -f *.o tokenize

#how the executable will be called
run:tokenize
	./tokenize
