graf.png : CB_graph.py CB_advection.cpp
	c++ CB_advection.cpp
	./a.out > advection.txt
	python3 CB_graph.py

advection.txt : CB_gravity.cpp
	c++ CB_advection.cpp
	./a.out > advection.txt
