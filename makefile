signal: signals.c
	gcc signals.c -o signals

run: signals
	./signals

clean:
	rm signals
	rm *~