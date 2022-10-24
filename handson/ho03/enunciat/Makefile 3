.PHONY: all
all: c-dev.df
	docker build -t c-dev -f c-dev.df .


.PHONY: clean
clean:
	docker rmi  c-dev
