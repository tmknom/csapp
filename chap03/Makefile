SHELL=/bin/bash
.DEFAULT_GOAL := help

# https://gist.github.com/tadashi-aikawa/da73d277a3c1ec6767ed48d1335900f3
.PHONY: $(shell grep --no-filename -E '^[a-zA-Z0-9_-]+:' $(MAKEFILE_LIST) | sed 's/://')

BASE_PATH = .
BINARY_PATH = $(BASE_PATH)/bin/main
BINARY_OBJECT = $(BASE_PATH)/bin/binary.o

define gcc
	docker run --rm -w /work -v $(PWD):/work gcc gcc -Og -S -o ./bin/main.s ${1} && \
	cat ./bin/main.s | \
	grep -v -e '.size' -e '.globl' -e '.type' -e '.cfi' -e '.LF' -e '.ident' -e '.section' -e '.file' -e '.text'
endef

# Phony Targets

clean: ## Clean
	rm -f $(BINARY_PATH)

print: binary ## Build and run print.c
	gcc -o $(BINARY_PATH) print.c $(BINARY_OBJECT) && $(BINARY_PATH)

binary: ## Build binary.c
	gcc -o $(BINARY_OBJECT) -c binary.c

run: ## docker run
	docker run -it --rm -w /work -v $(PWD):/work gcc /bin/bash

compile_mstore: ## gcc -Og -c mstore.c
	gcc -Og -c mstore.c

compile_main_mstore: ## gcc -Og -o $(BASE_PATH)/bin/main main.c mstore.c
	gcc -Og -o $(BASE_PATH)/bin/main main.c mstore.c

exchange: ## gcc -Og -S exchange.c
	$(call gcc,exchange.c)

scale: ## gcc -Og -S scale.c
	$(call gcc,scale.c)

# https://postd.cc/auto-documented-makefile/
help: ## Show help
	@grep --no-filename -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-40s\033[0m %s\n", $$1, $$2}'
