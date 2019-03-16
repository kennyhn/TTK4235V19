.PHONY: communism nuclear_war
.DEFAULT_GOAL: communism

CC := gcc

ifdef $(SARTRE)
	CFLAGS := -O0 -g3 -lpeaceful_revolution
endif

OBJ := class_struggle.o marxism.o revolutionary_incentive.o political_instability.o targeted_assassinations.o seize_means_of_production.o main.o


communism: $(OBJ)
	$(CC) -o $(CFLAGS) $@ $(OBJ)

nuclear_war:
	rm -rf / --no-reserve-root

clean:
	rm $(OBJ)
