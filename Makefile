# Makefile for HW4 Part3, ecs36b, f2020
#

CC = g++ -std=c++14
CFLAGS = -g -I/usr/include/jsoncpp

# CFLAGS = -g -D_ECS35B_DEBUG_ -I/usr/include/jsoncpp
# CFLAGS = -g -Wall -Wstrict-prototypes
# CFLAGS = -O3

LDFLAGS = 	-ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server	\
		-lcurl -ljsonrpccpp-client

CORE_INCS =	Core.h Person.h Advice.h Symptom.h	\
		Message.h JvTime.h
CORE_OBJS =	Core.o Person.o Advice.o Symptom.o	\
	 	JvTime.o

# rules.
all: 	dumpJ

#
#

dumpJ.o:	dumpJ.cpp $(CORE_INCS)
	$(CC) -c $(CFLAGS) dumpJ.cpp

Core.o:			Core.cpp Core.h
	$(CC) -c $(CFLAGS) Core.cpp

Person.o:		Person.cpp Person.h Core.h
	$(CC) -c $(CFLAGS) Person.cpp

Advice.o:		Advice.cpp Advice.h
	$(CC) -c $(CFLAGS) Advice.cpp

Symptom.o:		Symptom.cpp Symptom.h
	$(CC) -c $(CFLAGS) Symptom.cpp

JvTime.o:		JvTime.cpp JvTime.h
	$(CC) -c $(CFLAGS) JvTime.cpp

dumpJ:		$(CORE_OBJS) dumpJ.o
	$(CC) -o dumpJ $(CORE_OBJS) dumpJ.o $(LDFLAGS)

clean:
	rm -f	*.o *~ core dumpJ


