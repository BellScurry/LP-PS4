CC = g++

# Directory Options
### Header File Directories
CPLEX_INCLUDE = /home/jongho/.opt/ibm/ILOG/CPLEX_Studio_Community127/cplex/include
CONCERT_INCLUDE = /home/jongho/.opt/ibm/ILOG/CPLEX_Studio_Community127/concert/include
### 
CPLEX_ARCH = /home/jongho/.opt/ibm/ILOG/CPLEX_Studio_Community127/cplex/lib/x86-64_linux/static_pic
CONCERT_ARCH = /home/jongho/.opt/ibm/ILOG/CPLEX_Studio_Community127/concert/lib/x86-64_linux/static_pic

# Linker Options
LINKS = -lilocplex -lconcert -lcplex -lpthread

all: ilolplex1

ilolplex1:
	$(CC) -I$(CPLEX_INCLUDE) -I$(CONCERT_INCLUDE) -L$(CPLEX_ARCH) -L$(CONCERT_ARCH) -DIL_STD ilolpex1.cc -o ilolpex1 $(LINKS)

clean:
	rm ilolpex1 *.lp
