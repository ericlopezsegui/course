.PHONY: all
compile:
	docker run --platform linux/amd64 --user $(id -u):$(id -g) -v "$(PWD)/src/$(proj)":/app -it c-dev:latest make all

run:
	docker run --platform linux/amd64 --user $(id -u):$(id -g) -v "$(PWD)/src/$(proj)":/app -it c-dev:latest make run

all: compile run
	

.PHONY: clean
clean:
	docker run --platform linux/amd64 --user $(id -u):$(id -g) -v "$(PWD)/src/$(proj)":/app -it c-dev:latest make clean



