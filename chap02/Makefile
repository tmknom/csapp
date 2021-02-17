SHELL=/bin/bash
.DEFAULT_GOAL := help

# https://gist.github.com/tadashi-aikawa/da73d277a3c1ec6767ed48d1335900f3
.PHONY: $(shell grep --no-filename -E '^[a-zA-Z0-9_-]+:' $(MAKEFILE_LIST) | sed 's/://')

BASE_PATH = ..
BINARY_PATH = $(BASE_PATH)/bin/main

# Phony Targets

clean: ## Clean
	rm -f $(BINARY_PATH)

show_bytes: ## Build and run show_bytes.c
	gcc -o $(BINARY_PATH) show_bytes.c && $(BINARY_PATH)

sum: ## Build and run sum.c
	gcc -o $(BINARY_PATH) -c sum.c && hexdump -C $(BINARY_PATH)

inplace_swap: ## Build and run inplace_swap.c
	gcc -o $(BINARY_PATH) inplace_swap.c && $(BINARY_PATH)

mask: ## Build and run mask.c
	gcc -o $(BINARY_PATH) mask.c && $(BINARY_PATH)

# https://postd.cc/auto-documented-makefile/
help: ## Show help
	@grep --no-filename -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-40s\033[0m %s\n", $$1, $$2}'
