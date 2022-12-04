FLAGS = -std=c++11

map.o: map.cpp map.h
	g++ $(FLAGS) -c $<


Combat.o: Combat.cpp Combat.h Player_and_Shop.h Menu_Generator.h
	g++ $(FLAGS) -c $<

Menu_Operator.o: Menu_Operator.cpp Menu_Operator.h
	g++ $(FLAGS) -c $<

Menu_Generator.o: Menu_Generator.cpp Menu_Generator.h
	g++ $(FLAGS) -c $<

Player_and_Shop.o: Player_and_Shop.cpp Player_and_Shop.h Menu_Generator.h
	g++ $(FLAGS) -c $<

main.o: main.cpp Combat.h Menu_Operator.h Menu_Generator.h Player_and_Shop.h map.h
	g++ $(FLAGS) -c $<

main: main.o map.o Combat.o Menu_Operator.o Menu_Generator.o Player_and_Shop.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f main.o map.o Combat.o Menu_Operator.o Menu_Generator.o Player_and_Shop.o main

.PHONY: clean