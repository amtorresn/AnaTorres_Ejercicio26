fig.png: %.dat
	python plot.py 
    
all: exp_01.dat exp_001.dat exp_1.dat

%.dat: file.x
	./file.x

file.x: file.cpp
	c++ file.cpp -o file.x

clean:
	rm -rf *.x *.dat
    