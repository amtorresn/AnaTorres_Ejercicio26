fig.png: %.dat
	python plot.py 
    
all: euler.dat rk4.dat frog.dat

%.dat: file.x
	./file.x

file.x: file.cpp
	c++ file.cpp -o file.x

clean:
	rm -rf *.x *.dat
    